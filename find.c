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

/*
    int i=0;
    char ch=getchar();
    while(s[i]!='\n' && s[i] !='\0'){
        s[i]=ch;
        i++;
        ch=getchar();
    }
    s[i+1]='\0';
    return i;
    */
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

    /*
    int flag = 0;
    int j = 0;
    char *temp;
    char *temp2;
    for( int i = 0 ; i <LINE ; i++){
        if(*str1 == *str2){
            temp = str1;
            temp2 = str2;
            for(j = 0 ; j <strlen(str2) ; j++){
                if(*temp == *temp2){
                    temp++;
                    temp2++;
                }
                else break;
            }
            temp2 = str2;
            if(j == strlen(str2)){ // we finish to over all str2
                flag = 1;
                break;
            }
        }
        str1++;
    }
    return flag;
*/
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
    char s[LINE];
    char w[WORD];
    fgets(s, LINE , stdin); // to skip the second line
    while( fgets(s, LINE , stdin)){
        int j=0;
        for(int i = 0 ; i < LINE && s[i] != '\n' ; i++){
            if( s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
                w[j] = s[i];
                j++;
            }
            else {
                if(substring(w,str)){
                    printf("%s",s);
                    break;
                }
                j=0;
            }
        }
    }


}


void print_similar_words(char *str)
{
    char myLine[LINE];
    char myWord[WORD];
    fgets(myLine, LINE , stdin);
    while( fgets(myLine, LINE , stdin)){
        int lenline = strlen(myLine);
        int j=0;
        for(int i = 0 ; i < lenline  ; i++){
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
                memset(myWord , 0 , WORD); // reset the word
            }
        }
    }

}










