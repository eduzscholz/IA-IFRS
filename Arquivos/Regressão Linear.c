#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double MXY;     //media das entradas*saidas
    double MX;      //media das entradas
    double MY;      //media das saidas
    double MX2;     //media do quadrado
    double X2M;     //quadrado da media
}medias;

typedef struct{
    double X;
    double Y;
}vetor;

typedef struct{
    double A;
    double B;
}coeficientes;

medias calculoMedias(vetor* vet, int i){
    medias med;
    med.MX=0;
    med.MY=0;
    med.MX2=0;
    med.MXY=0;
    int j;
    for(j=0;j<i;j++){
        med.MX=med.MX+vet[j].X;
        med.MY=med.MY+vet[j].Y;
        med.MXY=med.MXY+(vet[j].X*vet[j].Y);
        med.MX2=med.MX2+(vet[j].X*vet[j].X);
    }
    med.MX=(med.MX/i);
    med.MY=(med.MY/i);
    med.MXY=(med.MXY/i);
    med.MX2=(med.MX2/i);
    med.X2M=(med.MX*med.MX);
    return med;
}

coeficientes calculoRegressao(medias med){
    coeficientes coef;
    coef.A=((med.MXY-(med.MX*med.MY))/(med.MX2-med.X2M));
    coef.B=(med.MY-(coef.A*med.MX));
    return coef;
}

int main()
{
    vetor* vet;
    medias med;
    coeficientes coef;
    int i=0;
    vet = malloc(sizeof(vetor));
    while(scanf("%lf %lf\n",&vet[i].X,&vet[i].Y)!=EOF){
        i++;
        vet=realloc(vet,sizeof(vetor)*(i+1));
    }
    med=calculoMedias(vet,i);
    coef=calculoRegressao(med);
    printf("%.4lf\n%.4lf",coef.A,coef.B);
    free(vet);
    return 0;
}
