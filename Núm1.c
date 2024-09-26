#include <stdio.h>
#include <string.h>

struct datanasc {
    int dia;
    int mes;
    int ano;
};

struct cliente {
    char nome[100];
    struct datanasc data;
    int idade;
    char sexo;
};

void lerData(struct datanasc* data) {
    printf("Digite o dia em que nasceu: ");
    scanf("%d", &data->dia);
    printf("Digite o mês em que nasceu: ");
    scanf("%d", &data->mes);
    printf("Digite o ano em que nasceu: ");
    scanf("%d", &data->ano);
}

void calcularIdade(struct cliente* c) {
    int ano_atual = 2024;
    c->idade = ano_atual - c->data.ano;
    if (c->data.mes > 9 || (c->data.mes == 9 && c->data.dia > 26)) {
        c->idade--;
    }
}

void lerDados(struct cliente* c) {
    printf("Digite o seu nome: ");
    scanf("%s", c->nome);
    printf("Data de nascimento:\n");
    lerData(&c->data);
    printf("Sexo (M ou F): ");
    scanf(" %c", &c->sexo);
    calcularIdade(c);
}

void imprimirCliente(const struct cliente* c) {
    printf("Nome: %s\n", c->nome);
    printf("Idade: %d\n", c->idade);
    printf("Sexo: %c\n", c->sexo);
}

struct cliente clientes[100];
int contadorClientes = 0;


void cadastrarCliente() {
    if (contadorClientes < 100) {
        lerDados(&clientes[contadorClientes]);
        contadorClientes++;
    } else {
        printf("Limite de clientes atingido.\n");
    }
}

void listarClientes() {
    if (contadorClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        for (int i = 0; i < contadorClientes; i++) {
            printf("\nCliente %d:\n", i + 1);
            imprimirCliente(&clientes[i]);
        }
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
