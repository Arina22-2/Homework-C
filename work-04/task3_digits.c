#include <stdio.h>

int main(void)
{
    int n;
    printf("Введите целое трёхзначное число N: ");
    if (scanf("%d", &n) != 1 || !((n >= 100 && n <= 999) || (n <= -100 && n >= -999))) {
        fprintf(stderr, "Ошибка: требуется трёхзначное целое число.\n");
        return 1;
    }
    const int magnitude = n < 0 ? -n : n;
    const int first = magnitude / 100;
    const int middle = magnitude / 10 % 10;
    const int last = magnitude % 10;
    const int sum = first + middle + last;
    const int reversed = (n < 0 ? -1 : 1) * (last * 100 + middle * 10 + first);
    printf("Последняя цифра %d, первая - %d, сумма цифр %d, число наоборот %d\n",
           last, first, sum, reversed);
    return 0;
}
