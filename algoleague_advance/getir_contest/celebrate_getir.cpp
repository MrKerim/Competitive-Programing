#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

vector<int> dijkstra(int start, const vector<vector<pair<int,int> > > &graph,int n){
    vector<int> dist_from_start(n,INT32_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > queue;

    dist_from_start[start] = 0;
    queue.push(make_pair(0,start));

    while(!queue.empty()){
        long long dist = queue.top().first;
        int current_node = queue.top().second;
        queue.pop();
        if (dist > dist_from_start[current_node]) continue;
        for(auto neighbor:graph[current_node]){
            if(dist_from_start[current_node] + neighbor.first < dist_from_start[neighbor.second])
            {
                dist_from_start[neighbor.second] = dist_from_start[current_node] + neighbor.first;
                queue.push(make_pair(dist_from_start[neighbor.second],neighbor.second));
            }
        }
    
    }

    return dist_from_start;

}


//every call represent the courier c and the before state s of houses

vector<vector<int> > dp;
int cal_dp_matrix(int getir_courier,const vector<vector<int> >&dp_matrix,int availability,int k){
    if(getir_courier==k) return 0;
    if(dp[getir_courier][availability]!=-1) return dp[getir_courier][availability];
    int ans = INT64_MAX;
    for (int i = 0; i < k; i++)
    {
        // Here availiblity is the state of the available houses in the form of an integer : 00000.. or 000111001..
        // We need to look if a house is available or not then we just need to check it for that house  ava..& 0001000
        // To do this for every house we can use the left shit operation i<<i in this way we can check every house:
        if(!(availability & 1<<i)){
            // It's available then let's take the min of every available roads.
            ans = min(ans, cal_dp_matrix(getir_courier+1,dp_matrix, (availability | (1<<i)),k) + dp_matrix[getir_courier][i]*dp_matrix[getir_courier][i] );

        }
    }
    dp[getir_courier][availability]=ans;
    return ans;
    

}


int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;

    //Graph initialization
    vector<vector<pair<int,int> > > graph(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,w; cin>>a>>b>>w;
        a--;b--;
        graph[a].push_back(make_pair(w,b));
        graph[b].push_back(make_pair(w,a));
    }

    // k coruiers and k houses
    vector<int> courier(k);
    for (int i = 0; i < k; i++)
    {
        int q;cin>>q;q--;
        courier[i]=q;
    }
    
    vector<int> houses(k);
    for (int i = 0; i < k; i++)
    {
        int q;cin>>q;q--;
        houses[i]=q;
    }

    vector<vector<int> > dp_matrix(k);
    for (int i = 0; i < k; i++)
    {
        vector<int> result = dijkstra(courier[i],graph,n);
        for (int j = 0; j < k; j++)
        {
            dp_matrix[i].push_back(result[houses[j]]);
        }
        
    }

    // dp_matrix
    // What we have is a matrix of kxk; which represent the distance between the corier (row)
    // and the house (colum). What we need to do is calculate every possible pattern to find
    // the minimum possible cost
    dp.resize(k,vector<int>(1<<k,-1));
    cout<<cal_dp_matrix(0,dp_matrix,0,k)<<endl;

}
