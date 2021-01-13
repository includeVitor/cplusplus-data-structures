#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct tipoElemento
{
	int elemento;
	
}TElemento;

typedef struct tipoLista{
	
	TElemento listaElemento[5];
	int posicaoLista;
	int tamanhoLista;
	
}TLista;

void criaLista(TLista *pLista)
{
	pLista->posicaoLista=0;
	pLista->tamanhoLista=0;	
	cout<<"\n Lista criada com sucesso ! \n\n";
}

void inserirElemento(TLista *pLista,int n)
{	
	int novoElemento;
	if(pLista->tamanhoLista<5)
	{
		cout<<"Digite um elemento : ";
		cin>>novoElemento;
		pLista->listaElemento[n].elemento=novoElemento;
		pLista->tamanhoLista++;
		cout<<"\n\n";
	}else
	{
		cout<<"\nLista cheia ! ! \n\n";
	} 	
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
		cout<<" Informe a posicao :  ";
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
void mostraLista(TLista *pLista)
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
	cout<<"\n\n";
}

void localizaElemento(TLista *pLista)
{
	int elementoAuxiliar;
	bool status=false;
	
	if(pLista->tamanhoLista ==0)
	{
		cout<<"\n Lista vazia!! 	\n\n";
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

void ordemCrescente(TLista *pLista)
{
	int aux;
	if(pLista->tamanhoLista==1)
	{
		cout<<"Ordem Crescente : "<<pLista->listaElemento[0].elemento<<"\n\n";
	}else
	{
		for(int i=0;i<pLista->tamanhoLista-1;i++)
		{
				for(int j=i+1;j<pLista->tamanhoLista;j++)
				{
					if(pLista->listaElemento[i].elemento > pLista->listaElemento[j].elemento)
					{
						aux=pLista->listaElemento[j].elemento;
						pLista->listaElemento[j].elemento=pLista->listaElemento[i].elemento;
						pLista->listaElemento[i].elemento=aux;		
					}
									
					
				}
		}
	
	}
	
}
void ordemDecrescente(TLista *pLista)
{
		int aux;
	
	if(pLista->tamanhoLista==1)
	{
		cout<<"Ordem Decrescente : "<<pLista->listaElemento[0].elemento<<"\n\n";
	}else
	{
		for(int i=0;i<pLista->tamanhoLista-1;i++)
		{
				for(int j=i+1;j<pLista->tamanhoLista;j++)
				{
					if(pLista->listaElemento[i].elemento < pLista->listaElemento[j].elemento)
					{
						aux=pLista->listaElemento[j].elemento;
						pLista->listaElemento[j].elemento=pLista->listaElemento[i].elemento;
						pLista->listaElemento[i].elemento=aux;		
					}
						
				}
		}
	
	}	
}
int main()
{
	TLista lista;
	int opcao,n=0;
	do
	{
		cout<<"[1] Criar Lista \n";	
		cout<<"[2] Inserir \n";
		cout<<"[3] Excluir \n";
		cout<<"[4] Mostrar lista \n";
		cout<<"[5] Localizar elemento \n";
		cout<<"[6] Lista em ordem crescente \n";
		cout<<"[7] Lista em ordem descrescente \n";
		cout<<"[8] Sair \n";
		cout<<"Escolha uma opcao : ";
		cin>>opcao;
		
		
		switch(opcao)
		{
			case 1 :{
				system("CLS");
				criaLista(&lista);
				break;
			}
			case 2:
			{
				system("CLS");
				inserirElemento(&lista,n);	
				n++;
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
				mostraLista(&lista);
				break;
			}
			case 5:
			{
				system("CLS");
				localizaElemento(&lista);
				break;
			}
			case 6:
			{
				system("CLS");
				ordemCrescente(&lista);
				break;
			}
			case 7:
				system("CLS");
				ordemDecrescente(&lista);
				break;
			
		}
		
		
		
		
		
	}while(opcao!=8);
	
	
	
	
	
	
	return 0;
}

