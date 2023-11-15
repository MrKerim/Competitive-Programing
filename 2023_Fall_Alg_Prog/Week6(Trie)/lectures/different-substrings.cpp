#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long int
using namespace std;

const int64_t INF = 1e17;
const int mod = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    string s;
    cin >> s;
    int n = s.size();

    s = " " + s;

    int x = 47;
    vector<int> h(100000);
    vector<int> p(100000, 1);

    for(int i = 1; i <= n; i++) {
        h[i] = (h[i-1] * x + (s[i] - 'a' + 1));
    }

    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * x;
    }


    auto range_h = [&](int l, int r) {
        return ((h[r] - h[l - 1] * p[r - l + 1]));
    };

    unordered_set<int> ans;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ans.insert(range_h(l, r));
        }
    }

    cout << ans.size() << endl; 

}