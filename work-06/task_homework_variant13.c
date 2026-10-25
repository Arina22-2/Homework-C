#include <stdio.h>
#include <math.h>

/* Работа 6, ДЗ на сложные условия, вариант 13.
   Область состоит из двух прямоугольников:
   -6 <= x <= -3, -3 <= y <= 7;
   -3 <= x <= -1,  2 <= y <= 7.
   Границы входят в область.

   Контрольные примеры:
   (-4, 0), (-2, 4) -> принадлежат;
   (-2, 0), (0, 0) -> не принадлежат;
   (-6, -3), (-1, 2), (-1, 7) -> принадлежат (границы). */
int is_in_region(double x, double y);

int main(void)
{
    double x, y;
    int result;

    printf("Введите координаты точки x, y: ");
    if (scanf("%lf %lf", &x, &y) != 2 ||
        !isfinite(x) || !isfinite(y)) {
        printf("Ошибка: необходимо ввести две конечные координаты.\n");
        return 1;
    }

    result = is_in_region(x, y);
    if (result == 1) {
        printf("Точка (%.6f, %.6f) принадлежит области.\n", x, y);
    }
    else {
        printf("Точка (%.6f, %.6f) не принадлежит области.\n", x, y);
    }

    return 0;
}

int is_in_region(double x, double y)
{
    int result;

    if ((x >= -6.0 && x <= -3.0 && y >= -3.0 && y <= 7.0) ||
        (x >= -3.0 && x <= -1.0 && y >= 2.0 && y <= 7.0)) {
        result = 1;
    }
    else {
        result = 0;
    }

    return result;
}
