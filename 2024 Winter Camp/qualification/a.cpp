#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main(){
    int r,c;cin>>r>>c;
    vector<vector<int> > graph(r,vector<int>(c,0));
    vector<vector<int> > result(r,vector<int>(c,0));
    for (int i = 0; i < r; i++){for (int j = 0; j < c; j++){ cin>>graph[i][j]; }}
    //For both 23 and 35 if there isn't another same number in the 8 neighboring cells we change it to the 35/23 respectively.
    //If not they remain same
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(graph[i][j]== 23 || graph[i][j]==35){
                bool reverse_numbers = true;
                // Now we are going to look for the cells neighbors
                for (int neighbor_r = -1; neighbor_r < 2; neighbor_r++){
                    for (int  neighbor_c = -1; neighbor_c < 2; neighbor_c++){
                        // Neighbors: for n_r = -1 n_c = -1,0,1 and so on...
                        if(neighbor_r!= 0 || neighbor_c != 0){

                            if(neighbor_r+i>=0 && neighbor_r+i<r && neighbor_c+j>=0 && neighbor_c+j<c){
                                // If the neighbor values are in the limits we will check if any of the negihbor are same as center
                                if(graph[neighbor_r+i][neighbor_c+j]==graph[i][j]) reverse_numbers = false;
                            }
                        }
                    }
                    
                }
                if(reverse_numbers){
                    if(graph[i][j]==23) result[i][j] = 35;
                    else result[i][j] = 23;
                }
                else result[i][j] = graph[i][j];
            }
            else result[i][j] = graph[i][j];
        }
        
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<result[i][j];
            if(j!=c-1) cout<<" ";
        }
        cout<<"\n";
        
    }
    
    
}