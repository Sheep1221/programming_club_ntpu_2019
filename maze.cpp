#include<bits/stdc++.h>

using namespace std;
char maze[50][50];
bool visited[50][50];
int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
void DFS(int i,int j,int dep);

int main()
{
    int n, m;
    cin>>n>>m;
    memset(maze, 0, sizeof(maze));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>maze[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
    }
    DFS(1, 1, 0);
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}
}

void DFS(int i,int j,int dep)
{
    cout<<i<<" "<<j<<endl;
	visited[i][j]=true;
	maze[i][j]=dep+'0';
	for(int k=0;k<4;k++)
    {
		int ni=i+dir[k][0];
		int nj=j+dir[k][1];
		if(!visited[ni][nj]&&maze[ni][nj]=='.')
			DFS(ni,nj,dep+1);
	}
}
