#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cont=0;
struct data
{
    int dia;
    int mes;
    int ano;
};
struct info
{
    char nome[30];
    char sexo;
    struct data d;
    int idade;
    char doencas[300];
    int cod;
};
struct info i[10];
void idade()
{
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int n=(tm.tm_mday + (tm.tm_mon + 1)*100 + (tm.tm_year + 1900)*10000);
    n=n-((i[cont].d.ano*10000) +(i[cont].d.mes*100) +i[cont].d.dia);//(tm.tm_mday + (tm.tm_mon + 1)*100 + (tm.tm_year + 1900)*10000);
    i[cont].idade= n/10000;
}
void cadastrar()
{
    fflush(stdin);
    printf("digite o nome do cliente:");
    gets(i[cont].nome);
    printf("digite M para masculino ou F para feminino:");
    scanf("%c",&i[cont].sexo);
    printf("digite o dia de nascimento:");
    scanf("%d",&i[cont].d.dia);
    printf("digite o mes de nacimento:");
    scanf("%d",&i[cont].d.mes);
    printf("digite o ano de nacimento:");
    scanf("%d",&i[cont].d.ano);
    idade();
    printf("alguma doenca importante?");
    fflush(stdin);
    gets(i[cont].doencas);
    i[cont].cod=cont;
    cont++;
}
void listar()
{
    int lista=0;
    for(lista=0;lista<10;lista++)
    {
        if(strcmp(i[lista].nome,"")==0)
        {
            if(lista==0)
                printf("Nao ha clientes");
            break;
        }
        printf("Nome:%s\nSexo:%c\nData de nascimento:%d/%d/%d\nIdade:%d\nDoencas:%s\n\n",i[lista].nome,i[lista].sexo,i[lista].d.dia,i[lista].d.mes,i[lista].d.ano,i[lista].idade,i[lista].doencas);

    }
}
int buscar()
{
    int pesquisa;
    char Nome[30];
    printf("digite o nome do cliente\n");
    fflush(stdin);
    gets(Nome);
    for(pesquisa=0;pesquisa<10;pesquisa++)
    {
        if(strcmp(i[pesquisa].nome,Nome)==0)
        {
            return pesquisa;
        }
    }
    return -1;
}
int excluir(int n)
{
    int x;
    if(n==-1)
        return 0;
    else
    {
        for(x=i[cont].cod;x<9;x++)
        {
            strcpy(i[x].nome,i[x+1].nome);
            i[x].sexo=i[x+1].sexo;
            i[x].d.dia=i[x+1].d.dia;
            i[x].d.mes=i[x+1].d.mes;
            i[x].d.ano=i[x+1].d.ano;
            i[x].idade=i[x+1].idade;
            strcpy(i[x].doencas,i[x+1].doencas);
            if(strcmp(i[x+1].nome,"null"))
            {
                cont--;
                return 1;
            }
        }
        strcpy(i[9].nome,"null");
        i[9].sexo='n';
        i[9].d.dia=0;
        i[9].d.mes=0;
        i[9].d.ano=0;
        i[9].idade=0;
        strcpy(i[9].doencas,"null");
        return 1;
    }
}
int menu()
{
    int n;
    printf("selecione uma opcao:\n1. cadastrar cliente\n2. Buscar cliente\n3. listar clientes\n4. excluir cliente\n0. Sair\n");
    scanf("%d",&n);
    return n;
}
int main()
{
    int cod=-1;
    int n;
    while(cod!=0)
    {
    cod=menu();
    switch(cod)
    {
    case 1:
        cadastrar();
        break;
    case 2:
        n=buscar();
        if(n==-1)
            printf("cliente nao encontrado\n");
        else
            printf("Nome:%s\nSexo:%c\nIdade:%d\n\n",i[n].nome,i[n].sexo,i[n].idade);
        break;
    case 3:
        listar();
        break;
    case 4:
        if(excluir(buscar())==1)
        {
            printf("cliente excluido com sucesso\n\n");
            cont--;
        }
        else
            printf("cliente nao encontrado\n\n");
        break;
    }
    }
    return 0;
}

