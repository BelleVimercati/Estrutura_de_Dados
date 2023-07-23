#include <stdio.h>
#include "ArvoreBinariaBusca.h"

typedef struct software{
    int identificador;
    char desenvolvedor[15];
} Software;

typedef struct hardware{
    int identificador;
    char desenvolvedor[15];
} Hardware;

int menu(){
    int op;
    printf("\n........................................\n");
    printf("1 - Inserir um elemento\n");
    printf("2 - Remover um elemento\n");
    printf("3 - Verificar se elemento existe\n");
    printf("4 - Buscar elemento\n");
    printf("5 - Imprimir largura\n");
    printf("7 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    printf("\n........................................\n");

    return op;
   
}

void *sistema(){ //menuzinho para conseguir inserir certinho
    int op;
    void *item;

    printf("1 - Software\n");
    printf("2 - Hardware\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
    {
        Software *s = (Software*)malloc(sizeof(Software));

        printf("Digite o identificador : ");
        scanf("%d", &s->identificador);
        printf("Digite o desenvlvedor: ");
        scanf("%s", &s->desenvolvedor);

        item = (Software *)s;

        return item;
    };
    
    case 2:
    {
        Hardware *h = (Hardware *)malloc(sizeof(Hardware));

        printf("Digite o identificador : ");
        scanf("%d", &h->identificador);
        printf("Digite o desenvlvedor: ");
        scanf("%s", &h->desenvolvedor);

        item = (Hardware*)h;

        return item;
    };

    default:
        break;
    }


}



int main(){

    Arvore a = inicializar();

    while(1){
        switch (menu()){
        case 1:
            int chave;
            printf("Digite a chave: ");
            scanf("%d", &chave);
            void * item = sistema();
            a = inserirAbb(a, chave, item, (sizeof(item)));

            break;
        
        default:
            break;
        }
    }
    

    return 0;
}