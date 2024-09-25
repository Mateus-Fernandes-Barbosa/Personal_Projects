#include <ctype.h>
#include <iostream>
#include <math.h>
using namespace std;

class Elemento{
    public:
    int qtd;
    float elemento;

    Elemento(){
        this->qtd = 0;
        this->elemento = -1;
    }
};



int main (void){
     float x [] = {51, 51, 52, 52, 52, 52, 52, 53, 53, 53, 53, 53, 53, 54, 54, 54, 54, 54, 54, 54, 54, 54, 55, 55, 55, 55, 55, 55, 55, 55, 55, 56, 56, 56, 56, 56, 56, 57, 57, 57, 57, 57, 58, 58,
59}; //Alterar qual o conjunto de números para uma nova questão
    
    //Quantidade de elementos no conjunto
    int length = sizeof(x)/sizeof(int);
    printf("Lenght: %i\n", length);
    

    //Cálculo da Média
    double media = 0;
    for(int i = 0; i < length; i++){
        media += x[i];
    }
    media /= length;
    printf("Média: %.3f\n", media);


    //Cálculo da Moda
    Elemento *auxModa [length];
    for(int i = 0; i < length; i++){
        auxModa[i] = new Elemento();
    }
    int posVecAuxModa = 0;
    auxModa[posVecAuxModa]->elemento = x[0];
    auxModa[posVecAuxModa]->qtd++;
    for(int i = 0, j = i + 1; i < length - 1; i++, j++){
        if(x[i] == x[j]){
            auxModa[posVecAuxModa]->qtd++;
        }
        else{
            posVecAuxModa++;
            auxModa[posVecAuxModa]->elemento = x[j];
            auxModa[posVecAuxModa]->qtd++;
        }
    }
    int moda;
    for(int i = 0; auxModa[i + 1]->elemento != -1 ; i++){
        if(auxModa[i]->qtd > auxModa[i + 1]->qtd){
            moda = i;
        }
        else if(auxModa[i]->qtd > auxModa[i + 1]->qtd){
            moda = i + 1;
        }
    }
    printf("Moda: ");
    for(int i = 0; i < length; i++){
        if(auxModa[i]->qtd == auxModa[moda]->qtd && auxModa[i]->elemento != auxModa[moda]->elemento){
            printf("%.3f, ", auxModa[i]->elemento);
        }
    } 
    printf("%.3f\n", auxModa[moda]->elemento);
    for(int i = 0; i < length; i++){
        free(auxModa[i]);
    }


    //Cálculo da Mediana
    if(length % 2 != 0){
        printf("Mediana: %.3f\n", x[((length/2))]);
    }
    else{
        float mediana = x[length/2] + x[(length/2) - 1];
        mediana /= 2;
        printf("Mediana: %.3f\n",mediana);
    }

    //Cálculo do desvio padrão
    double acumulador = 0;
    for(int i = 0; i < length; i++){
        acumulador += pow((x[i] - media), 2);
    }
    acumulador /= (length - 1);
    acumulador = sqrt(acumulador);
    printf("Desvio padrão: %.3f\n",acumulador);

    //Cálculo dos Quartis
    float Quartil1, Quartil3;
    float posQuartil1 = 0, posQuartil3 = 0;
    posQuartil1 = (25 * length)/100;
    posQuartil3 = (75 * length)/100;
    if(posQuartil1 - (int) posQuartil1 > 0){
        posQuartil1 = x[(int) posQuartil1] + x[(int) posQuartil1 + 1];
        posQuartil1 /= 2;
        posQuartil3 = x[(int) posQuartil3] + x[(int) posQuartil3 + 1];
        posQuartil3 /= 2;
    }
    printf("Posição do Quartil 1#: %.3f\n",posQuartil1);
    printf("Posição do Quartil 3#: %.3f\n",posQuartil3);

    Quartil1 = x[(int) posQuartil1];
    printf("Quartil 1#: %.3f\n",Quartil1);
    Quartil3 = x[(int) posQuartil3];
    printf("Quartil 3#: %.3f\n",Quartil3);

    //Cálculo da Faixa Interquartil
    float faixaInterquartil = Quartil3 - Quartil1;
    printf("Faixa Interquartil: %.3f\n", faixaInterquartil);

    //Cálculo de Outlier inferior
    printf("A partir desse valor há outliers inferiores: %.3f\n", (Quartil1 - (faixaInterquartil * 1.5)));

    //Cálculo de Outlier inferior Extremo
    printf("A partir desse valor há outliers inferiores Extremos: %.3f\n", (Quartil1 - (faixaInterquartil * 3)));

    //Cálculo de Outlier superior
    printf("A partir desse valor há outliers superiores: %.3f\n", (Quartil3 + (faixaInterquartil * 1.5)));

    //Cálculo de Outlier superior Extremo
    printf("A partir desse valor há outliers superiores Extremos: %.3f\n", (Quartil3 + (faixaInterquartil * 3)));
}