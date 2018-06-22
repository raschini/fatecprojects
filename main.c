#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "derivadas.h"
#include "integral.h"
#define h 0.0000000001// constante derivadas
#define n 1000// constante integral
#define E 0.000001 // constante Newton-Raphson

int main()
{
    int i, j;
    float x0=0.0;
    int opDer=0, opItg=0, op=0;
    /*>>>>inÍcio do while menu principal<<<*/
    do
    {
        opDer=0;
        opItg=0;
        op=0;
        system("CLS");
        printf("\t# # #  MENU  # # #\n\n");    //Menu
        printf("1 - Zero da funcao - Metodo Newton Raphson \n");
        printf("2 - Derivadas numericas\n");
        printf("3 - Integrais \n");
        printf("4 - SAIR \n");
        printf("\nDigite a opcao escolhida: ");
        fflush(stdin);
        scanf("%d",&op);

        /*#################################### INÍCIO DO SWITCH OP MENU PRINCIPAL ##########################################*/
        switch(op)
        {

        /*----------------------------------------------------------#CASO 1 opNEWTON RAPHSON - ZERO DA FUNÇÃO #------------------------------------------------------------------*/
        case 1:

            system("CLS");
            printf("- - -  Zero da Funcao - Metodo Newton Raphson  - - - \n");
            /*------------ GRÁFICO ---------------*/
            for(i = 0; i < 10; i++)
            {
                for(j = 0; j < 10; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        printf("\n\tY^");
                    }
                    else if((i == j) && (i > 0) && (i != 9))
                    {
                        printf(" \n\t |");
                    }
                    else if(i == 9 && j == 9)   //este else if do caractere '>', tem que estar antes do else if '_', se não a condiçao nao imprime, pois deve receber o valor antes
                    {
                        printf("  > X\n");
                    }
                    else if((i > 0) && (i == 9))
                    {
                        printf(" _");
                    }
                }

            }
            printf("\n\n");
            system ("pause");
            /* ----------GRÁFICO -------------*/
            /*--------------------------------------------------------Variáveis Newton------------------------------------------------------------*/
            float xn = 0.0;
            double erro = 0.0, x10 = 0.0, xk = 0.0;
            int k,opNew;
            double dnewton = 0.0,derxqnew=0.0,dercosnew=0.0;
            /*--------------------------------------------------------Variáveis Newton------------------------------------------------------------*/
            do
            {
                opNew = 0;
                k = 0;
                system("CLS");
                printf("\t - - -  Zero da Funcao - Metodo Newton Raphson  - - -\n\n");
                printf("1 - f (x) = x ^ 2 - 2");
                printf("\n2 - f (x) = 2x - cos (x)");
                printf("\n3 - f (x) = x * ln (x) - 1");
                printf("\n4 - Voltar ao menu anterior ");
                printf("\n\nDigite a opcao escolhida: ");
                fflush(stdin);
                scanf("%d",&opNew);

                switch(opNew)
                {

                /*======================================= INÍCIO DO SWITCH opNEWTON RAPHSON - ZERO DA FUNÇÃO==================================*/
                case 1:
                    printf("\n\nFuncao: f (x) = x ^ 2 - 2\nDerivada: f ' (x) = 2x");
                    printf("\nErro definido: %.6f",E);
                    printf("\n\nDigite o valor de xn (chute inicial): ");
                    scanf("%f", &xn);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");
                    for(k=0; k<50; k++)
                    {
                        if(k==0)
                            x10=xn;
                        derxqnew=derxqnewton(x10,h);
                        xk = x10-((pow(x10,2)-2)/derxqnew);
                        erro=((xk-x10)/xk); //calculo do erro
                        if (erro<0)
                        {
                            erro = erro*(-1);
                        }

                        printf("\n\nx%d:   %.16f\nErro: %.16f",k+1,xk,erro);
                        if(erro<=E)   //se erro for <= ao numero que o usuario entrou finaliza o laço
                        {
                            break;
                        }
                        else     //se nao, x0 recebe o valor de x
                        {
                            x10=xk;
                        }
                    }
                    printf("\n\n\nO Zero da funcao eh: x%d = %.16f\n",k+1, xk);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");
                    system("PAUSE");
                    fflush(stdin);
                    break;


                case 2:
                    printf("\n\nFuncao: f (x) = 2x - cos (x)\nDerivada: f ' (x) = 2 + sen (x)");
                    printf("\nE: %.6f",E);
                    printf("\n\nDigite o valor de x0 (chute inicial): ");
                    scanf("%f",&xn);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");
                    for(k=0; k<50; k++)
                    {
                        if(k==0)
                            x10=xn;
                        dercosnew=dercosnewton(x10,h);
                        printf("\n%.16f\n",dercosnew);
                        xk = x10-(((2*x10) - cos(x10)) / dercosnew);
                        erro=((xk-x10)/xk); //calculo do erro
                        if (erro<0)
                        {
                            erro = erro*(-1);
                        }

                        printf("\n\nx%d: %.16f\nErro: %.16f",k+1,xk,erro);
                        if(erro<=E)   //se erro for <= ao numero que o usuario entrou finaliza o laço
                        {
                            break;
                        }
                        else     //se nao, x0 recebe o valor de x
                        {
                            x10=xk;
                        }
                    }
                    printf("\n\nO Zero da funcao eh: x%d = %.16f\n\n",k+1, xk);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");
                    system("PAUSE");
                    fflush(stdin);
                    break;

                case 3:

                    printf("\n\nFuncao: f (x) = x * ln (x) - 1\nDerivada: f ' (x) = ln (x) + 1");
                    printf("\nE: %.6f",E);
                    printf("\n\nDigite o valor de x0 (chute inicial): ");
                    scanf("%f",&xn);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");

                    for(k=0; k<50; k++)
                    {
                        if(k==0)
                            x10=xn;
                        dnewton = derivadalnnewton(x10,h);
                        xk = x10-((x10*log(x10)-1) / dnewton) ;
                        erro=((xk-x10)/xk); //calculo do erro
                        if (erro<0)
                        {
                            erro = erro*(-1);
                        }

                        printf("\n\nx%d: %.16f\nErro: %.16f",k+1,xk,erro);
                        if(erro<=E)   //se erro for <= ao numero que o usuario entrou finaliza o laço
                        {
                            break;
                        }
                        else     //se nao, x0 recebe o valor de x
                        {
                            x10=xk;
                        }

                    }

                    printf("\n\nO Zero da funcao eh: x%d = %.16f\n\n",k+1, xk);
                    printf("\n\n------------------------------ ZERO DA FUNCAO ------------------------------\n\n");
                    system("PAUSE");
                    fflush(stdin);
                    break;

                case 4:
                    printf("\nVoce escolheu voltar ao Menu anterior\n\n");
                    system("PAUSE");
                    fflush(stdin);
                    break;
                /*----------------------------------------------------------#DEFAULT NEWTON RAPHSON - ZERO DA FUNÇÃO#------------------------------------------------------------------*/
                default:
                    printf("Valor invalido! Escolha entre uma das opcoes do Menu.\n\n");
                    system("PAUSE");
                    fflush(stdin);

                    break;
                }
            }
            while(opNew != 4);  //final do menu de Newton Raphson - Zero da Função
            break;
        /*=================================#FIM DO SWITCH opNEWTON RAPHSON - ZERO DA FUNÇÃO#=============================*/


        /*----------------------------------------------------------#CASO 2 DERIVADAS NUMERICAS#------------------------------------------------------------------*/
        case 2:

            do
            {
                system("CLS");
                printf("\t- - - Derivadas numericas - - - \n");
                printf("\nDigite o valor de x: ");
                scanf("%f",&x0);
                printf("\nEscolha f(x) na lista:\n");
                printf("1  -  f(x) = K\n");
                printf("2  -  f(x) = x ^ k\n");
                printf("3  -  f(x) = k ^ x\n");
                printf("4  -  f(x) = e ^ x\n");
                printf("5  -  f(x) = log k (x)\n");
                printf("6  -  f(x) = ln (x)\n");
                printf("7  -  f(x) = sen (x)\n");
                printf("8  -  f(x) = cos (x)\n");
                printf("9  -  f(x) = tg (x)\n");
                printf("10 -  f(x) = raiz (x)\n");
                printf("11 -  f(x) = 1 / x\n");
                printf("12 - Voltar ao Menu anterior\n");
                printf("\nDigite a opcao escolhida: ");
                fflush(stdin);
                scanf("%d", &opDer);
                system("CLS");
                /*======================================= INÍCIO DO SWITCH opDer (DERIVADAS)==================================*/
                switch(opDer)
                {
                    //>----------------------------Variáveis derivadas---------------------------------------
                    float  x1=0.0;
                    double ds=0.0,dc=0.0,dt=0.0, dpx=0.0, dpk=0.0, dl=0.0, ne=0.0, dlog=0.0, rx=0.0,divx=0.0;
                //----------------------------Variáveis derivadas---------------------------------------<
                //x1 = pontencias, ds = derivada seno, dc = derivada cosseno, dt = derivada tangente
                //dpx = derivada potencia em x, dpk = derivada pontencia em k, ne = derivada numero de euler
                //dlog = derivada log, rx = raiz de x, divx = 1/x

                case 1: //Cálculo da contante K
                    printf("Opcao escolhida - F(x) = k");
                    printf("\nDigite o valor de k: ");
                    scanf("%f", &x1);
                    printf("\nFuncao F(%.2f) = %.2f", x0, x1);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n", x0, x0*0);
                    system("PAUSE");
                    break;

                case 2: //Cálculo de x elevado a k
                    printf("Opcao escolhida - F(x) =  x ^ k\n");
                    printf("Digite o valor de k: ");
                    scanf("%f",&x1);
                    dpx = derivadaponteciaemx(x0,x1,h);
                    printf("\nFuncao F(%.2f) = %.2f ^ %.2f", x0, x0, x1);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n", x0,dpx );
                    system("PAUSE");
                    break;

                case 3:  //Cálculo de k elevado a x
                    printf("Opcao escolhida - F(x) =  k ^ x\n");
                    printf("Digite o valor de k: ");
                    scanf("%f",&x1);
                    dpk = derivadaponteciaemk(x0,x1,h);
                    printf("\nA funcao F(%.2f) = %.2f ^ %.2f",x0, x1, x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n", x0, dpk);
                    system("PAUSE");
                    break;

                case 4: //Cálculo de numero de euler elevado a x
                    printf("Opcao escolhida - F(x) =  e ^ x\n");
                    ne = derivadapotenciaeme(x0,h);
                    printf("\nA funcao F(%.2f) = 2.7182 ^ %.2f",x0,x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n", x0, ne);
                    system("PAUSE");
                    break;

                case 5:  //Cálculo de log na base k de x
                    printf("Opcao escolhida - F(x) =  log k (x)\n");
                    printf("Digite o valor de k: ");
                    scanf("%f",&x1);
                    dlog = derivadalogk(x0,x1,h);
                    printf("\nA funcao F(%.2f) = log (%.2f) na base %.2f", x0,x0, x1);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n",x0,dlog);
                    system("PAUSE");
                    break;

                case 6:  //Cálculo de ln de x
                    if (x0<0)
                    {
                        printf("Valor de x invalido para essa funcao!\n\n");
                        system("pause");
                        break;
                    }
                    printf("Opcao escolhida - F(x) =  ln (x)\n");
                    dl=derivadaln(x0,h);
                    printf("\nA funcao F(%.2f) = ln (%.2f)", x0, x0);
                    printf("\nDerivada numerica -> F'(%2.f) = %.16f\n\n\n",x0, dl);
                    system("PAUSE");
                    break;

                case 7:  //Cálculo de seno de x
                    printf("Opcao escolhida - F(x) =  sen (x)\n");
                    ds = derivadaseno(x0,h);
                    printf("\nA funcao F(%.2f) = sen (%.2f)", x0, x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n",x0,ds);
                    system("PAUSE");
                    break;

                case 8:  //Cálculo de cosseno de x
                    printf("Opcao escolhida - F(x) =  cos (x)\n");
                    dc = derivadacosseno(x0,h);
                    printf("\nA funcao de F(%.2f) = cos (%.2f)",x0, x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n",x0,dc );
                    system("PAUSE");
                    break;

                case 9:  //Cálculo tangente de x
                    printf("Opcao escolhida - F(x) =  tg (x)\n");
                    dt = derivadatangente(x0,h);
                    printf("\nA funcao F(%.2f) =  tg (%.2f)", x0,x0);
                    printf("\nDerivada numerica F'(%.2f) = %.16f\n\n\n",x0,dt );
                    system("PAUSE");
                    break;

                case 10:  //Cálculo da raiz de x
                    printf("Opcao escolhida - F(x) =  raiz (x)\n");
                    rx = derivadaraiz(x0,h);
                    printf("\nA funcao F(%.2f) = raiz (%.2f)", x0,x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n",x0,rx );
                    system("PAUSE");
                    break;

                case 11:  //Cálculo de 1/x
                    printf("Opcao escolhida - F(x) =  1/x\n ");
                    divx = derivada1x(x0,h);
                    printf("\nA funcao F(%.2f) = 1  / (%2.f)", x0, x0);
                    printf("\nDerivada numerica -> F'(%.2f) = %.16f\n\n\n", x0, divx);
                    system("PAUSE");
                    break;
                /*---------------------------------------------------------------#CASO 12 Voltar Menu Anterior opDer #-------------------------------------------------------------------------*/
                case 12:
                    fflush(stdin);
                    printf("\nVoce escolheu voltar ao Menu anterior.\n\n ");
                    system("PAUSE");
                    break;
                /*----------------------------------------------------------#DEFAULT opDer #------------------------------------------------------------------*/
                default:
                    printf("Valor invalido! Escolha entre uma das opcoes do Menu.\n\n");
                    system("PAUSE");
                    break;
                }
                fflush(stdin);
            }
            while(opDer != 12);  //final do menu de derivadas
            break;
        /*=======================================FIM DO SWITCH opDer DERIVADAS==================================*/


        /*----------------------------------------------------------#CASO 3 opINT INTREGRAIS#------------------------------------------------------------------*/
        case 3://integrais
            do // do menu integrais
            {
                system("CLS");
                printf(" - - - Integrais - - -\n");
                printf("\nDigite o valor de x0: ");
                scanf("%f",&x0);
                do //do para xn <= a x0
                {
                    printf("\nxn deve ser MAIOR que o valor de x0 = %.3f\n", x0);
                    printf("\nDigite o valor de xn: ");
                    scanf("%f",&xn);
                    if(xn<x0)
                    {
                        printf("O valor de xn = %.3f eh menor que o valor de x0 = %.3f\n", xn, x0);
                        printf("\nxn deve ser MAIOR que x0\n");
                        system("PAUSE");
                    }
                    else if(xn == x0)
                    {
                        printf("O valor de xn = %.3f eh igual o valor de x0 = %.3f\n", xn, x0);
                        printf("\nxn deve ser MAIOR que x0\n");
                        system("PAUSE");
                    }
                    system("CLS");
                }
                while(xn<=x0);
                fflush(stdin);
                printf("\nEscolha f(x) na lista:\n");
                printf("1  -  f(x) = K\n");
                printf("2  -  f(x) = x ^ k\n");
                printf("3  -  f(x) = k ^ x\n");
                printf("4  -  f(x) = e ^ x\n");
                printf("5  -  f(x) = log k (x)\n");
                printf("6  -  f(x) = ln (x)\n");
                printf("7  -  f(x) = sen (x)\n");
                printf("8  -  f(x) = cos (x)\n");
                printf("9  -  f(x) = tg (x)\n");
                printf("10 -  f(x) = raiz (x)\n");
                printf("11 -  f(x) = 1 / x\n");
                printf("12 - Voltar ao Menu anterior\n");
                printf("\nDigite a opcao escolhida: ");
                scanf("%d", &opItg);
                switch(opItg)
                {
                    /*======================================= INÍCIO DO SWITCH opINTEGRAIS==================================*/
                    float  x1=0.0, k=0.0;
                    double ipx=0.0,ico=0.0, ipk=0.0, ie=0.0, ilog=0.0, iln=0.0,is=0.0,ic=0.0,itg=0.0,ir=0.0,ix=0.0;

                case 1: //Cálculo da contante K
                    printf("\nOpcao escolhida - F(x) =  K\n");
                    printf("\nDigite o valor de k: ");
                    scanf("%f",&k);
                    ico=integralconstante(x0,xn,n,k);
                    printf("Resultado da integral eh: %.8f\n\n",ico);
                    system("PAUSE");
                    break;

                case 2: //Cálculo de pontencia de x
                    printf("\nOpcao escolhida - F(x) =  x ^ k\n");
                    printf("\nDigite o valor da pontencia k: ");
                    scanf("%f",&k);
                    ipx = integralpotencia(x0,xn,n,k);
                    printf("Resultado da integral eh: %.8f\n\n",ipx);
                    system("PAUSE");
                    break;

                case 3:  //Cálculo de k elevado a x
                    printf("\nOpcao escolhida - F(x) =  k ^ x\n");
                    printf("Digite o valor de k: ");
                    scanf("%f",&k);
                    ipk = integralpotenciaemk(x0,xn,n,k);
                    printf("Resultado da integral eh: %.8f\n\n",ipk);
                    system("PAUSE");
                    break;

                case 4: //Cálculo de número de euler elevado a x
                    printf("\nOpcao escolhida - F(x) =  e ^ x\n");
                    ie = integralpotenciaemeuler(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",ie);
                    system("PAUSE");
                    break;

                case 5:  //Cálculo de log na base k de x
                    printf("\nOpcao escolhida - F(x) =  log k (x)\n");
                    printf("Digite o valor de k: ");
                    scanf("%f",&x1);
                    ilog = integrallogk(x0,xn,n,k);
                    printf("Resultado da integral eh: %.8f\n\n",ilog );
                    system("PAUSE");
                    break;

                case 6:  //Cálculo de ln de x
                    if (x0<0)
                    {
                        printf("Valor de x invalido para essa funcao!\n\n");
                        system("pause");
                        break;
                    }
                    printf("\nOpcao escolhida - F(x) =  ln (x)\n");
                    iln=integralln(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",iln);
                    system("PAUSE");
                    break;

                case 7:  //Cálculo de seno de x
                    printf("\nOpcao escolhida - F(x) =  sen (x)\n");
                    is = integralseno(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",is);
                    system("PAUSE");
                    break;

                case 8:  //Cálculo de cosseno de x
                    printf("\nOpcao escolhida - F(x) =  cos (x)\n");
                    ic = integralcosseno(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",ic );
                    system("PAUSE");
                    break;

                case 9:  //Cálculo tangente de x
                    printf("\nOpcao escolhida - F(x) =  tg (x)\n");
                    itg = integraltg(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",itg );
                    system("PAUSE");
                    break;

                case 10:  //Cálculo da raiz de x
                    printf("\nOpcao escolhida - F(x) =  raiz (x)\n");
                    ir=integralraiz(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n",ir );
                    system("PAUSE");
                    break;

                case 11:  //Cálculo de 1/x
                    printf("\nOpcao escolhida - F(x) =  1 / x\n ");
                    ix=integral1x(x0,xn,n);
                    printf("Resultado da integral eh: %.8f\n\n", ix);
                    system("PAUSE");
                    break;

                case 12:
                    fflush(stdin);
                    printf("\n\nVoce escolheu voltar ao Menu anterior.\n\n");
                    system("PAUSE");
                    break;
                /*----------------------------------------------------------#DEFAULT INTEGRAIS#------------------------------------------------------------------*/
                default:
                    printf("Valor invalido! Escolha entre uma das opcoes do Menu.\n\n");
                    system("PAUSE");
                    break;
                }
            }
            while(opItg != 12); //final do menu de integrais
            system("CLS");
            fflush(stdin);
            break;
        /*----------------------------------------------------------#CASO S OP #------------------------------------------------------------------*/
        case 4:
            fflush(stdin);
            system("cls");
            printf("\nVoce escolheu sair do PROGRAMA DE CALCULO, ate mais! ;-) ");
            break;
        /*----------------------------------------------------------#DEFAULT OP #------------------------------------------------------------------*/
        default:
            printf("\nValor invalido! Escolha entre uma das opcoes do Menu.\n\n");
            fflush(stdin);
            system("PAUSE");
            break;
        }
        fflush(stdin);
        printf("\n\n");

        /*#####################################FIM DO SWITCH OP##########################################*/
    }
    while(op!=4); //final do menu principal

    return 0;
}
