#include<bits/stdc++.h>

using namespace std;
int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
char maze[50][50];
bool visited[50][50];
void route(int i, int j);
int ansx, ansy;

int main()
{
    int N, M, stx, sty;
    memset(maze, 0, sizeof(maze));
    memset(visited, 0, sizeof(visited));
    cin>>N>>M;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin>>maze[i][j];
            if((i==1||j==1||j==M||i==N)&&maze[i][j]=='.'){
				stx=i,sty=j;
            }
        }
    }

    route(stx, sty);
    cout<<ansx<<" "<<ansy<<endl;
}

void route(int i, int j)
{
    visited[i][j]=true;
    ansx=i,ansy=j;
    for(int k=0;k<4;k++)
    {
		int ni=i+dir[k][0];
		int nj=j+dir[k][1];
		if(!visited[ni][nj]&&maze[ni][nj]=='.')
            route(ni, nj);
    }
}
