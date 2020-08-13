/* 
 * File:   main.c
 * Author: hoangjam
 *
 * Created on August 12, 2020, 5:58 PM
 */

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int value) {
    int first = 0, last = n - 1, index = -1, counter=0;
    while (first <= last) {
        int middle = (first + last) / 2;
        counter++;
        if (arr[middle] == value) {
            index = middle;
            printf("%d ", index);
            break;
        } else if (arr[middle] > value) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    printf("count:%d", counter);
    return index; // Return index of value, -1 means not found
}

int main(int argc, char** argv) {
    
    // split will be at 56. last = n-1, 10-1=9/2 = index 4.
    int arr[] = {2, 11, 25, 37, 56, 61, 63, 88, 90, 100};
    binarySearch(arr, 10, 61);
//    printf("%d\n", binarySearch(arr, 10, 61));

    return 0;
}

