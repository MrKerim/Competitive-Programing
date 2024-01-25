#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long

vector<int> BFS_search(vector<vector<char> > &graph,vector<vector<bool> > &visited ,pair<int,int> start_node){
    vector<int> row(graph[0].size(),0);
    queue<pair<int,int> > que;
    que.push(start_node);
    visited[start_node.first][start_node.second]=true;

    while (!que.empty())
    {
        pair<int,int> current_node = que.front();
        que.pop();
        
        row[current_node.second]++;
        vector<pair<int,int> > neighbors;
        neighbors.push_back(make_pair(current_node.first+1,current_node.second));
        neighbors.push_back(make_pair(current_node.first,current_node.second+1));
        neighbors.push_back(make_pair(current_node.first-1,current_node.second));
        neighbors.push_back(make_pair(current_node.first,current_node.second-1));
        for(pair<int,int> neighbor:neighbors){
            if(neighbor.first>=0 && neighbor.first<graph.size() && neighbor.second>=0 && neighbor.second<graph[0].size() ){
                if (graph[neighbor.first][neighbor.second]=='#'&& !visited[neighbor.first][neighbor.second])
                {
                que.push(neighbor);
                visited[neighbor.first][neighbor.second]=true;
                }
            }
        }
        
        
    }
    return row;
}

int32_t main(){
    int q;cin>>q;
    while (q--)
    {
        int r,c;cin>>r>>c;
        vector<vector<char> > graph(r,vector<char>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin>>graph[i][j];
            }
            
        }
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        vector<vector<int> > rows;
        for (int i = 0; i < r; i++) { for (int j = 0; j < c; j++) {
            if (graph[i][j]=='#' && !visited[i][j])
                {
                rows.push_back(BFS_search(graph,visited,make_pair(i,j)));
                }
            } 
        }

        
        for(int tide_row = 0; tide_row < c; tide_row++){
            int ans=0;
            for (int island = 0; island < rows.size(); island++)
            {   
                int ans1=0,ans2=0;
                for (int counter = 0; counter < tide_row; counter++) { ans1+= rows[island][counter]; }
                for(int counter = tide_row+1; counter < c; counter++) { ans2+= rows[island][counter]; }
                ans+=ans1*ans1 + ans2*ans2;
            }
            if(tide_row==c-1) cout<<ans;
            else cout<<ans<<" ";
            
        }
        if (q!=0) cout<<endl;
    }
}