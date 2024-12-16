#include <iostream>
#include <stack>
using namespace std;
int32_t main(){
    int n;cin>>n;
    string s; cin>>s;
    stack<char> paranthesis;
    int closed_once = 0;
    for (int i = 0; i < n; i++)
    {
        char current_paranth = s[i];
        if(current_paranth == '(' || current_paranth == '{' || current_paranth == '['){
            paranthesis.push(current_paranth);
        }
        else{
            if(paranthesis.empty()){ cout<<"NO"<<endl;  return 0; }
            char top = paranthesis.top();
            if(current_paranth == ')' && top == '('){
                paranthesis.pop();
            }
            else if(current_paranth == '}' && top == '{'){
                paranthesis.pop();
            }
            else if(current_paranth == ']' && top == '['){
                paranthesis.pop();
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
            if( paranthesis.empty() )closed_once ++; 
        }

    }
    if(paranthesis.empty() && closed_once>1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}

