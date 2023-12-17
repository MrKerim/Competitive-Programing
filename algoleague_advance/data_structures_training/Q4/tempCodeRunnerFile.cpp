#include <iostream>
#include <map>
#include <stack>
using namespace std;
int32_t main(){
    int n,m;cin>>n>>m;
    map<int,int> mp;
    stack<int> will_be_deleted_keys;
    for (int i = 0; i < m; i++)
    {
        int x;cin>>x;
        mp[x]++;
        if(mp.size()==n){
            cout<<"Y";
            for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                if(itr->second == 1){
                    will_be_deleted_keys.push(itr->first);
            }
            else{
                mp[itr->first]--;
            }
            }
            while (!will_be_deleted_keys.empty())
            {
                mp.erase(will_be_deleted_keys.top());
            }
            
        }
        else{
            cout<<"N";
        }
    }
    cout<<endl;
    
}