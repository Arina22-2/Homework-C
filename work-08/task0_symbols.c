#include <stdio.h>

/* Работа 8, задание 0 и дополнительные пункты.
   n = 5, символы * и #:
   *****
   +*****+
   **###
   *!*!*!*!*!
   При нечётном n во второй половине на один символ больше. */
char select_symbol(int position, int count, char first, char second);

int main(void)
{
    int n, i;
    char first, second;

    printf("Введите количество символов: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Ошибка: количество должно быть неотрицательным.\n");
        return 1;
    }
    printf("Введите два символа, например * #: ");
    if (scanf(" %c %c", &first, &second) != 2) {
        printf("Ошибка ввода символов.\n");
        return 1;
    }

    printf("Обычная строка:\n");
    for (i = 0; i < n; i++) {
        putchar(first);
    }
    putchar('\n');

    printf("Строка с плюсами:\n");
    putchar('+');
    for (i = 0; i < n; i++) {
        putchar(first);
    }
    printf("+\n");

    printf("Два вида символов:\n");
    for (i = 0; i < n; i++) {
        putchar(select_symbol(i, n, first, second));
    }
    putchar('\n');

    printf("С восклицательными знаками:\n");
    for (i = 0; i < n; i++) {
        printf("%c!", first);
    }
    putchar('\n');

    return 0;
}

char select_symbol(int position, int count, char first, char second)
{
    char result;

    result = position < count / 2 ? first : second;
    return result;
}
