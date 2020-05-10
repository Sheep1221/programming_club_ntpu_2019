#include<iostream>
#define N 105

int main()
{
	using namespace std;
	int row, col, input[N][N]={}, counting[N][N]={};
	cin>>row>>col;
	for(int r=0; r<row; r++)
	{
		for(int c=0; c<col; c++)
		{
			cin>>input[r][c];
		}
	}
	if(row==1&&col==1)
	counting[0][0]==0;
	if(row==1)
	{
		for(int c=0; c<col; c++)
		{
			if(c==0)
			counting[0][0]=input[0][1];
			else if (c==col-1)
			counting[0][c]=input[0][c-1];
			else
			counting[0][c]=input[0][c-1]+input[0][c+1];
		}
	}
	else if(col==1)
	{
		for(int r=0; r<row; r++)
		{
			if(r==0)
			counting[0][0]=input[1][0];
			else if (r==row-1)
			counting[r][0]=input[r-1][0];
			else
			counting[r][0]=input[r-1][0]+input[r+1][0];
		}
	}

	for(int r=0; r<row; r++)
	{
		for(int c=0; c<col; c++)
		{
			if(r==0)
			{
				if(c==0)
				counting[r][c]=input[r][c+1]+input[r+1][c]+input[r+1][c+1];
				else if(c==col-1)
				counting[r][c]=input[r][c-1]+input[r+1][c]+input[r+1][c-1];
				else
				counting[r][c]=input[r][c+1]+input[r+1][c+1]+input[r+1][c]+input[r+1][c-1]+input[r][c-1];
			}
			else if(r==row-1)
			{
				if(c==0)
				counting[r][c]=input[r][c+1]+input[r-1][c]+input[r-1][c+1];
				else if(c==col-1)
				counting[r][c]=input[r][c-1]+input[r-1][c]+input[r-1][c-1];
				else
				counting[r][c]=input[r][c+1]+input[r-1][c+1]+input[r-1][c]+input[r-1][c-1]+input[r][c-1];
			}
			else
			{
				if(c==0)
				counting[r][c]=input[r+1][c]+input[r+1][c+1]+input[r][c+1]+input[r-1][c+1]+input[r-1][c];
				else if(c==col-1)
				counting[r][c]=input[r+1][c]+input[r+1][c-1]+input[r][c-1]+input[r-1][c-1]+input[r-1][c];
				else
				counting[r][c]=input[r+1][c]+input[r+1][c+1]+input[r][c+1]+input[r-1][c+1]+input[r-1][c]+input[r-1][c-1]+input[r][c-1]+input[r+1][c-1];;
			}
		}
	}

	for(int r=0; r<row; r++)
	{
		cout<<counting[r][0];
		for(int c=1; c<col; c++)
		{
			cout<<" "<<counting[r][c];
		}
		cout<<endl;
	}
}
