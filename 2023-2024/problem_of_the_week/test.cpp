#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int32_t main(){

    bool prime[1000];
    vector<int> primes;
    for (int i = 2; i < 1000; i++)
    {
    if(!prime[i]){
        primes.push_back(i);
        prime[i]=true;
        for (int j = i+i; j < 1000; j+=i)
        {
            if(!prime[j]){
                prime[j]=true;
            }
        }
        }
    }

    for (int i = 0; i < primes.size()-3; i++)
    {   
        cout<<"\n: "<<primes[i]<<" :"<<endl;
        cout<<pow(primes[i],5)<<" : "<<pow(primes[i],6)<<endl;
    }
    

    return 0;
}