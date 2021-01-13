#include <cstdlib>
#include <iostream>
using namespace std;


typedef struct tipoElemento
{
	int elemento;

}TElemento;

typedef struct tipoFila
{
	TElemento filaElemento[5];
	int tamanhoFila;
}TFila;

void criarFila(TFila *pFila)
{
	pFila->tamanhoFila=0;
	printf("\n Fila criada com sucesso \n\n");
	system("PAUSE");
	system("CLS");
}
void inserirElemento(TFila *pFila)
{
	if(pFila->tamanhoFila<5)
	{
		printf("\nDigite um numero :");
		scanf("%d",&pFila->filaElemento[pFila->tamanhoFila].elemento);
		pFila->tamanhoFila++;
		system("PAUSE");
		system("CLS");
	}else
	{
	printf("\n Fila cheia  \n\n");	
	}
	
}
void excluirElemento(TFila *pFila)
{
	if(pFila->tamanhoFila>0)
	{
		for(int i=0; i<pFila->tamanhoFila-1;i++)
		{
			pFila->filaElemento[i]=pFila->filaElemento[i+1];
		}
		pFila->tamanhoFila--;
		printf("\n Elemento Excluido \n\n");
	}else
	{
		printf("\n Fila vazia \n");
	}
}
void exibeFila(TFila *pFila)
{
	for(int i=0;i<pFila->tamanhoFila;i++)
	{
		cout<<"Posicao["<<i<<"]   Elemento :"<<pFila->filaElemento[i].elemento<<"\n";
		
	}
	system("PAUSE");
	
}	
void localizaElemento(TFila *pFila)
{
	int elemento;
	bool achou=false;
	cout<<"Digite um elemento : ";
	cin>>elemento;
	for(int i=0;i<pFila->tamanhoFila;i++)
	{
		if(elemento==pFila->filaElemento[i].elemento)
		{
			cout<<"Elemento encontrado!  \n";
			cout<<"Posicao["<<i<<"] Elemento :"<<pFila->filaElemento[i].elemento<<"\n\n";
			achou=true;
			system("PAUSE");
			system("CLS");			
		}
	}if(achou==false)
			{
			cout<<"Elemento nao encontrado \n\n";
			system("PAUSE");
			system("CLS");	
			
			}

	
	
}

int main()
{
TFila fila;
int opcao;
do
{
	cout<<"1 ]-Criar fila  \n";
	cout<<"2 ]-Inserir  elemento\n";
	cout<<"3 ]-Excluir elemento \n";
	cout<<"4 ]-Mostrar fila \n";
	cout<<"5 ]-Localizar Elemento \n";
	cout<<"6 ]-Sair\n\n";
	cout<<"Digite um numero : ";
	cin>>opcao;	
	switch(opcao)
	{
		case 1:{
			
			criarFila(&fila);
			break;
		}
		case 2:{
			system("CLS");
			inserirElemento(&fila);
			break;
		}
		case 3:{
			system("CLS");
			excluirElemento(&fila);
			break;
		}
		case 4:{
			system("CLS");
			exibeFila(&fila);
			break;
		}
		case 5:{
			system("CLS");
			localizaElemento(&fila);
			break;
		}
		
	}
	
	
	
	
}while(opcao!=6);


	
}
