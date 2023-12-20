
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int i,j,lin,col,faosso=0,jogada=1,trigo=0,leite=1;
void inicializa(char campo[25][50])
{
    for(i=0; i<25; i++) //campo com espaços
    {
        for(j=0; j<50; j++)
        {
            campo[i][j]=' ';
        }
    }
    for(i=0; i<3; i++)
    {
        lin=rand()%25-1;
        col=rand()%50-2;
        campo[lin][col]='~';
        campo[lin][col-1]='~';
        campo[lin][col+1]='~';
        campo[lin+1][col]='~';
        campo[lin+1][col-1]='~';
        campo[lin+1][col+1]='~';

    }
    for(i=0; i<3; i++)
    {
        lin=rand()%25-2;
        col=rand()%50-1;
        campo[lin][col]='~';
        campo[lin-1][col]='~';
        campo[lin+1][col]='~';
        campo[lin][col-1]='~';
        campo[lin+1][col-1]='~';
        campo[lin-1][col-1]='~';
    }
    for(i=0; i<5; i++)
    {
        lin=rand()%25;
        col=rand()%50;
        if(campo[lin][col]==' ')
        {
            campo[lin][col]='t';
        }
        else
        {
            i--;
        }
    }
    for(i=0; i<11; i++)
    {
        lin=rand()%25;
        col=rand()%50;
        if(campo[lin][col]==' ')
        {
            campo[lin][col]='R';
        }
        else
        {
            i--;
        }
    }
    for(i=0; i<5; i++)
    {
        lin=rand()%25;
        col=rand()%50;
        if(campo[lin][col]==' ')
        {
            campo[lin][col]=-102;
        }
        else
        {
            i--;
        }
    }
}//fim inicializa
void imprime(char campo[25][50])
{
    printf("\n              1111111111222222222233333333334444444444\n");
    printf("    01234567890123456789012345678901234567890123456789\n");
    for(i=0; i<25; i++)
    {
        printf("[%2d]",i);
        for(j=0; j<50; j++)
        {
            printf("%c",campo[i][j]);
        }
        printf("\n");
    }
}//fim imprime
void fertilizar(char campo[25][50])
{
    printf("Fertizar broto de trigo digite linha ecoluna [separados por espaço]: ");
    scanf("%d %d",&lin,&col);
    getchar();
    if (faosso>0)
    {
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49))
        {
            if(campo[lin][col]=='t')
            {
                campo[lin][col]='T';
                faosso--;
                jogada++;
            }
            else
            {
                printf("coordenada nao possue broto de trigo\n");
            }
        }
        else
        {
            printf("coordenada invalida\n");
        }
    }
    else
    {
        printf("voce nao possue farinha de osso\n");
    }
}
void colher(char campo[25][50])
{
    printf("Colher trigo digite linha ecoluna [separados por espaco]: ");
    scanf("%d %d",&lin,&col);
    if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49))
    {
        if(campo[lin][col]=='T')
        {
            campo[lin][col]=' ';
            trigo++;
            jogada++;
        }
        else
        {
            printf("coordenada não possui (T)rigo\n");
        }
    }
    else
    {
        printf("coordenada invalida\n");
    }
}//fim colher
void ordenhar(char campo[25][50])
{
    printf("Ordenhar cabra, digite linha ecoluna [separados por espaco]: ");
    scanf("%d %d",&lin,&col);
    if ((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49))
    {
        if(campo[lin][col]=='U')
        {
            campo[lin][col]=(-102);
            leite++;
            jogada++;
        }
        else
        {
            printf("coordenada nao possui cabra sem chifre\n");
        }
    }
    else
    {
        printf("coordenada invalida\n");
    }
}//fim ordenhar
void alimentar(char campo [25][50])
{
    int lin5, col5, asci=-102,trigo;
    printf("\nDIGITE O ESPACO QUE VOCE DESEJA ALIMENTAR:\n");
    scanf("%d",&lin5);
    scanf("%d",&col5);
    if((col5<50)&&(col5>-1)&&(lin5<25)&&(lin5>-1))
    {
        if(campo[lin5][col5]=='u')
        {
            if(leite>0)
            {
                campo[lin5][col5]=(-102);
                leite=(leite-1);
                jogada++;
            }
        }
        else
        {
            if(campo[lin5][col5]==-102)
            {
                if(trigo>0)
                {
                    if(campo[lin5][(col5+1)]==-102)
                    {
                        if((campo[lin5][(col5+2)]==' ')&&(campo[lin5][(col5+3)]==' '))
                        {
                            campo[lin5][(col5+2)]='u';
                            jogada++;
                            trigo=(trigo-1);
                        }//end if
                        else
                        {
                            printf("NAO EXISTE CABRA NESSE ESPACO");
                        }//end else
                    }//end if(coluna+1);
                    else
                    {
                        printf("NESSA POSICAO NAO TEM CABRA COM CHIFRE");
                    }
                }//end if(asci);
                else
                {
                    printf("SEM SALDO DE TRIGO");
                }
            }//end if(trigo);
            else
            {
                printf("NAO EXISTE CABRA NESSE ESPACO");
            }
        }//end else
    }//end if
    else
    {
        printf("voce saiu fora da campo");
    }
}//end void alimentar
//fim alimentar

