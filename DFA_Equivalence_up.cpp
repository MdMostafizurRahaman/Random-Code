#include<iostream>
#include<string>
using namespace std;

void matrix_initialize();
bool isFState(string str, int size);
int findDFA(string str, int size);
void DFA_Equivalence(int numOfStates);
void printTable(int size);
void print(int size);

const int numberOfAlphabet = 3;
const int maxMatrix = 100;
string DFA_Table[maxMatrix][numberOfAlphabet];
string FinalStates[maxMatrix];
bool matrix[maxMatrix][maxMatrix];

int main()
{
    int numOfStates;
    cout << "Number of States:";
    cin >> numOfStates;
    cout << "S " << "0 " << "1 " << endl;
    for(int i = 1; i <= numOfStates; i++)
    {
        cin >> DFA_Table[i][0] >> DFA_Table[i][1] >> DFA_Table[i][2];
    }


    int numOfFinalstate;
    cout << "Number of Final State:";
    cin >> numOfFinalstate;
    cout << "Final States are:";
    for(int i = 1; i <= numOfFinalstate; i++)
    {
        cin >> FinalStates[i];
    }

    matrix_initialize();
    DFA_Equivalence(numOfStates);
    printTable(numOfStates);
    print(numOfStates);

    return 0;
}

void matrix_initialize()
{
    for(int i = 0; i < maxMatrix; i++)
    {
        for(int j = 0; j < maxMatrix; j++)
        {
            matrix[i][j] = true;
        }
    }
}
bool isFState(string str, int size)
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
        if(DFA_Table[i][0] == str)
        return i;
    }
    return -1;
}
void DFA_Equivalence(int numOfStates)
{
    for(int i = 1; i <= numOfStates; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(isFState(DFA_Table[i][0], numOfStates) && !isFState(DFA_Table[j][0], numOfStates))
            {
                matrix[i][j] = false;
            }
            else if(!isFState(DFA_Table[i][0], numOfStates) && isFState(DFA_Table[j][0], numOfStates))
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
                    row = findDFA(DFA_Table[i][1],numOfStates);
                    col = findDFA(DFA_Table[j][1],numOfStates);
                    if(matrix[row][col] == false)
                    {
                        matrix[i][j] = false;
                        flag = true;
                    }

                    //for alphabet 1
                    row = findDFA(DFA_Table[i][2],numOfStates);
                    col = findDFA(DFA_Table[j][2],numOfStates);
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

void printTable(int size)
{
    cout << "Table::\n";
    bool flag = true;
    for(int i = 1; i <= size; i++)
    {
        if(i == 1)continue;
        cout << DFA_Table[i][0] << " ";
        for(int j = 1; j <= i-1; j++)
        {
            if(matrix[i][j])
            {
                cout << "= ";
            }
            else if(!matrix[i][j])
            {
                cout << "x ";
            }
        }
        cout << endl;
        if( i == size)
        {
            for(int i = 0; i < size; i++)
            {
                cout << " " << DFA_Table[i][0];
            }
        }
        
    }
    cout << endl;

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
                cout << "(" << DFA_Table[i][0] <<" = " << DFA_Table[j][0] << ")\n";
                flag = false;
            }
        }
    }

    if(flag)
    {
        cout << "No equivalent state found!\n";
    }
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

6
a b c
b d e
c e d
d f f
e f f 
f f f
3
b c f


*/