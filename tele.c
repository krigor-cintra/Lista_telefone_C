#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//contato - telefone e o nome da pessoa e a indicação do proximo da lista - 
struct contato {
	long telefone;
    char nome[25];
    struct contato *proxima;

};
//Criando as posiçoes da fila 
struct contato *primeira;
struct contato *ultima;
//Metodo para adicionar a fila  numero + nome -  seria viavel usar para aplicações comerciais char no telefone, mais facil para manipulação
void adicionar( long telefone, char *nome) {
    struct contato *nova = (struct contato*) malloc(sizeof(struct contato));
    nova->telefone = telefone;
    
    strcpy(nova->nome, nome);

    nova->proxima = primeira;

    primeira = nova;

};
//Exibir/mostrar os contatos que tem em lista 
void mostrar() {
    struct contato *ptr = primeira;
    printf("\nLista de Telefones\n");
    while(ptr != NULL) {
        printf(" %d - %s \n", ptr->telefone,ptr->nome);
        ptr = ptr->proxima;
    }

};
//Forma de procurar um contato pelo nome "usando a primeirea letra", poderia usar metodos para devolver qualquer nome com aquela letra seguindo a ordem em que ela aparece. formatação simples para reconhcer tanto em maiuscula e minuscula 
void procurar(char nome[25]){
    struct contato *ptr = primeira;
    

    while(ptr != NULL) {
		
		char de[25];
		strcpy(de,ptr->nome);	
		
		if(de[0] == nome[0]){
			printf("\nTelefones encontrados\n");
			printf(" %d - %s \n", ptr->telefone,ptr->nome);
		};
		ptr = ptr->proxima;
		if(de[0] != nome[0]){
			if (ptr == NULL){
				printf("\nNao encontramos nenhum contato\n");	
			};
			
		
		};
        
    }

};
struct contato* remover( long telefone) {
    struct contato* atual = primeira;
    struct contato* anterior = NULL;
    if(primeira == NULL) {
        return NULL;
    }
    while(atual->telefone != telefone) {
        if(atual->proxima == NULL) {
            return NULL;
        }
        else {
            anterior = atual;
            atual = atual->proxima;
        }
    }
    if(atual == primeira) {
        primeira = primeira->proxima;
    } else {
        anterior->proxima = atual->proxima;
    }
    return atual;

}

int main() {
	//Adicionando numeros de contatos aleatorios 
    adicionar(991686501, "Samuel Zanferdini Oliva");
    adicionar(988296172, "Lucas Balani Ferreira");
    adicionar(992301855, "Abner Walan Do Nascimento");
	adicionar(997871823, "Joao Victor Espag");
    adicionar(991442265, "Guilherme Otavio Da");
    adicionar(997946320, "Wallace Rian Ferreira");
    adicionar(997436984, "Karolaine Naiely Da");
    adicionar(999636266, "Matheus Jose Carneio");
	adicionar(991731339, "Bruno Fucherberger");
    adicionar(981526314, "Jeferson Ricardo Do");
   //mostrando a lista
    mostrar();
    
    //procurando por letra
    procurar("Z");
    //procurando por letra
    procurar("S");
    return 0;
	
	return 0;
}
