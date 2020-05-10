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

    if(n==0)return 1;
    if(Lad[n]!=0)return Lad[n];
	if(n>=1) Lad[n]+=ladder(n-1);
	if(n>=2) Lad[n]+=ladder(n-2);
	if(n>=3) Lad[n]+=ladder(n-3);
	return Lad[n];
}
