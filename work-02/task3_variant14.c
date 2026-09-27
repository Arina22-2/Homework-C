#include <stdio.h>

int main(void)
{
    int L = 1333;
    int n = 3;

    printf("Данные:    n = %3d, L = %4d\n"
           "Результат: %-+10.5f\n",
           n, L, (double)n / L);

    return 0;
}
