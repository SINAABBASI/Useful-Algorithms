#include <bits/stdc++.h>
using namespace std;

struct node
{ 
	node *child[26];
	bool isEnd;
};


node *getnode(){
	node *pNode = new node;
	pNode->isEnd = false;
	for(int i = 0; i < 26 ; i++){
		pNode->child[i] = NULL;
	}
	return pNode;
}

node root = getnode();

void insert(string key){
	node *cur = root;
	for(int i = 0;i < key.length() ;i ++){
		int  in = key[i] - 'a';
		
		if(! cur->child[in])
			cur->child[in] = getnode();

		cur = cur->child[in];
	}
	cur->isEnd = true;
	return;
}

bool find(string key){
	node *cur = root;
	for(int i = 0; i < key.length(); i++){
		int in = key[i] - 'a';
		
		if(!cur->child[in]) return false;

		cur = cur->child[in];
	}
	return (cur != NULL && cur->isEnd );
}

int main(){
	int n,q;
	string s;
	cin>>n>>q;
	for(int i =0 ; i < n ; i++){
		cin>>s;
		insert(s);
	}
	while(q--){
		cin>>s;
		if(find(s))cout<<"yes";
		else cout<<"no";
		cout<<endl;
	}
}