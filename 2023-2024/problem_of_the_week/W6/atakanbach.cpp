#include <iostream>
#include <vector>

using namespace std;
int32_t main(){
    int n,k; cin>>n>>k;
    vector<int> primes;
    // we will create an number array from 2 to n
    vector<bool> is_prime(n+1,true); // from 1 to n
    for(int i=2;i<n;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
    // now we will go for every i and i+1 prime to check if the resulting sum +1 is equal to an prime number or not
    int cnt = 0;
    for (int i = 0; i < primes.size()-1; i++)
    {
        int sum = primes[i] + primes[i+1] + 1;
        if(sum<=n && is_prime[sum]) cnt++;
    }
    if(cnt>=k) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    return 0;
}