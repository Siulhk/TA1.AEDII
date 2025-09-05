#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#include "ABB.h"

int main(void)
{
   no *T, *p;
   int x, c;

   T = ini_AB(T);
   
   do 
   {
      printf("\n");
      printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
      printf("2 - Remove Item da ARVORE DE BUSCA BINARIA\n");
      printf("3 - EMORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em-Ordem\n");
      printf("4 - PREORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre-Ordem\n");
      printf("5 - POSORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos-Ordem\n");
      printf("6 - PERCURSO EM LARGURA - TA1\n");
      printf("7 - BUSCA Item na ARVORE DE BUSCA BINARIA\n");
      printf("8 - Calcula a Altura de uma ARVORE DE BUSCA BINARIA\n");
      printf("9 - Imprime os valores ordenados de forma decrescente\n");
      printf("10 - Sair\n");
      printf("\n Escolha: ");

     cin >> c;

      switch(c) {
         case 1: 
			cout << " \nEntre com o item a ser inserido: ";
			cin >> x;
			T = insere_AB(T,x); 
			break;
         case 2: 
			cout << " \nEntre com o item a ser removido: ";
			cin >> x;
			T = remove_AB(T,x); 
			break;

         case 3: 
			emOrdem_AB(T);
 			printf("\n");	
			break;
         case 4: 
  		    preOrdem_AB(T);
 			printf("\n");	
			break;
         case 5: 
  		    posOrdem_AB(T);
 			printf("\n");	
			break;
		   case 6:
         noF *L;
         L = inicializaFila(L);
         percursoLargura(T,L,0);
			// ** Tema do Trabalho Avaliativo 1 **
			break;
		   case 7:
         int v;
			cout << " \nEntre com o item a ser procurado: ";
			cin >> x;
         v = busca(T,x);
         if (v==1)
            cout << "EXISTE";
         else
            cout << "NAO EXISTE";
         break;
      case 8:
         cout << "Altura da ABB: " << altura_AB(T);
         break;   
         case 9:
			cout << "Imprimindo em ordem decrescente\n";
         imprimeDescres(T);
         break;
		case 10:
			exit(0);
         break;
      };
   } while (c != 9);
}
