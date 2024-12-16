#include <iostream>
#include <vector>
#define int long long
using namespace std;

int cal_move(vector<vector<bool> > board,int n,int row){

    if(row==n) return 1;
    int check = 0;
    for (int j = 0; j < n; j++) { check+= board[row][j];}
    if(check==0) return 0;
    

    int sum = 0;
    for(int i=0;i<n;i++){
        if(board[row][i]) {
            vector<vector<bool> > copy(n,vector<bool>(n,false));
            for(int j=0;j<n;j++){
                for (int k = 0; k < n; k++)
                {
                    copy[j][k] = board[j][k];
                }
                
            }

            for(int j= 0;j<n;j++){copy[row][j]=false; copy[j][i] = false;}
            sum+= cal_move(copy,n,row+1);
        }
    }
    return sum;
    
}

int32_t main(){
    int n;cin>>n;
    vector<vector<bool> > board(n,vector<bool>(n,true));
    for (int i = 0; i < n; i++) { board[i][i]=false; board[i][n-i-1]=false; }
    cout<< cal_move(board,n,0)<<endl;
    return 0;
}
