#include <iostream>
#include <map>
#include <deque>
#include <stack>
#define int long long
using namespace std;

int32_t main(){
    int q; cin>>q;
    // We have a in the game queue; it's a queue 'cause
    // We have to take the player who spent the most time in the game
    // corallarly this the the player who first entered the game
    deque<string> game; stack<string> bench;
    map<string,int> joined;
    while (q--)
    {
        string input; cin>>input;
        if(input=="+" ){if(!bench.empty()){ game.push_back(bench.top()); bench.pop(); } }
        else if(input=="-"){ if(!game.empty()){ bench.push(game.front()); game.pop_front();} }
        else if(joined[input]==0){
            joined[input]=1;
            game.push_back(input);
        }
    }
    while(!game.empty()){
        cout<<game.back()<<" ";
        game.pop_back();
    }
    
}