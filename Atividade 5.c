#include <stdio.h>

void Maior_Menor_elemento(int *v, int n, int *min, int *max) {
    for (int i = 0; i < n; i++) {
        if (v[i] > *max) {
            *max = v[i];
        } else if (v[i] < *min) {
            *min = v[i];
        }
    }
}

int main() {
    int n;

    printf("Qual e o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int min = v[0], max = v[0];

    Maior_Menor_elemento(v, n, &min, &max);

    printf("Maior elemento: %d\nMenor elemento: %d\n", max, min);

    return 0;
}
