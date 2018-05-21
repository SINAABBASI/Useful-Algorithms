#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long
#define MAX 1000001
int multiple(int x,int res[],int res_size);


void fac(int n){
    int res[MAX];
	res[0]=1;
	int res_size=1;
	for(int x=2;x<=n;x++)
		res_size=multiple(x,res,res_size);
	for(int i=res_size-1;i>=0;i--)cout<<res[i];
}

int multiple(int x,int res[],int res_size){
	int carry=0;
	for(int i=0;i<res_size;i++){
		int p=res[i]*x+carry;
		res[i] = p % 10;
		carry = p/10;
	}
	while	(carry){
		res[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}
	return res_size;
}
int main(){
	int n;
	cin>>n;

	fac(n);
}