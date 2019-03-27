#define int_size 32
struct Node {
	int value;
	Node *parent;
	Node *child[2];
 
} root;
inline Node *Define(Node *p) {
	Node *ptr = new Node;
	(*ptr).value = 0;
	(*ptr).parent = p;
	(*ptr).child[0] = NULL;
	(*ptr).child[1] = NULL;
	return ptr;
}
inline void insert(int x, int t) {
	Node *foo;
	foo = &root;
	for(int i=int_size-1; i>=0; i--) {
		bool res = (((1<<i)&x) > 0);
if((*foo).child[res] == NULL) (*foo).child[res] = Define(foo);
		foo = (*foo).child[res];
	}
	(*foo).value += t;
	if((*foo).value == 0) {
		for(int i=0; i<int_size; i++) {
			foo = (*foo).parent;
			int res = (int) ((((1<<i)&x) > 0));
			(*foo).child[res] = NULL;
			if((*foo).child[1-res] != NULL) break;
		}
	}
}
inline int query(int x) {
	Node *foo;
	foo = &root;
	int ans = 0;
	for(int i=int_size-1; i>=0; i--) {
		bool res = (((1<<i)&x) > 0);
		if((*foo).child[1-res] != NULL) {
			if(res == 0) ans ^= (1<<i);
			foo = (*foo).child[1-res];
		}
		else {
			if(res == 1) ans ^= (1<<i);
			foo = (*foo).child[res];
		}
	}
	return ans;
}