#include <stdio.h>

/* Работа 7, задание 3, вариант 13.
   Стоимость покупки задаётся целым неотрицательным числом копеек.
   Слово "рубль" сокращено до "руб.", слово "копейка" склоняется.
   Контрольные примеры:
   121 -> 1 руб. 21 копейка; 122 -> 1 руб. 22 копейки;
   125 -> 1 руб. 25 копеек; 111 -> 1 руб. 11 копеек;
   100 -> 1 руб. 0 копеек; 0 -> 0 руб. 0 копеек. */
int get_rubles(int price);
int get_kopecks(int price);
int kopeck_form(int kopecks);

int main(void)
{
    int price;
    int rubles, kopecks;
    int form;

    printf("Введите стоимость покупки в копейках: ");
    if (scanf("%d", &price) != 1 || price < 0) {
        printf("Ошибка: введите неотрицательное целое число копеек.\n");
        return 1;
    }

    rubles = get_rubles(price);
    kopecks = get_kopecks(price);
    form = kopeck_form(kopecks);

    printf("Стоимость покупки: %d руб. %d ", rubles, kopecks);
    switch (form) {
        case 1:
            printf("копейка.\n");
            break;
        case 2:
            printf("копейки.\n");
            break;
        default:
            printf("копеек.\n");
            break;
    }

    return 0;
}

int get_rubles(int price)
{
    int result;

    result = price / 100;
    return result;
}

int get_kopecks(int price)
{
    int result;

    result = price % 100;
    return result;
}

int kopeck_form(int kopecks)
{
    int result;

    switch (kopecks) {
        case 11:
        case 12:
        case 13:
        case 14:
            result = 3;
            break;
        default:
            switch (kopecks % 10) {
                case 1:
                    result = 1;
                    break;
                case 2:
                case 3:
                case 4:
                    result = 2;
                    break;
                default:
                    result = 3;
                    break;
            }
            break;
    }

    return result;
}
