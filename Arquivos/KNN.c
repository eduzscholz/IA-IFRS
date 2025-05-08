#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int main()
{
    double *x,*y;       //vetores x y
    double distaciaXY;  //distancia entre pontos
    int i=1,j,k;
    int knn;            //guarda o mais proximo KNN
    double menorDistancia=-1;   //guarda a menor distancia encontrada
    x=calloc(i,sizeof(double)); //aloca o espaco para 1 double
    y=calloc(i,sizeof(double));
    while(scanf("%lf %lf\n",&x[i-1],&y[i-1])!=EOF){ //busca entrada e realoca conforme sao colocadas
        x=realloc(x,sizeof(double)*(i+1);
        y=realloc(y,sizeof(double)*(i+1);
        i++;
    }
    k=i-1;      //bota no k a ultima posiçao nos ponteiros
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            if(i!=j){
                distanciaXY = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));      //calcula a distancia entre os pontos
                if(distaciaXY<menorDistancia || menorDistancia==-1){        //verifica se nova distancia e menor q a guardada
                    menorDistancia=distaciaXY;                              //substitui a nova menor distancia
                    knn=j;                                                  //guarda a posiçao do menor atual
                }
            }
        }
        printf("%d\n",knn);
        menorDistancia=-1;
    }
    free(y);
    free(x);
    return 0;
}
