#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int **matrizEntrada;                //matriz com os dados do page rank
    float *aponta;                      //para quem aponta a linha da matriz
    float *pageRank;                    //guarda os valores do pagerank
    int tamanhoMatriz;
    int i,j;
    float temporario=0;                 //vai guardar o valor para a multiplicaçao do pagerank
    char intermediario[100];            //variavel intermediaria para saber tamanho da matriz
    scanf("%s",intermediario);
    tamanhoMatriz = strlen(intermediario);  //guarda o tamanho da matriz
    //aloca as variaveis
    matrizEntrada=calloc(tamanhoMatriz,sizeof(int*));
    aponta=calloc(tamanhoMatriz,sizeof(float));
    pageRank=calloc(tamanhoMatriz, sizeof(float));
    for(i=0;i<tamanhoMatriz;i++){
        matrizEntrada[i]=calloc(tamanhoMatriz, sizeof(int));    //aloca as linha da matriz
    }
    //coloca dados na matriz usando um vetor de caracteres como interemediario
    for(i=0;i<tamanhoMatriz;i++){
        for(j=0;j<tamanhoMatriz;j++){
            matrizEntrada[i][j]=intermediario[j]-48;    //transforma o caractere do nomero no numero
            aponta[i]=aponta[i]+matrizEntrada[i][j];    //guarda para quantos ele aponta
        }
        pageRank[i]=1;
        if(i==tamanhoMatriz-1)break;
        scanf("%s",intermediario);
    }
    //faz o page rank
    for(int k=0;k<100;k++){
        for(i=0;i<tamanhoMatriz;i++){
            for(j=0;j<tamanhoMatriz;j++){
                if(matrizEntrada[j][i]==1){
                    temporario=temporario+(pageRank[j]/aponta[j]);  //faz o calculo do page rank e incrementa no temporario
                }
            }
            pageRank[i]=0.15+(0.85*temporario);     //termina o calculo do page rank
            temporario=0;
        }
    }
    //printa todos valores do pagerank
    for(i=0;i<tamanhoMatriz;i++){
        printf("%.4f\n",pageRank[i]);
    }
    return 0;
}
