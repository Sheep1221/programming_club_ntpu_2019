#include<iostream>
#include<cstring>
#include<queue>
#define MAX 1005

using namespace std;
typedef pair<int, int> pii;
char maze[MAX][MAX];
int dist[MAX][MAX];
int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
vector<pii> fires;
pii J;

int floodfill()
{
    memset(dist, -1, sizeof(dist));
    queue<pii> que;
    for(int i=0; i<fires.size(); i++)
    {
        que.push(fires[i]);
        dist[fires[i].first][fires[i].second]=1;
    }
    que.push(J);
    dist[J.first][J.second]=1;
    while(que.size())
    {
        pii now=que.front();
        que.pop();
        int a=now.first;
        int b=now.second;
        cout<<a<<" "<<b<<" "<<dist[a][b]<<endl;
        for(int i=0; i<4; i++)
        {
            int aa=a+dir[i][0];
            int bb=b+dir[i][1];
            if(maze[a][b]=='J'&& maze[aa][bb]==0)
                return dist[a][b];
            if((maze[aa][bb]=='.'||maze[aa][bb]=='J')&&dist[aa][bb]==-1)
            {
                dist[aa][bb]=dist[a][b]+1;
                maze[aa][bb]=maze[a][b];
                que.push(pii(aa,bb));
            }
        }
    }
    return -1;
}

int main()
{
    int cases, R, C;
    cin>> cases;
    while(cases--)
    {
        cin>> R>> C;
        fires.clear();
        memset(maze,0,sizeof(maze));
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='F')
                    fires.push_back(pii(i, j));
                if(maze[i][j]=='J')
                    J=pii(i,j);
            }
        }
        int ans=floodfill();
        if(ans==-1) cout<<"Impossible"<<endl<<" "<<endl;
        else cout<<ans<<endl;
    }
}
