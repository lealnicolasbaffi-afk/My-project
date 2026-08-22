#include <stdio.h>

int monotono(int a, int b, int c);
int CristaVale(int a, int b, int c);

int main()
{
int a, b, c, d, i;
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);

d = monotono(a, b, c);

while(scanf("%d", &i) != EOF)
{
    if( 1 == CristaVale(a, b, c)){
        printf("O elemento %d e uma crista\n", b);
        d=0;
    }
    if( -1 == CristaVale(a, b, c)){
        printf("O elemento %d e um vale\n", b);
        d=0;
    }
    a = b;
    b = c;
    c = i;
}
if( 1 == d){
    printf("A sequencia e monotona crescente\n");
}
if( -1 == d){ 
    printf("A sequencia e monotona decrescente\n");
}   
 return 0;
}
int monotono(int a, int b, int c)
{
    if( b < c ){
        if (a < b){
            return 1;  
        }
        }
        if( b > c ){
        if (a > b){
            return -1;
        }
    }
    return 0;
}
int CristaVale(int a, int b, int c)
{
    if( b < c ){
        if (a > b){
            return 1;       
        }
        }
        if( b > c ){
        if (a < b){
            return -1;
        }
    }
    return 0;