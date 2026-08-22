#include <stdio.h>

int main()
{

    int num1, tent1, tempo1; // dados 1º lugar
    int num2, tent2, tempo2; // dados 2º lugar
    int num, tent, tempo;    // dados piloto de agora

    num1 = 2147483647;
    tent1 = 2147483647;
    tempo1 = 2147483647;
    num2 = 2147483647;
    tent2 = 2147483647;
    tempo2 = 2147483647;


    while (scanf("%d %d %d", &num, &tent, &tempo) == 3)
    {
        if (
            tempo < tempo1 ||
            (tempo == tempo1 && tent < tent1) ||
            (tempo == tempo1 && tent == tent1 && num < num1))
        {
            if (num != num1)
            {
                num2 = num1;
                tent2 = tent1;
                tempo2 = tempo1;

                num1 = num;
                tent1 = tent;
                tempo1 = tempo;
            }
            else
            {
                num1 = num;
                tent1 = tent;
                tempo1 = tempo;
            }
        }
        else if (num != num1 && (tempo < tempo2 ||
                                 (tempo == tempo2 && tent < tent2) ||
                                 (tempo == tempo2 && tent == tent2 && num < num2)))
        {
            num2 = num;
            tent2 = tent;
            tempo2 = tempo;
        }
    }


    // conversão
    int min1 = (tempo1 / 60000) % 60;
    int seg1 = (tempo1 / 1000) % 60;
    int ms1  = tempo1 % 1000;

    int min2 = (tempo2 / 60000) % 60;
    int seg2 = (tempo2 / 1000) % 60;
    int ms2  = tempo2 % 1000;

    // ===== saída pole position =====
    printf("Pole position: Piloto %d, com tempo de %d ", num1, min1);

    if (min1 == 1) printf("minuto");
    else printf("minutos");

    printf(", %d ", seg1);

    if (seg1 == 1) printf("segundo");
    else printf("segundos");

    printf(" e %d ", ms1);

    if (ms1 == 1) printf("milissegundo");
    else printf("milissegundos");

    printf(" (tentativa %d).\n", tent1);

    // ===== segundo lugar =====
    printf("Segundo lugar: Piloto %d, com tempo de %d ", num2, min2);

    if (min2 == 1) printf("minuto");
    else printf("minutos");

    printf(", %d ", seg2);

    if (seg2 == 1) printf("segundo");
    else printf("segundos");

    printf(" e %d ", ms2);

    if (ms2 == 1) printf("milissegundo");
    else printf("milissegundos");

    printf(" (tentativa %d).\n", tent2);

    return 0;
}