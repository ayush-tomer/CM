#include <stdio.h>
#include <math.h>
#define f(x) (1 / (1 + (x) * (x)))
int main()
{
    int n;
    double a, b, h, sum = 0, integral;
    printf("Enter number of sub-intervals:\n");
    scanf("%d", &n);
    printf("Enter lower limit:\n");
    scanf("%lf", &a);
    printf("Enter upper limit:\n");
    scanf("%lf", &b);
    h = fabs(b - a) / n;
    for(int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }
    integral = (h / 2) * (f(a) + f(b) + 2 * sum);
    printf("The integral is: %lf", integral);
    return 0;
}