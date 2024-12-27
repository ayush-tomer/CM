#include <stdio.h>
#define SIZE 100
int main()
{
    int n;
    double x[SIZE], y[SIZE], xp, yp = 0;
    printf("Enter number of data:\n");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    printf("Enter interpolation point:\n");
    scanf("%lf", &xp);
    for (int i = 0; i < n; i++)
    {
        double p = 1;
        for (int j = 0; j < n; j++)
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