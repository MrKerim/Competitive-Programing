#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long int
using namespace std;

const int64_t INF = 1e17;
const int mod = 1e9+7;

struct Node {
    Node* child[2];
    int visit;
};

Node* root = new Node();

int get_bit(int x, int i) {
    if (((1 << i) & x) != 0) {
        return 1;
    }
    return 0;
}

void insert(int x) {
    Node* curr = root;
    for (int i = 30; i >= 0; i--) {
        int c = get_bit(x, i);
        if (curr->child[c] == nullptr) {
            curr->child[c] = new Node();
        } 
        curr = curr->child[c];
        curr->visit++;
    }
}

void erase(int x) {
    Node* curr = root;
    for (int i = 30; i >= 0; i--) {
        int c = get_bit(x, i);
        Node* parent = curr;
        curr = curr->child[c];
        curr->visit--;
        if (curr->visit == 0) {
            parent->child[c] = nullptr;
        }
    }
}

int max_xor(int x) {
    Node* curr = root;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int c = get_bit(x, i);
        if (curr->child[c ^ 1] == nullptr) {
            curr = curr->child[c];
        }
        else {
            curr = curr->child[c ^ 1];
            ans += (1 << i);
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;

    insert(0);

    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') {
            insert(x);
        }
        if (c == '-') {
            erase(x);
        }
        if (c == '?') {
            cout << max_xor(x) << endl;
        }
    }
}