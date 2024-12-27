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
    int n, i;
    double a, b, x1, x2, f1, f2, e;
    printf("Enter the lower limit:\n");
    scanf("%lf", &a);
    printf("Enter the upper limit:\n");
    scanf("%lf", &b);
    printf("Enter the number of iterations:\n");
    scanf("%d", &n);
    printf("Enter the tolerance:\n");
    scanf("%lf", &e);
    int fib = fibonacci(n);
    int fib1 = fibonacci(n - 1);
    int fib2 = fibonacci(n - 2);
    for(i = 1; i < n; i++)
    {
        x1 = a + ((double)fib2 / fib) * (b - a);
        x2 = a + ((double)fib1 / fib) * (b - a);
        f1 = f(x1);
        f2 = f(x2);
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
    double min = (a + b) / 2.0;
    printf("The minimum value of the function is approximately at x = %lf\n", min);
    printf("f(x) = %lf", f(min));
    return 0;
}