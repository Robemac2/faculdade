#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{ //estrutura cliente
	char nome[30];
	int ano;
	float gasto;
} Cliente;

int n = 2;
Cliente *lista;
int i = 0;

int sair()
{
	char x;
	printf("\n\tPressione qualquer tecla para continuar...\n");
	scanf(" %c", &x);
	return 0;
}

int listar()
{
	for (int j = 0; j < i; j++)
	{
		printf("\n\t%s", lista[j].nome);
	}
}

int cadastro()
{ //adicionar cliente

	if (i == n)
	{
		n += 10;
		lista = (Cliente *)realloc(lista, n * sizeof(Cliente));
	}

	system("cls");
	printf("\n\tCadastro De Cliente.\n\n\tNome: ");
	scanf("%s", lista[i].nome);
	printf("\tAno Nascimento: ");
	scanf("%d", &lista[i].ano);
	lista[i].gasto = 0;
	i++;
	listar();
	sair();
}

int compra()
{ //adicionar compra = somar ao gasto
	system("cls");
	int j;
	float compra = 0;
	char nome[30];
	printf("\n\tCliente: ");
	scanf("%s", nome);
	for (j = 0; j < n; j++)
	{
		if (strcmp(nome, lista[j].nome) == 0)
		{
			system("cls");
			printf("\n\tNome: %s\n\tGasto No Mês: R$ %.2f\n\n\tCompra Atual: R$", lista[j].nome, lista[j].gasto);
			scanf("%f", &compra);
			lista[j].gasto = lista[j].gasto + compra;
		}
	}
	sair();
}

int remover()
{ //remover cliente
	system("cls");
	int j;
	int encontrado = -1;
	char nome[30];
	printf("\n\tCliente: \n\t");
	scanf("%s", nome);
	for (j = 0; j < n; j++)
	{
		if (strcmp(nome, lista[j].nome) == 0)
		{
			encontrado = j;
			break;
		}
	}

	if (encontrado < 0)
	{

		printf("\n\n\tCliente não encontrado.");
		sair();
		return 0;
	}

	if (encontrado < i - 1)
	{
		for (j = encontrado; j < i; j++)
		{
			lista[j] = lista[j + 1];
		}
	}
	i--;

	printf("\n\n\tCliente Removido");
	listar();
	sair();
}

int virar_mes()
{ //virar mes para zerar compra
	int j = 0;
	for (j = 0; j < i; j++)
	{
		lista[j].gasto = 0;
	}
	printf("\n\tMês Avançado.");
	sair();
}

int melhor_cliente()
{ //listar cliente maior compra

	int j;
	Cliente melhor = lista[0];
	for (j = 1; j < i; j++)
	{
		if (lista[j].gasto > melhor.gasto)
		{
			melhor = lista[j];
		}
	}
	printf("\tO melhor cliente:\n\tNome: %s\n\tGasto No Mês: R$ %.2f", melhor.nome, melhor.gasto);
	sair();
}

int consulta()
{ //listar dados de um cliente
	system("cls");
	int j;
	char nome[30];
	printf("\n\tCliente: \n\t");
	scanf("%s", nome);
	for (j = 0; j < n; j++)
	{
		if (strcmp(nome, lista[j].nome) == 0)
		{
			printf("\n\n\tCliente: %s\n\tAno Nascimento: %d\n\tTotal Compra No Mês: R$ %.2f\n\n\t", lista[j].nome, lista[j].ano, lista[j].gasto);
		}
	}
	sair();
}

int menu()
{ //menu de selecao
	int input = 0;
	system("cls");
	printf("\tSelecione Uma Opção\n\n\t1 - Cadastrar Cliente \n\t2 - Inserir Compra\n\t3 - Remover Cliente\n\t4 - Mudar Mês\n\t5 - Melhor Cliente\n\t6 - Buscar Cliente\n\n\t");
	while (input < 1 || input > 6)
	{
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			cadastro();
			break;
		case 2:
			compra();
			break;
		case 3:
			remover();
			break;
		case 4:
			virar_mes();
			break;
		case 5:
			melhor_cliente();
			break;
		case 6:
			consulta();
			break;
		default:
			printf("\n\tSelecione Uma Opção Válida.\n\t");
			break;
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	lista = (Cliente *)malloc(n * sizeof(Cliente));
	while (1)
	{
		menu();
	}
	return 0;
}