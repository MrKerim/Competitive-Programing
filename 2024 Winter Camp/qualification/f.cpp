#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
using namespace std;

bool greedy(int start,int end,vector<int> &ballons,int target,int pre_result,map<int,int> &mp){
    if(start>end) return false;
    pre_result += ballons[start];
    mp[pre_result] = 1;
    if (pre_result == target) return true;
    else if(pre_result > target) return false;
    else{
        for (int i = start+1; i <=end; i++)
        {
            if(greedy(i,end,ballons,target,pre_result,mp)) return true;
        }
        return false;
        
    }
    
}

int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> ballons(n),predictions(m);
    for(int i=0;i<n;i++) cin >> ballons[i];
    for(int i=0;i<m;i++) cin >> predictions[i];
    sort(ballons.begin(),ballons.end());
    map<int,int> mp;
    // We will use greedy aproach and let's see if it pass thorugh time limit
    // And also used map to store the values so that may be we can get pass thrpugh the time limit
    for (int i = 0; i < m; i++)
    {
        if(mp[predictions[i]]) cout<<"yes"<<endl;
        else{
            if(greedy(0,n-1,ballons,predictions[i],0,mp)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
    

}