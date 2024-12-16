#include <iostream>
#include <vector>
using namespace std;

int32_t main(){

    int elves,houses; cin>>elves>>houses;

    if(elves >= houses){
        cout<<0<<endl;
        return 0;
    }

    vector<int> distance_queue;
    for(int i=0;i<houses;i++){
        int dist; cin>>dist;
        distance_queue.push_back(dist);
    }

    sort(distance_queue.begin(),distance_queue.end());
    int total_distance = distance_queue[houses-1]-distance_queue[0];

    vector<int> interval;

    for (int i = 0; i < houses-1; i++)
    {
        interval.push_back(abs(distance_queue[i]-distance_queue[i+1]));
    }
    sort(interval.begin(),interval.end(),greater<int>());
    // size of the interval queue is houses-1 ; so the 

    int remove=0;
    // we gonna look elves-1 number of intervals
    for (int i = 0; i < elves-1; i++)
    {
        remove+= interval[i];
    }

    cout<<total_distance-remove<<endl;

    return 0;
}