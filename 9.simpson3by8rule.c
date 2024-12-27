#include <stdio.h>
#include <math.h>
#define f(x) (1 / (x))
int main()
{
    int n;
    double a, b, h, sum = 0, integral;
    printf("Enter multiple of 3 as number of sub-intervals:\n");
    scanf("%d", &n);
    printf("Enter lower limit:\n");
    scanf("%lf", &a);
    printf("Enter upper limit:\n");
    scanf("%lf", &b);
    h = fabs(b - a) / n;
    for(int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if(i % 3 == 0)
        {
            sum += 2 * f(x);
        }
        else
        {
            sum += 3 * f(x);
        }
    }
    integral = (3 * h / 8) * (f(a) + f(b) + sum);
    printf("The integral is: %lf", integral);
    return 0;
}