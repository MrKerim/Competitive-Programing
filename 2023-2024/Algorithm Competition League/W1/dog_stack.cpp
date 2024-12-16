#include <iostream>
#include <stack>
using namespace std;

int32_t main(){
    
    int q; cin>>q;
    while(q--){
        string a;cin>>a;
        stack<int> stack_d; stack<int> stack_o; stack<int> stack_g;
        for(int i = 0; i< a.size();i++){
            if(a[i]=='D') stack_d.push(i);
            else if(a[i]=='O') stack_o.push(i);
            else stack_g.push(i);
        }
        int moves = 0;
        while(!stack_d.empty() && !stack_o.empty() && !stack_g.empty()){
            int d_number = stack_d.top();
            int o_number = stack_o.top();
            // if o < d then we will pop the d
            if(o_number<d_number) {stack_d.pop(); continue;}
            // if not then we will look to the o and g
            int g_number = stack_g.top();
            // if g<o then we will pop the o
            if(g_number<o_number){ stack_o.pop(); continue;}
            // If it's here then we can make a move :D
            moves++;
            stack_d.pop();
            stack_o.pop();
            stack_g.pop();
        }

        cout<<moves<<endl;

        
    }


    return 0;
}