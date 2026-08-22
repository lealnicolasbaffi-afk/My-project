#include <stdio.h>

int main(){
    int ocorrencia[6];
    for(int i = 0; i < 6; i++)
    ocorrencia[i] = 0;
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
    
        int joagada;    
        scanf("%d", &joagada);

        for(int k = 1; k <= 6; k++)
        {
            if(joagada == k)
            ocorrencia[k - 1]++;
        }

    }
    
    for (int i = 0; i < 6; i++)
    printf("a ocorrencia de %d foi de %d\n", i+1, ocorrencia[i]);
    
    return 0;
}