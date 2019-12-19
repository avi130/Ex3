#include <stdio.h>
#include "find.h"
#include <string.h>
int main() {



    char myLine[LINE];
    char compare_Word[WORD];
    fgets(myLine,LINE , stdin);
    int i = 0;
    for( i = 0 ; i<LINE ; i++)
    {
        if(myLine[i] != '\t' && myLine[i] != ' ' )
        {
            compare_Word[i] = myLine[i];
        }
        else{
            break;
        }
    }

    compare_Word[i] = '\0';
    i++;
    if(myLine[i] == 'a')
    {
        print_lines(compare_Word);
    }
    else if(myLine[i] == 'b')
    {
        print_similar_words(compare_Word);
    }


    return 0;
}
