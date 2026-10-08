#include <stdio.h>

int main(void)
{
    int a = 11, b = 3;
    int x = a / b;
    float y = a / b;
    double z = a / b;
    printf("a = %d, b = %d\n", a, b);
    printf("Неявное преобразование: x = %d, y = %.6f, z = %.6f\n", x, y, z);
    /* Оба операнда int, поэтому сначала 11 / 3 даёт 3.
       Присваивание float/double не восстанавливает дробную часть. */
    printf("(float)a / b = %.6f\n", (float)a / b);
    printf("(double)a / b = %.12f\n", (double)a / b);
    printf("(float)(a / b) = %.6f\n", (float)(a / b));
    printf("(double)(a / b) = %.12f\n", (double)(a / b));
    printf("a / (double)b = %.12f\n", a / (double)b);
    printf("При приведении до деления получается вещественное деление.\n");
    printf("При приведении после (a / b) дробная часть уже потеряна.\n");
    return 0;
}
