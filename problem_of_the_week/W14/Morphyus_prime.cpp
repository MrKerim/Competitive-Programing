#include <iostream>
#include <map>
using namespace std;

int32_t main(){
    int n;cin>>n;
    map <int,int> mp;
    mp[0]=2;  mp[2] = 3; mp[3] = 5; mp[5] = 7; mp[7] = 2;
    int arr[6] = {0,0,0,0,0,0}; int ans = 0;
    while(true){
        for (int i = 0; i < 6; i++)
        { 
            if(arr[i]!=7){ arr[i] = mp[arr[i]]; break;}
            else{arr[i] = 2;}
        }
        
        // Now we will check if the number is exceeding
        int num = 0; int ten = 1;
        for (int i = 0; i < 6; i++) {num+= arr[i]*ten; ten*=10; }
        if(num>n){break;} ans++;
    }
    cout<<ans<<endl;
}