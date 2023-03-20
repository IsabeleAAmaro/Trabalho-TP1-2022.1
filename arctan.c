#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float x;
    int i;
    float somatorio = 0.0;
    float expoente;
    float potenciacao;
    int aux = 1;

    do {
        printf("\nDigite o valor de x: ");
        scanf("%f", &x);
    if(x < 0) {
        x *= (-1);
    }
   
    if(x >= 1) {
        printf("Valor inválido, digite novamente.");
        }
    }while(x >= 1);

    do{
        printf("\nDigite o valor de N:  ");
        scanf("%d", &n);
    if(n < 0) {
            printf("Valor inválido, digite novamente.");
        }
    }while(n < 0);

    for (i = 0; i <= n; i++) {
        potenciacao = 1.0;

        expoente = (2 * i + 1);

        while (expoente != 0) {
        potenciacao *= x;
        expoente--;
    }
        if(aux%2 == 0) {
            potenciacao *= (-1);
        }
        somatorio += potenciacao / (2 * i + 1);
        aux++;
    }
    printf("\nResultado: %f", somatorio);
}
