/*
 * Resolve ax^2 + bx + c = 0.
 * 
 * $ ./quad 1 -1 -1
 * Equacao: 1x^2 + -1x + -1 = 0
 * D = 5.00000
 * raiz D = 2.23607
 * x1 = -0.61803
 * x2 = 1.61803
 * Valor do polinomio em x1 e x2:
 * 0.00000
 * 0.00000
 * $ ./quad 1 -1 1
 * Equacao: 1x^2 + -1x + 1 = 0
 * D = -3.00000
 * raiz D = 1.73205I
 * x1 = 0.50000 - 0.86603I
 * x2 = 0.50000 + 0.86603I
 * Valor do polinomio em x1 e x2:
 * 0.00000
 * 0.00000
 * $ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void print_complex(char *pref, double complex z, char *suff);
double complex p(double a, double b, double c, double complex z);
    
int main(int argc, char *argv[])
{
    // ax^2 + bx + c = 0
    double a = atof(argv[1]), b = atof(argv[2]), c = atof(argv[3]);
    
    if (a == 0.0) {
        printf("O coeficiente de x^2 deve ser nao-nulo\n");
        return 0;
    }

    printf("Equacao: %lgx^2 + %lgx + %lg = 0\n", a, b, c);

    double D = b * b - 4 * a * c;
    printf("D = %.5lf\n", D);
    print_complex("raiz D = ", csqrt(D), "\n");

    double complex x1 = (-b - csqrt(D)) / (2 * a);
    double complex x2 = (-b + csqrt(D)) / (2 * a);

    print_complex("x1 = ", x1, "\n");
    print_complex("x2 = ", x2, "\n");

    printf("Valor do polinomio em x1 e x2:\n");
    print_complex("", p(a, b, c, x1), "\n");
    print_complex("", p(a, b, c, x2), "\n");
    
    return 0;
}

void print_complex(char *pref, double complex z, char *suff) {
    double a = creal(z);
    double b = cimag(z);
    printf("%s", pref);

    if (b == 0.0) {
        printf("%.5lf", a);
        printf("%s", suff);
        return;
    }
    if (a == 0.0) {
        printf("%.5lfI", b);
        printf("%s", suff);        
        return;
    }
    
    printf("%.5lf", a);
    if (b < 0.0) 
        printf(" - %.5lfI", -b);
    else 
        printf(" + %.5lfI", b);
    printf("%s", suff);
}

double complex p(double a, double b, double c, double complex z) {
    return a * z * z + b * z + c;
}
