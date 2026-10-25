#include <stdio.h>
#include <math.h>

/* Работа 6, задание 3, вариант 13.
   Из трёх вещественных чисел выбрать числа из интервала (-1, 1).
   Контрольные примеры:
   -0.5, 0, 2 -> -0.5, 0;
   -1, 1, 2 -> подходящих чисел нет;
   -0.9, 0.2, 0.8 -> все три числа.
   Концы интервала -1 и 1 не входят. */
int is_in_interval(double x);

int main(void)
{
    double a, b, c;
    int first, second, third;

    printf("Введите три вещественных числа: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3 ||
        !isfinite(a) || !isfinite(b) || !isfinite(c)) {
        printf("Ошибка: необходимо ввести три конечных числа.\n");
        return 1;
    }

    first = is_in_interval(a);
    second = is_in_interval(b);
    third = is_in_interval(c);

    printf("Числа из интервала (-1, 1):\n");
    if (first == 1) {
        printf("%.6f\n", a);
    }
    if (second == 1) {
        printf("%.6f\n", b);
    }
    if (third == 1) {
        printf("%.6f\n", c);
    }
    if (first == 0 && second == 0 && third == 0) {
        printf("Подходящих чисел нет.\n");
    }

    return 0;
}

int is_in_interval(double x)
{
    int result;

    if (x > -1.0 && x < 1.0) {
        result = 1;
    }
    else {
        result = 0;
    }

    return result;
}
