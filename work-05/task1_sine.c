#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void)
{
    double gr;
    printf("Введите угол в градусах: ");
    if (scanf("%lf", &gr) != 1 || !isfinite(gr)) {
        fprintf(stderr, "Ошибка: необходимо ввести конечное число.\n");
        return 1;
    }
    double radians = gr * (M_PI / 180.0);
    printf("sin(%.6f градусов) = %.6f\n", gr, sin(radians));
    return 0;
}
