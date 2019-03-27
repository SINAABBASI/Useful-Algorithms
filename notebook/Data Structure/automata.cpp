// in the name of Allah

#include <bits/stdc++.h>

#define endl '\n'
#define mod 1000000007
#define sz(x) ((int) (x.size()))

using namespace std;

int szs;
int aut[1000][26];

void zombie(string s) {
	szs = sz(s);
	memset(aut, 0, sizeof aut);
	aut[0][s[0]-'A'] = 1;
	int back = 0;
	for(int i=1; i<szs; i++) {
		aut[i][s[i] - 'A'] = i+1;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(c == s[i]) continue;
			aut[i][c - 'A'] = aut[back][c - 'A'];
		}
		back = aut[back][s[i] - 'A'];
	}
}

char out[3000003];
int state[3000003];

void process(string s) {
	int end = 0;
	state[0] = 0;
	for(int i=0; i<sz(s); i++) {
		int st = state[end];
		if(s[i] < 'A' || 'Z' < s[i]) {
			out[end++] = s[i];
			state[end] = 0;
		}
		else {
			st = aut[st][s[i] - 'A'];
			if(st == szs) end -= (szs - 1);
			else {
				out[end++] = s[i];
				state[end] = st;
			}
		}
	}
	out[end] = 0;
	puts(out);
}

int main() {
	int T;
	string line, s;
	while(getline(cin, line)) {
		stringstream in(line);
		in >> T >> s;
		zombie(s);
		while(T--) {
			getline(cin, line);
			process(line);
		}
	}
	return 0;
}