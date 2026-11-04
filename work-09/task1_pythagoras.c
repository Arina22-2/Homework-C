#include <stdio.h>

/* Работа 9, задание 1. Полная таблица Пифагора 10 на 10
   и её левый нижний треугольник.
   Контроль: 3*4 = 12, 10*10 = 100.
   В i-й строке треугольника выводится i произведений. */
int product(int a, int b);

int main(void)
{
    int i, j;
    int size = 10;

    printf("Таблица Пифагора:\n");
    printf("    ");
    for (j = 1; j <= size; j++) {
        printf("%4d", j);
    }
    putchar('\n');
    for (i = 1; i <= size; i++) {
        printf("%4d", i);
        for (j = 1; j <= size; j++) {
            printf("%4d", product(i, j));
        }
        putchar('\n');
    }

    printf("\nЛевый нижний треугольник:\n");
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= i; j++) {
            printf("%4d", product(i, j));
        }
        putchar('\n');
    }

    return 0;
}

int product(int a, int b)
{
    int result;

    result = a * b;
    return result;
}
