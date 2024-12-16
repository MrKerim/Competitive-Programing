#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int32_t main(){
    int n,m,c; cin>>n>>m>>c;
    vector<int> stocks(n,0);
    for (int i = 0; i < n; i++) cin >> stocks[i];

    vector<int> cost_2_stocks;
    vector<int> cost_1_stock;
    vector<bool> visited(n,false);

    for (int i = 0; i < c; i++)
    {
        int c1,c2; cin >> c1 >> c2;
        cost_2_stocks.push_back(stocks[c1]+stocks[c2]);
        visited[c1] = true;
        visited[c2] = true;
    }
    for (int i = 0; i < n; i++) if(!visited[i]) cost_1_stock.push_back(stocks[i]);

    sort(cost_2_stocks.begin(), cost_2_stocks.end(), greater<int>());
    sort(cost_1_stock.begin(), cost_1_stock.end(), greater<int>());


    


}