#include<bits/stdc++.h>
using namespace std;
#include<string.h>
int main(void)
{
    char str[100],state='a';
    int i;
    printf("enter your string:\n");
    scanf("%s",str);

    for(i=0;i<strlen(str)-2;i++)
    {
        cout << "a->";
        if(state=='a')
        {
        // if(str[i]=='0')state='q0';
         if(str[i]=='1')
        {
            if(str[i+1]=='1'&&str[i+2]=='1'){
                state='b';
                cout << "b->";
                
            }
            else{
                state='a';
                cout <<"a->";
                }
        }
        }
        else if(state=='b')
        {
            if(str[i]=='1'){
                state='c';
                cout << "c->";
            }
        }
        else if(state=='c')
        {
            if(str[i]=='1'){
                state='d';
                cout <<"d->";
            }
        }
        else if(state=='d')
        {
            if(str[i]=='1'){
                state='d';
                cout <<"d->";
            }
            else if(str[i]=='0'){
                state='d';
                cout <<"d->";
            }
        }
        //printf("%c\n",state);

    }
    if(state=='d')
        printf("accepted!");
    else 
        printf("unaccepted");
    


}