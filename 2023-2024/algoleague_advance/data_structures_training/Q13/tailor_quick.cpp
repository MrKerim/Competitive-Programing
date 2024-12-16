#include <iostream>
#include <vector>
#include <queue>
#define C INT64_MIN
#define int long long
using namespace std;

int32_t main(){
    int n; cin>>n;
    vector<int> songs(n); int max = INT64_MIN;
    for(int i=0; i<n; i++){ cin>>songs[i]; if(songs[i]>max) max = songs[i]; }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> results(n);
    for(int i=0; i<n; i++) pq.push(make_pair(songs[i], i));

    while(!pq.empty()){
        pair<int,int> song = pq.top(); pq.pop();
        int time = song.first; int index = song.second;
        if(songs[index] == C) continue;
        if(songs[index] == max) {
            results[index] = -2;
            songs[index] = C;
            continue;
        }
        int new_index = index;
        while(songs[new_index] == C || songs[index] == songs[new_index]) new_index = (new_index+1)%n;
        results[index] = new_index;
        songs[index] = C;
    }

    for(int i=0; i<n; i++) cout<<results[i]+1<<" ";
    
}