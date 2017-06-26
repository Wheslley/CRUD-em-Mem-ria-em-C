#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time
{
    int codigo;
    char nome [15];
    int anoFundacao;
    struct time *proximo;
    struct time *anterior;
};
time *inicioTime = NULL;
time *atualTime = NULL;

int exibirMenu ();
void cadastrarTime();
time *localizaTime (int cod);
void listarTime (time *pont);
void editarTime ();
void excluirTime ();

int main()
{
    int opcao = -1;
    while (opcao != 0)
    {
        opcao = exibirMenu ();
        if (opcao == 1)
        {
            cadastrarTime();
        }
        else if (opcao == 2)
        {
             listarTime (inicioTime);
        }
        else if (opcao == 3)
        {
             editarTime ();
        }
        else if (opcao == 4)
        {
             excluirTime ();
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int exibirMenu ()
{
    int op;
    printf("\n\n ESCOLHA UMA OPCAO: ");
    printf("\n 0 - SAIR");
    printf("\n 1 - CADASTRAR UM TIME");
    printf("\n 2 - LISTAR TIME");
    printf("\n 3 - EDITAR TIME");
    printf("\n 4 - EXCLUIR TIME");
    printf("\n OPCAO: ");
    scanf("%d", &op);

    return op;
}

void cadastrarTime()
{
    time *ponteiro = NULL;
    ponteiro = (time*) malloc (sizeof(time));

    printf("\n Digite o nome do time: ");
    fflush(stdin);
    gets(ponteiro->nome);
    printf("\n Digite o codigo do time: ");
    scanf("%d", &ponteiro->codigo);
    printf("\n Digite o ano de fudacao do time: ");
    scanf("%d", &ponteiro->anoFundacao);
    ponteiro->proximo = NULL;

    if (inicioTime == NULL)
    {
        inicioTime = ponteiro;
        ponteiro->anterior = NULL;
    }
    else
    {
        ponteiro->anterior = atualTime;
        atualTime->proximo = ponteiro;
    }
    atualTime = ponteiro;

    printf("\n           CADASTRO REALIZADO COM SUCESSO!!");
}

time *localizaTime (int cod)
{
     time *ponteiro = inicioTime;
     while (ponteiro != NULL)
     {
          if (ponteiro->codigo == cod)
             return ponteiro;
          ponteiro = ponteiro->proximo;
     }
     return ponteiro;
}

void listarTime (time *pont)
{
     if (pont != NULL)
     {
         printf("\n\n Nome do time: %s", pont->nome);
         printf("\n Fundado em: %d", pont->anoFundacao);
         printf("\n Codigo: %d", pont->codigo);
         listarTime (pont->proximo);
     }
}

void editarTime ()
{
     int cod, cont=0;
     int achouTime = 0;
     time *ponteiro = inicioTime;
     printf("\n Digite o codigo do time que deseja editar: ");
     scanf("%d", &cod);

    while (cont == 0)
     {

           if(ponteiro->codigo == cod)
           {
               ++cont;
                printf("\n Digite o nome do time: ");
                fflush(stdin);
                gets(ponteiro->nome);
                printf("\n Digite o codigo do time: ");
                scanf("%d", &ponteiro->codigo);
                printf("\n Digite o ano de fudacao do time: ");
                scanf("%d", &ponteiro->anoFundacao);
           }
           ponteiro = ponteiro->proximo;
     }

    if(cont == 0)
    {
        printf("Nenhum time encontrado!!");
    }
    else
    {
        printf("Edicao realizada com sucesso!!");
    }
}

void excluirTime ()
{
     int cod;
     int achouTime = 0;
     time *ponteiro = inicioTime;
     printf("\n Digite o codigo do time que deseja excluir: ");
     scanf("%d", &cod);

     while (ponteiro != NULL)
     {

           if(ponteiro->codigo == cod)
           {

                if (ponteiro->anterior == NULL) //PRIMEIRO ELEMENTO
                {
                    if(ponteiro->proximo == NULL)
                    {
                        inicioTime = NULL;
                    }
                    else
                    {
                        inicioTime->proximo = ponteiro->proximo;
                        inicioTime->anterior = NULL;
                    }
                }
                else if (ponteiro->proximo == NULL) /// ULTIMO ELEMENTO
                {

                     atualTime = ponteiro->anterior;
                     atualTime->proximo = NULL;
                }
                else /// outros elementos
                {

                     ponteiro->anterior->proximo = ponteiro->proximo;
                     ponteiro->proximo->anterior = ponteiro->anterior;
                }
                achouTime = 1;
           }
           ponteiro = ponteiro->proximo;
     }

     if (ponteiro == NULL && achouTime == 0)
        printf("\n     NENHUM TIME CADASTRADO COM ESTE CODIGO!!");
     else
          printf("\n     TIME EXCLUIDO COM SUCESSO!! ");
}
