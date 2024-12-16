#include <iostream>
#include <vector>
#define int unsigned long long
using namespace std;

int power(int inp){
    int res = 1;
    while(inp>0){
        res = res*10;
        inp--;
    }
    return res;
}

int32_t main(){
    int n;cin>>n;
    string s;cin>>s;

    vector<int >prefix_string(n+1,0);
    for (int i = 1; i < n+1; i++)
    {
        int lettet_number = s[i-1]-96;
        prefix_string[i] = prefix_string[i-1] * 10 + lettet_number;
    }

    int q;cin>>q;
    while(q--){
        int a,b,l,r; cin>>a>>b>>l>>r;
        int left = prefix_string[b] - (prefix_string[a-1] * (power(b-a+1)));
        int right =  prefix_string[r]-prefix_string[l-1]*(power(r-l+1));
        // left basamak = b-a-1
        // right basamak r-l-1
        if(b-a<r-l){
            left = left * power(r-l - b +a);
        }
        if(b-a>r-l){
            right = right * power(b-a-r+l);
        }

        if (left<right){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    
    
}