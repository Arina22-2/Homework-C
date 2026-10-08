#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/* ДЗ_5.pdf, вариант 14. Все углы в радианах.
   g = y^(x+1)/(cbrt(|y-2|)+3)
       + (x+y/2)/(2|x+y|) * (x+1)^(-1/sin(z)). */
int main(void)
{
    double x, y, z;
    printf("Введите x, y, z через пробел: ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3 ||
        !isfinite(x) || !isfinite(y) || !isfinite(z)) {
        fprintf(stderr, "Ошибка ввода.\n");
        return 1;
    }
    /* Положительные основания обеспечивают вещественную степень. */
    if (y <= 0.0 || x <= -1.0 || x + y == 0.0 || sin(z) == 0.0) {
        fprintf(stderr, "Значения вне поддерживаемой области определения.\n");
        return 1;
    }
    const double first = pow(y, x + 1.0) / (cbrt(fabs(y - 2.0)) + 3.0);
    const double second = (x + y / 2.0) / (2.0 * fabs(x + y))
                        * pow(x + 1.0, -1.0 / sin(z));
    const double g = first + second;
    if (!isfinite(g)) {
        fprintf(stderr, "Результат не является конечным числом.\n");
        return 1;
    }
    printf("x = %.6f, y = %.6f, z = %.6f\n", x, y, z);
    printf("g = %.6f\n", g);
    return 0;
}
