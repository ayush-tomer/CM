#include <stdio.h>
#include <math.h>
#define f(x) ((x) * (x) - 4 * (x) + 4)
int fibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n, fib, fib1, fib2;
    double a, b, e, min;
    printf("Enter the lower limit:\n");
    scanf("%lf", &a);
    printf("Enter the upper limit:\n");
    scanf("%lf", &b);
    printf("Enter the number of iterations:\n");
    scanf("%d", &n);
    printf("Enter the tolerance:\n");
    scanf("%lf", &e);
    fib = fibonacci(n);
    fib1 = fibonacci(n - 1);
    fib2 = fibonacci(n - 2);
    for(int i = 1; i < n; i++)
    {
        double x1 = a + ((double)fib2 / fib) * (b - a);
        double x2 = a + ((double)fib1 / fib) * (b - a);
        double f1 = f(x1);
        double f2 = f(x2);
        if(f1 > f2)
        {
            a = x1;
            fib = fib1;
            fib1 = fib2;
            fib2 = fibonacci(n - i - 2);
        }
        else
        {
            b = x2;
            fib = fib1;
            fib1 = fib2;
            fib2 = fibonacci(n - i - 2);
        }
        if(fabs(b - a) < e)
        {
            break;
        }
    }
    min = (a + b) / 2.0;
    printf("The minimum value of the function is approximately at x = %lf\n", min);
    printf("f(x) = %lf", f(min));
    return 0;
}