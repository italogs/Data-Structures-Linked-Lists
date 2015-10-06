
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TLSE{
	int info;
	struct TLSE *prox;
}TLSE;


TLSE *inicializa(TLSE *l){
	return NULL;

}
TLSE *ins_ini(TLSE *l,int info){
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = info;
	novo->prox = l;
	return novo;
}
void imprime(TLSE *l){
	while(l){
		printf("(%d), ",l->info);
		l = l->prox;
	}
	printf("\b\b \n\n");

}
void imprime_rec(TLSE *l){

	if (l){
		printf("(%d), ",l->info);
		imprime_rec(l->prox);
	}
}
void libera(TLSE *l){
	TLSE *p =l,*q;
	while(p){
		q = p;
		p = p->prox;
		free(q);

	}
	l=NULL;

}
TLSE *libera_rec(TLSE *l){
	if (l){
		
		return libera_rec(l->prox);
		free(l);
		l= NULL;
	} else 
	return l;
}

TLSE *busca(TLSE *l,int info){
	while(l && l->info != info) {
		l = l->prox;
	}
	return l;

}
TLSE *busca_rec(TLSE *l,int info) {

	if ( !l || l->info == info) {return l;}

	return busca_rec(l->prox,info);

}
TLSE *retira(TLSE *l,int info) {

	TLSE *ant = NULL,*p = l;
	while(p && p->info != info) {
		ant = p;
		p = p->prox;
	}

	if(!p) return l;

	if(!ant) 
		l = l->prox;
	else
		ant->prox = p->prox;

	free(p);
	
	return l;
}

TLSE *retira_rec(TLSE *l,int info){

	if (!l) return l;

	if(info == l->info) {
		TLSE *p = l;
		l = l->prox;
		free(p);

	} else {
		l-> prox = retira_rec(l->prox,info);
		
	}
	return l;
}

TLSE *ins_ord(TLSE *l,int info) {

	TLSE *p = l,*ant = NULL;
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = info;
	while(p && info != p->info) {
		ant = p;
		p = p->prox;
	}
	if(!ant) {
		novo->prox=p;
		return novo;
	}
	
	novo->prox = p;
	ant->prox = novo;
	return l;
}

TLSE *ins_ord_rec(TLSE *l,int info) {

	if(!l || (l->info >=info)){
		TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
		novo->info = info;
		novo->prox = l;
		return novo;
	}
	l->prox = ins_ord_rec(l->prox,info);
	return l;
}

TLSE *ins_fim(TLSE *l,int info){
	if(!l) return ins_ini(l,info);
	TLSE *p = l;

	while(p->prox) p = p->prox;

	p->prox = ins_ini(p->prox,info);
	return l;
}

TLSE *ins_fim_rec(TLSE *l,int info){

	if(!l) return ins_ini(l,info);

	l->prox = ins_fim_rec(l->prox,info);

	return l;
}


TLSE *rr_rec(TLSE *l, int info){
	if(!l) return l;
	if(l->info == info) {
		TLSE *p = l;
		l = l->prox;
		free(p);
		l = rr_rec(l,info);

	}
	else l->prox = rr_rec(l->prox,info);
	return l;
}

// TLSE *rr(TLSE *l,int info){
// 	while(l && l->info == info) {
// 		l = retira(l,info);
// 	}
// 	if(!l) return l;
// 	TLSE *p = l->prox,ant=l;
// 	while(p) {

// 	if(p->info  == info) {
// 		ant->prox = p->prox;
// 		TLSE *q = p;
// 		p = p->prox;
// 		free(q);
// 	}

// 	else {ant = p; p = p->prox;}
// 	return l;
// 	}
// }


//lista 1
//Q1)
void inverte(TLSE *l) {
	if(!l) return;
	TLSE *aux = l;
	int n = 0;
	for (aux = l,n=0;aux;aux=aux->prox,n++){}
	int vet_aux[n];
	int i = 0;
	for(aux = l; aux !=NULL ; aux=aux->prox,i++){
		vet_aux[i] = aux->info;
	}
	for(aux = l,i=n-1;i>=0;aux=aux->prox,i--){
		aux->info = vet_aux[i];
	}


}

//Q2)
TLSE *inverteQ2(TLSE *l) {
	if(!l) return l;
	TLSE *aux = l, *ant = NULL;
	while(aux) {
		TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
		novo->info = aux->info;
		novo->prox = ant;
		ant = novo;
		aux = aux->prox;
	}
	return ant;		
}

