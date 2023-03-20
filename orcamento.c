#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculaOrcamento (char estacao, char tipo_imovel, float TamApartamento, float TamCasa, int pe, int elec, int pin, int tec,
                         float *peDiaria, float *elecDiaria, float *pinDiaria, float *tecDiaria, float *aju1D, float *aju2D, float *aju3D,
                         float *aju4D, float *ajuste, float *mao_de_obra, float *obra_bruta, float *ajuste_porcentagem);

float calculaValorTotal(float orcamento, int parcelas, char pagamento, float *desconto, float *juros, float *mensalidade);

int main() {
    int loop_float = 1;
    int loop_char = 0;
    int parcelas;
    float parcela_potencia;
    char estacao, tipo_imovel, pagamento;
    int pe, elec, pin, tec;
    float aju1D, aju2D, aju3D, aju4D;
    float peDiaria, elecDiaria, pinDiaria, tecDiaria;
    float TamApartamento, TamCasa, obra_bruta, ajuste_porcentagem, ajuste;
    float mao_de_obra;
    float orcamento, mensalidade, valor_total;
    float juros, desconto;

    do{
        printf("\nDigite a quantidade de horas trabalhadas pelo pedreiro: ");
        scanf("%d", &pe);

        if (pe < 0) {
            loop_float =  1;
            printf("\nValor Inválido, digite novamente.");
        } else {
            loop_float = 0;
        }
    }while(loop_float == 1);


    do{
        printf("\nDigite a quantidade de horas trabalhadas pelo técnico de Ar-condicionado: ");
        scanf("%d", &tec);
        loop_float = 0;

        if (tec < 0) {
            loop_float =  1;
            printf("\n\nValor Inválido, digite novamente.");
        }
    }while(loop_float == 1);

    do{
        printf("\nDigite a quantidade de horas trabalhadas pelo pintor: ");
        scanf("%d", &pin);
        loop_float = 0;

        if (pin < 0) {
            loop_float =  1;
            printf("\nValor Inválido, digite novamente.");
        }
    }while(loop_float == 1);

    do{
        printf("\nDigite a quantidade de horas trabalhadas pelo eletricista: ");
        scanf("%d", &elec);
        loop_float = 0;

        if (elec < 0) {
            loop_float =  1;
            printf("\nValor Inválido, digite novamente.");
        }
    }while(loop_float == 1);

    do{
        printf("\nDigite em qual ambiente será feita a instalação (C para casa e A para apartamento): ");
        getchar();
        scanf("%c", &tipo_imovel);

        switch (tipo_imovel) {
            case 'c':
            case 'C':
                do {
                    loop_char = 0;
                    printf("\nDigite quantos metros cúbicos (m³) tem o ambiente: ");
                    scanf("%f", &TamCasa);

                    if (TamCasa < 0) {
                        printf("\nValor inválido, digite novamente.");
                    }
                } while (TamCasa < 0);
                break;

                case 'A':
                case 'a':
                    do {
                        loop_char = 0;
                        printf("\nDigite quantos metros quadrados (m²) tem o ambiente: ");
                        scanf("%f", &TamApartamento);

                        if(TamApartamento < 0) {
                            printf("Valor inválido, digite novamente.");
                        }
                    }while (TamApartamento < 0);
                    break;

                default:
                loop_char = 1;
                printf("\nOpção inválida, digite novamente.");
                break;
            }
    }while(loop_char == 1);

    do{
        printf("\nDigite a estação do ano: ");
        estacao = getchar();
        estacao = getchar();

        switch (estacao) {
            case 'v':
                ajuste = 0.40;
                loop_char = 0;
            break;
            case 'V':
                ajuste = 0.40;
                loop_char = 0;
            break;

            case 'I':
                ajuste = -0.1;
                loop_char = 0;
            break;
            case 'i':
                ajuste = -0.1;
                loop_char = 0;
            break;

            default:
                loop_char = 1;
                printf("\nOpção inválida, digite novamente.");
            break;
            }
    }while(loop_char == 1);

    do{
        printf("\nDigite a forma de pagamento: ");
        scanf(" %c", &pagamento);
        getchar();

        switch (pagamento) {

            case 'v':
            loop_char = 0;
            break;

            case 'V':
            loop_char = 0;
            break;

            case 'p':
                loop_char = 0;
                printf("\nDigite o número de parcelas: ");
                scanf("%d", &parcelas);

                if(parcelas < 0) {
                    loop_char = 1;
                    printf("Valor inválido, digite novamente.");
                }

                if(parcelas == 0) {
                    printf("\nLogo, o pagamento será a vista.");
                    loop_char = 0;
                }
                break;

            case 'P':
                loop_char = 0;
                printf("\nDigite o número de parcelas: ");
                scanf("%d", &parcelas);

                if(parcelas < 0) {
                    loop_char = 1;
                    printf("Valor inválido, digite novamente.");
                }

                if(parcelas == 0) {
                    printf("\nLogo, o pagamento será a vista.");
                    loop_char = 0;
                }
                break;

            default:
                loop_char = 1;
                printf("\nOpção inválida, digite novamente.");
            break;
        }
    }while(loop_char == 1);

    orcamento = calculaOrcamento(estacao, tipo_imovel, TamApartamento, TamCasa, pe, elec, pin, tec, &peDiaria, &elecDiaria, &pinDiaria, &tecDiaria, &aju1D, &aju2D, &aju3D, &aju4D, &ajuste, &mao_de_obra, &obra_bruta, &ajuste_porcentagem);

    valor_total = calculaValorTotal(orcamento, parcelas, pagamento, &desconto, &juros, &mensalidade);

    printf("\t******* Informações *******\n\n");
    
    printf("Valor da mão de obra do pedreiro: R$%.2f\n", peDiaria);
    printf("Valor da mão de obra do eletricista: R$%.2f\n", elecDiaria);
    printf("Valor da mão de obra do técnico em Ar-condicionado: R$%.2f\n", tecDiaria);
    printf("Valor da mão de obra do pintor: R$%.2f\n", pinDiaria);
    printf("Valor da mão de obra do ajudante do pedreiro: R$%.2f\n", aju1D);
    printf("Valor da mão de obra do ajudante do eletricista: R$%.2f\n", aju2D);
    printf("Valor da mão de obra do ajudante do técnico em Ar-condicionado: R$%.2f\n", aju3D);
    printf("Valor da mão de obra do ajudante do pintor: R$%.2f\n", aju4D);
    printf("Valor total da mão de obra: R$%.2f\n", mao_de_obra);
    printf("Valor da obra bruta: R$%.2f\n", obra_bruta);

    if (estacao == 'v' || estacao == 'V') {
        printf("Ajuste sobre a mão de obra e obra bruta: + 40%%\n");
    }

    if (estacao == 'i'|| estacao == 'I') {
        printf("Ajuste sobre a mão de obra e obra bruta: - 10%%\n");
    }

    printf("Valor do orçamento: R$%.2f\n", orcamento);

    if (pagamento == 'v'){
        printf("Desconto: R$%.2f\n", orcamento - valor_total);
        printf("Valor total: R$%.2f\n", valor_total);
        printf("Juros: Não se aplica.");
    }

    if (pagamento == 'V'){
        printf("Desconto: R$%.2f\n", orcamento - valor_total);
        printf("Valor total: R$%.2f\n", valor_total);
        printf("Juros: Não se aplica.");
    }

    if (pagamento == 'p'){
        printf("Número de parcelas: %d\n", parcelas);
        printf("Valor da mensalidade: R$%.2f\n", mensalidade);
        valor_total = mensalidade * parcelas;
        printf("Valor total das mensalidades: R$%.2f\n", valor_total);
        printf("Juros: R$%.2f\n", valor_total - orcamento);
    }

    if (pagamento == 'P'){
        printf("Número de parcelas: %d\n", parcelas);
        printf("Valor da mensalidade: R$%.2f\n", mensalidade);
        valor_total = mensalidade * parcelas;
        printf("Valor total das mensalidades: R$%.2f\n", valor_total);
        printf("Juros: R$%.2f\n", valor_total - orcamento);
    }
}

