#include <stdio.h>
#include <math.h>
#define f(x) (3 * (x) - cos(x) - 1)
#define g(x) (3 + sin(x))
int main()
{
    int step = 1, maxsteps;
    double x0, x1, f0, f1, g0, e;
    printf("Enter initial guess:\n");
    scanf("%lf", &x0);
    printf("Enter tolerable error:\n");
    scanf("%lf", &e);
    printf("Enter maximum number of iterations:\n");
    scanf("%d", &maxsteps);
    printf("Step\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do
    {
        f0 = f(x0);
        g0 = g(x0);
        if(g0 == 0)
        {
            printf("Mathematical Error.");
            return 1;
        }
        x1 = x0 - f0 / g0;
        f1 = f(x1);
        printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", step, x0, f0, x1, f1);
        x0 = x1;
        step++;
    }
    while(fabs(f1) > e && step <= maxsteps);
    printf("Root is: %lf", x1);
    return 0;
}