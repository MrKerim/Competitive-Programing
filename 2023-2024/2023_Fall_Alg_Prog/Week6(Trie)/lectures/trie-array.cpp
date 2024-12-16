#include <map>
#include <iostream>
#define all(x) (x).begin(), (x).end()
#define int long long int
using namespace std;

const int64_t INF = 1e17;
const int mod = 1e9 + 7;

struct Node
{
    map<char, int> child;
    int visit=0;
};

Node nodes[10000000];
int last_index = 2;

void insert(string s)
{
    int curr = 1;
    for (auto c : s)
    {
        if (nodes[curr].child.count(c) == 0)
        {
            nodes[curr].child[c] = last_index++;
        }
        curr = nodes[curr].child[c];
        nodes[curr].visit++;
    }
}

int search(string s)
{
    int curr = 1;
    for (auto c : s)
    {
        if (nodes[curr].child.count(c) == 0)
        {
            return 0;
        }
        curr = nodes[curr].child[c];
    }
    return nodes[curr].visit;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << search(s) << endl;
    }
}