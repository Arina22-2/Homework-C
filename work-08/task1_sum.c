#include <stdio.h>

/* Работа 8, задание 1. Сумма целых чисел от m до n включительно.
   1 5 -> 15, 5 повторений;
   5 1 -> 15, 5 повторений;
   -2 2 -> 0, 5 повторений;
   3 3 -> 3, 1 повторение. */
long long sum_interval(int m, int n);
long long iteration_count(int m, int n);

int main(void)
{
    int m, n;
    long long result, count;

    printf("Введите границы m и n: ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Ошибка: необходимо ввести два целых числа.\n");
        return 1;
    }

    result = sum_interval(m, n);
    count = iteration_count(m, n);
    printf("Сумма от %d до %d = %lld\n", m, n, result);
    printf("Цикл выполнен %lld раз.\n", count);

    return 0;
}

long long sum_interval(int m, int n)
{
    long long i;
    long long sum = 0;
    int step;

    step = m <= n ? 1 : -1;
    for (i = m; step > 0 ? i <= n : i >= n; i += step) {
        sum += i;
    }

    return sum;
}

long long iteration_count(int m, int n)
{
    long long result;

    result = m <= n ? (long long)n - m + 1 : (long long)m - n + 1;
    return result;
}
