    #include <stdio.h>

    void soma(int *q, int *k, int *j)
 {
     *j = *q + *k;
 }
    int main(){
        int a;
        int b;
        int c = 0; 

        scanf("%d", &a);
        scanf("%d", &b);
        soma(&a, &b, &c);
        printf("a soma foi ser %d", c);
        return 0;
    }