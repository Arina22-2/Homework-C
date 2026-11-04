#include <stdio.h>

/* Работа 9, задание 1, вариант 13.
   Контрольный пример (как на сайте):
   20 21 22 23 24
   19 20 21 22
   18 19 20
   17 18
   16 */
int pattern_number(int row, int column);

int main(void)
{
    int i, j;
    int rows = 5;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows - i; j++) {
            printf("%4d", pattern_number(i, j));
        }
        putchar('\n');
    }

    return 0;
}

int pattern_number(int row, int column)
{
    int result;

    result = 20 - row + column;
    return result;
}
