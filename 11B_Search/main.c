/* 
 * File:   main.c
 * Author: hoangjam
 *
 * Created on August 7, 2020, 10:46 AM
 */

#include <stdio.h>
#include <stdlib.h>

int indexOf(int *a, int num){
    int i;
    int size = sizeof(a)/sizeof(int);
    for(i = 0; i < size ; i++){
        if (a[i] == num){
            return i;
        }
        else{
            return -1;
        }
    }
}

int main(int argc, char** argv) {

    int arr[] = {90, 88, 56, 100, 2, 25};
    printf("Enter the number to search for: ");
    int num;
    scanf("%d", &num);
    indexOf(arr, num);
    
    return 0;
}



