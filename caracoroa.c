#include <stdio.h>
#include <stdlib.h>

int main() {
    int maria;
    int joao;
    int maria_total;
    int maria_vitorias;
    int joao_total;
    int joao_vitorias;


    int rodadas, resultados;
    int i;
    int abortar = 0;

do {
    do {

    printf("Digite o número de rodadas:\n");
    scanf("%d", &rodadas);
    abortar = 0;

    maria = 0;
    joao = 0;

        for(i = 0; i < rodadas; i++) {
           
            if(abortar == 0) {
           
            printf("Digite o resultado da rodada:\n");
            scanf("%d", &resultados);

            switch (resultados) {
            case 0:
                maria++;
                maria_vitorias++;
                break;

            case 1:
                joao++;
                joao_vitorias++;
                break;            
               
                default:
                printf("Rodada Abortada! tente novamente.\n");
                abortar = 1;
                break;
            }
        }
    }

    if(rodadas == 0) {
        printf("Ninguém jogou!\n");
    }
   
    if (abortar == 0) {
        printf("Maria venceu %d vez(es) e João venceu %d vez(es)\n", maria, joao);
    }

    joao_total =+ joao_vitorias;
    maria_total =+ maria_vitorias;

    printf("Ao longo dos anos, Maria venceu %d vez(es) e João venceu %d vez(es)\n", maria_total, joao_total);

    }while(rodadas != 0);
}while (abortar == 0);
}
