#include <stdio.h>
#include <math.h>

/* Работа 6, задание 2, вариант 13.
   F(x) = -3*x + 9 при x > 3;
   F(x) = x^3 / (x^2 + 8) при x <= 3.

   Контрольные примеры:
   x = 4: F = -3*4 + 9 = -3;
   x = 2: F = 8 / (4 + 8) = 0.666667;
   x = 3: F = 27 / (9 + 8) = 1.588235 (граница);
   x = -2: F = -8 / 12 = -0.666667. */
double calculate_f(double x);

int main(void)
{
    double x;
    double result;

    printf("Введите x: ");
    if (scanf("%lf", &x) != 1 || !isfinite(x)) {
        printf("Ошибка: необходимо ввести конечное число.\n");
        return 1;
    }

    result = calculate_f(x);
    if (!isfinite(result)) {
        printf("Ошибка: результат вычисления не является конечным.\n");
        return 1;
    }

    printf("F(%.6f) = %.6f (%s)\n", x, result,
           x > 3.0 ? "x > 3" : "x <= 3");

    return 0;
}

double calculate_f(double x)
{
    double result;

    if (x > 3.0) {
        result = -3.0 * x + 9.0;
    }
    else {
        result = x * x * x / (x * x + 8.0);
    }

    return result;
}
