#include<bits/stdc++.h>
#define arow 3
#define acol 2
#define trow 2
#define tcol 3 
#define brow 1
#define bcol 3
using namespace std;
int main()
{
    double A[arow][acol] = {1, 1, 
                           -2, 3, 
                           2, -1};

    double B[brow][bcol] = {3, 1, 2};
    double AT[trow][tcol];

    printf("Matrix:\n");
    for(int i = 0; i < arow; i++)
    {
        for(int j = 0; j < acol; j++)
        {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    printf("Transpose:\n");
    for(int i = 0; i < trow; i++)
    {
        for(int j = 0; j < tcol; j++)
        {
            AT[i][j] = A[j][i];
            printf("%lf ", AT[i][j]);
        }
        printf("\n");
    }

    double AAT[trow][acol];
    printf("Multiplication:\n");
    for(int i = 0; i < trow; i++)
    {
        for(int j = 0; j < acol; j++)
        {
            AAT[i][j] = 0;
            for(int k = 0; k < arow; k++)
            {
                AAT[i][j] += AT[i][k]*A[k][j];
            }
        }
    }

    for(int i = 0; i < trow; i++)
    {
        for(int j = 0; j < acol; j++)
        {
            printf("%lf ", AAT[i][j]);
        }
        printf("\n");
    }


    return 0;
}