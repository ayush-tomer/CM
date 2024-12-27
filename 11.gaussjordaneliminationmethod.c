#include <stdio.h>
#define SIZE 100
int main()
{
    int n;
    double a[SIZE][SIZE];
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
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                a[i][j + n] = 1;
            }
            else
            {
                a[i][j + n] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i][i] == 0)
        {
            printf("Mathematical Error.");
            return 1;
        }
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                double ratio = a[j][i] / a[i][i];
                for(int k = 0; k < 2 * n; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 * n; j++)
        {
            a[i][j] /= a[i][i];
        }
    }
    printf("The inverse matrix is:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = n; j < 2 * n; j++)
        {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}