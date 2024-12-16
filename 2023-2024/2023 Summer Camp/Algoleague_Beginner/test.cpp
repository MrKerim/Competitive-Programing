#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;

//defining a subset function
long long subset_sum(int n){
    int target = n*(n+1)/4;
    
    //Defining DP array
    // We don't need a matrice we just need to use 2 space:
    vector<vector<long long> > DP(2,vector<long long>(target+1,0));
    // Adding base condition for 0 and 1 :
    DP[0][0]=1;
    DP[1][0]=1;

    // Now dynamic programing :D
     
    for(int num=1;num<n+1;num++){
        for(int sum=1;sum<DP[0].size();sum++){
            
            if(sum>=num){
                DP[1][sum] = (DP[0][sum]+DP[0][sum-num])%MOD;
            }
            else{
                DP[1][sum] = DP[0][sum];
            }

            //swapping
            swap(DP[0], DP[1]);
            for (int i = 0; i < DP[0].size(); i++)
            {
                DP[1][i]=0;
            }
            DP[1][0]=1;
            
            
        }
    }

    return DP[0][DP[0].size()-1];

}



int main(){
    
    int n;
    cin>>n;
    if(n%4==1 || n%4==2){
        cout<<0<<endl;
        return 0;
    }
    
    cout<< subset_sum(n) << endl;

    return 0;
}