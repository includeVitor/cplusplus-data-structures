#include <cstdlib>
#include <iostream>
using namespace std;


typedef struct tipoElemento
{
	int valorPrato;
}TElemento;

typedef struct tipoPilha
{
	TElemento pilhaElemento[5];
	int topoPilha;
}TPilha;

void criarPilha(TPilha *pPilha)
{
	pPilha->topoPilha=-1;
	cout<<"\n Pilha criada com sucesso ! \n\n";
}

void inserirElemento(TPilha *pPilha)
{
	if(pPilha->topoPilha< 4)
	{
		pPilha->topoPilha++;
		cout<<"\n Digite um numero : ";
		scanf("%d",&pPilha->pilhaElemento[pPilha->topoPilha].valorPrato);
		
	}else
	{
		cout<<"\n Pilha cheia ! \n";
	}
	cout<<"\n\n";
}

void excluirElemento(TPilha *pPilha)
{
	if(pPilha->topoPilha>=0)
	{
		pPilha->topoPilha--;
		cout<<"\n Elemento excluido da pilha \n";
	}else
	{
		cout<<"\n Pilha vazia ! ! \n";
	}
		
}
void mostrarPilha(TPilha *pPilha)
{
	if(pPilha->topoPilha>-1)
	{
		for(int i=-1;i<pPilha->topoPilha;i++)
		{
			cout<<"\n Posicao ["<<i+1<<"]  Elemento : "<<pPilha->pilhaElemento[i+1].valorPrato<<"\n";
		}
	}else
	{
		cout<<"\n Pilha vazia !\n";
	}
	cout<<"\n\n";	
}

void localizarElemento(TPilha *pPilha)
{
	int elemento;
	bool achou=false;
	cout<<"Digite um elemento : ";
	cin>>elemento;
	for(int i=-1;i<pPilha->topoPilha;i++)
	{
		if(elemento==pPilha->pilhaElemento[i+1].valorPrato)
		{
			cout<<"\nElemento encontrado!! \n\n";
			cout<<"Posicao ["<<i+1<<"]  Elemento :"<<pPilha->pilhaElemento[i+1].valorPrato<<"\n";
			achou=true;
			break;	
		}
		
	}
	if(achou==false)
	{
		cout<<"\n Elemento nao existe !\n";
	}
	cout<<"\n\n";
		
}
int main()
{
	TPilha  pilha;	
	int opcao;
	do
	{
		cout<<"[1] Criar pilha \n";
		cout<<"[2] Inserir elemento\n";
		cout<<"[3] Excluir elemento\n";
		cout<<"[4] Mostrar pilha \n";
		cout<<"[5] Localizar elemento\n";
		cout<<"[6] Sair \n";
		cout<<"Escolha uma opcao :";
		cin>>opcao;
		
		switch (opcao)
		{
			case 1 :
			{
				system("CLS");
				criarPilha(&pilha);	
				break;
			}
			case 2:
			{
				system("CLS");
				inserirElemento(&pilha);
				break;
			}
			case 3:
			{
				system("CLS");
				excluirElemento(&pilha);
				break;
			}
			case 4:
			{
				system("CLS");
				mostrarPilha(&pilha);
				break;
			}
			case 5:
			{
				system("CLS");
				localizarElemento(&pilha);	
				break;
			}	
		}
		
	}while(opcao!=6);
	system("PAUSE");
	return 0;
	
}
