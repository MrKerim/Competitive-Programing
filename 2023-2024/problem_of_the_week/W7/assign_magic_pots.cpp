#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int32_t main(){
    int N,P;cin>>N>>P;
    vector<int> person(N);
    vector<int> magic_pots(P);
    for(int i=0;i<N;i++) cin>>person[i];
    for(int i=0;i<P;i++) cin>>magic_pots[i];
    sort(person.begin(),person.end());
    sort(magic_pots.begin(),magic_pots.end());
    int count = 0;
    for(int p:magic_pots) {
        if (p >= person[count] && count<N ) count++;
    }

    cout<<count<<endl;
}