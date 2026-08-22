/*
 * Resolve p(x) = 0 para um polinômio de grau no máximo 5.
 * Usa o método de Newton. Para resolver
 * 
 * a0 + a1 x + a2 x^2 + a3 x^3 + a4 x^4 + a5 x^5 = 0,
 * 
 * com o método de Newton iniciado em x0, execute
 * 
 * ./quintic a0 a1 a2 a3 a4 a5 x0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Itera até que o valor de z mude por no máximo EPSILON
// Itera no máximo ITER_MAX vezes
#define EPSILON 1e-16
#define ITER_MAX 10000

// Tolerância para o teste p(z) = 0
// O valor de p(z) deve ser no máximo TOLERANCIA
#define TOLERANCIA 1e-5

double eval_poly(double a[], int d, double x);
double root(double a[], double b[], double x0, bool *succ);

int main(int argc, char *argv[])
{
    double a[6]; // p(x) = a[0] + ... + a[5] * x^5
    double b[5]; // p'(x) = a[1] + ... + 5 * a[4] * x^4

    for (int i = 0; i < 6; ++i)
        a[i] = atof(argv[i + 1]);
    for (int i = 0; i < 5; ++i)
        b[i] = (i + 1) * a[i + 1];

    bool succ;
    double x0 = atof(argv[7]);
    double r = root(a, b, x0, &succ);
    if (succ) {
        printf("Raiz: %.5lf\n", r);
        printf("p(%lf) = %.5lf\n", r, eval_poly(a, 5, r));
    } else
        printf("Nao convergiu: p(%.5lf) = %.5lf\n", r, eval_poly(a, 5, r));
    
    return 0;
}

double root(double a[], double b[], double x0, bool *succ) {
    double x1;

    for (int i = 0; i < ITER_MAX; ++i) {
        printf("%.5lf\n", x0);
        x1 = x0 - eval_poly(a, 5, x0) / eval_poly(b, 4, x0);
        if (fabs(x1 - x0) < EPSILON)
            break;
        x0 = x1;
    }

    *succ = fabs(eval_poly(a, 5, x1)) < TOLERANCIA;
    if (!*succ)
        fprintf(stderr, "pval: %.5lf\n", eval_poly(a, 5, x1));

    return x1;
}

double eval_poly(double a[], int d, double x) {
    double s = 0;
    for (int i = d; i >= 0; --i) {
        s = s * x + a[i];
    }
    return s;
}


/* 
i need to make this function find thhe roots of any polinomial function with a degree less than 500.
 This functions must also include the complex functions.
 All the codes on this folder already the ideia of the code, but do not include the complex roots
 To do this. The EP summary explains the ideia tho solve this problem
  */