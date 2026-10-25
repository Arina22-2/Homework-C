#include <stdio.h>

/* Работа 7, задание 1. Распознавание латинских букв и цифр.
   Результат функции: 1 - цифра, 2 - буква, 0 - другой символ.
   Контрольные примеры: 5 -> цифра; a, Z -> буква;
   + -> неизвестный символ. */
int classify_symbol(char c);

int main(void)
{
    char c;
    int result;

    printf("Введите латинскую букву или цифру: ");
    if (scanf(" %c", &c) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    result = classify_symbol(c);
    switch (result) {
        case 1:
            printf("Символ '%c' - это цифра.\n", c);
            break;
        case 2:
            printf("Символ '%c' - это буква.\n", c);
            break;
        default:
            printf("Неизвестный символ.\n");
            break;
    }

    return 0;
}

int classify_symbol(char c)
{
    int result;

    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            result = 1;
            break;
        default:
            result = ((c >= 'a' && c <= 'z') ||
                      (c >= 'A' && c <= 'Z')) ? 2 : 0;
            break;
    }

    return result;
}
