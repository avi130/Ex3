#include <stdio.h>
#include "find.h"
int main() {

    char q[]="cat b\n\nthis is a text file crat\nlooking for the word cat\nthe program should print also cats\nand crats and lcat but it shouldent\nprint the word caats";
    print_similar_words(q);


}
