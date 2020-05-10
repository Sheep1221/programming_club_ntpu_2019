#include<iostream>
/*把所有成績通通改成他喜歡的 0 分，輸出修改過後的成績，並且將原順序倒過來輸出*/
/*此處不用陣列，改用遞迴*/
using namespace std;
int i=0;

int counting(int n);

int main()
{
    int n;
    cin >> n;
    counting(n);
}

int counting(int n)
{
    int score;
    if(i<n)
    {
        i++;
        cin >> score;
        if(score>0)
            score=0;
        counting(n);
        cout << score <<endl;
    }
    else
        return 0;

}
