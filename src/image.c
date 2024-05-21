#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {
    (void)img;
    (void)w;
    (void)h;
    (void)T;
    for (int i =0;i<w*h;i++ ) {
        if (img[i]<= T) {
            img[i]=0;
        }else {
            img[i]=255;
        }
    }

    // TODO: Implement me!
}

void scale_image(float *result, const float *img, int w, int h) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;
    float min = img[0];
        float max =img[0];
        //finding max and min
        for (int i=0; i<(w*h); i++){
            min = fmin(img[i], min);
            max = fmax(img[i], max);
        }
        if (min==max){
            for (int i=0;i<w*h;i++){
                result[i]=0;
            }
        }else{ 
            for( int i=0;i<w*h;i++){
                result[i]= (img[i]-min)*255 / (max-min);
            }
        }

    // TODO: Implement me!
}

float get_pixel_value(const float *img, int w, int h, int x, int y) {
    (void)img;
    (void)w;
    (void)h;
    (void)x;
    (void)y;
    if (x<0) {
        if (x==-1){
            x=0;
        }else{x=1;}
    }else if(x>w-1){
        if (x==w){
            x=w-1;
        }else{ x=w-2;}
    }
    if (y<0) {
        if (y==-1){
            y=0;
        }else{y=1;}
    }else if(y>h-1){
        if (y==h){
            y=h-1;
        }else{ y=h-2;}
    }
    return img[y*w+x];

    // TODO: Implement me!

    return 0;
}

float *array_init(int size) {
    (void)size;
    float *array= calloc (size, sizeof(float));
    // TODO: Implement me!
    return array;
}

void array_destroy(float *m) {
    (void)m;
    free (m);
    // TODO: Implement me!
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    (void)filename;
    (void)w;
    (void)h;
    // TODO: Implement me!
    FILE *f=fopen (filename, "r");
    if (f==NULL) {
        return NULL;
    }
    char sa[3];
    int ma;
    
    fscanf (f,"%2s\n%d %d\n%d\n",sa ,w , h, &ma );

     if ((strcmp(sa,"P2" ))!=0 ||*w<=0 || *h<=0 || ma!=255  ) {
        fclose(f);
       return NULL;
    }
    int siz = (*w)* (*h);
    float *array= array_init (siz);
    int temp;
    int i=0;
    while(!feof(f)){ 
        fscanf(f, "%d ",&temp);
     if (temp<0|| temp>255){
        array_destroy(array);
        fclose (f);
        return NULL;
     }else { array[i] = temp; i++; }
    }
    if(i!=siz){fclose (f);
        return NULL;
    }
    fclose (f);
    return array;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    (void)img;
    (void)w;
    (void)h;
    (void)filename;
       FILE *f=fopen (filename, "w");
       if (f==NULL){
        printf("file not appropriate");
        return;
       }
    fprintf(f,"P2\n%d %d\n255\n ",w, h);
    for(int j=0;j<h;j++){
        for (int i=0; i<w;i++){
              fprintf(f,"%d ",(int)img[j*w+i]);
        }
      fprintf(f,"\n");
    }
    fclose(f);

    // TODO: Implement me!
}
