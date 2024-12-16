#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long int
using namespace std;

const int64_t INF = 1e17;
const int mod = 1e9+7;

struct Node {
    map<char, Node*> child;
    int visit;
};

Node* root = new Node();

void insert(string s) {
    Node* curr = root;
    for (auto c : s) {
        if (curr->child.count(c) == 0) {
            curr->child[c] = new Node();
        } 
        curr = curr->child[c];
        curr->visit++;
    }
}

int search(string s) {
    Node* curr = root;
    for (auto c : s) {
        if (curr->child.count(c) == 0) {
            return 0;
        } 
        curr = curr->child[c];
    }
    return curr->visit;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << search(s) << endl;
    }
}