#include <iostream>
#include <vector>
using namespace std;
#define int long long
int32_t main(){
    int n,k; cin>>n>>k;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) cin>>numbers[i];
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + numbers[i-1];
    int ans = 0; // Array is all positive integers
    for(int i = 0; i <= n-k; i++){
        ans = max(ans, prefix[i+k] - prefix[i]);
    }
    cout<<ans<<endl;
    
}