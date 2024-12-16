#include <iostream>
#include <vector>

using namespace std;

int32_t main(){
    int n,m; cin >> n >> m;
    pair<int,int> inzva;
    vector<vector<int> > base(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        string s; cin>> s;
        for (int j = 0; j < m; j++)
        {
            if(s[j] == 'i') {inzva = {i,j}; base[i][j] = 0;}
            else if(s[j] == 'a') base[i][j] = 1;
            else if(s[j] == 'b') base[i][j] = -1;
            else base[i][j] = 0;
        }
    }

    vector<vector<int> > dp(n,vector<int>(m,0));
    // first we will cover the row and the column on inzva
    for (int i = inzva.first+1; i < n; i++) dp[i][inzva.second] = dp[i-1][inzva.second] + base[i][inzva.second];
    for (int i = inzva.first-1; i>=0; i--) dp[i][inzva.second] = dp[i+1][inzva.second] + base[i][inzva.second];

    for (int i = inzva.second+1; i < m; i++) dp[inzva.first][i] = dp[inzva.first][i-1] + base[inzva.first][i];
    for (int i = inzva.second-1; i>=0; i--) dp[inzva.first][i] = dp[inzva.first][i+1] + base[inzva.first][i];

    // now we will go from the inzva to the corners of the matrix
    for (int i = inzva.first+1; i < n; i++)
        for (int j = inzva.second+1; j<m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + base[i][j];


    for (int i = inzva.first-1; i >=0; i--)
        for (int j = inzva.second+1; j<m; j++)
            dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + base[i][j];


    for (int i = inzva.first+1; i < n; i++)
        for (int j = inzva.second-1; j>=0; j--)
            dp[i][j] = dp[i-1][j] + dp[i][j+1] - dp[i-1][j+1] + base[i][j];


    for (int i = inzva.first-1; i >=0; i--)
        for (int j = inzva.second-1; j>=0; j--)
            dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + base[i][j];






    int best = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            best = max(best,dp[i][j]);

    cout << best << endl;
    
}