#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int front;
    int back;
    int* data;
}filaInt;

filaInt *criaFilaInt(int tam){
    filaInt* f= malloc(sizeof(filaInt));
    f->data=malloc(sizeof(int)*tam);
    f->front=f->back=-1;
    return f;
}
void enqueue(filaInt *f, int valor, int tam){
    if(f->back!=f->front-1 && (f->front!=0||f->back!=9)){
        if(f->front==-1)f->front=f->back=0;
        else if(f->back==tam-1)f->back=0;
        else f->back++;
        f->data[f->back]=valor;
    }
}
int dequeue(filaInt *f, int tam){
    if(f->front!=-1){
        int temp=f->data[f->front];
        if(f->front==f->back)f->front=f->back=-1;
        else if(f->front==tam-1)f->front=0;
        else f->front++;
        return temp;
    }
    return -1;
}
bool estaVazia(filaInt *f,int tam){
    if(f->front==-1)return true;
    else return false;
}
void verificaMatriz(bool **matriz,int tam){ //funçao para verificar matriz
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void buscaEmLargura(bool **matriz,int s, int f, int tam){
    bool *marcado=calloc(tam,sizeof(bool));     //VARIAVEL PARA MARCAR OS QE JA FORAM PASSDOS
    int *origem=calloc(tam,sizeof(int));        //NO PIOR CASO ELE VAI TER QUE PERCORRER TODOS
    int v,i;
    filaInt* F=criaFilaInt(tam);
    marcado[s]=true;
    enqueue(F,s,tam);
    while(!estaVazia(F,tam)){
        v=dequeue(F,tam);
        if(v==f)break;
        for(i=0;i<tam;i++){
            if(matriz[v][i])    //VIZINHOS DE V
                if(!marcado[i]){
                    marcado[i]=true;
                    enqueue(F,i,tam);
                    origem[i]=v;
                }
        }
    }
    int *caminho=calloc(tam,sizeof(int));
    i=0;
    if(v==f){
        caminho[i]=v;
        while(v!=s){
            v=origem[v];
            i++;
            caminho[i]=v;
        }
    }
    for(;i>=0;i--)
        printf("%d\n",caminho[i]);
}

int main(){
    bool **matriz;
    int tam,i,j;
    char inter[100];
    //Botando a matriz de adjacencia no sistema
    scanf("%s",inter);
    tam = strlen(inter);
    matriz=calloc(tam,sizeof(int*));
    for(i=0;i<tam;i++)
        matriz[i]=calloc(tam, sizeof(int));
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(inter[j]=='1')
                matriz[i][j]=true;
            else
                matriz[i][j]=false;
        }
        if(i==tam-1)break;
            scanf("%s",inter);
    }
    //fim da solicitaçao da matriz
    buscaEmLargura(matriz,0,tam-1,tam);
    return 0;
}
