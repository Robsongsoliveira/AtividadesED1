#include <stdio.h>

void parte_int_frac(double *n, int *p_int, double *p_frac) {
    *p_int = (int)*n;
    *p_frac = *n - *p_int;
}

int main() {
    double n;
    int p_int;
    double p_frac;
    scanf("%lf", &n);
    parte_int_frac(&n, &p_int, &p_frac);
    printf("Parte inteira = %d\nParte fracionada = %lf\n", p_int, p_frac);

    return 0;
}
