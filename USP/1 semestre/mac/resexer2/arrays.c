#include <stdio.h>

int main(){
int freq[26];
for( int i = 0; i < 26; i++)
freq[i] = 0; 


char ch;
while( scanf("%c", &ch) != EOF)
{
    if(ch >= 'A' && ch <= 'Z') 
    {
        freq[ch - 'A']++;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        freq[ch -'a']++;
    }
}
    for(int i = 0; i < 26; i++)
    {
        printf("a letra %c aparece %d vezes \n", i + 'A', freq[i]);
    }

 return 0;
}