#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_V 50
vector<int> G[MAX_V];
bool visited[MAX_V];
void dfs(int node) {
	cout<<node<<endl;
    visited[node] = true;
    for (auto neighbour: G[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(visited,0,sizeof(visited));
	dfs(1);
}
