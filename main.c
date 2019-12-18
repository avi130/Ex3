#include <stdio.h>
#include "find.h"
#include <string.h>
int main() {
    char w[WORD];
    char option;
    getWord(w);
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
    return 0;
}
