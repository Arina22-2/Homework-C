#include <stdio.h>

/* Работа 8, задание 3, вариант 13.
   S = 1/3^2 + 1/5^2 + 1/7^2 + ... + 1/(2*n+1)^2.
   n = 1 -> 0.1111111111;
   n = 2 -> 0.1511111111;
   n = 3 -> 0.1715192744. */
double sum_series(int n);

int main(void)
{
    int n;
    double result;

    printf("S = 1/3^2 + 1/5^2 + ... + 1/(2*n+1)^2.\n");
    printf("Введите натуральное n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка: n должно быть положительным целым числом.\n");
        return 1;
    }

    result = sum_series(n);
    printf("Сумма %d слагаемых = %.10f\n", n, result);

    return 0;
}

double sum_series(int n)
{
    int i;
    double denominator;
    double sum = 0.0;

    for (i = 0; i < n; i++) {
        denominator = 2.0 * i + 3.0;
        sum += 1.0 / (denominator * denominator);
    }

    return sum;
}
