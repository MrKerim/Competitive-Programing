#include <iostream>
#include <vector>
#define int long long
using namespace std;
bool is_prime[10000007];
// 0 -> prime
int32_t main(){
    vector<int> primes;
    for (int i = 2; i < 10000007; i++){ if (!is_prime[i])
    {for (int j = i*2; j < 10000007; j+=i) is_prime[j] = true;
    primes.push_back(i);}}
    int n; cin >> n;
    while (n--)
    {
        int x, y; cin >> x >> y; if(y>x) swap(x, y);
        if(!is_prime[x]) cout<<-1<<endl;
        // x is not prime and we have y let's see which of the prime divisors of x also divies the y
        bool flag = false;
        for(int x_div_prime : primes){
            if(x_div_prime > y) break;
            if(x % x_div_prime == 0 && y % x_div_prime == 0){
                cout<<x_div_prime<<" ";
                flag = true;
            }
        }
        if(!flag) cout<<-1;
        cout<<endl;
    }
    
    
}