#include <stdio.h>
#define f(x, y) ((((y) * (y)) - ((x) * (x))) / (((y) * (y)) + ((x) * (x))))
int main()
{
    int n;
    double x0, y0, h, xn, yn;
    printf("Enter the initial values of x and y:\n");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter calculation point xn:\n");
    scanf("%lf", &xn);
    printf("Enter the number of steps:\n");
    scanf("%d", &n);
    h = (xn - x0) / n;
    printf("x0\t\ty0\t\tk1\t\tk2\t\tk3\t\tk4\t\tk\t\tyn\n");
    for(int i = 0; i < n; i++)
    {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * f(x0 + h, y0 + k3);
        double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x0, y0, k1, k2, k3, k4, k, yn);
        x0 = x0 + h;
        y0 = yn;
    }
    printf("The value of y at x = %lf is %lf.", xn, yn);
    return 0;
}