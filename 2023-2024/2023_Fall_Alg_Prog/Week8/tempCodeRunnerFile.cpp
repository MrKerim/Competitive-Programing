#include <iostream>
using namespace std;
#define int long long
#include <vector>
int32_t main(){
    int n; cin>>n;
    vector<int> decks;
    for (int i = 0; i < n; i++)
    {
        int input;cin>>input;
        decks.push_back(input);
    }
    vector<int> prefix(n+1);
    prefix[0]=0;
    for (int i = 1; i < n+1; i++)
    {
        prefix[i]=prefix[i-1] + decks[i-1];
    }

    int Q;cin>>Q;
    vector<vector<int> > query_arry(Q);
    // Now the array holds 3 values ticket number , query number and the result;
    for (int i = 0; i < Q; i++)
    {
        int query_q;cin>>query_q;
        query_arry[i].push_back(query_q);
        query_arry[i].push_back(i);
        query_arry[i].push_back(0);
    }

    sort(query_arry.begin(),query_arry.end());

    // Now we need to answer the querries in the order
    int index = 0;
    for (int i = 0; i < Q; i++)
    {   
        int q_n = query_arry[i][0];
        while(q_n <= prefix[index]){
            index++;
        }
        query_arry[i][2] = index;
        query_arry[i][0] = query_arry[i][1];
        query_arry[i][1] = q_n;
    }

    sort(query_arry.begin(),query_arry.end());
    for (int i = 0; i < Q; i++)
    {
        cout<<query_arry[i][2]<<" ";
    }
}
