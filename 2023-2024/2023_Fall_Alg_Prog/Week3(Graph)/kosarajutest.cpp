#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

// Function to perform DFS starting from a given vertex
void DFS(int v, const vector<vector<int> >& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFS(i, adj, visited, Stack);
        }
    }

    // Push the current vertex to the stack after its DFS is complete
    Stack.push(v);
}

// Function to find strongly connected components
int printSCCs(const vector<vector<int> >& adj,const vector<vector<int> > & transpose, int V) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Perform DFS and fill the stack
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            DFS(v, adj, visited, Stack);
        }
    }


    // Reset visited array
    fill(visited.begin(), visited.end(), false);

    // Process vertices in the order defined by the stack
    int count = 0;
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            // Perform DFS on the transpose starting from the popped vertex
            DFS(v, transpose, visited, Stack);
            count++;
        }
    }
    return count;
}

int main() {
    int n,s;cin>>n>>s;
    vector<vector<int> > graph(n+s);
    vector<vector<int> > transpose(n+s);
    for(int i = 0;i<n-1;i++){
        graph[i].push_back(i+1);
        transpose[i+1].push_back(i);
    }
    for (int i = n ; i < n+s-1; i++)
    {
        graph[i].push_back(i+1);
        transpose[i+1].push_back(i);
    }

    // Getting the portal values and assign them to heao
    // SO that we can acces elements in the increasing order
    int p;cin>>p;
    vector< priority_queue<int> > portals(n);
    while(p--){
        int a,b;cin>>a>>b;
        a--; b+=n-1;
        portals[a].push(b);
    }


    int south_max = -1;
    int north_max = -1;
    for(int north_node = 0;north_node < n;north_node ++){
        while(!portals[north_node].empty()){
            int south_node = portals[north_node].top();
            portals[north_node].pop();
            if(south_node > south_max) {

                if(north_node>north_max){
                // There is no crossection
                // Then this node is a type
                graph[south_node].push_back(north_node);
                transpose[north_node].push_back(south_node);
                south_max = south_node;
                }
                else{
                // There is a crossection
                graph[north_node].push_back(south_node);
                transpose[south_node].push_back(north_node);
                }
            }
            else {
                // There is a crossection
                // This node is type b
                graph[north_node].push_back(south_node);
                transpose[south_node].push_back(north_node);
            }
            north_max = north_node;
        }
    }


    cout <<printSCCs(graph,transpose,n+s);
    

    return 0;
}
