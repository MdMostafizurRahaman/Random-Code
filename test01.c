#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define PI   3.14159

int main (void) {
  int i, n=MAXN;
  double a=0, b=2*PI, h;
  double x[MAXN + 1], sinx[MAXN + 1];
  
  h = (b - a)/n;
  x[0] = a;
  for (i=1; i< MAXN; i++)
    x[i] = x[i-1] + h;
  x[i] = b;

  for (i=0; i<= MAXN; i++)
    sinx[i] = sin(x[i]);

  printf("\"x\",\"sin(x)\"\n");
  for (i=0; i<= MAXN; i++)
    printf("%lf,%lf\n", x[i],sinx[i] );


  return EXIT_SUCCESS;
}
