//Protótipo
float integralconstante(float x0, float xn,float n, float k);
float integralpotencia(float x0, float xn,float n, float k);
float integralpotenciaemk(float x0, float xn,float n, float k);
float integralpotenciaemeuler(float x0, float xn,float n);
float integrallogk(float x0, float xn,float n, float k);
float integralln(float x0, float xn,float n);
float integralseno(float x0, float xn,float n);
float integralcosseno(float x0, float xn,float n);
float integraltg(float x0, float xn,float n);
float integralraiz(float x0, float xn,float n);
float integral1x(float x0, float xn,float n);

//Funções
//Contante K
float integralconstante(float x0, float xn,float n, float k){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        f+=k;
    }
    it=(h*(k+k+(2*f)))/2;
    return it;
}

//Potências
float integralpotencia(float x0, float xn, float n, float k){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=pow(aux,k);
    }
    it=(h*(pow(x0,k)+pow(xn,k)+(2*f)))/2;
    return it;
}

//integral K elevado a x
float integralpotenciaemk(float x0, float xn,float n, float k){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=pow(k,aux);
    }
    it=(h*(pow(k,x0)+pow(k,xn)+(2*f)))/2;
    return it;
}

//integral de Euler
float integralpotenciaemeuler(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=exp(aux);
    }
    it=(h*(exp(x0)+exp(xn)+(2*f)))/2;
    return it;
}

//integral logk (x)
float integrallogk(float x0, float xn,float n, float k){
    double h=0.0, aux=0.0,f=0.0,it=0.0, lg=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=log(aux)/log(k);
    }
    lg=(log(x0)/log(k))+(log(xn)/log(k));
    it=(h*(lg+(2*f)))/2;
    return it;
}

//integral ln
float integralln(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=log(aux);
    }
    it=(h*(log(x0)+log(xn)+(2*f)))/2;
    return it;
}

//integral seno
float integralseno(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=sin(aux);
    }
    it=(h*(sin(x0)+sin(xn)+(2*f)))/2;
    return it;
}

//integral cosseno
float integralcosseno(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=cos(aux);
    }
    it=(h*(cos(x0)+cos(xn)+(2*f)))/2;
    return it;
}

//integral tg
float integraltg(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=tan(aux);
    }
    it=(h*(tan(x0)+tan(xn)+(2*f)))/2;
    return it;
}

//integral raiz de (x)
float integralraiz(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=sqrt(aux);
    }
    it=(h*(sqrt(x0)+sqrt(xn)+(2*f)))/2;
    return it;
}

//integral 1/x
float integral1x(float x0, float xn,float n){
    double h=0.0, aux=0.0,f=0.0,it=0.0;
    int i;
    h=(xn-x0)/n;
    aux = x0;
    for(i=1;i<n;i++){
        aux+=h;
        f+=1/aux;
    }
    it=(h*(1/x0+1/xn+ (2*f)))/2;
    return it;
}
