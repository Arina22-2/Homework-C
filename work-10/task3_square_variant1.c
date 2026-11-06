#include <stdio.h>

/* Работа 10, задание 3, вариант 1: заполненный квадрат.
   Каждая операция выполнена отдельной функцией.
   Контроль: сторона 3 -> площадь 9 и рисунок 3 на 3.
   Сравнение сторон 3 и 2 -> разность площадей 5.
   Для рисования используются целые стороны в количестве символов. */
double square_area(int side);
void square_definition(void);
void draw_square(int side);
double compare_squares(int first, int second);

int main(void)
{
    int side, second, choice;
    double difference;

    printf("Введите целую положительную сторону квадрата: ");
    if (scanf("%d", &side) != 1 || side <= 0) {
        printf("Ошибка: сторона должна быть положительным целым числом.\n");
        return 1;
    }

    do {
        printf("\n1 - площадь\n2 - определение квадрата\n");
        printf("3 - нарисовать квадрат\n4 - сравнить с другим квадратом\n");
        printf("0 - выход\nВаш выбор: ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода пункта меню.\n");
            return 1;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                printf("Площадь квадрата со стороной %d = %.2f\n", side, square_area(side));
                break;
            case 2:
                square_definition();
                break;
            case 3:
                if (side > 50) {
                    printf("Для рисунка сторона должна быть не больше 50 символов.\n");
                }
                else {
                    draw_square(side);
                }
                break;
            case 4:
                printf("Введите сторону второго квадрата: ");
                if (scanf("%d", &second) != 1 || second <= 0) {
                    printf("Ошибка: сторона должна быть положительным целым числом.\n");
                    return 1;
                }
                difference = compare_squares(side, second);
                printf("Разность площадей = %.2f\n", difference);
                if (difference > 0.0) {
                    printf("Первый квадрат больше по площади.\n");
                }
                else if (difference < 0.0) {
                    printf("Второй квадрат больше по площади.\n");
                }
                else {
                    printf("Площади квадратов равны.\n");
                }
                break;
            default:
                printf("Неизвестный пункт меню.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

double square_area(int side)
{
    double result;

    result = (double)side * side;
    return result;
}

void square_definition(void)
{
    printf("Квадрат - четырёхугольник, у которого все стороны равны,\n");
    printf("а все углы прямые. Площадь квадрата равна квадрату его стороны.\n");
}

void draw_square(int side)
{
    int i, j;

    printf("Рисунок квадрата:\n");
    for (i = 0; i < side; i++) {
        for (j = 0; j < side; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

double compare_squares(int first, int second)
{
    double result;

    result = square_area(first) - square_area(second);
    return result;
}
