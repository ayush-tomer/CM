#include <stdio.h>
#include <math.h>
#define f(x) (1 / (1 + (x) * (x)))
int main()
{
    int n, i;
    double a, b, h, x, sum = 0, integral;
    printf("Enter number of sub-intervals: ");
    scanf("%d", &n);
    printf("Enter lower limit: ");
    scanf("%lf", &a);
    printf("Enter upper limit: ");
    scanf("%lf", &b);
    h = fabs(b - a) / n;
    for(i = 1; i < n; i++)
    {
        x = a + i * h;
        sum += f(x);
    }
    integral = (h / 2) * (f(a) + f(b) + 2 * sum);
    printf("The integral is: %lf", integral);
    return 0;
}