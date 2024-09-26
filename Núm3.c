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
    printf("Salário base: ");
    scanf("%f", &f->salario_base);
    printf("Benefícios: ");
    scanf("%f", &f->beneficios);
    printf("Descontos: ");
    scanf("%f", &f->descontos);

    f->salario_liquido = calcularSalarioLiquido(f->salario_base, f->beneficios, f->descontos);
}

void exibirFuncionarios(struct Funcionario funcionarios[], int total) {
    for (int i = 0; i < total; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salário Líquido: %.2f\n", funcionarios[i].salario_liquido);
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
        printf("1. Cadastrar funcionário\n");
        printf("2. Exibir funcionários\n");
        printf("3. Exibir média salarial\n");
        printf("4. Exibir funcionário com maior salário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalFuncionarios < MAX_FUNCIONARIOS) {
                    cadastrarFuncionario(&funcionarios[totalFuncionarios]);
                    totalFuncionarios++;
                } else {
                    printf("Limite de funcionários atingido.\n");
                }
                break;

            case 2:
                exibirFuncionarios(funcionarios, totalFuncionarios);
                break;

            case 3:
                if (totalFuncionarios > 0) {
                    printf("Média salarial: %.2f\n", calcularMediaSalarial(funcionarios, totalFuncionarios));
                } else {
                    printf("Nenhum funcionário cadastrado.\n");
                }
                break;

            case 4:
                if (totalFuncionarios > 0) {
                    struct Funcionario* maiorSalario = encontrarMaiorSalario(funcionarios, totalFuncionarios);
                    printf("Maior salário: %s com %.2f\n", maiorSalario->nome, maiorSalario->salario_liquido);
                } else {
                    printf("Nenhum funcionário cadastrado.\n");
                }
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}
