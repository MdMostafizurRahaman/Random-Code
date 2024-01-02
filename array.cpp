#include<stdio.h>
int main(){
    int std[100];
    std[0] = 100;
    std[1] = 200;
    std[2] = 50;

    printf("%d ", std[0]);
    printf("%d ", std[1]);
    printf("%d ", std[2]);
    printf("%d ", std[20]);

    int arr[5];
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

}