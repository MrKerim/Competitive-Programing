#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main(){
    int n,k; cin>>n>>k;
    vector<bool> in_game(n,true);

    // We will have a counter and k counter to eliminate
    int turn = 0;
    int k_val = k%n;
    int k_counter = 0;
    int remaining = n;

    while(remaining >0){
        if(in_game[turn%n]){
            if(k_counter == k_val){
                cout<<(turn%n)+1<<" ";
                in_game[turn%n] = false;
                remaining--;
                k_counter = 0;
                k_val = k%remaining;
            }
            else k_counter++;
        }
        turn++;
    }
}