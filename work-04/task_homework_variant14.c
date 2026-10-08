#include <stdio.h>

/* Работа 4, ДЗ, вариант 14: Калибровка станка.
   Успех, если каждый из параметров A, B, C кратен трём. */
int main(void)
{
    int A, B, C;
    printf("Введите целые параметры A, B, C: ");
    if (scanf("%d %d %d", &A, &B, &C) != 3) {
        fprintf(stderr, "Ошибка: необходимо ввести три целых числа.\n");
        return 1;
    }
    const int condition = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);
    printf("A = %d, B = %d, C = %d\n", A, B, C);
    printf("Калибровка успешна (1 - да, 0 - нет): %d\n", condition);
    return 0;
}
