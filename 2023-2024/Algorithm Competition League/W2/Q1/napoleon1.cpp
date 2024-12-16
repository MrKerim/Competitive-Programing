#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int32_t main(){
    int n,k;cin>>n>>k;
    vector<int> maximum(n,0);
    vector<int> parallel_time_lines(n,0);
    int last_time = 0;
    for (int i = 0; i < n; i++)
    {
        int a,input;cin>>a>>input;
        if(input>0){
            for (int i = 0; i < n; i++)
            {
                parallel_time_lines[i] = parallel_time_lines[i] + input;
                maximum[i] = max(maximum[i],parallel_time_lines[i]);
            }
            
        }
        else{
            for (int i = 0; i < n; i++)
            {
                if(i!=last_time){
                parallel_time_lines[i] = parallel_time_lines[i] + input;
                maximum[i] = max(maximum[i],parallel_time_lines[i]);
            }
            }
            last_time++;
        }

    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans,maximum[i]);
    }
    cout<<ans+k<<endl;
    
    
}