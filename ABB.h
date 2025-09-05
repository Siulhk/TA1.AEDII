/*
 * ABB.h
  */

struct no {
	int info;
	no *Llink;
	no *Rlink;
};

struct noF {
	int info;
	noF *link;
	int nivel;
};
// retorna altura de uma Arvore de Busca Binaria
int altura_AB(no *T) {
	int aL, aR;
		
	if(T == NULL) {
		return -1;
	}
	else {
		aL = altura_AB(T->Llink);
		aR =  altura_AB(T->Rlink);
		if (aL < aR){
			return (aR+1);
		}
		else{
			return (aL+1);
		}
	}
}

noF *inicializaFila(noF *L) {
	return NULL;
}
noF *insereFila(noF *L, int x, int n) {
	noF *N, *P;

	N = new noF;
	N->info = x;
	N->link = NULL;
	N->nivel = n;
	 
	if (L == NULL){
		L = N;
	}
	else {
		P = L;	
		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N; 	
	} 
	return L;
}
void imprimeFila(noF *L,no *T) {
	noF *P;
	
	
	printf("\n Imprime Fila: \n");
	for(int i=0;i<=altura_AB(T);i++){	
		P = L;
		while(P != NULL) {
			if (P->nivel*(-1)==i)
			{
				cout << P->info <<" ";
			}
			P = P->link;
		}
		cout <<"\n";
	}
}

no *ini_AB(no *T) {
	return NULL;
}

no *novoNo_AB(no *T, int x) {
	T = new no;
	if (T != NULL) {
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
	}
	return T;
}

no *insere_AB(no *T, int x) {
	if (T == NULL){
		T = novoNo_AB(T,x);
		return T;
	}
	else {
		if (x < T->info){ 
			T->Llink = insere_AB(T->Llink, x);
		}
		else {	 
				T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(no *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		cout << T->info << " ";
		emOrdem_AB(T->Rlink);
	}
}

void preOrdem_AB(no *T) {
	if(T != NULL) {
		cout << T->info << " ";
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}

void posOrdem_AB(no *T) {
	if(T != NULL) {
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		cout << T->info << " ";
	}
}

// ** BUSCA VALOR NA ABB **
int busca(no *T, int x) {
	int p;
	if(T == NULL){
		return 0;
    }
	else {
		if (T->info == x)
			return 1;
		else{
			if (x < T->info){
				p = (busca(T->Llink, x));
				return p;
			}
			else{
				p = (busca(T->Rlink, x));
				return p;
			}
		}
	}
} 

no *maior_AB(no *T) {
    no *p;
	if (T != NULL) {
		while (T->Rlink != NULL){
			T = T->Rlink;
		}
		return T;  
	}
	else
		return NULL;
}


no *remove_AB(no *T, int x){
	no *p;

	if (T == NULL) {
		return NULL;
	}
	else{
		if (x < T->info)
			T->Llink = remove_AB(T->Llink, x);
		else {
			if (x > T->info)
				T->Rlink = remove_AB(T->Rlink, x);
			else {
				//no folha
				if ((T->Llink == NULL) && (T->Rlink == NULL)){
					p = T;
					free(p);
					T = NULL;
					return T;
				}
				else{
					// so tem o filho da direita
					if (T->Llink == NULL){ 
						p = T;
						T = T->Rlink;
						free(p);
						return T;
					}
					else{
						// so tem o filho da esquerda 
						if (T->Rlink == NULL){ 
							p = T;
							T = T->Llink;
							free(p);
							return T;
						}
						else {
							// NO tem 2 filhos 
							p = maior_AB(T->Llink);
							T->info = p->info;
							T->Llink = remove_AB(T->Llink,p->info);
						}
					}
				}
			}
		}
		return T;
	}
}

void percursoLargura (no *T,noF *L,int nivel){

	if (T!=NULL)
	{
	L = insereFila(L,T->info,nivel);
	percursoLargura(T->Llink,L,nivel-1);
	percursoLargura(T->Rlink,L,nivel-1);
	}
	if(nivel==0){
	imprimeFila(L,T);
	}
}

void imprimeDescres(no *T){
	if(T!=NULL){
		imprimeDescres(T->Rlink);
		cout << T->info << "\n";
		imprimeDescres(T->Llink);
	}
}