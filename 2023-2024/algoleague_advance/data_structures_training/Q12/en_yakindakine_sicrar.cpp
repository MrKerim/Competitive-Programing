#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define int long long
using namespace std;

int32_t main(){
    int n; cin>>n;
    map<int,int> players;
    queue<int> game_pitch;
    stack<int> bench;
    for (int i = 0; i < n; i++)
    {
        string x; cin>>x;
        if(x=="+") {if(!bench.empty()) {game_pitch.push(bench.top()); bench.pop();}}
        else if(x=="-") {if( !game_pitch.empty()) {bench.push(game_pitch.front()); game_pitch.pop();}}
        else if(players[stoi(x)]!=1) {game_pitch.push(stoi(x)); players[stoi(x)]=1; }
    }
    
    while(!bench.empty()) bench.pop();
    while(!game_pitch.empty()){
        bench.push(game_pitch.front());
        game_pitch.pop();
    }
    while(!bench.empty()){
        cout<<bench.top()<<" ";
        bench.pop();
    }
}