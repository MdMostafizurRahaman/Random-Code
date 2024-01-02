#include<stdio.h>
#include<string.h>
int main()
{
  int Q,i,no_of_alphabets,j,k,x,y,fnl,w=0;
  char q0,F,a,q,b;
  printf("Enter the number of finite states\n");
  scanf("%d",&Q);
  getchar();
  char state[Q+1];
  printf("Enter the states of the DFA\n");
  for(i=0;i<Q;i++)
  {scanf("%c",&state[i]);getchar();}
  //state[i]='\0';
  printf("Enter the number of alphabets\n");
  scanf("%d",&no_of_alphabets);
  getchar();
  char alphabet[no_of_alphabets+1];
  printf("Enter the alphabets\n");
  for(i=0;i<no_of_alphabets;i++)
  {scanf("%c",&alphabet[i]);getchar();}
  printf("Enter starting state\n");
  scanf("%c",&q0);
  getchar();

  printf("Enter the number of accepting states\n");
  scanf("%d",&fnl);
  char finl[fnl+1];
  for(i=0;i<fnl;i++){
  printf("Enter accepting states\n");
  scanf("%c",&finl[i]);getchar();}
  getchar();

  //alphabet[i]='\0';

  int del[Q][no_of_alphabets];

  for(i=0;i<Q;i++){
   for(j=0;j<no_of_alphabets;j++)
   {
      if(i==0&&j==0){;}
      else getchar();
     printf("Del function of %c to %c.\n",state[i],alphabet[j]);
     scanf("%c",&b);

     for(k=0;k<Q;k++){
       if(state[k]==b) {del[i][j]=k;break;}
     }
   }
  }

  q=q0;

  getchar();
  char str[200];
  gets(str);
 // getchar();
  for(i=0;i<strlen(str);i++){
      a=str[i];


      for(j=0;j<no_of_alphabets;j++)
      {
        if(alphabet[j]==a) {y=j;break;}
      }
      for(k=0;k<Q;k++)
      {
        if(state[k]==q){x=k;break;}
      }
      printf("del(%c,%c) ->",q,a);
      q=state[del[x][y]];
      printf("%c\n",q);
  }
  for(i=0;i<fnl;i++){
  if(q==finl[i]) {w=1;printf("DFA accepted.\n");}}
  if(!w) printf("DFA rejected.\n");

}
