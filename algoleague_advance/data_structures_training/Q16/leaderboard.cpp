#include <iostream>
#include <queue>
using namespace std;
#define int long long

int32_t main(){
    int n,operations;
    cin >> n >> operations;
    priority_queue<int> pq;
    queue<int> que;
    for(int q = 0;q<operations;q++){
        string inp; int x;
        cin >> inp >> x;
        if(inp == "add")  pq.push(x);
        else{
            while (x--)
            {
                cout << pq.top() << " ";
                que.push(pq.top());
                pq.pop();
            }
            cout << endl;
            while (!que.empty())
            {
                pq.push(que.front());
                que.pop();
            }
            
            
    }
}
}