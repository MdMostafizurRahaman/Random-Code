#include<iostream>
#include<string>
using namespace std;
const int numOfAlpha = 3;
const int maxN = 100;
string DFA[maxN][numOfAlpha];
string FinalStates[maxN];
bool matrix[maxN][maxN];

void calibrate()
{
    for(int i = 0; i < maxN; i++)
    {
        for(int j = 0; j < maxN; j++)
        {
            matrix[i][j] = true;
        }
    }
}
bool isFinalState(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(FinalStates[i] == str)
        return true;
    }
    return false;
}

int findDFA(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(DFA[i][0] == str)
        return i;
    }
    return -1;
}
void Minimize(int numOfStates)
{
    for(int i = 1; i <= numOfStates; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(isFinalState(DFA[i][0], numOfStates) && !isFinalState(DFA[j][0], numOfStates))
            {
                matrix[i][j] = false;
            }
            else if(!isFinalState(DFA[i][0], numOfStates) && isFinalState(DFA[j][0], numOfStates))
            {
                matrix[i][j] = false;
            }
        }
    }

    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 1; i <= numOfStates; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(matrix[i][j])
                {
                    int row, col;

                    // for alphabet 0
                    row = findDFA(DFA[i][1],numOfStates);
                    col = findDFA(DFA[j][1],numOfStates);
                    if(matrix[row][col] == false)
                    {
                        matrix[i][j] = false;
                        flag = true;
                    }

                    //for alphabet 1
                    row = findDFA(DFA[i][2],numOfStates);
                    col = findDFA(DFA[j][2],numOfStates);
                    if(matrix[row][col] == false)
                    {
                        matrix[i][j] = false;
                        flag = true;
                    }
                }
            }
        }
    }
}

void print(int size)
{
    cout << "Equivalent states : \n";
    bool flag = true;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(matrix[i][j])
            {
                cout << "(" << DFA[i][0] <<" , " << DFA[j][0] << ")\n";
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "No equivalent state found!\n";
    }
}
int main()
{
    int numOfStates;
    cin >> numOfStates;
    for(int i = 1; i <= numOfStates; i++)
    {
        cin >> DFA[i][0] >> DFA[i][1] >> DFA[i][2];
    }


    int numOfFinalstate;
    cin >> numOfFinalstate;
    for(int i = 1; i <= numOfFinalstate; i++)
    {
        cin >> FinalStates[i];
    }

    calibrate();
    Minimize(numOfStates);
    print(numOfStates);

    return 0;
}

/*
6
a b c
b a d
c e f
d e f
e e f
f f f
3
c d e


*/