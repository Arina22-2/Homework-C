#include <stdio.h>
#include <math.h>

/* Работа 10, задание 2, вариант 1.
   exp(-x) = 1 - x + x^2/2! - x^3/3! + ...
   N - число первых слагаемых, включая единицу.
   Следующий член: term *= -x/k.
   Контроль: x = 0 -> 1;
   x = 1, N = 5 -> 0.375; exp(-1) = 0.3678794412;
   x = -1 -> exp(1) = 2.7182818285. */
double exp_n(double x, int n);
double exp_eps(double x, double eps);

int main(void)
{
    double x, eps;
    double standard, fixed, accurate;
    int n;

    printf("exp(-x) = 1 - x + x^2/2! - ...\n");
    printf("Введите x, число слагаемых N и точность eps: ");
    if (scanf("%lf %d %lf", &x, &n, &eps) != 3 ||
        !isfinite(x) || !isfinite(eps) || n < 1 || n > 1000 ||
        eps <= 0.0 || eps >= 1.0) {
        printf("Ошибка: x конечное, N от 1 до 1000, 0 < eps < 1.\n");
        return 1;
    }

    standard = exp(-x);
    fixed = exp_n(x, n);
    accurate = exp_eps(x, eps);
    if (!isfinite(standard) || !isfinite(fixed) || !isfinite(accurate)) {
        printf("Ошибка: при вычислении ряда произошло переполнение.\n");
        return 1;
    }

    printf("%-16s %18s %18s\n", "Метод", "Значение", "Отклонение");
    printf("exp(-x)          %18.10f %18.10g\n", standard, 0.0);
    printf("exp_n(x, N)      %18.10f %18.10g\n", fixed, fabs(fixed - standard));
    printf("exp_eps(x, eps)  %18.10f %18.10g\n", accurate, fabs(accurate - standard));
    if (fabs(accurate - standard) > eps) {
        printf("Заданная точность не достигнута: влияет округление чисел.\n");
    }

    return 0;
}

double exp_n(double x, int n)
{
    int k;
    double term = 1.0;
    double sum = term;

    for (k = 1; k < n; k++) {
        term *= -x / k;
        sum += term;
        if (!isfinite(term) || !isfinite(sum)) {
            return NAN;
        }
    }

    return sum;
}

double exp_eps(double x, double eps)
{
    int k = 1;
    double term = 1.0;
    double sum = term;

    while (fabs(term) > eps) {
        term *= -x / k;
        sum += term;
        if (!isfinite(term) || !isfinite(sum) || k >= 10000) {
            return NAN;
        }
        k++;
    }

    return sum;
}
