#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int num;
    struct Node *prox;
};

void inicializa(struct Node *PILHA)
{
    PILHA-> prox = NULL;
}


struct Node* aloca()
{
    struct Node *novo = (struct Node *) malloc(sizeof(struct Node));
    return novo;
}

int vazia(struct Node *PILHA)
{
    if(PILHA ->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void empilha(struct Node *PILHA,int elemento)
{
    struct Node *novo = aloca();
    novo ->prox = NULL;
    novo ->num = elemento;

    struct Node *temp = PILHA->prox;

    if(vazia(PILHA))
    {
        PILHA->prox=novo;
        return;
    }
    else{
            while(temp->prox !=NULL)
            {
                temp = temp ->prox;
            }
            temp->prox = novo;
        }
}

int desempilha(struct Node *PILHA)
{
    if(vazia(PILHA))
    {
        printf("Pilha Vazia");
    }
    else
    {
        struct Node *ultimo,*penultimo;
        ultimo = PILHA->prox;
        penultimo = PILHA;
        while(ultimo->prox!=NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo ->prox;
        }
        penultimo ->prox = NULL;
        return ultimo->num;
    }
}

void exibe(struct Node *PILHA)
{   
    struct Node *tmp = PILHA->prox;
    while(tmp!=NULL)
    {
        printf("%d |",tmp->num);
        tmp = tmp->prox;
    }
}

char *infixaParaPosfixa (char inf[]) {
   char *posf; 
   char *pilha; int t;
   int N, i, j;

   N = strlen (inf);
   posf = malloc ((N+1) * sizeof (char));
   pilha = malloc (N * sizeof (char));
   t = 0;
   pilha[t++] = inf[0];
   for (j = 0, i = 1; inf[i] != '\0'; ++i) {
      // pilha[0..t-1] é uma pilha de bytes
       if(j==0)
         {
             posf[j++] ='E';
         }
      switch (inf[i]) {
         char x;
        
         case '(': pilha[t++] = inf[i];
                   break;
         case ')':


                   while ((x = pilha[--t]) != '(')   // n-and-a-half loop
                      posf[j++] = x;
                   break;
         case '+': 
         case '-': 

                                    posf[j++] = 'E';

                    while ((x = pilha[t-1]) != '(') { // n-and-a-half loop
                      posf[j++] = x;
                      --t;
                   }
                   pilha[t++] = inf[i];
                   break;
         case '*':
         case '/': 
                   posf[j++] = 'E';
 
                   while ((x = pilha[t-1]) != '(' 
                          && x != '+' && x != '-') { // n-and-a-half loop
                      posf[j++] = x;
                      --t;
                   }
                   pilha[t++] = inf[i];
                   break;
         default:  
                posf[j++] = inf[i];
      }
   }
   free (pilha);
   posf[j] = '\0';
   return posf;
}


int main()
{
    int op;
    struct Node *PILHA = (struct Node *) malloc (sizeof(struct Node));
    char vetor[100],*aux;
    scanf("%s",vetor);
    int tam = strlen(infixaParaPosfixa(vetor));
    aux = malloc(tam*sizeof(char));
    aux = infixaParaPosfixa(vetor);
    printf("%s",aux);
    printf("\n");
    for(int i=0; i<strlen(aux);i++)
    {
        if(aux[i] == 'E')
        {
            empilha(PILHA,0);
            printf("Pilha\n");           
            exibe(PILHA);

        }
        else if(aux[i] != '+' && aux[i] !='-' && aux[i] !='/' && aux[i] != '*')
        {
            int x = desempilha(PILHA);
            int num = x*10+aux[i]-'0';
            empilha(PILHA,num);
            printf("Pilha\n");           
            exibe(PILHA);

            
        }
        
        else if(aux[i] == '+' || aux[i] =='-' || aux[i] =='/' || aux[i] == '*')
        {
            int y = desempilha(PILHA);
            int x = desempilha(PILHA);
            if(aux[i] == '+')
            {
                int res = x+y;

                empilha(PILHA,res);
            }
            if(aux[i] == '-')
            {
                int res = x-y;
  
                empilha(PILHA,res);
            }
            if(aux[i] == '/')
            {
                int res = x/y;
                empilha(PILHA,res);
            }
            if(aux[i] == '*')
            {
                int res = x*y;
                empilha(PILHA,res);
            } 
            printf("Pilha\n");           
            exibe(PILHA);
        }
    }
    printf("Final\n");
    exibe(PILHA);
    



}
