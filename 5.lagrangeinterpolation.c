#include <stdio.h>
int main()
{
    int n, i, j;
    double x[100], y[100], xp, yp = 0, p;
    printf("Enter number of data:\n");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    printf("Enter interpolation point:\n");
    scanf("%lf", &xp);
    for (i = 0; i < n; i++)
    {
        p = 1;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }
    printf("Interpolated value at %lf is %lf.", xp, yp);
    return 0;
}