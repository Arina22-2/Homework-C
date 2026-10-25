#include <stdio.h>

/* Работа 7, задание 1. Исходный пример с символами 'a' и 'b'.
   Контрольные примеры: a -> распознан; b -> распознан;
   c -> неизвестный символ. */
int recognize_symbol(char c);

int main(void)
{
    char c;
    int result;

    printf("Введите символ 'a' или 'b': ");
    if (scanf(" %c", &c) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    result = recognize_symbol(c);
    if (result == 1) {
        printf("Введено '%c'.\n", c);
    }
    else {
        printf("Неизвестный символ.\n");
    }

    return 0;
}

int recognize_symbol(char c)
{
    int result;

    switch (c) {
        case 'a':
        case 'b':
            result = 1;
            break;
        default:
            result = 0;
            break;
    }

    return result;
}
