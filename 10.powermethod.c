#include <stdio.h>
#include <math.h>
#define SIZE 100
int main()
{
    int n;
    double a[SIZE][SIZE], x[SIZE], y[SIZE], zmax, emax;
    printf("Enter the order of the matrix:\n");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("Enter the initial guess vector:\n");
    for(int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }
    do
    {
        double e[SIZE];
        for(int i = 0; i < n; i++)
        {
            y[i] = 0;
            for(int j = 0; j < n; j++)
            {
                y[i] = y[i] + a[i][j] * x[j];
            }
        }
        zmax = fabs(y[0]);
        for(int i = 1; i < n; i++)
        {
            if(fabs(y[i]) > zmax)
            {
                zmax = fabs(y[i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            y[i] = y[i] / zmax;
        }
        for(int i = 0; i < n; i++)
        {
            e[i] = 0;
            e[i] = fabs((fabs(y[i])) - (fabs(x[i])));
        }
        emax = fabs(e[0]);
        for(int i = 1; i < n; i++)
        {
            if(fabs(e[i]) > emax)
            {
                emax = fabs(e[i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            x[i] = y[i];
        }
    }
    while(emax > 0.0001);
    printf("The required eigen value is %lf\n", zmax);
    printf("The required eigen vector is:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%lf\n", y[i]);
    }
    return 0;
}