#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

typedef struct {
    char marca[10];
    char modelo[20];
    int ano;
    char placa[9];
}
Carro;

Carro lista[10];
int i = 0;

void ordenar() {
    int count, j, key;
    Carro aux;
    for (count = 1; count <= i; count++) {
        aux = lista[count];
        j = count - 1;

        while (j >= 0 && lista[j].ano > aux.ano) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = aux;
    }
}

int sair() {
	char x;
	printf("\n\tPressione qualquer tecla para continuar...\n");
	scanf(" %c", &x);
	return 0;
}

int cadastro() {

    int confirma = 0;

    system("cls");
    printf("\n\tMarca: "); //cadastro carro
    scanf("%s", lista[i].marca);
    printf("\tModelo: ");
    scanf("%s", lista[i].modelo);
    printf("\tAno: ");
    scanf("%d", & lista[i].ano);
    printf("\tPlaca: ");
    scanf("%s", lista[i].placa);
    printf("\n\tConfirme os Dados:\n\n\t1-Confirmar\n\t2-Corrigir\n\n\t");

    while (confirma != 1 && confirma != 2) {
        scanf("%d", & confirma);
        switch (confirma) {
        case 1:
            ordenar();
            i++;
            break;

        case 2:
            cadastro();
            break;

        default:
            printf("\n\tSelecione A Opção 1 Ou 2.\n\t");
            break;
        }
    }
    return 1;
}

int listarTodos() {
    int j;
    for (j = 0; j < 10; j++) {
        if (lista[j].ano != 0) {
            printf("\n\tMarca: %s\tModelo: %s\tAno: %d\tPlaca: %s\n\n\t", lista[j].marca, lista[j].modelo, lista[j].ano, lista[j].placa);
            printf("-------------------------------------------------\n\n");
        }
    }
    sair();
}

int buscaPorAno() {
    int j;
    int ano;
    printf("\n\tAno Da Busca:\n\t");
    scanf("%d", & ano);
    for (j = 0; j < 10; j++) {
        if (ano == lista[j].ano) {
            printf("\n\tMarca: %s\tModelo: %s\tAno: %d\tPlaca: %s\n\n\t", lista[j].marca, lista[j].modelo, lista[j].ano, lista[j].placa);
            printf("-------------------------------------------------\n\n");
        }
    }
    sair();
}

int buscarAnoAcima() {
    int j;
    int ano;
    printf("\n\tBuscar Mais Novo Que:\n\t");
    scanf("%d", & ano);
    for (j = 0; j < 10; j++) {
        if (ano < lista[j].ano) {
            printf("\n\tMarca: %s\tModelo: %s\tAno: %d\tPlaca: %s\n\n\t", lista[j].marca, lista[j].modelo, lista[j].ano, lista[j].placa);
            printf("-------------------------------------------------\n\n");
        }
    }
    sair();
}

int buscarModelo() {
    int j;
    char modelo[20];
    printf("\n\tBuscar Modelo:\n\n\t");
    scanf("%s", modelo);
    for (j = 0; j < 10; j++) {
        if (strcmp(modelo, lista[j].modelo) == 0) {
            printf("\n\tMarca: %s\tModelo: %s\tAno: %d\tPlaca: %s\n\n\t", lista[j].marca, lista[j].modelo, lista[j].ano, lista[j].placa);
            printf("-------------------------------------------------\n\n");
        }
    }
    sair();
}

int busca() {
    int input = 0;
    system("cls");
    printf("\n\t1 - Listar Todos\n\t2 - Buscar Por Ano\n\t3 - Buscar Mais Novo Que Ano\n\t4 - Buscar Modelo\n\n\t");
    while (input < 1 || input > 4) {
        scanf("%d", & input);
        system("cls");

        switch (input) {
        case 1:
            listarTodos();
            break;

        case 2:
            buscaPorAno();
            break;

        case 3:
            buscarAnoAcima();
            break;

        case 4:
            buscarModelo();
            break;

        default:
            printf("\n\tSelecione Uma Opção Válida.\n\t");
            break;
        }
    }
    return 2;
}

int menu() {

    int input = 0;

    system("cls");
    printf("\tSelecione Uma Opção\n\n\t1 - Cadastrar Novo Veículo \n\t2 - Buscar Veículo\n\n\t");

    while (input !=1 || input !=2) {
        scanf("%d", & input);
        switch (input) {
        case 1:
            if (i < 10) {
                cadastro();
            } else {
                printf("\n\tLimite De Carros Cadastrados\n\t");
            }
            break;

        case 2:
            busca();
            break;

        default:
            printf("\n\tSelecione A Opção 1 Ou 2.\n\t");
            break;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "portuguese");
    while (1) {
        menu();
    }
    return 0;
}
