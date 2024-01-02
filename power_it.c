#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double maxv(double a,double b)
      {
          if(a>b)
            return a;
          else 
            return b;
}
int main (void) {
  
   double l0=0,l1;
   double x1[3];
  double x0[3]={1.0,3.0,5.0},a[3][3]={{1,2,0.0},{-2.0,1.0,2.0},{1,3.0,1.0}};
  printf("Initial x0 matrix is %lf %lf %lf\n",x0[0],x0[1],x0[2]);
  int i=0;
  
   printf("---------------------------------\n");
  while(1)
  {
  i++;
  

     
       x1[0] = a[0][0]*x0[0]+a[0][1]*x0[1]+a[0][2]*x0[2];
       x1[1] = a[1][0]*x0[0]+a[1][1]*x0[1]+a[1][2]*x0[2];
       x1[2] = a[2][0]*x0[0]+a[2][1]*x0[1]+a[2][2]*x0[2];
     

//printf("iter i=%d\nEigenvector : %lf  %lf  %lf\n",i,fabs(x1[0]),fabs(x1[1]),fabs(x1[2]));

 l1=maxv(fabs(x1[0]),fabs(x1[1]));
 l1=maxv(fabs(l1),fabs(x1[2]));
 

//printf(" l1=%lf\n",l1);


x1[0]=x1[0]/l1;
x1[1]=x1[1]/l1;
x1[2]=x1[2]/l1;

if(fabs(l1-l0)<0.000001)
break;

printf("iter i=%d\nEigenvector : %lf  %lf  %lf\n",i,x1[0],x1[1],x1[2]);

x0[0]=x1[0];
x0[1]=x1[1];
x0[2]=x1[2];
l0=l1;



}

printf("Max igen value : %lf\n",l1);
printf("Eigenvector : %lf  %lf  %lf\n",x1[0],x1[1],x1[2]);



  return 0;
}
