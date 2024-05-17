#include "convolution.h"

#include <stdlib.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;
    (void)matrix;
    (void)w_m;
    (void)h_m;
    int a= w_m/2;
    int b= h_m/2;
for (int x=0; x<w ;x++ ) {
    for(int y=0; y<h; y++){
        float ans=0;
        for(int i=0; i<w_m; i++){
            for(int j=0; j<h_m; j++){
                ans+= matrix[j* w_m+1] *get_pixel_value(img, w, h, x-a+i,y-b+j);
            };
        };
        result[y*w+x]=ans;
    };

};
    // TODO: Implement me!
}
