#include <iostream>
#include <vector>

using namespace std;
int32_t main(){
    vector<pair<int,int> > connected;
    int n,m; cin>>n>>m;
    vector<vector<int> > graph(n);
    for (int i = 0; i < m; i++)
    {   int a,b; cin>>a>>b;
    a--;b--;
        graph[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {  
        sort(graph[i].begin(),graph[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        for(int neighbor : graph[i]){
            if(count(graph[neighbor].begin(), graph[neighbor].end(), i)!=0){
                if(i<neighbor){
                    if(count(connected.begin(),connected.end(),make_pair(i,neighbor))==0){
                    connected.push_back(make_pair(i,neighbor));}
                }
                else{
                    if(count(connected.begin(),connected.end(),make_pair(neighbor,i))==0){
                    connected.push_back(make_pair(neighbor,i));}}
            }
        }
    }
    
    cout<<connected.size()<<endl;
    sort(connected.begin(),connected.end());
    for (int i = 0; i < connected.size(); i++)
    {
        cout<<connected[i].first+1<<" "<<connected[i].second+1<<endl;
    }
    
    
    
    return 0;
}