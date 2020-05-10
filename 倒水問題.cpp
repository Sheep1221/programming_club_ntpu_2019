#include<iostream>

using namespace std;
int liters[102], number[102];
void print_number(int m);
void filling(int amount, int current, int m);

int main()
{
    int total, M;
    cin>> total>> M;
    for(int i=0; i<M; i++)
        cin>> liters[i];
    filling(total, 0, M);
    return 0;
}

void print_number(int m)
{
    cout<< '(' << number[0];
    for(int i=1; i<m; i++)
        cout<< ',' << number[i];
    cout<< ')' << endl;
}

void filling(int amount, int current, int m)
{
    int liter = liters[current];
    if(amount==0)
    {
        print_number(m);
        return;
    }
    if(current>=m)
        return;

    for(int i = amount/liter; i>=0; i--)
    {
        number[current]=i;
        cout<< liter<< " "<<i<<endl;
        filling(amount-liter*i, current+1, m);
    }
}
