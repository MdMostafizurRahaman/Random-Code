#include<stdio.h>
int main(){
    int n = 7;
    int a[] = {2, 5, 11, 6, 2, 3, 6};

    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n\n");

    int x = 0;

    printf("PARENT PROCESS:\n");

    int freq[21];
    for(int i=0; i<=20; i++){
        freq[i] = 0;
        for(int j=0; j<n; j++){
            if(a[j] == i) freq[i]++;
        }
        printf("Frequency of %d id %d\n", i, freq[i]);
    }

    int par_pid = getpid();
    int child1_pid = -1;
    fork();
    if(par_pid != getpid()){
        printf("CHILD1:\n");
        int sum = 0;
        for(int i=0; i<n; i++){
            if(a[i] % 2 == 0) sum += a[i];
        }
        printf("Sum of even values %d\n", sum);
        child1_pid = getpid();
    }

    fork();

    if(getppid() == par_pid && child1_pid != getpid()){
        printf("CHILD2:\n");
        int fr = 0;
        for(int i=0; i<n; i++){
            if(a[i] % 2 == 0) fr++;
        }
        printf("Number of even numbers %d\n", fr);
    }

    if(getppid() == child1_pid){
        printf("CHILD3:\n");
        printf("Sorted array: ");
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i] > a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
