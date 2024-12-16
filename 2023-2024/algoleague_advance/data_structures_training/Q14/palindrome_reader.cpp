#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int32_t main(){
    int n; cin>>n;
    vector<char> input(n); for(int i=0; i<n; i++) cin>>input[i];
    sort(input.begin(), input.end());
    vector<char> output;
    char odd_char = ' '; bool is_odd = false;

    for(int i=0; i<n; i+=2){
        if(i!=n-1){
            char prev = input[i]; char next = input[i+1];
            if(prev == next) output.push_back(prev);
            else{
                if(is_odd){
                    cout<<"NO SOLUTION";
                    return 0;
                }
                else{
                    odd_char = prev;
                    is_odd = true;
                    i--;
                }
            }
        }
        else{
            if(is_odd){
                if(odd_char == input[i]) output.push_back(odd_char);
                else{
                    cout<<"NO SOLUTION";
                    return 0;
                }
            }
            else{
                odd_char = input[i];
                is_odd = true;
            }
        } 
    }

    for(char x: output) cout<<x;
    if(is_odd) cout<<odd_char;
    for(int i=output.size()-1; i>=0; i--) cout<<output[i];
}