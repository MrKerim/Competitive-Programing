#include <iostream>
#include <vector>
#include <queue>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define INF 1e18
using namespace std;
pair<int,int> unit[4] = {make_pair(0,1),make_pair(1,0),make_pair(-1,0),make_pair(0,-1)};


vector<vector<int> > dijkstra_labyrinth_solver(int r,int c,pair<int,int> start,pair<int,int> end,vector<vector<char> > matrix
,vector<vector<int> > distance) {

    priority_queue< pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<int,int> current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distance[current_node.first][current_node.second]) continue;
        for (pair<int,int> dimension :unit){
            pair<int,int> neighbor = make_pair(dimension.first+current_node.first,dimension.second + current_node.second);
            if(neighbor.first<r && neighbor.first>= 0 && neighbor.second<c && neighbor.second >= 0){
            if( matrix[neighbor.first][neighbor.second]!='*' ){  
            if(distance[current_node.first][current_node.second] + 1 < distance[neighbor.first][neighbor.second])
            {
                distance[neighbor.first][neighbor.second] = distance[current_node.first][current_node.second] + 1;
                if(neighbor.first==end.first && neighbor.second == end.second) return distance;

                pq.push(make_pair(distance[neighbor.first][neighbor.second],neighbor));
         
            }
            }
        }
        }
    }

    return distance;
}

int32_t main(){
    int r,c;cin>>r>>c;
    pair<int,int> start;
    pair<int,int> end;
    vector<vector<char> > matrix(r,vector<char> (c));
    for (int i = 0; i < r; i++){ for (int j = 0; j < c; j++){ 
    char inp;cin>>inp; matrix[i][j]=inp; if(inp=='A') start = make_pair(i,j); if(inp =='B') end =  make_pair(i,j);
    } }
    vector<vector<int> > distance(r,vector<int> (c,INF));
    distance[start.first][start.second] = 0;

    vector<vector<int> > result = dijkstra_labyrinth_solver(r,c,start,end,matrix,distance);
    if(result[end.first][end.second]==INF){cout<<-1<<endl; return 0;}
    cout<<result[end.first][end.second]<<endl;
    return 0;
}