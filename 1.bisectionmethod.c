#include <stdio.h>
#include <math.h>
#define f(x) (cos(x) - (x) * exp(x))
int main()
{
    int step = 1;
    double x0, x1, x2, f0, f1, f2, e;
    up:
    printf("Enter 2 initial guesses:\n");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%lf", &e);
    f0 = f(x0);
    f1 = f(x1);
    if(f0 * f1 > 0)
    {
        printf("Incorrect initial guesses.\n");
        goto up;
    }
    printf("Step\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", step, x0, x1, x2, f2);
        if(f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step++;
    }
    while(fabs(f2) > e);
    printf("Root is: %lf", x2);
    return 0;
}