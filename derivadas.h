//Protótipo
float derivadaponteciaemx(float x0, float x1,double h);
float derivadaponteciaemk(float x0, float x1,double h);
float derivadapotenciaeme(float x0,double h);
float derivadalogk(float x0, float x1,double h);
float derivadaln(float x0,double h);
float derivadaseno(float x0,double h);
float derivadacosseno(float x0,double h);
float derivadatangente(float x0,double h);
float derivadaraiz(float x0,double h);
float derivada1x(float x0,double h);
float derivadalnnewton(float x0,double h);
float derxqnewton(float x0,double h);
float dercosnewton(float x0,double h);

//Funções
 //Cálculo de x^k
float derivadaponteciaemx(float x0, float x1,double h){
    double dx=0.0, soma=0.0;
    soma = x0+h;
    dx = (pow(soma,x1) - pow(x0,x1))/h;
    return dx;
}

 //Cálculo de k^x
float derivadaponteciaemk(float x0, float x1,double h){
    double dk = 0.0, soma = 0.0;
    soma = x0+h;
    dk = (pow(x1,soma) - pow(x1,x0))/h;
    return dk;
}

//Cálculo de e^x
float derivadapotenciaeme(float x0,double h){
    double de = 0.0, soma = 0.0;
    soma = x0+h;
    de = ((exp(soma))-(exp(x0)))/h;
    return de;
}

//Cálculo de logk (x)
float derivadalogk(float x0, float x1,double h){
    double dlog = 0.0, soma = 0.0;
    soma = x0+h;
    dlog = ((log(soma)/log(x1))-(log(x0)/log(x1)))/h;
    return dlog;
}

//Cálculo de ln(x)
float derivadaln(float x0,double h){
    double dl = 0.0, soma = 0.0;
    soma = x0+h;
    dl = ((log(soma))-(log(x0)))/h;
    return dl;
}

//Cálculo de seno (x)
float derivadaseno(float x0,double h){
    double ds =0.0, soma=0.0;
    soma= x0+h;
    ds = ((sin(soma))-(sin(x0)))/h;
    return ds;
}

//Cálculo de cosseno (x)
float derivadacosseno(float x0,double h){
    double dc =0.0, soma=0.0;
    soma= x0+h;
    dc = ((cos(soma))-(cos(x0)))/h;
    return dc;
}

//Cálculo de tangente (x)
float derivadatangente(float x0,double h){
    double dt =0.0, soma=0.0;
    soma= x0+h;
    dt = ((tan(soma))-(tan(x0)))/h;
    return dt;
}

//Cálculo da raiz (x)
float derivadaraiz(float x0,double h){
    double rx =0.0, soma=0.0;
    soma= x0+h;
    rx = ((sqrt(soma))-(sqrt(x0)))/h;
    return rx;
}

//Cálculo de 1/x
float derivada1x(float x0,double h){
   double divx =0.0, soma=0.0;
    soma= x0+h;
    divx = ((1/soma)-(1/x0))/h;
    return divx;
}

//Cálculo de ln(x) para newton
float derivadalnnewton(float x10,double h){
    double dnewton = 0.0, soma = 0.0;
    soma = x10+h;
    dnewton = ((soma*(log(soma))-1)-(x10*(log(x10))-1))/h;
    return dnewton;
}

float derxqnewton(float x10,double h){
    double newtonq=0.0, soma=0.0;
    soma = x10+h;
    newtonq= (((pow(soma,2))-2) - ((pow(x10,2))-2))/h;
    return newtonq;
}

float dercosnewton(float x10,double h){
    double newton=0.0, soma=0.0;
    soma = x10+h;
    newton= (((2*soma)-cos(soma)) - ((2*x10)-cos(x10)))/h;
    return newton;
}
