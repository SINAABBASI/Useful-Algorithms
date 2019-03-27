int mul_tree[max_n];
int add_tree[max_n];

void internalUpdate(int idx, int mul, int add) {
  while(idx < MAXN) {
    mul_tree[idx] += mul;
    add_tree[idx] += add;
    idx += (idx & -idx);
  }
}
void update(int l, int r, int val) {
  internalUpdate(l, val, -val * (l - 1));
  internalUpdate(r+1, -val, val * r);
}
int query(int idx) {
  int mul = 0;
  int add = 0;
  int start = idx;
  while(idx > 0) {
    mul += mul_tree[idx];
    add += add_tree[idx];
    idx -= (idx & -idx);
  }
  return mul * start + add;
}