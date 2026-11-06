#include <stdio.h>
#include <math.h>

/* Работа 10, общий пример задания 2. Три способа вычисления sin(x).
   N - число первых слагаемых: x - x^3/3! + x^5/5! - ...
   Следующий член: term *= -x*x / ((2*k)*(2*k+1)).
   Углы вводятся в радианах.
   Контроль: x = 0 -> 0; x = 1, N = 5 -> 0.8414710097;
   sin(1) = 0.8414709848. */
double reduce_angle(double x);
double sin_n(double x, int n);
double sin_eps(double x, double eps);

int main(void)
{
    double x, eps;
    double standard, fixed, accurate;
    int n;

    printf("Введите x в радианах, число слагаемых N и точность eps: ");
    if (scanf("%lf %d %lf", &x, &n, &eps) != 3 ||
        !isfinite(x) || !isfinite(eps) || n < 1 || n > 1000 ||
        eps <= 0.0 || eps >= 1.0) {
        printf("Ошибка: x конечное, N от 1 до 1000, 0 < eps < 1.\n");
        return 1;
    }

    standard = sin(x);
    fixed = sin_n(x, n);
    accurate = sin_eps(x, eps);
    printf("%-16s %18s %18s\n", "Метод", "Значение", "Отклонение");
    printf("sin(x)           %18.10f %18.10g\n", standard, 0.0);
    printf("sin_n(x, N)      %18.10f %18.10g\n", fixed, fabs(fixed - standard));
    printf("sin_eps(x, eps)  %18.10f %18.10g\n", accurate, fabs(accurate - standard));
    if (fabs(accurate - standard) > eps) {
        printf("Заданная точность не достигнута: влияет округление чисел.\n");
    }

    return 0;
}

double reduce_angle(double x)
{
    double pi = 3.14159265358979323846;
    double result;

    result = fmod(x, 2.0 * pi);
    if (result > pi) {
        result -= 2.0 * pi;
    }
    if (result < -pi) {
        result += 2.0 * pi;
    }

    return result;
}

double sin_n(double x, int n)
{
    int k;
    double term, sum;

    x = reduce_angle(x);
    term = x;
    sum = term;
    for (k = 1; k < n; k++) {
        term *= -x * x / ((2.0 * k) * (2.0 * k + 1.0));
        sum += term;
    }

    return sum;
}

double sin_eps(double x, double eps)
{
    int k = 1;
    double term, sum;

    x = reduce_angle(x);
    term = x;
    sum = term;
    while (fabs(term) > eps) {
        term *= -x * x / ((2.0 * k) * (2.0 * k + 1.0));
        sum += term;
        k++;
    }

    return sum;
}
