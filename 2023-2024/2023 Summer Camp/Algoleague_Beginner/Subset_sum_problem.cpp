#include <iostream>
#include <vector>

using namespace std;

//defining a subset function
long long subset_sum(vector<int> array,long target){
    
    //Defining DP array
    vector<vector<long long> > DP(array.size()+1,vector<long long>(target+1,0));
    // Adding base condition:
    for(int i = 0;i<DP.size();i++){
        DP[i][0]=1;
    }

    // Now dynamic programing :D
    for(int num=1;num<DP.size();num++){
        for(int sum=1;sum<DP[0].size();sum++){
            DP[num][sum] = DP[num-1][sum];
            if(sum>=num){
                DP[num][sum] = DP[num][sum] + DP[num-1][sum-array[num-1]];
            }
        }
    }

    return DP[DP.size()-1][DP[0].size()-1];

}



int main(){
    
    vector<int> arr(3,0);
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    cout<< subset_sum(arr,3) << endl;

    return 0;
}