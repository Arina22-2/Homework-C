#include <stdio.h>

/* Второй этап задания 2: переменные x, y, z удалены. */
int main(void)
{
    int a = 11, b = 3;
    printf("(float)a / b = %.6f\n", (float)a / b);
    printf("(double)a / b = %.12f\n", (double)a / b);
    printf("(float)(a / b) = %.6f\n", (float)(a / b));
    printf("(double)(a / b) = %.12f\n", (double)(a / b));
    printf("a / (double)b = %.12f\n", a / (double)b);
    return 0;
}
