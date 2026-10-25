#include <stdio.h>
#include <math.h>

/* Работа 7, задание 2. Калькулятор на основе switch.
   Дополнительная операция: ^ - возведение в степень.
   Контрольные примеры:
   2+3 -> 5; 8-3 -> 5; 4*2.5 -> 10; 7/2 -> 3.5;
   2^3 -> 8; 5/0 -> ошибка; 2?3 -> неизвестная операция.
   Ввод без пробелов, например 2+3, по формату %f%c%f. */
float calculate(float x, char operation, float y);

int main(void)
{
    float x, y;
    char operation;
    float result;

    printf("Введите выражение без пробелов (+, -, *, /, ^), например 2+3: ");
    if (scanf("%f%c%f", &x, &operation, &y) != 3 ||
        !isfinite(x) || !isfinite(y)) {
        printf("Ошибка ввода выражения.\n");
        return 1;
    }

    if (operation != '+' && operation != '-' && operation != '*' &&
        operation != '/' && operation != '^') {
        printf("Ошибка: неизвестная операция.\n");
        return 1;
    }
    if (operation == '/' && y == 0.0f) {
        printf("Ошибка: деление на ноль.\n");
        return 1;
    }

    result = calculate(x, operation, y);
    if (!isfinite(result)) {
        printf("Ошибка: результат не определён или слишком велик.\n");
        return 1;
    }

    printf("%.6g %c %.6g = %.6g\n", x, operation, y, result);

    return 0;
}

float calculate(float x, char operation, float y)
{
    float result;

    switch (operation) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '^':
            result = (float)pow(x, y);
            break;
        default:
            result = 0.0f;
            break;
    }

    return result;
}
