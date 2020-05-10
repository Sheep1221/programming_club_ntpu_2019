#include<iostream>
#define N 55

int object_detect(char object);
using namespace std;

int main()
{
    int R, C, row, col, T, counting[100][5]={0}, ans[100]={0};
    char object[N][N];
    cin>>R>>C;
    for(int r=0; r<R; r++)
    {
        for(int c=0; c<C; c++)
        {
            cin>>object[r][c];
        }
    }
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>row>>col;
        int r=row+1;
        for(int j=0; j<3; j++)
        {
            if(r>=R)
                break;
            if(object_detect(object[r][col])==2)
                    break;
            counting[i][0]+=object_detect(object[r][col]);
           // cout<<object_detect(object[r][col])<<endl;
            r++;
        }
        r=row-1;
        for(int j=0; j<3; j++)
        {
            if(r<0)
                break;
            if(object_detect(object[r][col])==2)
                    break;
            counting[i][1]+=object_detect(object[r][col]);
            r--;
        }
        int c=col+1;
         for(int j=0; j<3; j++)
        {
            if(c>=C)
                break;
            if(object_detect(object[row][c])==2)
                    break;
            counting[i][2]+=object_detect(object[row][c]);
            c++;
        }
        c=col-1;
         for(int j=0; j<3; j++)
        {
            if(c<0)
                break;
            if(object_detect(object[row][c])==2)
                    break;
            counting[i][3]+=object_detect(object[row][c]);
            c--;
        }

        for(int dir=0; dir<=3; dir++)
        {
            if(counting[i][dir]>ans[i])
                ans[i]=counting[i][dir];
              //  cout<<counting[i][dir]<<endl;
        }
    }

    for(int i=0; i<T; i++)
        cout<<ans[i]<<endl;
}

int object_detect(char object)
{
    if(object=='#')
        return 2;
    else if(object=='!')
        return 1;
    else
        return 0;
}
