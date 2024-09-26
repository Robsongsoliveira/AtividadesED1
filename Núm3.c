#include <stdio.h>

#define MAX_FUNCIONARIOS 10

struct Funcionario {
    char nome[100];
    char cargo[50];
    float salario_base;
    float beneficios;
    float descontos;
    float salario_liquido;
};

float calcularSalarioLiquido(float salario_base, float beneficios, float descontos) {
    return salario_base + beneficios - descontos;
}


void cadastrarFuncionario(struct Funcionario* f) {
    printf("Nome: ");
    scanf("%s", f->nome);
    printf("Cargo: ");
    scanf("%s", f->cargo);
    printf("Sal�rio base: ");
    scanf("%f", &f->salario_base);
    printf("Benef�cios: ");
    scanf("%f", &f->beneficios);
    printf("Descontos: ");
    scanf("%f", &f->descontos);

    f->salario_liquido = calcularSalarioLiquido(f->salario_base, f->beneficios, f->descontos);
}

void exibirFuncionarios(struct Funcionario funcionarios[], int total) {
    for (int i = 0; i < total; i++) {
        printf("\nFuncion�rio %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Sal�rio L�quido: %.2f\n", funcionarios[i].salario_liquido);
    }
}

float calcularMediaSalarial(struct Funcionario funcionarios[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += funcionarios[i].salario_liquido;
    }
    return soma / total;
}

struct Funcionario* encontrarMaiorSalario(struct Funcionario funcionarios[], int total) {
    struct Funcionario* maior = &funcionarios[0];
    for (int i = 1; i < total; i++) {
        if (funcionarios[i].salario_liquido > maior->salario_liquido) {
            maior = &funcionarios[i];
        }
    }
    return maior;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int totalFuncionarios = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar funcion�rio\n");
        printf("2. Exibir funcion�rios\n");
        printf("3. Exibir m�dia salarial\n");
        printf("4. Exibir funcion�rio com maior sal�rio\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalFuncionarios < MAX_FUNCIONARIOS) {
                    cadastrarFuncionario(&funcionarios[totalFuncionarios]);
                    totalFuncionarios++;
                } else {
                    printf("Limite de funcion�rios atingido.\n");
                }
                break;

            case 2:
                exibirFuncionarios(funcionarios, totalFuncionarios);
                break;

            case 3:
                if (totalFuncionarios > 0) {
                    printf("M�dia salarial: %.2f\n", calcularMediaSalarial(funcionarios, totalFuncionarios));
                } else {
                    printf("Nenhum funcion�rio cadastrado.\n");
                }
                break;

            case 4:
                if (totalFuncionarios > 0) {
                    struct Funcionario* maiorSalario = encontrarMaiorSalario(funcionarios, totalFuncionarios);
                    printf("Maior sal�rio: %s com %.2f\n", maiorSalario->nome, maiorSalario->salario_liquido);
                } else {
                    printf("Nenhum funcion�rio cadastrado.\n");
                }
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Op��o inv�lida.\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}