//Q3)
TLSE *desloca(TLSE *l, int n){
	if(!l || n<=0) return l;
	TLSE *novol = l;
	int i =0;
	for (i =0 ; novol && i<n;novol=novol->prox,i++){}
	while(l!=novol){
		TLSE *aux=l;
		l=l->prox;
		free(aux);
	}
	if(n%2==0){//par
		TLSE *primeiro = novol;
		novol = novol->prox;
		primeiro->prox = NULL;
		TLSE *aux = novol;
		while(aux->prox){
			aux = aux->prox;
		}
		aux->prox = primeiro;
	} else {//impar
		TLSE *ultimo = novol, *ant = NULL;
		if(ultimo->prox){
			while(ultimo->prox){
				ant = ultimo;
				ultimo = ultimo->prox;
			}
			ant->prox = NULL;
			ultimo->prox = novol;
			novol = ultimo;
		}
		
	}
	return novol;
}

//Q4)
typedef struct aluno{
	int mat;
	float cr;
	struct aluno *prox;
}TAluno;

TAluno *insere_TAluno(TAluno *l,int mat,int cr) {

	TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
	novo->mat = mat;
	novo->cr = cr;
	if(!l) {novo->prox = NULL;}
	else{novo->prox = l; }
	return novo;
}

void print_TAluno(TAluno *l) {
	if(!l) return;

	TAluno *aux = l;
	while(aux){
		printf("Aluno: %d, %f\n",aux->mat,aux->cr);
		aux = aux->prox;
	}

}
TAluno *copia(TAluno *l) {
	if(!l) return l;
	TAluno *cabeca = (TAluno *)malloc(sizeof(TAluno));
	cabeca->mat = l->mat;
	cabeca->cr = l->cr;
	cabeca->prox = NULL;
	TAluno *aux = cabeca;
	l =l->prox;
	while(l){
		TAluno *novo= (TAluno *)malloc(sizeof(TAluno));
		novo->cr = l->cr;
		novo->mat = l->mat;
		aux->prox = NULL;
		aux->prox = novo;
		aux=novo;
		l=l->prox;
	}
	return cabeca;
}

//Q5)
TLSE *rto(TLSE *l,int elem) {
	if(!l) return l;
	TLSE *aux = l;
	while (l && l->info == elem) {
		aux = l;
		l = l->prox;
		free(aux);
	}
	if(!l) return l;
	aux = l;
	while(aux->prox){
		if(aux->prox->info == elem) {
			TLSE *p = aux->prox;
			aux->prox = aux->prox->prox;
			aux = aux->prox;
			free(p);
		} else 
			aux = aux->prox;
	}
	return l;
}

//Q6)
// TLSE *i_p(TLSE *l) {
// 	if(!l) return l;
// 	TLSE *fim_i = NULL, *fim_p = NULL, *cabeca_i = NULL, *cabeca_p = NULL, *aux = l;
// 	while(aux) {
// 		TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
// 		novo->info = aux->info;
// 		novo->prox = NULL;

// 		if(aux->info % 2 != 0) {
// 			if(!cabeca_i) {

// 				fim_i = cabeca_i = novo;
// 				fim_i->prox = cabeca_p;
// 			} else {
// 				novo->prox = fim_i->prox;
// 				fim_i->prox = novo;
// 				fim_i = novo;
// 			}
// 		} else {
// 			if(!cabeca_p) {
// 				fim_p = cabeca_p = novo;
// 				if(fim_i) 
// 					fim_i->prox = cabeca_p;
// 			} else {
// 				fim_p->prox = novo;
// 				fim_p = novo;
// 			}
// 		}
// 		aux = aux->prox;
// 	}
// 	if(cabeca_i) return cabeca_i;
// 	return cabeca_p;
// }

//Q7)
void i_p(TLSE *l) {
	if(!l) return ;
	int n_i =0,n_p=0;
	TLSE *aux = l;
	while(aux){
		if(aux->info % 2 == 0)
			n_p++;
		else
			n_i++;
		aux=aux->prox;
	}
	int vet_i[n_i],vet_p[n_p],i_p=0,i_i=0;
	aux = l;
	while(aux) {
		if(aux->info %2 ==0)
			vet_p[i_p++] = aux->info;
		else
			vet_i[i_i++] = aux->info;
		aux=aux->prox;
	}
	aux = l;
	for(i_i=0;i_i<n_i;i_i++) {
		aux->info = vet_i[i_i];
		aux = aux->prox;
	}
	for(i_p=0;i_p<n_p;i_p++){
		aux->info =vet_p[i_p];
		aux = aux->prox;	
	}
}


