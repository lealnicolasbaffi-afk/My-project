#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>


#define ERR 1e-12        // Ordem de grandeza da aproximação...
#define EPSILON 1e-14    // valor que verifica o quanto mudou xi pra x(i+1)
#define N 256            // Valor de n Para achar os pontos iniciais
#define M 500            //grau maximo de polinomio
#define IT_MAX 10000     //valor máximo de i para a verificação de convergência de z(i)

double complex resolve_polinomio(double complex x, double a[], int grau)
{
    double complex s = 0;
    for (int i = grau; i >= 0; --i) {
        s = s * x + a[i];        }  //resolve o polinômio por horner
    return s;
}

double complex calcula_raiz(double a[], double b[], double complex x0, bool *succ, int grau) {
    double complex x1 =x0;

    for (int i = 0; i < IT_MAX; ++i) {
        double complex dp = resolve_polinomio(x0, b, grau-1);

        if (cabs(dp) < 1e-14) {
            *succ = false;
            return x0;        }

        x1 = x0 - resolve_polinomio(x0 ,a ,grau) / dp;
        if (cabs(x1 - x0) <= EPSILON){
            *succ = true;
            return x1;
        }
        x0 = x1;              
    }
    *succ = cabs(creal(resolve_polinomio(x1, a, grau))) <= ERR && cabs(cimag(resolve_polinomio(x1, a, grau))) <= ERR;
    return x1;
}

int main()
{
  
    double z[N + 1];              //salva todos os valores de Rz e Iz
    double a[M + 1];              //Salva todos os coeficientes do polinomio
    double b[M];                  //salva todos os coeficientes da derivada do polinômio
    int k;                        //salva o valor do coeficiente atual
    double complex raizes[M];     //salva todas as raizes encontradas
    int u = 0;                    //aponta para a raiz u+1
    bool succ;
    int GRAU = 0;


    for(int i = 0; i <= N; i++)    {
        z[i] = -2.0 + (4.0*i)/(N); } //guarda todos os valores que tanto a parte real quanto a imaginaria podem assumir em z(0), isto é, -2 <= Rz <= 2 e -2 <= Iz <= 2.

    for(int i = 0; i <= M; i++)    {
        a[i] = 0;                  } //limpa a memória do vetor dos coeficientes.
    
    while(scanf("%d", &k) != EOF)  {
        scanf("%lf", &a[k]);   
        if(a[k] != 0)
        GRAU = k;                  } //escaneia todos os coeficientes e suas respectivas posições.
    for(int i = 0; i < M; i++)     {
        b[i] = (i+1)*a[i+1];       } //calula a derivada do polinômio

    for(int re = 0; re <= N; re ++)
        for(int im = 0; im <= N; im ++) {
            double complex x = z[re] + z[im]*I;
            double complex r = calcula_raiz(a, b, x, &succ, GRAU);
            if (succ) {
             int verifica = 0;
             for(int i = 0; i < u; i++){
                if (fabs(creal(r) - creal(raizes[i])) <= ERR && fabs(cimag(r) - cimag(raizes[i])) <= ERR)
                verifica = 1;           } 
             if (verifica == 0)
             {
                raizes[u] = r;
                u++;
             }
             
            }
}    
            for (int i = 0; i <= u-1; i++)
            {
                printf("%.12lf %.12lf\n", creal(raizes[i]), cimag(raizes[i]));
            }
            
return 0;
}