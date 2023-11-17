#include <iostream>
#include <vector>
using namespace std;

int32_t main(){

    int r,c;cin>>r>>c;
    vector<vector<bool> > seats(r,vector<bool>(c,false));
    int friends; cin>>friends;
    int reserve; cin>> reserve;
    while (reserve--)
    {
        int r_r,r_c; cin>>r_r>>r_c;
        r_r--; r_c--;
        seats[r_r][r_c] = true;
    }
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        int count = 0;
        for (int j = 0; j < c; j++)
        {
            if(!seats[i][j]){
                count++;
                if(count==friends){
                    sum+=1;
                    count = 0;
                    j = j +1-friends;
                    
                }
            }
            else{
                count = 0;
            }
        }
        
    }
    cout<<sum<<endl;
    
    
    
    return 0;
}