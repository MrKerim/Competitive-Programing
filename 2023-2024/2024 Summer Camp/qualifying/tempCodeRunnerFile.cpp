#include <iostream>
#include <vector>

using namespace std;
int32_t main(){
    int n,m,c; cin>>n>>m>>c;
    vector<int> stocks(n,0);
    for (int i = 0; i < n; i++) cin >> stocks[i];
    vector<pair<int,int> > constrains;
    for (int i = 0; i < c; i++)
    {
        int c1,c2; cin >> c1 >> c2;
        constrains.push_back(make_pair(c1,c2));
    }

    string binary = bitset<8>(5).to_string();
    cout << binary << endl;

}