float calculaOrcamento (char estacao, char tipo_imovel, float TamApartamento, float TamCasa, int pe, int elec, int pin, int tec,
                         float *peDiaria, float *elecDiaria, float *pinDiaria, float *tecDiaria, float *aju1D, float *aju2D, float *aju3D,
                         float *aju4D, float *ajuste, float *mao_de_obra, float *obra_bruta, float *ajuste_porcentagem) {

    float orcamento_local;

        *peDiaria = ((float)pe * 1.37);

        *elecDiaria = ((float)elec * 1.62);

        *pinDiaria = ((float)pin * 1.5);

        *tecDiaria = ((float)tec * 1.87);

        *aju1D = ((float)pe * 0.62);

        *aju2D = ((float)elec * 0.62);

        *aju3D = ((float)pin * 0.62);

        *aju4D = ((float)tec * 0.62);

        *mao_de_obra = (*peDiaria + *elecDiaria + *tecDiaria + *pinDiaria + *aju1D + *aju2D + *aju3D + *aju4D);

        switch (tipo_imovel) {
        case 'c':
            *obra_bruta = (TamCasa * 40.00);
            break;

        case 'a':
            *obra_bruta = (TamApartamento * 50.00);
            break;

        case 'A':
            *obra_bruta  = (TamApartamento * 50.00);
            break;

        case 'C':
            *obra_bruta = (TamCasa * 40.00);
            break;

        default:
        break;
        }

        switch (estacao) {

        case 'v':
            *ajuste = 0.40;
           
            break;

        case 'V':
            *ajuste = 0.40;
            break;

        case 'i':
            *ajuste = -0.1;
            break;

        case 'I':
            *ajuste = -0.1;
            break;

        default:
            *ajuste = 0.0;
        break;
    }

    orcamento_local =  (*mao_de_obra + *obra_bruta) * (1 + *ajuste);
    return orcamento_local;

}

float calculaValorTotal(float orcamento, int parcelas, char pagamento, float *desconto, float *juros, float *mensalidade) {
 float potencia = (float)parcelas / 12.00;
 float valor_total;

    switch (pagamento) {
        case 'v':
            valor_total = (orcamento - (orcamento * 0.15));
            break;

        case 'V':
            valor_total = (orcamento - (orcamento * 0.15));
            break;

        case 'p':
            *mensalidade = ((float)orcamento * pow(1.12, potencia)) / (float)parcelas;
            valor_total = *mensalidade * parcelas;
            break;

        case 'P':
            *mensalidade = ((float)orcamento * pow(1.12, potencia)) / (float)parcelas;
            valor_total = *mensalidade * parcelas;
            break;

        default:
        break;
    }
        return valor_total;
}