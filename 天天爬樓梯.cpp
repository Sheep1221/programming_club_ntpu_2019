#include<iostream>

int ladder(int n);

int main()
{
	int n;
	std::cin >> n;
	std::cout << ladder(n) << '\n';
	return 0;
}

int Lad[35]={0};
int ladder(int n){
	if(n==1)return 1;
	if(n==2)return 2;
	if(n==3)return 4;
	if(Lad[n]!=0)return Lad[n];
	return Lad[n]=ladder(n-1)+ladder(n-2)+ladder(n-3);
}
