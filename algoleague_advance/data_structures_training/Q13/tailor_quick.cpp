#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

int32_t main(){
    int n; cin>>n;

    vector<int> results(n);
    int max = 0;
    vector<pair<int,int> > songs;
    for(int i=0; i<n; i++) { int a; cin>>a; songs.push_back(make_pair(a, i)); if(a>max) max = a;}
    for(int i=0; i<n; i++) if(songs[i].first == max) results[i] = -2;
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(int i=0; i<n; i++) pq.push(songs[i]);

    while (!pq.empty())
    {
        pair<int,int> song = pq.top();
        pq.pop();
        if(results[song.second] == -2) {continue; cout<<"index: "<<song.second<<" It's a max song"<<endl; }
        // This song is not the max so we have to proccess it
        if(song.first == songs[(song.second+1)%n].first){
            //here goes some code
        }
        else{
            cout<< "index: "<<song.second<< " value: "<<song.first<< "index+1"<<(song.second+1)%n<< " value: "<<songs[(song.second+1)%n].first<<endl;
            results[song.second] = songs[(song.second+1)%n].second;
            cout<<"results["<<song.second<<"] = "<<results[song.second]<<endl;
            songs.erase(songs.begin() + (song.second)%n);
            cout<<"we erase the song"<<endl;
        }

    }
    
    for(int i=0; i<n; i++) cout<<results[i]+1<<" ";
    
}