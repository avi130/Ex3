//
// Created by avi on 17/12/2019.
//

#include "sort.h"



static int arr[50]={0};

void shift_element(int *arr,int i ){

    int index= 4*i;
    arr=arr+i;
    for (int x = 0; x < i; x++)
    {
        *arr=*(arr-1);
        arr=arr-1;
    }
    *arr=0;
}

void insertion_sort(int *arr,int len) {
    int key;
    int j;
    for (int i = 0; i < len; i++) {
        key = *(arr + i);
        j = i - 1;
        while (*(arr + j) > key && j >= 0) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}





