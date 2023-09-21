// Funzioni Stringhe
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0, lung;
    char str1[20], str2[20],str3[40];
    printf("Inserisci la prima stringa\n");
    scanf("%s", str1);
    lung = strlen(str1);
    printf("La lunghezza della stringa e' %d\n", lung);
    printf("Inserisci la seconda stringa\n");
    scanf("%s", str2);
    // confronto le 2 stringhe
    if (strcmp(str1, str2) == 0){   //strcmp>0 str1 + lunga di str2
                                    //strcmp<0 str1 + corta di str2
        printf("Le due stringhe sono uguali");
    }else{
        printf("Le due stringhe sono diverse");
    }
    strcat(str1,str2);
    printf("La stringa concatenata e': %s",str1);
    strcpy(str1,str2);
    printf("Le stringa copiata e' %s",str1);
    return 0;
}
