#include <stdio.h>
int main()
{
    int n, i, j;
    double x[100], y[100], p[100][100], k, f, f1;
    printf("Enter number of observations:\n");
    scanf("%d", &n);
    printf("Enter corresponding values of x:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Enter corresponding values of y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
        p[i][0] = y[i];
    }
    printf("Enter the value of x for which you want to find y:\n");
    scanf("%lf", &k);
    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n - j; i++)
        {
            p[i][j] = (p[i + 1][j - 1] - p[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    f = y[0];
    for(i = 1; i < n; i++)
    {
        f1 = p[0][i];
        for(j = 0; j < i; j++)
        {
            f1 *= (k - x[j]);
        }
        f += f1;
    }
    printf("The value of y at x = %lf is %lf.", k, f);
    return 0;
}