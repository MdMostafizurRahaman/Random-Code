#include<bits/stdc++.h>
using namespace std;
#define inf 1000000

int find(char arr[], int N, char x)
{
    for(int i = 1; i <= N ; i++)
    {
        if(x == arr[i])
        return i;
    }

    return -1;
}

int main()
{
    int max, edges;
    cout << "How many points : ";
    cin >> max;
    char point[max+1];
    cout << " Enter the points : ";
    for(int i = 1 ; i <= max ; i++)
    {
        cin >> point[i];
    }

    int mat[max+1][max+1];

    for(int i = 0; i <= max ; i++)
    {
        for(int j = 0 ; j <= max ; j++)
        {
            mat[i][j] = inf;
        }
    }

    cout << "Enter how many edges : ";
    cin >> edges;
    cout << "Enter the edges : " << endl;
    for(int i = 1 ; i <= edges; i++)
    {
        char x,y;
        int w;
        cin >> x >> y >> w;
        mat[x-'A'+1][y-'A'+1] = mat[y-'A'+1][x-'A'+1] = w;
    }

    char x;
    int start, finish;
    cout << "Enter starting node : ";

    cin >> x;
    start = find(point, max, x);
    cout << "Enter destination node : ";
    cin >> x;
    finish = find(point, max, x);

    cout << start << " " << finish << endl;

    for(int i = 1 ; i <= max ; i++)
    {
        for(int j = 1 ; j <= max ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int visited[max+1][max+1];
    for(int i = 0 ; i <= max; i++)
    {
        for(int j = 0 ; j <= max; j++)
        {
            visited[i][j] = 0;
        }
    }

    int cur = start;
    cout << char('A'-1+start) << " ";

    while(cur != finish)
    {
        int cmp = inf;
        int min = inf;
        for(int i = 1; i <= max ; i++)
        {
            if(mat[cur][i] < cmp)
            {
                cmp = mat[cur][i];
                min = i;
            }
        }

        if(min == inf)
        {
            cout << "There is no path ahead!" << endl;
            break;
        }
        else if(!visited[cur][min])
        {
            cout << char('A'-1+min )<< " ";
            visited[cur][min] = visited[min][cur] = 1;
            cur = min;
        }
        else
        {
            mat[cur][min] = mat[min][cur] = inf;
        }
    }

    return 0;
}
/*
A B 15
A H 10
A G 25
B C 11
H D 20
C D 27
G F 13
F E 19
H E 2
E D 7
*/