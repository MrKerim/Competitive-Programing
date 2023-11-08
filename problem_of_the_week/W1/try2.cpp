#include <iostream>
#include <vector>
#define int long long
using namespace std;
bool is_prime[4000];
int32_t main(){

    int N;cin>>N;
    vector<int> primes;
    for (int i = 2; i < 4000; i++)
    {
        if(!is_prime[i]){
            primes.push_back(i);
            is_prime[i] = true;
            for (int j = i+i; j < 4000; j+=i)
            {
                if(!is_prime[j]){
                    is_prime[j]=true;
                }
            }
            
        }   
    }
    int result = 0;
    for(int prime: primes){
        for (int i = 1; i <= prime; i++)
        {
            if(i*prime*prime*prime<=((double)N)/((double)prime*prime)) result++;
        }
        
    }
    cout<<result<<endl;
    

}