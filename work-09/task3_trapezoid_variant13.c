#include <stdio.h>
#include <math.h>

/* Работа 9, задание 3, вариант 13. Заполненная прямоугольная трапеция.
   h - число строк, b - длина верхнего основания, angle - нижний острый угол.
   При h = 4, b = 3, angle = 45 и символе *:
   ***
   ****
   *****
   ******
   Ширина строки i: b + округление(i / tan(angle)), i от 0 до h-1.
   На символьной сетке высоте h строк соответствует h-1 промежутков. */
double row_width(int row, int b, double angle);

int main(void)
{
    int h, b, i, j, width;
    double angle, bottom;
    char symbol;

    printf("Введите высоту h (2-50 строк), верхнее основание b (1-100): ");
    if (scanf("%d %d", &h, &b) != 2 || h < 2 || h > 50 || b < 1 || b > 100) {
        printf("Ошибка: допустимы h от 2 до 50 и b от 1 до 100.\n");
        return 1;
    }
    printf("Введите нижний острый угол в градусах (0 < угол < 90): ");
    if (scanf("%lf", &angle) != 1 || !isfinite(angle) ||
        angle <= 0.0 || angle >= 90.0) {
        printf("Ошибка: угол должен быть между 0 и 90 градусами.\n");
        return 1;
    }
    printf("Введите символ для заполнения, например *: ");
    if (scanf(" %c", &symbol) != 1) {
        printf("Ошибка ввода символа.\n");
        return 1;
    }

    bottom = row_width(h - 1, b, angle);
    if (!isfinite(bottom) || bottom > 200.0) {
        printf("Ошибка: трапеция слишком широкая (больше 200 символов).\n");
        return 1;
    }

    printf("Трапеция:\n");
    for (i = 0; i < h; i++) {
        width = (int)row_width(i, b, angle);
        for (j = 0; j < width; j++) {
            putchar(symbol);
        }
        putchar('\n');
    }

    return 0;
}

double row_width(int row, int b, double angle)
{
    double radians;
    double result;

    radians = angle * 3.14159265358979323846 / 180.0;
    result = b + floor(row / tan(radians) + 0.5);
    return result;
}