typedef struct TLista{
	int mat;
	float cr;
	char nome[30];
	struct TLista *prox;
}TLista;

TLista *ins_ini_TLista(TLista *l,int mat,float cr, char nome[]){
	TLista *novo = (TLista *)malloc(sizeof(TLista));
	novo->mat = mat;
	novo->cr = cr;
	strcpy(novo->nome,nome);
	novo->prox = l;
	return novo;
}


//Q8)
int igual(TLista *l1,TLista *l2) {
	if(!l1 && !l2) return 1;
	if( (!l1 && l2) || (l1 && !l2) ) return 0;

	TLista *l1aux = l1, *l2aux = l2;

	while( l1aux && l2aux) {
		if(l1aux->mat != l2aux->mat || strcmp(l1aux->nome,l2aux->nome) != 0 || l1aux->cr != l2aux->cr) return 0;
		l1aux = l1aux->prox;
		l2aux = l2aux->prox;
	}
	return (!l1aux && !l2aux);
}

int main(void){


	
	// TLSE *lista = NULL,*lista2 = NULL;
	// lista = inicializa(lista);


	// lista = ins_ini(lista,4);
	// lista = ins_ini(lista,1);
	// lista = ins_ini(lista,5);
	// lista = ins_ini(lista,6);
	// lista = ins_ini(lista,3);
	// lista = ins_ini(lista,6);
	// imprime(lista);
	/***** 	Q2	
	printf("Inverte\n");
	TLSE *lista_inv = inverteQ2(lista);
	imprime(lista);
	imprime(lista_inv);
	*******/
	/***** 	Q3
	// imprime(desloca(lista,3));
	****/
	/***** 	Q4
	****/
	// TAluno *lista_TAluno = NULL;
	// lista_TAluno = insere_TAluno(lista_TAluno,123,3.0);
	// lista_TAluno = insere_TAluno(lista_TAluno,345,4.0);

	// print_TAluno(lista_TAluno);
	// TAluno *lista_TAluno2 = copia(lista_TAluno);
	// lista_TAluno->mat = 444;
	// printf("Resultado:\n");
	// print_TAluno(lista_TAluno);
	// printf("\n\n\n");
	// print_TAluno(lista_TAluno2);

	/***** 	Q5
	****/
	// imprime(rto(lista,6));
	/***** 	Q6
	****/
	// imprime(i_p(lista));

	/***** 	Q7
	****/
	// i_p(lista);
	// imprime(lista);

	/***** 	Q8
	****/
	TLista *TLista1 = NULL, *TLista2 = NULL;
	TLista1 = ins_ini_TLista(TLista1,123,3.0,"italo");
	TLista1 = ins_ini_TLista(TLista1,456,4.0,"italo2");
	TLista1 = ins_ini_TLista(TLista1,789,5.0,"italo3");
	TLista1 = ins_ini_TLista(TLista1,0123,6.0,"italo4");

	TLista2 = ins_ini_TLista(TLista2,123,3.0,"italo");
	TLista2 = ins_ini_TLista(TLista2,456,4.0,"italo2");
	TLista2 = ins_ini_TLista(TLista2,789,5.0,"italo3");
	TLista2 = ins_ini_TLista(TLista2,0123,6.0,"italo4");
	

	printf("%d\n\n",igual(TLista1,TLista2));
	// imprime(lista);


	// // printf("%p",lista);
	// lista = ins_ini(lista,3);
	// lista = ins_ini(lista,0);

	// lista = ins_ini(lista,-79);
	// lista = ins_ini(lista,5);
	// imprime_rec(lista);

	// lista = retira(lista,0);
	// lista = retira(lista,5);
	// imprime_rec(lista);
	// printf("lista %d",lista==NULL?1:0);
	// lista =libera_rec(lista);
	// imprime_rec(lista);
	// printf("lista %d\n",lista==NULL?1:0);
	// free(lista);
	// printf("lista %d",lista->info);
	// lista = ins_ini(lista,5);


	// lista = ins_ord_rec(lista, 10);
	// lista = ins_ord_rec(lista, 155);
	// lista = ins_ord_rec(lista, 0);
	// lista = ins_ord_rec(lista, 73);
	// lista = ins_ord_rec(lista, 2);
	// imprime_rec(lista);
	return 0;
}

