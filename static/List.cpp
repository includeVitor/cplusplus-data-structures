#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct tipoElemento
{
	int elemento;
}TElemento;

typedef struct tipoLista
{
	TElemento listaElemento[5];
	int tamanhoLista;
	int posicaoLista;
}TLista;

void criarLista(TLista *pLista)
{
	pLista->posicaoLista=0;
	pLista->tamanhoLista=0;
	cout<<"\n Lista criada com Sucesso ! \n\n";
}

void inserirElemento(TLista *pLista)
{
	int elementoAuxiliar;
	
	if(pLista->tamanhoLista==0)
	{
		cout<<"\n Digite um numero :";
		cin>>elementoAuxiliar;
		pLista->listaElemento[pLista->tamanhoLista].elemento=elementoAuxiliar;
		pLista->tamanhoLista++;
		cout<<"\n";
	}else
	{
		if(pLista->tamanhoLista < 5)
		{
			cout<<"\n Digite  um numero : ";
			cin>>elementoAuxiliar;
			cout<<"\n";
			
			for (int i=0;i<pLista->tamanhoLista;i++)
			{
				if(elementoAuxiliar<pLista->listaElemento[i].elemento)
				{
					pLista->posicaoLista=i;
					for(int j=pLista->tamanhoLista;j>pLista->posicaoLista;j--)
					{
						pLista->listaElemento[j].elemento=pLista->listaElemento[j-1].elemento;
					}
					pLista->listaElemento[pLista->posicaoLista].elemento=elementoAuxiliar;
					pLista->tamanhoLista++;
					break;
				}
			}
		if(elementoAuxiliar>pLista->listaElemento[pLista->tamanhoLista-1].elemento)
		{
			pLista->listaElemento[pLista->tamanhoLista].elemento=elementoAuxiliar;
			pLista->tamanhoLista++;		
		}	
		}else
		{
			cout<<"\nLista cheia!! \n";
		}
	}
}
void localizarElemento(TLista *pLista)
{
	int elementoAuxiliar;
	bool status=false;
	
	if(pLista->tamanhoLista ==0)
	{
		cout<<"\n Lista vazia 	\n";
	}else
	{
		cout<<"\n Informe o elemento : ";
		cin>>elementoAuxiliar;
		for(int i=0; i<pLista->tamanhoLista ;i++)
		{
			if(elementoAuxiliar==pLista->listaElemento[i].elemento)
			{
				cout<<"\n"<<"Posicao  ["<<i<<"] Elemento :"<<pLista->listaElemento[i].elemento<<"\n";
				status=true;
				break;
			}	
		}
		if(status==false)
		{
			cout<<"\n Elemento nao existe  \n";
		}
		cout<<"\n";
	}	
}

void mostrarLista(TLista *pLista)
{
	if(pLista->tamanhoLista==0)
	{
		cout<<"\n Lista vazia ! \n";
	}else
	{
		cout<<"Conteudo da lista :\n\n";
		for(int i=0;i<pLista->tamanhoLista;i++)
		{
			cout<<" Posicao : ["<<i<<"]  Elemento :"<<pLista->listaElemento[i].elemento<<"\n";
		}
	}
	cout<<"\n";
	
}

void excluirElemento(TLista *pLista)
{
	int posicaoElemento;
	if(pLista->tamanhoLista==0)
	{
		cout<<"\nLista vazia ! ! \n\n";
	}
	else
	{
		cout<<"Infome a posicao do elemento : ";
		cin>>posicaoElemento;
		cout<<"\n\n";
		if(posicaoElemento==pLista->tamanhoLista-1)
		{
			pLista->tamanhoLista--;
		}else
		{
			for(int i=posicaoElemento;i<pLista->tamanhoLista;i++)
			{
				pLista->listaElemento[posicaoElemento].elemento=pLista->listaElemento[posicaoElemento+1].elemento;
				posicaoElemento++;			
			}
			pLista->tamanhoLista--;	
		}
		cout<<"\nElemento excluido com sucesso \n\n";	
	}	
}

int main()
{
	TLista lista;
	int opcao;
	do
	{
		cout<<"[1] Criar lista\n";
		cout<<"[2] Inserir elemento\n";
		cout<<"[3] Excluir elemento\n";
		cout<<"[4] Localizar elemento\n";
		cout<<"[5] Mostrar Lista \n";
		cout<<"[6] Sair\n";
		cout<<"Escolha uma opcao: ";
		cin>>opcao;
		switch(opcao)
		{
			case 1:
			{
				system("CLS");
				criarLista(&lista);
				break;
				}
			case 2:
			{
				system("CLS");
				inserirElemento(&lista);
				break;
				}
			case 3:
			{
				system("CLS");
				excluirElemento(&lista);
				break;
				}
			case 4:
			{
				system("CLS");
				localizarElemento(&lista);
				break;
				}
			case 5:
			{
				system("CLS");
				mostrarLista(&lista);	
				break;
				}	
			
		}

	}while(opcao!=6);
	
	system("PAUSE");
	return 0;
}
