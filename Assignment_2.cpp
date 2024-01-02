#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, p, q, flag;
    double eigen_vector[20][20];
    double V[20][20];
    double VT[20][20];
    double U[20][20];
    double eigen_value[20];
    double square_value[20];
    double a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10];
    double temp[10][10], theta, zero = 1e-5, max, pi = 3.141592654;

    double A[20][20], AT[20][20], E[20][20];
    int A_matrix_row, col_of_A_matrix;

    printf("Enter the dimentions of A matrix(row,col)->\n");
    scanf("%d%d", &A_matrix_row, &col_of_A_matrix);
    printf("Enter The Matrix\n");
    for (int i = 0; i < A_matrix_row; i++)
    {
        for (int j = 0; j < col_of_A_matrix; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    double ATrow = col_of_A_matrix, ATcol = A_matrix_row;
    // finding AT'
    for (int i = 0; i < A_matrix_row; i++)
    {
        for (int j = 0; j < col_of_A_matrix; j++)
        {
            AT[j][i] = A[i][j];
        }
    }

    // Forming AT*A
    for (int i = 0; i < ATrow; i++)
    {
        for (int j = 0; j <= col_of_A_matrix; j++)
        {
            a[i][j] = 0;
            for (int k = 0; k < ATcol; k++)
            {
                a[i][j] += AT[i][k] * A[k][j];
            }
        }
    }
    n = ATrow;


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d[i][j] = a[i][j];
            if (i == j)
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }

    do
    {
        flag = 0;
        p = 0;
        q = 1;
        max = fabs(d[p][q]);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (max < fabs(d[i][j]))
                    {
                        max = fabs(d[i][j]);
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if (d[p][p] == d[q][q])
        {
            if (d[p][q] > 0)
                theta = pi / 4;
            else
                theta = -pi / 4;
        }
        else
        {
            theta = 0.5 * atan(2 * d[p][q] / (d[p][p] - d[q][q]));
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    s1[i][j] = 1;
                    s1t[i][j] = 1;
                }
                else
                {
                    s1[i][j] = 0;
                    s1t[i][j] = 0;
                }
            }
        }

        s1[p][p] = cos(theta);
        s1t[p][p] = s1[p][p];

        s1[q][q] = cos(theta);
        s1t[q][q] = s1[q][q];

        s1[p][q] = -sin(theta);
        s1[q][p] = sin(theta);

        s1t[p][q] = s1[q][p];
        s1t[q][p] = s1[p][q];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                {
                    temp[i][j] += s1t[i][p] * d[p][j];
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                d[i][j] = 0;
                for (p = 0; p < n; p++)
                    d[i][j] += temp[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                    temp[i][j] += s[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                s[i][j] = temp[i][j];
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    if (fabs(d[i][j]) > zero)
                        flag = 1;
            }
        }
    } while (flag == 1);

    printf("----------Eigen_values----------\n");
    for (i = 0; i < n; i++)
    {

        printf("%8.4lf", d[i][i]);
        eigen_value[i] = d[i][i];
    }

    // sorting Decreasing order of eigen_values
    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - c - 1; d++)
        {
            if (eigen_value[d] < eigen_value[d + 1])
            {
                double swap = eigen_value[d];
                eigen_value[d] = eigen_value[d + 1];
                eigen_value[d + 1] = swap;
            }
        }
    }
    printf("\n\n------Decresing Eigen_value-----\n");
    for (i = 0; i < n; i++)
    {

        printf("%8.4lf", eigen_value[i]);
    }
    printf("\n\n----Corresponding eigenvector----\n\n");

    for (j = 0; j < n; j++)
    {
        printf("(");
        for (i = 0; i < n - 1; i++)
            printf("% 8.4lf,", s[i][j]);
        printf("%8.4lf )^T\n", s[n - 1][j]);
    }

    printf("\n\n");

    for (j = 0; j < n; j++)
    {
        printf("(");
        square_value[j] = 0;
        for (i = 0; i < n; i++)
        {
            printf("% 8.4lf,", s[i][j]);
            eigen_vector[j][i] = s[i][j];
            square_value[j] = square_value[j] + (s[i][j] * s[i][j]);
        }
        printf(")^T\n");
    }

    // Normalizing Eigenvectors
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            eigen_vector[i][j] = (eigen_vector[i][j] / (sqrt(square_value[i])));
        }
    }
    // Forming V matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            V[j][i] = eigen_vector[i][j];
        }
    }

    // forming VT matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            VT[i][j] = V[j][i];
        }
    }
    // printing V matrix
    printf("\n---------[V]---------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf\t", V[i][j]);
        }
        printf("\n");
    }

    // printing VT matrix
    printf("\n---------[VT]---------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf\t", VT[i][j]);
        }
        printf("\n");
    }

    // Forming E matrix;
    int nth_eigen_value = 0;
    for (int i = 0; i < A_matrix_row; i++)
    {
        for (int j = 0; j < col_of_A_matrix; j++)
        {
            if (i == j)
            {
                E[i][j] = sqrt(fabs(eigen_value[nth_eigen_value]));
                nth_eigen_value++;
            }
            else
            {
                E[i][j] = 0;
            }
        }
    }

    printf("\n---------[E]---------\n");
    for (int i = 0; i < A_matrix_row; i++)
    {
        for (int j = 0; j < col_of_A_matrix; j++)
        {
            printf("%lf ", E[i][j]);
        }
        printf("\n");
    }

    //  Forming Symmetric Matrix Multiplying (A*AT) Matrices
    for (int i = 0; i < A_matrix_row; i++)
    {
        for (int j = 0; j < ATcol; j++)
        {
            a[i][j] = 0;
            for (int k = 0; k < col_of_A_matrix; k++)
            {
                a[i][j] += A[i][k] * AT[k][j];
            }
        }
    }

    n = A_matrix_row;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d[i][j] = a[i][j];
            if (i == j)
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }

    do
    {
        flag = 0;
        p = 0;
        q = 1;
        max = fabs(d[p][q]);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (max < fabs(d[i][j]))
                    {
                        max = fabs(d[i][j]);
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if (d[p][p] == d[q][q])
        {
            if (d[p][q] > 0)
                theta = pi / 4;
            else
                theta = -pi / 4;
        }
        else
        {
            theta = 0.5 * atan(2 * d[p][q] / (d[p][p] - d[q][q]));
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    s1[i][j] = 1;
                    s1t[i][j] = 1;
                }
                else
                {
                    s1[i][j] = 0;
                    s1t[i][j] = 0;
                }
            }
        }

        s1[p][p] = cos(theta);
        s1t[p][p] = s1[p][p];

        s1[q][q] = cos(theta);
        s1t[q][q] = s1[q][q];

        s1[p][q] = -sin(theta);
        s1[q][p] = sin(theta);

        s1t[p][q] = s1[q][p];
        s1t[q][p] = s1[p][q];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                    temp[i][j] += s1t[i][p] * d[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                d[i][j] = 0;
                for (p = 0; p < n; p++)
                    d[i][j] += temp[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                    temp[i][j] += s[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                s[i][j] = temp[i][j];
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    if (fabs(d[i][j]) > zero)
                        flag = 1;
            }
        }
    } while (flag == 1);

    printf("----------Eigenvalue---------\n\n");
    for (i = 0; i < n; i++)
    {

        printf("%8.4lf ", d[i][i]);
        eigen_value[i] = d[i][i];
    }

    // sorting Decreasing order of eigen_values
    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - c - 1; d++)
        {
            if (eigen_value[d] < eigen_value[d + 1])
            {
                double swap = eigen_value[d];
                eigen_value[d] = eigen_value[d + 1];
                eigen_value[d + 1] = swap;
            }
        }
    }
    printf("\n---------Decresing Eigenvalue----------\n");
    for (i = 0; i < n; i++)
    {

        printf("%8.4lf ", eigen_value[i]);
    }
    printf("\n-----Corresponding Eigenvector-----\n\n");

    for (j = 0; j < n; j++)
    {
        printf("(");
        square_value[j] = 0;
        for (i = 0; i < n; i++)
        {
            printf("% 8.4lf,", s[i][j]);
            eigen_vector[j][i] = s[i][j];
            square_value[j] = square_value[j] + (s[i][j] * s[i][j]);
        }
        printf(")^T\n");
    }
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            eigen_vector[i][j] = (eigen_vector[i][j] / (sqrt(square_value[i])));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            U[j][i] = eigen_vector[i][j];
        }
    }
    // printing V matrix
    printf("--------[U]--------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf\t", U[i][j]);
        }
        printf("\n");
    }
}

/*
3 3
1 2 3
4 3 2
1 3 5
*/
