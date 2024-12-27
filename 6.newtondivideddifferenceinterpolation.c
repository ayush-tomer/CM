#include <stdio.h>
#define SIZE 100
int main()
{
    int n;
    double x[SIZE], y[SIZE], p[SIZE][SIZE], k, f;
    printf("Enter number of observations:\n");
    scanf("%d", &n);
    printf("Enter corresponding values of x:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Enter corresponding values of y:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
        p[i][0] = y[i];
    }
    printf("Enter the value of x for which you want to find y:\n");
    scanf("%lf", &k);
    for(int j = 1; j < n; j++)
    {
        for(int i = 0; i < n - j; i++)
        {
            p[i][j] = (p[i + 1][j - 1] - p[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    f = y[0];
    for(int i = 1; i < n; i++)
    {
        double f1 = p[0][i];
        for(int j = 0; j < i; j++)
        {
            f1 *= (k - x[j]);
        }
        f += f1;
    }
    printf("The value of y at x = %lf is %lf.", k, f);
    return 0;
}