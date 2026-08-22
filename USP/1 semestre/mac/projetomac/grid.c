/******************************************************************************
Ao preencher esse cabeçalho com o meu nome e o meu número USP, declaro que sou
o único autor e responsável por esse programa. Todas as partes originais desse
Exercício-Programa (EP) foram desenvolvidas e implementadas por mim seguindo
as instruções desse EP e que portanto não constituem desonestidade acadêmica
ou plágio.
Declaro também que sou responsável por todas as cópias desse programa e que eu
não distribuí ou facilitei a sua distribuição. Estou ciente que os casos de
plágio e desonestidade acadêmica serão tratados segundo os critérios
divulgados na página da disciplina.
Entendo que EPs sem assinatura não serão corrigidos e, ainda assim, poderão
ser punidos por desonestidade acadêmica.
Nome : Nicolas Leal Baffi 
NUSP : 17864385
Turma: 02
Prof.: Guilherme Oliveira Mota
******************************************************************************/

#include <stdio.h>

int verify(int a, int b, int c, int a2, int b2, int c2)
{
    if (c2 < c)
        return 1;
    else if (c2 > c)
        return 0;
    else if (c2 == c)
    {
        if (b2 < b)
            return 1;
        else if (b2 > b)
            return 0;
        else if (b2 == b)
        {
            if (a2 < a)
                return 1;
            else if (a2 > a)
                return 0;
        }
    }
    return 0;
}

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

    int n1, n2, n3;
    int l1, l2, l3;
    int t1, t2, t3;

    scanf("%d %d %d", &n2, &l2, &t2);
    scanf("%d %d %d", &n3, &l3, &t3);

    if (1 == verify(n2, l2, t2, n3, l3, t3))
    {
        n1 = n3;
        l1 = l3;
        t1 = t3;
    }
    else if (0 == verify(n2, l2, t2, n3, l3, t3))
    {
        n1 = n2;
        l1 = l2;
        t1 = t2;
        n2 = n3;
        l2 = l3;
        t2 = t3;
    }

    while (scanf("%d %d %d", &n3, &l3, &t3) != EOF)
    {
        if (1 == verify(n1, l1, t1, n3, l3, t3))
        {
            if(n3 == n1)
            {
            n1 = n3;
            l1 = l3;
            t1 = t3;
            }
            else
            {
            n2 = n1;
            l2 = l1;
            t2 = t1;
            n1 = n3;
            l1 = l3;
            t1 = t3;
            }
        }
        else if (1 == verify(n2, l2, t2, n3, l3, t3))
        {
                if(n3 != n1)
        {
            n2 = n3;
            l2 = l3;
            t2 = t3;
        }
    }
    }

    time(1, n1, t1, l1);
    time(2, n2, t2, l2);
    
    return 0;
}