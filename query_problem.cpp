#include <bits/stdc++.h> 
using namespace std;
#define fr first
#define sc second
const int N=1<<20;

int segm_tree[2*N];

void update(int node, int left, int right, int x, int y) {
    if (left == right) { //we are in the xth leaf
        segm_tree[node] = y;
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) { //we need to update the left son
            update(2 * node + 1, left, middle, x, y);
        } else {
            update(2 * node + 2, middle + 1, right, x, y);
        }
        //after updating said son, recalculate the current segment
        recalculate(node);
    }
}

void build(int node, int left, int right) { //"node" is the index in the array, while "left"
                                            // and "right" are the ends of the current segment
    if (left == right) {
        segm_tree[node] = a[left]; //we are in a leaf node
    } else {
        int middle = (left + right) / 2;
        build(2 * node + 1, left, middle);
        build(2 * node + 2, middle + 1, right);
        recalculate(node);
    }
}

int query(int node, int left, int right, int x, int y) {
    if (x <= left && right <= y) {
        //the segment of "node" is completely included in the query
        return segm_tree[node];
    } else {
        int answer = -inf;
        int middle = (left + right) / 2;
        if (x <= middle) {
            //the query segment and the left son segment have at least one element in common
            answer = max(answer, query(2 * node + 1, left, middle, x, y));
        }
        if (y >= middle + 1) {
            //the query segment and the right son segment have at least one element in common
            answer = max(answer, query(2 * node + 2, middle + 1, right, x, y));
        }
        return answer;
    }
}

int main(){
	build(0,0,len-1);
	return 0;
}