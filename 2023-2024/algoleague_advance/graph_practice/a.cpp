#include <iostream>
#include <vector>
using namespace std;

int32_t main(){
    int n,m; cin>>n>>m;
    vector<vector<int > > matrix(n,vector<int>(n,0));
    for (int i = 0; i < m; i++)
    {
        int a,b; cin>>a>>b;
        a--;b--;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n;j++){
            if(matrix[i][j]!=0){
                cout<<j+1<<" ";
            }
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n;j++){
            cout<< matrix[i][j]<<" ";
            
        }
        cout<<endl;
    }
    

    
    
    
}