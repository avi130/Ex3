#include "sort.h"
#include <stdio.h>
#define SIZE 50

int main(){

        int arr[SIZE];
        printf("Please enter 50 numbers for the arr:\n");
        for (int i = 0; i < SIZE; i++) {
            int temp_numb;
            scanf(" %d", &temp_numb);
            *(i+arr) = temp_numb;
        }

        insertion_sort(arr, SIZE);
        for (int j = 0; j < SIZE; j++) {
            if (j == SIZE-1) {
                printf("%d\n", arr[j]);
            } else {
                printf("%d,", arr[j]);
            }
        }





    return 0;
}