#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 256

int main()
{
//printf("Vvedite stroku: ");
    FILE* f = fopen("r.txt", "r");
    if(f==NULL) return 1;
    char *stroka;
    stroka = (char*) malloc(n*sizeof(char));
    stroka[0]='\0';
    int j=0;
    do
    {
        stroka[j] = fgetc(f);
        stroka[j+1] = '\0';
        //printf("%s|\n", stroka);
        j++;
        if (feof(f))
            break ;
    }
    while(1);
    stroka[j-1]='\0';
    printf("stroka iz faila:\n%s|", stroka);
    fclose(f);

    char ss[]= {'.',' ','\0'};
    char s_[]= {' ','\0'};
//char *stroka;
//stroka = (char*) malloc(n*sizeof(char));
//gets(stroka);
    int c=0, i=0, k = strlen(stroka);
    char *s;
    s = (char*) malloc((k+1)*sizeof(char));
    s[0]='\0';
    while(stroka[i]==' ' && i<k)
    {
        i++;
    }
    while(i<k)
    {
        if(stroka[i]==' ')
        {
            s = strncat(s, stroka+i-c, c+1);
            c=0;
            do
            {
                i++;
            }
            while(stroka[i]==' ' && i<k);
            if(stroka[i]=='.')
            {
                if(s[strlen(s)-2]!='.')
                    s[strlen(s)-1]='\0';
                if(i+1<k && stroka[i+1]!=' ')
                {
                    s = strcat(s, ss);
                    i++;
                }
            }
        }
        else if(stroka[i]=='.' && i+1<k && stroka[i+1]!=' ')
        {
            s = strncat(s, stroka+i-c, c);
            c=0;
            s = strcat(s, ss);
            i++;
        }
        else
        {
            c++;
            i++;
        }
    }
    if(stroka[k-1]!=' ')
        s = strncat(s, stroka+i-c, c);
    else s[strlen(s)-1]='\0';
    printf("\nrezultat pravilnoy rasstanovki probelov i tochek:\n%s|\n", s);
///////////////////////////////////////////////////////////////////////////////////////////////
    char* ps;
    ps = (char*) malloc(n*sizeof(char));
    if(s[strlen(s)-1]=='.')
        c=1;
    else c=0;
    stroka[0]='\0';
    printf("delim stroku \"%s\" na slova:", s);
    char *sl = strtok(s, " .");
    while (sl != NULL)
    {
        printf("\n%s", sl);
//sl[strlen(sl)-1]=' ';
        stroka = strcat(stroka, sl);
        stroka = strcat(stroka, s_);
        ps = sl;
        sl = strtok(NULL, " .");
    }

    if(c)
        stroka[strlen(stroka)-1]='.';
    else stroka[strlen(stroka)-1]='\0';

    printf("\nrezultat udaleniya vseh tochek krome posledney (esli ona estb):\n%s|\n", stroka);
    printf("poslednee slovo:\n%s|\n", ps);
    s[0] = '\0';
    sl = strtok(stroka, " .");
    while (sl != NULL)
    {
        if(strcmp(sl, ps)!=0 && strlen(sl)>1)
        {
            sl[strlen(sl)-1]=' ';
            s = strcat(s, sl);
        }
        sl = strtok(NULL, " .");
    }
    //if(strlen(ps)>1)
        //s = strcat(s, ps);
    if(c)
        s[strlen(s)-1]='.';
    else s[strlen(s)-1]='\0';
    printf("\nrezultat vypolneniya programmy:\n%s|\n", s);
    f = fopen("y.txt","w");
    if (f == NULL)
        return 1;
    stroka[0]='\0';
    for (i = 0; s[i]!='\0'; i++)
        fputc(s[i], f);
    fclose(f);
    f = fopen("y.txt","r");
    fgets(stroka, n, f);
    printf("proverka:\n%s|\n", stroka);
    fclose(f);
    return 0;
}
