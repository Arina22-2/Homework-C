#include <stdio.h>

/* Работа 9, задание 2, вариант 1 (в задании всего 12 вариантов).
   Подсчитать количество цифр 3. Повторение программы через do-while.
   30333 -> 4; -313 -> 2; 0 -> 0; 123456789 -> 1.
   Знак минус не считается цифрой. */
int count_threes(long long number);

int main(void)
{
    long long number;
    int result;
    char again;

    do {
        printf("Введите целое число: ");
        if (scanf("%lld", &number) != 1) {
            printf("Ошибка: необходимо ввести целое число.\n");
            return 1;
        }

        result = count_threes(number);
        printf("Количество цифр 3: %d\n", result);
        printf("Продолжить? (y - да, n - нет): ");
        if (scanf(" %c", &again) != 1 ||
            (again != 'y' && again != 'Y' && again != 'n' && again != 'N')) {
            printf("Ошибка: необходимо ввести y или n.\n");
            return 1;
        }
    } while (again == 'y' || again == 'Y');

    return 0;
}

int count_threes(long long number)
{
    int digit;
    int count = 0;

    do {
        digit = (int)(number % 10);
        if (digit == 3 || digit == -3) {
            count++;
        }
        number /= 10;
    } while (number != 0);

    return count;
}
