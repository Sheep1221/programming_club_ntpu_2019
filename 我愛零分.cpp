#include<iostream>
/*��Ҧ����Z�q�q�令�L���w�� 0 ���A��X�ק�L�᪺���Z�A�åB�N�춶�ǭ˹L�ӿ�X*/
/*���B���ΰ}�C�A��λ��j*/
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
