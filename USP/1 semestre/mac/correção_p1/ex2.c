#include <stdio.h>

int monotona(int a, int b, int c){
    int r = 0;
    if(a < b){
        if(b < c){
            r = 1;}}
    if(c < b){
        if( b < a){
            r = -1;}}
    return r;
}
int valepico(int a, int b, int c){
    int r = 0;
    if(a > b){
        if(c > b){
            r = -1;}}
    if(a < b){
        if( c < b){
            r = 1;}}
    return r;}

int main(){
int a, b, c, d, i;
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);
d = monotona(a,b,c);
while(scanf("%d", &i) != EOF){
    if(1 == valepico(a, b, c)){
        printf("Elemento %d é um pico\n", b);
        d = 0;}
    else if(-1 == valepico(a,b,c)){
        printf("Elemento %d é um vale\n", b);
        d = 0;}
    a = b;
    b = c;
    c = i;
}
 if(1 == valepico(a, b, c)){
        printf("Elemento %d é um pico\n", b);
        d = 0;}
    else if(-1 == valepico(a,b,c)){
        printf("Elemento %d é um vale\n", b);
    }
return 0;
}