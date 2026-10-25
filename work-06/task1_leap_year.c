#include <stdio.h>

/* Работа 6, задание 1: проверка високосного года.
   Контрольные примеры:
   2018 -> не високосный; 1900 -> не високосный;
   2020 -> високосный; 2000 -> високосный. */
int is_leap_year(int year);

int main(void)
{
    int year;
    int result;

    printf("Введите год: ");
    if (scanf("%d", &year) != 1 || year <= 0) {
        printf("Ошибка: год должен быть положительным целым числом.\n");
        return 1;
    }

    result = is_leap_year(year);
    if (result == 1) {
        printf("Год %d високосный.\n", year);
    }
    else {
        printf("Год %d не високосный.\n", year);
    }

    return 0;
}

int is_leap_year(int year)
{
    int result;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        result = 1;
    }
    else {
        result = 0;
    }

    return result;
}
