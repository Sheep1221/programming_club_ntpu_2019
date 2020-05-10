#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	stack<int> sta;
	queue<int> que;
	priority_queue<int> pq;
	
	while(cin>>n)
	{
		while(sta.size())sta.pop();
		while(que.size())que.pop();
		while(pq.size())pq.pop();
		
		int type, data;
		bool issta, isque, ispq;
		issta=isque=ispq=true;
		
		while(n--)
		{
		    cin>> type>>data;
		    switch (type){
		    case 1:{
			    sta.push(data);
			    que.push(data);
			    pq.push(data);
			    break;
		    }
		    case 2:{
			    if(sta.empty()||sta.top()!=data)
			    issta=false;
			    if(que.empty()||que.front()!=data)
				isque=false;
				if(pq.empty()||pq.top()!=data)
				ispq=false;
				if(!sta.empty())
				sta.pop();
				if(!que.empty())
				que.pop();
				if(!pq.empty())
				pq.pop(); 
			    break;
		    }
		    }
	    }
		if(issta&&!isque&&!ispq)
		cout<<"stack"<<endl;
		else if(!issta&&isque&&!ispq)
		cout<<"queue"<<endl;
		else if(!issta&&!isque&&ispq)
		cout<<"priority queue"<<endl;
		else if(!issta&&!isque&&!ispq)
		cout<<"impossible"<<endl;
		else
		cout<<"not sure"<<endl;
		
	} 
}
