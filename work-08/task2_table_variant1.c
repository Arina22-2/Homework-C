#include <stdio.h>
#include <math.h>

/* Работа 8, задание 2, вариант 1 (в таблице всего 12 вариантов).
   f(x) = x^2 + sin(5*x), 0.1 <= x <= 2.1. Углы в радианах.
   Контрольный пример при шаге 1:
   x = 0.1 -> 0.489426;
   x = 1.1 -> 0.504460;
   x = 2.1 -> 3.530304. */
double calculate_f(double x);

int main(void)
{
    double start = 0.1;
    double end = 2.1;
    double step, x, intervals;
    int i, count;

    printf("f(x) = x^2 + sin(5*x), интервал [0.1; 2.1].\n");
    printf("Введите положительный шаг табуляции: ");
    if (scanf("%lf", &step) != 1 || !isfinite(step) || step <= 0.0) {
        printf("Ошибка: шаг должен быть конечным положительным числом.\n");
        return 1;
    }

    intervals = (end - start) / step;
    if (!isfinite(intervals) || intervals > 9999.0) {
        printf("Ошибка: слишком маленький шаг (допускается до 10000 строк).\n");
        return 1;
    }
    count = (int)floor(intervals + 1e-9) + 1;

    printf("---------------------------\n");
    printf("|     x     |     f(x)     |\n");
    printf("---------------------------\n");
    for (i = 0; i < count; i++) {
        x = start + i * step;
        printf("| %9.6f | %11.6f |\n", x, calculate_f(x));
    }
    printf("---------------------------\n");

    return 0;
}

double calculate_f(double x)
{
    double result;

    result = x * x + sin(5.0 * x);
    return result;
}
