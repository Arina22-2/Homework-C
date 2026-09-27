#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>

#define D 2.54
#define D_SPANISH 2.32166

void task1(void);
void task2(void);
void task3(void);
void homework(void);

int main(void)
{
    int choice;

#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    puts("Работа 3. Ввод/вывод данных");
    puts("1 - Задание 1");
    puts("2 - Задание 2");
    puts("3 - Задание 3");
    puts("4 - Домашнее задание, вариант 14");

    printf("Выберите задание: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 4:
            homework();
            break;

        default:
            puts("Неверный номер задания.");
    }

#ifdef _WIN32
    system("pause");
#endif

    return 0;
}

void task1(void)
{
    int num1, num2;

    puts("Введите первое целое число:");
    scanf("%d", &num1);

    printf("Введено число %d\n", num1);

    puts("Введите второе целое число:");
    scanf("%d", &num2);

    printf("Введено число %d\n", num2);

    printf("Сумма: %d\n", num2 + num1);
    printf("Разность второго и первого: %d\n", num2 - num1);
    printf("Произведение: %d\n", num2 * num1);

    if (num1 != 0)
    {
        printf("Частное второго числа на первое: %.2f\n",
               (double)num2 / num1);

        printf("Остаток от деления второго числа на первое: %d\n",
               num2 % num1);
    }
    else
    {
        puts("Деление на ноль невозможно.");
    }
}

void task2(void)
{
    int dym;
    float resultEnglish;
    float resultSpanish;

    puts("Введите целое количество дюймов:");
    scanf("%d", &dym);

    resultEnglish = D * dym;
    resultSpanish = D_SPANISH * dym;

    printf("%d английских дюймов - это %.2f см\n",
           dym, resultEnglish);

    printf("%d испанских дюймов (pulgada) - это %.2f см\n",
           dym, resultSpanish);
}

void task3(void)
{
    double a, b;

    printf("Введите a: ");
    scanf("%lf", &a);

    printf("Введите b: ");
    scanf("%lf", &b);

    printf("+---------------+---------------+---------------+\n");
    printf("|     a * b     |      a+b      |      a-b      |\n");
    printf("+---------------+---------------+---------------+\n");
    printf("| %13.2f | %13.2f | %13.2f |\n",
           a * b, a + b, a - b);
    printf("+---------------+---------------+---------------+\n");
}

void homework(void)
{
    float celsius;
    float fahrenheit;
    float kelvin;

    printf("Введите температуру в градусах Цельсия: ");
    scanf("%f", &celsius);

    fahrenheit = celsius * 9.0f / 5.0f + 32.0f;
    kelvin = celsius + 273.15f;

    printf("Температура по Фаренгейту: %.2f F\n", fahrenheit);
    printf("Температура по Кельвину: %.2f K\n", kelvin);
}