#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define fastio                        \
  ::ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                      \
  cout.tie(NULL);

int arr[200001], tree[800004];

void update(int ind, int l, int r, int a, int b, int val)
{
  if (l > b || r < a)
    return;
  if (l >= a && r <= b)
  {
    tree[ind] = val;
    return;
  }

  int mid = (l + r) / 2;
  update(ind * 2, l, mid, a, b, val);
  update(ind * 2 + 1, mid + 1, r, a, b, val);
  tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
}

int query(int ind, int l, int r, int a, int b)
{
  if (l > b || r < a)
    return 0;
  if (l >= a && r <= b)
    return tree[ind];
  int mid = (l + r) / 2;
  int t1 = query(ind * 2, l, mid, a, b);
  int t2 = query(ind * 2 + 1, mid + 1, r, a, b);
  return max(t1, t2);
}

void solution()
{
  int n;
  cin >> n;

  vector<pair<int, int>> elems;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    elems.push_back({arr[i], -i});
  }
  sort(elems.begin(), elems.end());
  for (auto x : elems)
  {
    int max_lis = query(1, 1, n, 1, -x.second - 1) + 1;
    update(1, 1, n, -x.second, -x.second, max_lis);
  }
  cout << tree[1];
}
int32_t main()
{
  fastio;
  solution();
}