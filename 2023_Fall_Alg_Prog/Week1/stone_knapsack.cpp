#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool knapsack(int past_sum, vector<int> input , int start , int target , int len){
    if(len==start) return false; 
    if(target-past_sum-input[start]==0) return true;
    if(target-past_sum-input[start]<0) return knapsack(past_sum,input,start + 1,target,len);
    // if  .. sum .. > 0
    return knapsack(past_sum + input[start],input, start + 1 ,target,len);

}


int main(){
    int n;cin>>n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
    {
        cin>>stones[i];
    }
    int sum = accumulate(stones.begin(),stones.end(),0);
    if(sum%2==1) {  cout<<"false"<<endl; return 0;  }

    for (int i = 0; i < n; i++)
    {
        if(knapsack(0,stones,i,sum/2,n)) { cout<<"true"<<endl; return 0; }
    }
    cout<<"false"<<endl;
    
    return 0;
}