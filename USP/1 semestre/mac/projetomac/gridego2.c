#include <stdio.h>

int time(int class, int pilot, int milli, int laps)
{
    int milliseconds, seconds, minutes;

    milliseconds = milli % 1000;
    seconds = (milli / 1000) % 60;
    minutes = (milli / 60000) % 60;

    if (class == 1)
        printf("Pole position: Piloto %d, com tempo de", pilot);
    else if (class == 2)
        printf("Segundo lugar: Piloto %d, com tempo de", pilot);
    if (minutes == 1)
        printf(" %d minuto, ", minutes);
    else
        printf(" %d minutos, ", minutes);
    if (seconds == 1)
        printf("%d segundo e ", seconds);
    else
        printf("%d segundos e ", seconds);
    if (milliseconds == 1)
        printf("%d milissegundo", milliseconds);
    else
        printf("%d milissegundos", milliseconds);

    printf(" (tentativa %d).\n", laps);

    return 0;
}
int main()
{

    int num1, tent1, tempo1; // dados 1º lugar
    int num2, tent2, tempo2; // dados 2º lugar
    int num, tent, tempo;    // dados piloto de agora

    tempo1 = 1000000;

    tempo2 = 1000000;

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

    time(1, num1, tempo1, tent1);
    time(2, num2, tempo2, tent2);
}