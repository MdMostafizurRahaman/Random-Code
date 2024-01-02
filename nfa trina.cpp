#include<bits/stdc++.h>
using namespace std;

char alpha[5]= {'x','y','z','t'};

int findState(char ch)
{
     int in;
    for(int i=0; i<4; i++)
    {
        if(ch==alpha[i])
        {
            in=i;
        }
    }

    return in;

}

int main()
{

    printf("Enter String:\n");
    char s[2000];
    scanf("%s",s);

//NFA table

    char state[4][2][6]= {{"x","xy"},{"\0","z"},{"\0","t"},{"\0","\0"}};
    printf("\nNFA Transition Table:\n\n");
    printf("State\t0\t1\n");
    printf("---------------------------\n");

    for(int i=0; i<4; i++)
    {
        printf("%c->\t",alpha[i]);
        for(int j=0; j<2; j++)
        {
            if(state[i][j][0]=='\0')  printf("null\t");
            else printf("%s\t",state[i][j]);
        }
        printf("\n-------------------------\n");
    }
    printf("Starting state->x\n");
    printf("Accepting state->t\n");

    int flag=0;

    for(int i=0; s[i]!='\0')
    {
        if(s[i]=='0'&& flag==0)
        {
            printf("(x,0)->x\n");
            i++;
        }
        else if(s[i]=='0'&& flag==1)
        {
            printf("(t,0)->t\n");
            printf("String Accepted!\n");
            i++;
        }
        else if(s[i]=='1'&& flag==1)
        {
            printf("(t,1)->t\n");
            printf("String Accepted!\n");
            i++;
        }
        else if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1')
        {
            flag=1;
            printf("(x,1)->y\n(y,1)->z\n(z,1)->t\n");
            i=i+3;
            printf("String Accepted!\n");
        }
        else if(s[i]=='1'&& flag==0)
        {
            printf("(x,1)->x\n");
            i++;
        }
    }

    if(flag==0) printf("String is not Accepted!\n");

//NFA to DFA

    vector<set<char>>v;
    set<char>init;
    init.insert('x');
    v.push_back(init);
    printf("DFA: \n");

    for(int i=0; i<100; i++)
    {
        set<char>temp1;
        set<char>temp2;

          if(i<v.size()){
            init=v[i];
              for(int l=0;l<init.size();l++){
                for(int j=0;state[findState(l)][0][j];j++){
                    temp1.insert(state[findState(l)][0][j]);
                }
                for(int j=0;state[findState(l)][1][j];j++){
                    temp2.insert(state[findState(l)][1][j]);
                }
              }
              printf("(");
             for(auto ch:init){
                printf("%c",ch);
             }
             printf(",0)-->");
             for(auto ch:temp1){
                printf("%c",ch);
             }
             printf("\n");
             printf("(");
             for(auto ch:init){
                printf("%c",ch);
             }
             printf(",1)-->");
             for(auto ch:temp2){
                printf("%c",ch);
             }
             printf("\n");
          }
          int fl=0;

            for(auto st:v){
                if(temp1==st) fl=1;
            }
            if(fl==0) v.push_back(temp1);

            fl=0;

            for(auto b:v){
                if(temp2==b) fl=1;
            }
            if(fl==0) v.push_back(temp2);

    }
}