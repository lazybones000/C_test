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

int binary_insertion_sort(int data[],int n)
{
    int i, j, pass, t, mid;
    int cnt = 0;

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
            cnt++;
        }
        data[mid] = t;
    }

    assert(is_data_sorted(data,n) && sum(data,n)==before_sum);

    return cnt;
}

int main(){
    int data1[] = {1, 5,12,22,23,29,35,42,42,48,50,54,56,66,76,82,86,86,90,91};
    int data2[] = {99,91,83,74,68,67,58,57,57,56,55,46,42,32,32,29,25,18,16,14};
    int data3[] = {1,16,71,86,63,13,55,85,53,12, 8,32,45,13,56,21,58,46,82,81};
    int data4[] = {44,96,22,29,61,35,50,73,66,44,59,92,39,53,24,54,10,45,49,86};
    int data5[] = {13,74,22,68,18,87, 5,58,91, 2,25,77,14,14,24,34,74,72,59,33};

    int m1 = binary_insertion_sort(data1, 20);
    printf("DATA 1>> %i\n", m1);

    int m2 = binary_insertion_sort(data2, 20);
    printf("DATA 2>> %i\n", m2);

    int m3 = binary_insertion_sort(data3, 20);
    printf("DATA 3>> %i\n", m3);

    int m4 = binary_insertion_sort(data4, 20);
    printf("DATA 4>> %i\n", m4);

    int m5 = binary_insertion_sort(data5, 20);
    printf("DATA 5>> %i\n", m5);
    return 0;
}