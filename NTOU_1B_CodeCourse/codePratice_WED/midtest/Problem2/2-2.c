#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_data_sorted(int data[],int n)
{
    int i;
    for(i = 0; i < n-1; ++i) {
        if (data[i]>data[i+1]) {
            return 0;
        }
    }
    return 1;
}

int sum(int data[],int n)
{
    int s = 0,i;
    for(i = 0; i < n; ++i) {
        s += data[i];
    }
    return s;
}

void binary_insertion_sort(int data[],int n)
{
    int i, j, pass, t, mid;

#ifndef NDEBUG
    int before_sum = sum(data,n);
#endif    
    for(i = 1; i < n; ++i) {
        int low = 0, high = i-1;
        while(low <= high) {
            mid = (low+high)/2;
            if (data[mid]==data[i]) {
                break;
            } else if (data[mid]<data[i]) {
                low = mid+1;
            } else {
                high= mid-1;
            }
        }
        if (data[mid]<data[i]) {
            mid += 1;
        }
        t = data[i];
        for(j=i;j>mid;--j) {
            data[j]=data[j-1];
        }
        data[mid] = t;
    }

    assert(is_data_sorted(data,n) && sum(data,n)==before_sum);

    return;
}

void formatOutput( int arr[], int n ){
    for ( int i = 0 ; i < n ; i++  ){
        printf("%i ",arr[i]);
    }printf("\n");
}

int main(){
    /*由大到小排*/
    int data6[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("DATA 6:\n");
    binary_insertion_sort(data6, 20);
    formatOutput(data6, 20);

    /*有重複元素的情況*/
    int data7[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
    printf("DATA 7:\n");
    binary_insertion_sort(data7, 20);
    formatOutput(data7, 20);

    /*都是負數的情況*/
    int data8[] = {-10, -5, -3, -8, -1, -12, -7, -20, -3, -5, -15, -2, -9, -8, -1, -4, -6, -6, -11, -2};
    printf("DATA 8:\n");
    binary_insertion_sort(data8, 20);
    formatOutput(data8, 20);

    /*有正有負的情況*/
    int data9[] = {-10, 5, -3, 8, -1, 12, -7, 0, 3, -5, 15, -2, 9, -8, 1, -4, 6, -6, 11, 2};
    printf("DATA 9:\n");
    binary_insertion_sort(data9, 20);
    formatOutput(data9, 20);

    /*數字很大的情況*/
    int data10[] = {1000000, -1000000, 999999, -999999, 500000, -500000, 750000, -750000, 
                   250000, -250000, 875000, -875000, 125000, -125000, 625000, -625000,
                   375000, -375000, 937500, -937500};
    printf("DATA 10:\n");
    binary_insertion_sort(data10, 20);
    formatOutput(data10, 20);

    /*包含0的情況*/
    int data11[] = {0, 5, -2, 0, 8, 3, 0, -1, 7, 0, 4, 9, 0, -3, 6, 0, 2, 1, 0, -4};
    printf("DATA 11:\n");
    binary_insertion_sort(data11, 20);
    formatOutput(data11, 20);

    /*幾乎排序好，只有少部分錯位的情況*/
    int data12[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 11, 12, 13, 14, 10, 16, 17, 18, 19, 20};
    printf("DATA 12:\n");
    binary_insertion_sort(data12, 20);
    formatOutput(data12, 20);

    /*混合情況*/
    int data13[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-99,-99,-99,55,-1};
    printf("DATA 13:\n");
    binary_insertion_sort(data13, 20);
    formatOutput(data13, 20);

    return 0;
}