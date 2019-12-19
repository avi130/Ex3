//
// Created by avi on 18/12/2019.
//
#include "find.h"
#include <string.h>
#include <stdio.h>



int getLine(char s[]){

    if (strlen(s)>LINE)
        return -1;
    int counter=0;
    char ch=*(s);
    s[0]=ch;
    while(s[counter]!='\n' && s[counter]!='\0' && counter<LINE ){
        counter++;
        ch=*(s+counter);
        s[counter]=ch;
    }

    s[counter]='\0';
    return counter;
}


int getWord(char w[])
{
    int i=0;
    char x=*(w);
    w[0]=x;
    while((w[i]!='\n') && (w[i]!=' ') && (w[i]!='\t' && w[i]!='\0'))
    {
        i++;
        x=*(w+i);
        w[i]=x;
        if(i > WORD)
        {
            return -1;
        }
    }
    w[i]='\0';
    return i;
}



int substring(char *str1, char *str2){
    int len=strlen(str2);
    int flag=0;
    char *temp=str2;
    for( int k = 0 ; k <LINE ; k++){
        while(*str1==*str2){
            flag++;
            if(flag == len)
                return 1;
            str2=str2+1;
            str1=str1+1;
        }
        str2=temp;
        flag=0;
    }
    return 0;
}

int similar(char *str1, char *str2, int n)
{
    int wrongTemp=0;
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
            wrongTemp++;
            str1++;
            if(wrongTemp>n)
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
    int j=0;
    char myLine[LINE];
    fgets(myLine, LINE , stdin);
    char myWord[WORD];
    while( fgets(myLine, LINE , stdin)){
        int length = strlen(myLine);
        for(int i = 0 ; i < length  ; i++){
            if( myLine[i] != ' ' && myLine[i] != '\n' && myLine[i] != '\t' && myLine[i] != '\0'){
                myWord[j] = myLine[i];
                j++;

            }
            else{
                char *temp = myWord;
                char *word=myLine;
                if (similar(myWord, str , 1)){
                    printf("%s\n",word);
                    break;
                }
                j=0;
                memset(myWord , 0 , WORD);
            }
        }
    }
}


void print_similar_words(char *str)
{
    int j=0;
    char myLine[LINE];
    fgets(myLine, LINE , stdin);
    char myWord[WORD];
    while( fgets(myLine, LINE , stdin)){
        int length = strlen(myLine);
        for(int i = 0 ; i < length  ; i++){
            if( myLine[i] != ' ' && myLine[i] != '\n' && myLine[i] != '\t' && myLine[i] != '\0'){
                myWord[j] = myLine[i];
                j++;

            }
            else{
                char *temp = myWord;
                if (similar(myWord, str , 1)){
                    printf("%s\n",temp);
                }
                j=0;
                memset(myWord , 0 , WORD);
            }
        }
    }

}










