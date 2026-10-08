#include <stdio.h>
#include <math.h>

int main(void)
{
    char c = '!';
    int i = 2;
    float f = 3.14f;
    double d = 5e-12;
    printf("Начальные значения: c = %c, i = %d, f = %.2f, d = %.12e\n", c, i, f, d);
    printf("Введите символ, целое число, float и double через пробел: ");
    if (scanf(" %c %d %f %lf", &c, &i, &f, &d) != 4 ||
        !isfinite(f) || !isfinite(d)) {
        fprintf(stderr, "Ошибка ввода.\n");
        return 1;
    }
    printf("Введено: c = %c, i = %d, f = %.6f, d = %.12g\n", c, i, f, d);
    /* 1а: modf отделяет целую часть к нулю и дробную часть со знаком. */
    double integer_part;
    const double fraction = modf(d, &integer_part);
    printf("1а) Число %.12g: целая часть = %.0f, дробная часть = %.12g\n",
           d, integer_part, fraction);
    /* 1б: код одного байта, а не код многобайтового символа Unicode. */
    const unsigned int code = (unsigned char)c;
    printf("1б) Код символа: десятичный = %u, шестнадцатеричный = 0x%02X\n", code, code);
    /* 1в: вещественное деление вместо целочисленного 1 / i. */
    if (i == 0) {
        printf("1в) 1/i не определено: i = 0.\n");
    } else {
        printf("1в) 1/i = %.12g\n", 1.0 / i);
    }
    return 0;
}
