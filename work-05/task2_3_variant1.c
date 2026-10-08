#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <limits.h>

/* Работа 5, задание 2, вариант 1, и задание 3*.
   a = lg(x), b = a^2 + sqrt(c*x), y = exp(2*x) + 9.7^b. */
int main(void)
{
    const double c = 0.4;
    double x;
    printf("Введите x: ");
    if (scanf("%lf", &x) != 1 || !isfinite(x) || x <= 0.0) {
        fprintf(stderr, "Ошибка: x должен быть конечным положительным числом.\n");
        return 1;
    }
    const double a = log10(x);
    const double b = a * a + sqrt(c * x);
    const double y = exp(2.0 * x) + pow(9.7, b);
    if (!isfinite(a) || !isfinite(b) || !isfinite(y)) {
        fprintf(stderr, "Ошибка: результат вычисления не является конечным.\n");
        return 1;
    }
    printf("x = %.6f, c = %.1f\n", x, c);
    printf("a = %.6f, b = %.6f\n", a, b);
    printf("y = %.2f\n", y);
    if (trunc(a) < INT_MIN || trunc(a) > INT_MAX ||
        trunc(b) < INT_MIN || trunc(b) > INT_MAX ||
        trunc(y) < INT_MIN || trunc(y) > INT_MAX) {
        fprintf(stderr, "Ошибка: целые части не помещаются в int.\n");
        return 1;
    }
    const int A = (int)a, B = (int)b, C = (int)y;
    const int condition_a = (A % 2 == 0) != (B % 2 == 0);
    const int condition_b = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);
    printf("A = %d, B = %d, C = %d\n", A, B, C);
    printf("а) условие выполнено (1 - да, 0 - нет): %d\n", condition_a);
    printf("б) условие выполнено (1 - да, 0 - нет): %d\n", condition_b);
    return 0;
}
