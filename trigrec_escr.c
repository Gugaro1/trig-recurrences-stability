#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trigrec.h"


double * resmem(int k){
   double *ptr;
   ptr = (double*) malloc(k * sizeof(double));
   if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
   }
   return ptr;
}

int main(int argc, char *argv[]) {
   int k;
   double x;
   if (argc!=3
         || sscanf(argv[1],"%d",&k)!=1
         || sscanf(argv[2],"%lf",&x)!=1
         ) {
      fprintf(stderr, "trigrec_escr k x\n");
      return -1;
   }  
   double *c0 =resmem(k);
   double *c1 =resmem(k);
   double *c2 =resmem(k);
   double *c3 =resmem(k);
   double *s0 =resmem(k);
   double *s1 =resmem(k);
   double *s2 =resmem(k);
   double *s3 =resmem(k);
   trigrec0(k, x, c0 , s0);
   trigrec1(k, x, c1 , s1);
   trigrec2(k, x, c2 , s2);
   trigrec3(k, x, c3 , s3); 
   for (int j = 0; j <= k ; j++) {
       printf("%.16g  %.16g  %.16g  %.16g  %.16g  %.16g  %.16g  %.16g \n", c0[j], c1[j], c2[j], c3[j], s0[j], s1[j], s2[j], s3[j]);
   }
   return 0;
}

