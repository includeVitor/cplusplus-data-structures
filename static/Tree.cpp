#include <iostream>
#include <cstdlib>
using namespace std;

struct arvore
{
	int chave;
}Arvore[50];

void inserir(int valor,arvore *pArvore,int &cE,int &cD)
{
	if(pArvore[0].chave ==0)
	{
		pArvore[0].chave = valor;
		return;
	}
	
	if(valor<pArvore[0].chave)
	{
		if(pArvore[2*cE+1].chave==0)
		{
			pArvore[2*cE+1].chave=valor;
			return;
		}
		if(valor>pArvore[2*cE+1].chave)
		{
			 int tmp=2*cE+1;
			
			pArvore[2*tmp+2].chave=valor;
		}
		if(valor<pArvore[2*cE+1].chave)
		{
			int tmp=2*cE+1;
			
			pArvore[2*tmp+1].chave=valor;
		}
		int tmp;
		tmp=2*cE+1;
		if(pArvore[2*tmp+1].chave !=0 && pArvore[2*tmp+2].chave!=0)
		{
			cE=2*cE+1;
		}
			
	}
	
	if(valor>pArvore[0].chave)
	{
		
		if(pArvore[2*cD+2].chave==0)
		{
			pArvore[2*cD+2].chave=valor;
			return;
		}
		if(valor>pArvore[2*cD+2].chave)
		{
			 int tmp=2*cD+2;
			
			pArvore[2*tmp+2].chave=valor;
		}
		if(valor<pArvore[2*cD+2].chave)
		{
			int tmp=2*cD+2;
			
			pArvore[2*tmp+1].chave=valor;
		}
		int newtmp;
		newtmp=2*cD+2;
		if(pArvore[2*newtmp+1].chave !=0 && pArvore[2*newtmp+2].chave!=0)
		{
			cD=2*cD+2;

		}
		
	}
	
	
	
	
}

int main(void)
{
	int contadorE=0,contadorD=0;
 	for(int i=0;i<=50;i++)
	{
		Arvore[i].chave=0;
	}
	inserir(11,Arvore,contadorE,contadorD);
	inserir(9,Arvore,contadorE,contadorD);
	inserir(13,Arvore,contadorE,contadorD);
	inserir(8,Arvore,contadorE,contadorD);
	inserir(10,Arvore,contadorE,contadorD);
	inserir(12,Arvore,contadorE,contadorD);
	inserir(30,Arvore,contadorE,contadorD);
	inserir(29,Arvore,contadorE,contadorD);
	inserir(45,Arvore,contadorE,contadorD);
	
	for(int i=0;i<=50;i++)
	{
		cout<<"Posicao "<<i<<" :";
		if(Arvore[i].chave!=0)
		{	
			cout<<Arvore[i].chave;
		}
		cout<<"\n";
	}
	
}
