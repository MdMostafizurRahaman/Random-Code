#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define p 0
#define q 1
#define r 2
#define s 3
#define final 3
using namespace std;
int main()
{
    int state[4][2];

    state[p][0]=p;
    state[p][1]=q;

    state[q][0]=p;
    state[q][1]=r;

    state[r][0]=p;
    state[r][1]=s;

    state[s][0]=s;
    state[s][1]=s;

    char str[100];
    printf("Enter a string consisting of 0's and 1's only: ");
    scanf("%s",str);

    char curr = p;
    for(int i = 0; str[i] != '\0'; i++)
    {

        if(str[i]=='0')
            curr=state[curr][0];
        else if(str[i]=='1')
            curr=state[curr][1];
        
        else
        {
            exit(0);
        }

        if(curr==p)
            printf("p->");
        else if(curr==q)
            printf("q->");
        else if(curr==r)
            printf("r->");
        else if(curr==s)
            printf("s->");
        
    }
    if(curr==final)
    printf("Accepted\n");
    else 
    printf("Rejected\n");
    return 0;
}