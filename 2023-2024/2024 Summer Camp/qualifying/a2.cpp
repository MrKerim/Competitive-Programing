#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#define int long long

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

    int all_possible_per = (1<<n)-1;

    int max_sum = 0;
    for (int bit_map = 0; bit_map < all_possible_per; bit_map++)
    {
        string binary = bitset<20>(bit_map).to_string();
        reverse(binary.begin(), binary.end());
        bool check = true;
        for(auto c : constrains){
            if(binary[c.first] != binary[c.second] ) {
                check = false;
                break;
            }
        }
        if(!check) continue;

        int sum = 0;
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (bit_map & (bit_map << j)) {
                sum += stocks[j];
                count++;
            }
        }
        if (count != m) continue;
        max_sum = max(max_sum,sum);
    }
    
    cout << max_sum << endl;
}