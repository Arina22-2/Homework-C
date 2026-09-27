#include <stdio.h>

int main(void)
{
    double X, L;

    printf("Введите X (мс): ");
    scanf("%lf", &X);

    printf("Введите L (см): ");
    scanf("%lf", &L);

    printf("Минимальная скорость = %.2f м/с\n", 10.0 * L / X);

    return 0;
}
