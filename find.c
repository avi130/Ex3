//
// Created by avi on 18/12/2019.
//
#include "find.h"
#define Line 265
#define Word 30
#include <string.h>
#include <stdio.h>


int getLine(char s[]){
    char x[Line];
    if (strlen(s)>250)
        return -1;
    int counter=0;
    char ch=*(s);
    s[0]=ch;
    while(s[counter]!='\n' && s[counter]!='\0' && counter<Line ){
        counter++;
        ch=*(s+counter);
        s[counter]=ch;
    }

    s[counter]='\0';
    return counter;
}


int getword(char w[])
{
    int i=0;
    char x=*(w);
    w[0]=x;
    while((w[i]!='\n') && (w[i]!=' ') && (w[i]!='\t' && w[i]!='\0'))
    {
        i++;
        x=*(w+i);
        w[i]=x;
        if(i > 30)
        {
            return -1;
        }
    }
    w[i]='\0';
    return i;
}

char downcase(char c){
    if(c>='A'&& c<='Z'){
        return c-'A'+'a';
    }
    return c;
}


int substring(char *str1, char *str2){
    int len=strlen(str2);
    int i=0;
    while(*str1!='\0' && *str2 !='\0')
    {
        while(*str1==*str2){
            i++;
            if(i==len)
                return 1;
            str2=str2+1;
            str1=str1+1;
        }
        str2=str2-i;
        i=0;
    }
    return 0;

}

int similar(char *str1, char *str2, int n)
{
    int wrongtemp=0;
    int len1=strlen(str1);
    int len2= strlen(str2);
    if(len1-len2<0 || len1-len2>n)
    {
        return 0;
    }
    while(*str2 !='\0')
    {
        if(*str1!=*str2)
        {
            wrongtemp++;
            str1++;
            if(wrongtemp>n)
            {
                return 0;
            }
        } else{
            str1++;
            str2++;
        }
    }
    return 1;

}

void print_lines(char *str)
{
    int issimilar;
    char compareword [256];
    int comparsize=0;
    int counter=0;
    int counterwordinline=0;
    int totallength=strlen(str);
    int linecounter=0;

    char find [64000];
    strcpy(find,str );
    int findNum=getword(find);

    char newline[64000];
    strcpy(newline, str);
    int i = getLine(newline);
    int x=0;
    while ( counter+i<totallength && linecounter<250)
    {

        counter+=i+1;
        str=str+i+1;
        strcpy(newline, str);
        i = getLine(newline);

        counterwordinline=0;
        while(counterwordinline<i)
        {
            strcpy(compareword,newline+counterwordinline);
            comparsize=getword(compareword);
            counterwordinline+=comparsize+1;
            issimilar=similar(compareword,find,1);
            if(issimilar==1)
            {
                printf("%s\n", newline);
                break;
            }
        }

        strcpy(compareword,newline);
        linecounter++;
    }
}


void print_similar_words(char *str)
{
    int issimilar;
    char compareword [256];
    int comparsize=0;
    int counter=0;
    int counterwordinline=0;
    int totallength=strlen(str);
    int linecounter=0;

    char find [64000];
    strcpy(find,str );
    int findNum=getword(find);

    char newline[64000];
    strcpy(newline, str);
    int i = getLine(newline);
    int x=0;
    while ( counter+i<totallength && linecounter<250)
    {

        counter+=i+1;
        str=str+i+1;
        strcpy(newline, str);
        i = getLine(newline);

        counterwordinline=0;
        while(counterwordinline<i)
        {
            strcpy(compareword,newline+counterwordinline);
            comparsize=getword(compareword);

            counterwordinline+=comparsize+1;
            issimilar=similar(compareword,find,1);
            if(issimilar==1)
            {
                printf("%s\n", compareword);
                break;
            }
        }
        strcpy(compareword,newline);
        linecounter++;
    }
}