void mover(char campo[25][50])
{
    int lin1,col1,lin2,col2;
    printf("Mover, selecione uma Cabra/Cabrito, digite linha ecoluna [separados por espaco]: ");
    scanf("%d %d",&lin1,&col1);
    if((lin1>=0)&&(lin1<=24)&&(col1>=0)&&(col1<=49))
    {
        if((campo[lin1][col1]==-102)||(campo[lin1][col1]=='u')||(campo[lin1][col1]=='U'))
        {
            printf("Selecione para onde mover a Cabra/Cabrito, digite linha ecoluna [separados por espaco]: ");
            scanf("%d %d",&lin2,&col2);
            if((lin2>=0)&&(lin2<=24)&&(col2>=0)&&(col2<=49))
            {
                if((abs(lin1-lin2)<=1)&&(abs(col1-col2)<= 1))
                {
                    if((campo[lin2][col2]=='R')&&(campo[lin1][col1]==-102))
                    {
                        campo[lin2][col2]='U';
                        campo[lin1][col1]=' ';
                        faosso++;
                    }
                    else
                    {
                        if(campo[lin1][col2]==' ')
                        {
                            campo[lin2][col2]=campo[lin1][col1];
                            campo[lin1][col1]=' ';
                        }





                        else

                        {

                            printf("A coordenada de destino nao esta vazia\n");
                        }
                         jogada++;
                    }

                }
                else
                {
                    printf("A coordenada precisa estar ao redor da Cabra/cabrito\n");
                }

            }
            else
            {
                printf("coordenada invalida\n");
            }

        }
        else
        {
            printf("coordenada nao possui Cabra/cabrito\n");
        }
    }
    else
    {
        printf("coordenada invalida\n");
    }
}
//fim mover
void noite(char campo[25][50])
{
    for(i=0; i<25; i++)
    {
        for(j=0; j<50; j++)
        {
            if(campo[i][j]=='R')
            {
                campo[i][j]=' ';
            }
        }
    }
    for(i=0; i<11; i++)
    {
        lin=rand()%25;
        col=rand()%50;
        if((campo[lin][col]==' ')||(campo[lin][col]=='u')||(campo[lin][col]=='U')||(campo[lin][col]==-102))
        {
            campo[lin][col]='R';
        }
        else
        {
            i--;
        }
    }
    for(i=0; i<25; i++)
    {
        for(j=0; j<50; j++)
        {
            if((campo[i][j]==' ')&&(rand()%1250==0))
            {
                campo[i][j]='t';
            }
            if((campo[i][j]=='U')&&(rand()%100<30))
            {
                campo[i][j]=-102;
            }

        }
    }
}
int main(int argc, char*argv[])
{
    char campo[25][50],op;
    srand(time(NULL));
    inicializa(campo);
    while (op != 'A')
    {
        imprime(campo);
        printf("Leite: %d Trigo: %d Farinha de osso: %d  |jogadas: %d\n", leite, trigo, faosso, jogada);
        printf("Escolha (f)etilizar, (c)olher, (o)rdenhar, (a)alimentar, (m)over (s)air ");
        scanf("%s",&op);
        switch(op)
        {
        case('f'):
            fertilizar(campo);
            break;
        case('c'):
            colher(campo);
            break;
        case('o'):
            ordenhar(campo);
            break;
        case('a'):
            alimentar(campo);
            break;
        case('m'):
            mover(campo);
            break;
        case('s'):
            noite(campo);
            break;
        }
        if(jogada>7)
        {
            imprime(campo);
            noite(campo);
            jogada=1;
        }
    }
    return 0;
}//fim main
