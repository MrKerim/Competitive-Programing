#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin>>n;
    
    //Vector initialization
    vector<long long> mountain(n,0);
    for(int i=0;i<n;i++){
        cin>>mountain[i];
    }

    //Prefix array initialization
    vector<long long> prefix(n+1,0);
    for(int i=1;i<n+1;i++){
        prefix[i] = prefix[i-1] + mountain[i-1];
    }
    

    //Looping through the pre and summing the revenue;
    long long revenue = 0;

    //difference in the pre suffix
    for(int dif = 1;dif<n+1;dif++){
        for(int count=0;count<n+1-dif;count++){
            revenue += prefix[count+dif]-prefix[count];
        }
    }

    cout<<revenue<<endl;

    return 0;
}