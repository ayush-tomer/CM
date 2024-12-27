#include <stdio.h>
#include <math.h>
#define f(x) (2 * pow((x), 3) - 2 * (x) - 5)
int main()
{
    int step = 1, maxsteps;
    double x0, x1, x2, f0, f1, f2, e;
    up:
    printf("Enter 2 initial guesses: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter tolerable error: ");
    scanf("%lf", &e);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxsteps);
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
        x2 = x0 - (x1 - x0) * f0 / (f1 - f0);
        f2 = f(x2);
        printf("%d\t\t%lf\t\t%lf\t\t%lf\t\t%lf\n", step, x0, x1, x2, f2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step++;
    }
    while(fabs(f2) > e && step <= maxsteps);
    printf("Root is: %lf\n", x2);
    return 0;
}