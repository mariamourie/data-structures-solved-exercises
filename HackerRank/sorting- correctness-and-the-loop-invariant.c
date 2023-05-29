#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int N, int arr[]) {
    int i, j, aux;
    for(i = 0; i < N; i++) {
        j = i - 1;
        while(j >= 0) {
            if(arr[j+1] < arr[j]) {
                aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
            }
            j--;
        }
    }
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}

