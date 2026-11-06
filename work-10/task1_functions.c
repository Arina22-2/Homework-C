#include <stdio.h>
#include <math.h>

/* Работа 10, задание 1.
   fa(x) = x^2 - 3*x + 9 при x <= 3;
   fa(x) = 1/(x^3 + 3) при x > 3.
   fb(x) = x * exp(sin(x^2)).
   Контроль: x = 0 -> fa = 9, fb = 0,
   произведение = 0, разность квадратов = 81, удвоенная сумма = 18.
   x = 3 -> fa = 9; x = 4 -> fa = 1/67. */
double fa(double x);
double fb(double x);
double product(double a, double b);
double difference_of_squares(double a, double b);
double double_sum(double a, double b);

int main(void)
{
    double x, a, b, result;
    double p, d, s;
    int choice;

    printf("Введите x: ");
    if (scanf("%lf", &x) != 1 || !isfinite(x)) {
        printf("Ошибка: введите конечное число.\n");
        return 1;
    }

    a = fa(x);
    b = fb(x);
    if (!isfinite(a) || !isfinite(b)) {
        printf("Ошибка: значения функций не являются конечными.\n");
        return 1;
    }

    do {
        printf("\n1 - fa(x)\n2 - fb(x)\n3 - произведение\n");
        printf("4 - разность квадратов\n5 - удвоенная сумма\n");
        printf("6 - все результаты\n0 - выход\nВаш выбор: ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода пункта меню.\n");
            return 1;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                printf("fa(%.6f) = %.6f\n", x, a);
                break;
            case 2:
                printf("fb(%.6f) = %.6f\n", x, b);
                break;
            case 3:
            case 4:
            case 5:
                if (choice == 3) {
                    result = product(a, b);
                    printf("Произведение: ");
                }
                else if (choice == 4) {
                    result = difference_of_squares(a, b);
                    printf("Разность квадратов: ");
                }
                else {
                    result = double_sum(a, b);
                    printf("Удвоенная сумма: ");
                }
                if (isfinite(result)) {
                    printf("%.6f\n", result);
                }
                else {
                    printf("ошибка: результат слишком велик.\n");
                }
                break;
            case 6:
                p = product(a, b);
                d = difference_of_squares(a, b);
                s = double_sum(a, b);
                printf("fa(%.6f) = %.6f\nfb(%.6f) = %.6f\n", x, a, x, b);
                if (!isfinite(p) || !isfinite(d) || !isfinite(s)) {
                    printf("Ошибка: один из результатов слишком велик.\n");
                    break;
                }
                printf("Произведение = %.6f\n", p);
                printf("Разность квадратов = %.6f\n", d);
                printf("Удвоенная сумма = %.6f\n", s);
                break;
            default:
                printf("Неизвестный пункт меню.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

double fa(double x)
{
    double result;

    if (x <= 3.0) {
        result = x * x - 3.0 * x + 9.0;
    }
    else {
        result = 1.0 / (x * x * x + 3.0);
    }

    return result;
}

double fb(double x)
{
    double result;

    result = x * exp(sin(x * x));
    return result;
}

double product(double a, double b)
{
    double result;

    result = a * b;
    return result;
}

double difference_of_squares(double a, double b)
{
    double result;

    result = a * a - b * b;
    return result;
}

double double_sum(double a, double b)
{
    double result;

    result = 2.0 * (a + b);
    return result;
}
