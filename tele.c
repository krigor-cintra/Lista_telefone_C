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
			sleep(2);
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
	long tel;
	int opcao,op;
	char nome[25];
	
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
   
   do {
   	system ("cls");
   	  printf("---###--LISTA DE CONTATOS--###---\n");

          printf("\n       ####### MENU #######\n\n");
          printf("   ( 1 ) CADASTRAR CONTATO \n");
          printf("   ( 2 ) CONSULTAR UM CONTATO POR LETRA \n");
          printf("   ( 3 ) LISTAR TODOS OS CONTATOS \n");
          printf("   ( 4 ) EXCLUIR UM CONTATO \n");
          printf("   ( 5 ) SAIR \n");
          
           printf("\n ESCOLHA UMA OPCAO:");
          scanf("%d",&opcao);
          fflush(stdin);
          
          switch(opcao) {
          	case 1:
          		printf("\n--**** CADASTRO DE CONTATO ****--");
          		 printf("\n NOME:");
          		 scanf("%s",&nome);
          		 printf("\n TEL:");
          		 scanf("%i",&tel);
          		 adicionar(tel, nome);
          		 fflush(stdin);
                 break;
            case 2:
            	system("cls");
                         printf("\n--**** CONSULTAR UM CONTATO POR LETRA ****--");
                         printf("\nPESQUISAR:");
                         scanf("%s",&nome);
                         procurar(nome);
                        system("pause");
                       break;
            case 3:
            	mostrar();
            	system("pause");
                       break;
            case 4:
            	printf("\n--###----EXCLUIR CONTATO----###--\n");
                printf("\nINFORMA O TELEFONE: ");
                scanf("%i",&tel);
                remover(tel);
                system("pause");
                break;
            case 5:
            	system ("cls");
                  printf ("\n     Informações dos Alunos:\n\n");
                  printf ("     RA: 202002220112 - BRUNO FUCHERBERGER PEREIRA\n");
                  printf ("     RA: 202002346906 - Matheus JOSE CARNEIRO DOS SANTOS\n");
                  printf ("     RA: 202002394961 - Kirgor G.\n");
                  printf ("     Unidade: ESTACIO - RIBEIRÃO PRETO\n");
                  printf ("     Curso: Ciência da Computacao \n");
                  printf ("     Disciplina: ESTRUTURA DE DADOS EM C\n");
                  printf ("     Professora: Samuel\n\n");
             

                  getchar();
                  printf("\nObrigado pela visita , Volte Sempre!!\n");
                  system("exit");
                  break;
		  }

   }while(opcao!=5);
   
   //mostrando a lista
   
    mostrar();
    
    
    
    //procurando por letra
    procurar("Z");
    //procurando por letra
    procurar("S");
    return 0;
	
	return 0;
}
