#include <bits/stdc++.h>
#define MAX 200011
using namespace std;

void preKmp(string x, int m, int kmpNext[]) {
   int i, j;
 
   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}
 
 
void KMP(string x, int m, string y, int n) {
   int i, j, kmpNext[MAX];
 
   /* Preprocessing */
   preKmp(x, m, kmpNext);
 
   /* Searching */
   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         cout<<(j - i);
         i = kmpNext[i];
      }
   }
}
int main()
{
    string txt = "00000";
    string pat = "00";
    KMP(pat,pat.size(), txt,txt.size());
    return 0;
}