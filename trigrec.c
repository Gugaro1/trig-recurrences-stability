#include <math.h>
#include <stdlib.h>
#define MPI 3.14159265358979323846


void trigrec0 (int k, double x, double c[], double s[]) {
    c[0] = 1;
    s[0] = 0;
    for(int j = 1 ; j<=k; j++){
        c[j] = cos(j*x);
        s[j] = sin(j*x);
    }
}

void trigrec1 (int k, double x, double c[], double s[]) {
    int j;
    c[0] = 1;
    s[0] = 0;
    c[1] = cos(x);
    s[1] = sin(x);
    double c1 = c[1];
    for(j = 1; j<k; j++){
        c[j+1] = 2*c1*c[j] - c[j-1];
        s[j+1] = 2*c1*s[j] - s[j-1];
    }
}


void trigrec2 (int k, double x, double c[], double s[]) {
    int j;
    c[0] = 1;
    s[0] = 0;
    c[1] = cos(x);
    s[1] = sin(x);
    double c1 = c[1], s1 = s[1];
    for(j = 1; j<k; j++){
        c[j+1] = c1*c[j] - s1*s[j];
        s[j+1] = s1*c[j] + c1*s[j];
    }
}

void trigrec3 (int k, double x, double c[], double s[]) {
    double t, dc, ds;
    dc=sin(x/2); dc=-2*dc*dc;
    t = 2 * dc;
    ds = ((int)floor(x/MPI)%2 == 0 ? 1:-1)* sqrt(-dc*(2 + dc));
    c[0] = 1, s[0] = 0;
    for(int j = 1; j<=k; j++){
        c[j] = c[j-1] + dc; s[j] = s[j-1] + ds;
        dc = t * c[j]  + dc; ds = t * s[j]  + ds;
    }
}
