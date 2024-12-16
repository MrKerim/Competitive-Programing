#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int BFS_A(vector<string> &farm, vector<vector<int>> &dp, pair<int,int> startingPoint){
    vector<vector<bool> >visited(farm.size(),vector<bool>(farm[0].size(),false));
    queue<pair<int,int>> q;
    q.push(startingPoint);
    visited[startingPoint.first][startingPoint.second] = true;
    dp[startingPoint.first][startingPoint.second] = 0;
    // if the starting point is on the border
    if(startingPoint.first == 0 || startingPoint.first == farm.size()-1 || startingPoint.second == 0 || startingPoint.second == farm[0].size()-1) return 0;
    
    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if(x-1 >= 0 && !visited[x-1][y] && farm[x-1][y] != '#'){
            visited[x-1][y] = true;

            if(dp[x-1][y] > dp[x][y]+1){
                dp[x-1][y] = dp[x][y]+1;
                q.push({x-1,y});
                if(x-1 == 0 || x-1 == farm.size()-1 || y == 0 || y == farm[0].size()-1) return dp[x-1][y];
            }


        }
        if(x+1 < farm.size() && !visited[x+1][y] && farm[x+1][y] != '#'){
            visited[x+1][y] = true;
            
            if(dp[x+1][y] > dp[x][y]+1){
                dp[x+1][y] = dp[x][y]+1;
                q.push({x+1,y});
                if(x+1 == 0 || x+1 == farm.size()-1 || y == 0 || y == farm[0].size()-1) return dp[x+1][y];
            }

        }
        if(y-1 >= 0 && !visited[x][y-1] && farm[x][y-1] != '#'){
            visited[x][y-1] = true;
            
            if(dp[x][y-1] > dp[x][y]+1){
                dp[x][y-1] = dp[x][y]+1;
                q.push({x,y-1});
                if(x == 0 || x == farm.size()-1 || y-1 == 0 || y-1 == farm[0].size()-1) return dp[x][y-1];
            }
        }
        if(y+1 < farm[0].size() && !visited[x][y+1] && farm[x][y+1] != '#'){
            visited[x][y+1] = true;
            
            if(dp[x][y+1] > dp[x][y]+1){
                dp[x][y+1] = dp[x][y]+1;
                q.push({x,y+1});
                if(x == 0 || x == farm.size()-1 || y+1 == 0 || y+1 == farm[0].size()-1) return dp[x][y+1];    
            }
        }
    }

    return -1;
}


void BFS_tractor(vector<string> &farm, vector<vector<int>> &dp, vector<pair<int,int>> &tractors){
    vector<vector<bool> >visited(farm.size(),vector<bool>(farm[0].size(),false));
    queue<pair<int,int>> q;

    for(auto tractor: tractors){
        q.push(tractor);
        visited[tractor.first][tractor.second] = true;
        dp[tractor.first][tractor.second] = 0;
    }

    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        if(x-1 >= 0 && !visited[x-1][y] && farm[x-1][y] != '#'){
            
            visited[x-1][y] = true;

            if(dp[x-1][y]< dp[x][y]+1) continue;
            else {dp[x-1][y] = dp[x][y]+1; q.push({x-1,y});}
        }
        if(x+1 < farm.size() && !visited[x+1][y] && farm[x+1][y] != '#'){
            
            visited[x+1][y] = true;
            
            if(dp[x+1][y]< dp[x][y]+1) continue;
            else {dp[x+1][y] = dp[x][y]+1; q.push({x+1,y});}


        }
        if(y-1 >= 0 && !visited[x][y-1] && farm[x][y-1] != '#'){
            
            visited[x][y-1] = true;

            if(dp[x][y-1]< dp[x][y]+1) continue;
            else {dp[x][y-1] = dp[x][y]+1; q.push({x,y-1});}

        }
        if(y+1 < farm[0].size() && !visited[x][y+1] && farm[x][y+1] != '#'){
            visited[x][y+1] = true;

            if(dp[x][y+1]< dp[x][y]+1) continue;
            else {dp[x][y+1] = dp[x][y]+1; q.push({x,y+1});}
        }
    }
    
}

int32_t main(){
    int n,m; cin>>n>>m;
    vector<string> farm;
    pair<int,int> startingPoint;
    vector<pair<int,int> > tractors;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        farm.push_back(s);
        for (int j = 0; j < m; j++)
        {
            if(s[j] == 'A') startingPoint = {i,j};
            else if(s[j] == 'M') tractors.push_back({i,j});
        }
    }

    vector<vector<int> > dp(n,vector<int>(m,INT32_MAX));
    BFS_tractor(farm,dp,tractors);

    int result = BFS_A(farm,dp,startingPoint);
    cout<<result<<endl;


}