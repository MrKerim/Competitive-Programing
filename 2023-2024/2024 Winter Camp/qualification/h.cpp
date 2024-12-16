#include <iostream>
#include <vector>
#include <map>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main(){
    int n,m;cin >> n >> m;
    vector<int> inputA(n,0);
    vector<int> inputB(m,0);
    map<int,int> inputA_map;
    map<int,int> inputA_map_check;
    // We will stro the inputs as well as the bridges by using map and store them in an array of pairs
    vector<pair<int,int> > bridges; bridges.push_back(make_pair(-1,-1));
    for(int i=0;i<n;i++) {cin >> inputA[i]; inputA_map[inputA[i]]=i; inputA_map_check[inputA[i]]=1;}
    for(int i=0;i<m;i++) {cin >> inputB[i];
    if(inputA_map_check[inputB[i]]) bridges.push_back(make_pair(inputA_map[inputB[i]],i));}
    inputA.push_back(0); inputB.push_back(0);
    bridges.push_back(make_pair(n,m)); // To make the end of the road connected
    // Now we have the bridges and wee will calculate the max possible score by selecting
    int sum = 0;
    for (int brd = 1; brd < bridges.size(); brd++)
    {
        int roadA = 0; for(int j = bridges[brd-1].first+1;j<=bridges[brd].first;j++) roadA = (roadA + inputA[j])%MOD;
        int roadB = 0; for(int j = bridges[brd-1].second+1;j<=bridges[brd].second;j++) roadB = (roadB + inputB[j])%MOD;
        sum = (sum + max(roadA,roadB))%MOD;
    }
    cout << sum << endl;
}