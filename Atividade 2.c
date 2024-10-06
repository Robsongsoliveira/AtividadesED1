#include <stdio.h>

int main() {
    float v[10];

    for (int i = 0; i < 10; i++) {
        scanf("%f", &v[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("Endereco da posicao %d : %p\n", i, (void*)&v[i]);
    }

    return 0;
}
