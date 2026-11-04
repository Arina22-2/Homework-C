#include <stdio.h>

/* Работа 8, задание 1А. Степени двойки и перевод в K = 1024.
   n = 3 -> 1, 2, 4, 8; результат 8 / 1024 = 0.0078125 K.
   n = 11 -> 2^11 = 2048, результат 2 K.
   m = 1331 -> степени до 1024; значение m в K: 1.3 K. */
int power_two(int n);
double to_k(int value);

int main(void)
{
    int n, m, i;
    int value;

    printf("Введите степень n (от 0 до 30): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 30) {
        printf("Ошибка: степень должна быть от 0 до 30.\n");
        return 1;
    }

    for (i = 0; i <= n; i++) {
        value = power_two(i);
        printf("2^%-2d = %12d\n", i, value);
    }
    printf("Результат: %.7g K\n", to_k(power_two(n)));

    printf("Введите положительное целое m: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Ошибка: m должно быть положительным.\n");
        return 1;
    }

    printf("Степени двойки, не превышающие m:\n");
    for (i = 0; i <= 30; i++) {
        value = power_two(i);
        if (value > m) {
            break;
        }
        printf("2^%-2d = %12d (%10.1f K)\n", i, value, to_k(value));
    }
    printf("Число %d в K: %.1f K\n", m, to_k(m));

    return 0;
}

int power_two(int n)
{
    int i;
    int result = 1;

    for (i = 0; i < n; i++) {
        result *= 2;
    }

    return result;
}

double to_k(int value)
{
    double result;

    result = value / 1024.0;
    return result;
}
