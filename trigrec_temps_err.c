#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "trigrec.h"
#include "temps.h"


double maxerror(double c1[], double c2[], int k);
double * resmem(int k);
void temps_funcio(void (*func)(int, double, double*, double*), int k, double x, double c[], double s[], int i);


int main (int argc, char *argv[]){
   int k;
   double x;
   if (argc!=3
         || sscanf(argv[1],"%d",&k)!=1
         || sscanf(argv[2],"%lf",&x)!=1
         ) {
      fprintf(stderr, "trigrec_temps_err k x\n");
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

   printf("El temps de càlcul dels algorismes són: \n");
   temps_funcio(trigrec0, k, x, c0, s0, 0);
   temps_funcio(trigrec1, k, x, c1, s1, 1);
   temps_funcio(trigrec2, k, x, c2, s2, 2);
   temps_funcio(trigrec3, k, x, c3, s3, 3);

   printf("Els errors dels algorismes són:\n");
   printf("errc1 %.4g \t", maxerror(c0, c1, k));
   printf("errc2 %.4g \t", maxerror(c0, c2, k));
   printf("errc3 %.4g \n", maxerror(c0, c3, k));
   printf("errs1 %.4g \t", maxerror(s0, s1, k));
   printf("errs2 %.4g \t", maxerror(s0, s2, k));
   printf("errs3 %.4g \n", maxerror(s0, s3, k));

   free(c0);
   free(c1);
   free(c2);
   free(c3);
   free(s0);
   free(s1);
   free(s2);
   free(s3);

   return 0;
}

double * resmem(int k){
   double *ptr = (double*) malloc(k * sizeof(double));
   if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
   }
   return ptr;
}

void temps_funcio(void (*func)(int, double, double*, double*), int k, double x, double c[], double s[], int i ){
   double tt0 = -1, tt1, tt2, dif;
   tt1 = temps(&tt0);
   func(k, x, c, s);
   tt2 = temps(&tt0);
   dif = tt2 - tt1;
   printf("temps trigrec%d: %.4g \n", i, dif);
}

double maxerror(double c1[], double c2[], int k){
   double max = 0, err;
   for(int i = 0; i <= k; i++){
      err = fabs(c1[i] - c2[i]);
      if(err > max)
      {
         max = err;
      }
   }
   return max;
}