#include <stdio.h>
#include "find.h"
int main() {

    //char q[]="cat b\n\nthis is a text file crat\nlooking for the word cat\nthe program should print also cats\nand crats and lcat but it shouldent\nprint the word caats";
    //print_similar_words(q);
/*

        char w[WORD];
        getword(w);
        printf("%s",w);char c;
        printf("please enter your command. a / b ");
        scanf(" %c", &c);
        printf("%c",c);
        if(c == 'b')
            print_similar_words(w);

        else if (c == 'a')
            print_lines(w);

        else
            printf("there is no such commend.");
*/
    char s[WORD];
    char ch;
    getword(s);
    scanf(" %c",&ch);
    if(ch == 'a'){
        print_lines(s);
    }
    if(ch == 'b'){
        print_similar_words(s);
    }
    return 0;


}
