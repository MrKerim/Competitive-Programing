#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define fastio                        \
  ::ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                      \
  cout.tie(NULL);

int arr[200001], tree[800004], lazy[800004], prefix_sum[200001];

void push(int ind, int l, int r)
{
  int val = lazy[ind];
  tree[ind] += val;
  lazy[ind] = 0;
  if (l == r)
    return;
  lazy[ind * 2] += val;
  lazy[ind * 2 + 1] += val;
}

// range update
void range_update(int ind, int l, int r, int a, int b, int val)
{
  push(ind, l, r);
  if (l > b || r < a)
    return;
  if (l >= a && r <= b)
  {
    lazy[ind] += val;
    push(ind, l, r);
    return;
  }

  int mid = (l + r) / 2;
  range_update(ind * 2, l, mid, a, b, val);
  range_update(ind * 2 + 1, mid + 1, r, a, b, val);
  tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
}

int query(int ind, int l, int r, int a, int b)
{
  push(ind, l, r);
  if (l > b || r < a)
    return INT64_MIN;
  if (l >= a && r <= b)
    return tree[ind];
  int mid = (l + r) / 2;
  int t1 = query(ind * 2, l, mid, a, b);
  int t2 = query(ind * 2 + 1, mid + 1, r, a, b);
  return max(t1, t2);
}

void build(int ind, int l, int r)
{
  if (l == r)
  {
    tree[ind] = prefix_sum[l];
    return;
  }
  int mid = l + (r - l) / 2;
  build(2 * ind, l, mid);
  build(2 * ind + 1, mid + 1, r);
  tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
}

void solution()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }
  build(1, 1, n);
  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int k, u;
      cin >> k >> u;
      range_update(1, 1, n, k, n, u - arr[k]);
      arr[k] = u;
    }
    if (type == 2)
    {
      int a, b;
      cin >> a >> b;
      int sol = query(1, 1, n, a, b);
      if (a != 1)
      {
        sol -= query(1, 1, n, a - 1, a - 1);
      }

      if (sol < 0)
      {
        sol = 0;
      }
      cout << sol << endl;
    }
  }
}
int32_t main()
{
  fastio;
  solution();
}