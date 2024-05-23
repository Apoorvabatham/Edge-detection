#include <stdio.h>
#include <stdlib.h>

#include "argparser.h"
#include "convolution.h"
#include "derivation.h"
#include "gaussian_kernel.h"
#include "image.h"

int main(int const argc, char **const argv) {
    /**
     * Parse arguments. The parsed image file name and threshold are available
     * in the image_file_name and threshold global variables (see argparser.h).
     */
    parse_arguments(argc, argv);
    printf("Computing edges for image file %s with threshold %i\n",
           image_file_name, threshold);

    /**
     * Read Image from given file.
     *
     * If the input file is broken terminate with return value 1.
     *
     * Hint: The width and height of the image have to be accessible in the
     * scope of this function.
     */
    // TODO: Implement me!
    int w;
    int h;
       float *image= read_image_from_file( "image_file_name", &w, &h);
       if (image ==NULL){return 1;}
    /**
     * Blur the image by using convolve with the given Gaussian kernel matrix
     * gaussian_k (defined in gaussian_kernel.h). The width of the matrix is
     * gaussian_w, the height is gaussian_h.
     *
     * Afterwards, write the resulting blurred image to the file out_blur.pgm.
     */
    // TODO: Implement me!
    float *blur_img=array_init(w*h);
    if (blur_img==NULL){return 1;}
       convolve(blur_img, image, w, h, gaussian_k, gaussian_w, gaussian_h);
       char *ob ="out_blur.pgm";
       write_image_to_file(blur_img, w,h, ob);
    /**
     * Compute the derivation of the blurred image computed above in both x and
     * y direction.
     *
     * Afterwards, rescale both results and write them to the files out_d_x.pgm
     * and out_d_y.pgm respectively.
     */
    // TODO: Implement me!
    float * xres= array_init(w*h);
    float *yres = array_init(w*h);
    float *xscale = array_init(w*h);
    float *yscale = array_init(w*h);

       derivation_x_direction(xres, blur_img, w, h);
       scale_image(xscale, xres, w, h);
        write_image_to_file(xscale, w,h, "out_d_x.pgm");
        
       derivation_y_direction(yres, blur_img, w, h);
       scale_image(yscale, yres, w, h);
        write_image_to_file(yscale, w,h, "out_d_y.pgm");

    /**
     * Compute the gradient magnitude of the blurred image by using the
     * (unscaled!) derivations in x- and y-direction computed earlier.
     *
     * Afterwards, rescale the result and write it to out_gm.pgm.
     */
    // TODO: Implement me!
    float *gradient_res= array_init(w*h);
     float *gradient_sc= array_init(w*h);

       gradient_magnitude(gradient_res, xres, yres, w, h);
        scale_image(gradient_sc, gradient_res, w, h);
       write_image_to_file(gradient_sc, w,h, "out_gm.pgm");
    /**
     * Apply the threshold to the gradient magnitude.
     * Then write the result to the file out_edges.pgm.
     */
    // TODO: Implement me!
    apply_threshold(gradient_res, w, h, threshold);
      write_image_to_file(gradient_res, w, h, "out_edges.pgm");
    /**
     * Remember to free dynamically allocated memory when it is no longer used!
     */
    array_destroy(blur_img);
    array_destroy(xres);
    array_destroy(yres);
    array_destroy(xscale);
    array_destroy(yscale);
    array_destroy(gradient_res);
    array_destroy(gradient_sc);
    
}
