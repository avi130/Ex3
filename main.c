#include <stdio.h>
#include "find.h"
#include <string.h>
int main() {
/*
    char w[6400];
    int i=0;
    int count=0;
    w[i]=getchar();
    while(i<6400 )
    {
        i++;
        w[i]=getchar();
        if(w[i]=='\n' && w[i-1]=='\n')
        {
            count++;
            if(count>1)
                break;
        }
    }
    printf("%s\n",w);
    printf("start\n");
    print_similar_words(w);
    printf("aa\n");
    print_lines(w);
    printf("aa\n");
    */
/*
    char p[265];
    if(p[0]!='a'&&p[0]!='b')
    {
        return 0;
    }
    else if(p[0]=='a')
    {
        print_lines(w);
    }
    else if(p[0]=='b')
    {
        print_similar_words(w);
    }
    else{
        printf("%c",p[0]);
    }
*/





/*
    char w[WORD];
    char option;
    getLine(w);
    printf("%s\n",w);

    option=getchar();
    printf("%s\n",w);
    printf("%c",option);
    if(option!='a'&&option!='b')
    {
        return 0;
    }
    if(option=='a')
    {
        print_lines(w);
    }
    if(option=='b')
    {
        print_similar_words(w);
    }

*/

    char line[LINE];
    char w[WORD];

    fgets(line,LINE , stdin);
    int j = 0;
    int i = 0;
    for( i = 0 ; i<LINE ; i++){
        if(line[i] != ' ' || line[i] != '\t' ){
            w[i] = line[i];
            //j++;
        }
        else{
            break;
        }
    }

    printf("%c",line[i]);
    w[i] = '\0';
    i++;
    if(line[i] == 'a'){
        print_lines(w);
    }
    if(line[i] == 'b'){
        print_similar_words(w);
    }
    return 0;

}
