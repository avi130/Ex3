//
// Created by avi on 18/12/2019.
//

#ifndef MATALA3FIND_FIND_H
#define MATALA3FIND_FIND_H

#define WORD 30
#define LINE 256
int getLine(char s[]);

int getword(char w[]);

int substring(char *str1, char *str2);

char downcase(char c);

int similar(char *str1, char *str2, int n);

void print_similar_words(char *str);

void print_lines(char *str);

#endif //MATALA3FIND_FIND_H
