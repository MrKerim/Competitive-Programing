#include <iostream>
#include <stack>
using namespace std;

int32_t main(){
    
    int q; cin>>q;
    while(q--){
        string s;cin>>s;
        stack<string> stck;
        int moves = 0;
        for(char c:s){
            // If it's d we will add it!
            if(c=='D') stck.push("D");
            if(c=='O') {
                if(stck.empty()) continue;
                if(stck.top()=="D"){stck.pop(); stck.push("DO");}
                else{ while(!stck.empty()){stck.pop();} }
            } 
            if(c=='G') {
                if(stck.empty()) continue;
                if(stck.top()=="DO"){ moves++; stck.pop();}
                else{ while(!stck.empty()){stck.pop();} }
            }
    }
    cout<<moves<<endl;

    }
    return 0;
}