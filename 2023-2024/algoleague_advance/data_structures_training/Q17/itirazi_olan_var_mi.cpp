#include <iostream>
#include <queue>
#include <vector>
#define int long long
#define right second
#define left first
#define val first
#define index second
using namespace std;

int32_t main(){
    int n; cin>>n;
    vector<pair<int,int> > cats(n);
    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for(int i=0;i<n;i++) {
        cin>>cats[i].first;
        cats[i].second=i;
        pq.push(make_pair(cats[i].first,i));
    }
    // We will pop the each elemnt from min to max and mark the sides of it
    vector<pair<int,int> > result(n,make_pair(-1,-1));
    vector<bool> marked(n,false);
    int left_most = 0;
    int right_most = n-1;

    int left_most_should = 0;
    int right_most_should = n-1;

    int pre_val = -1;
    queue<int> pre_index;
    queue<pair<int,int> > pre_queue;

    
    for(int i=0;i<n;i++){
        pair<int,int> cat = pq.top(); pq.pop();

        int current_index = cat.index;
        int r_index = current_index+1;
        int l_index = current_index-1;

        while(marked[left_most_should]) left_most_should++;
        while(marked[right_most_should]) right_most_should--;

        if(cat.val != pre_val){

            right_most = right_most_should;
            left_most = left_most_should;
            pre_val = cat.val;
            while(!pre_index.empty()){
                int ind = pre_index.front(); pre_index.pop();
                pair<int,int> p = pre_queue.front(); pre_queue.pop();
                cats[ind] = p;
            }
        }
        

        if(r_index == n) {
            // We only change the result and right_most
            result[current_index].right = current_index;
            right_most_should--;
        }
        else{

            result[current_index].right = cats[right_most].index;
            // After that we need to update the cats array
            if(current_index == right_most_should) right_most_should--;
        }

        if(l_index < 0) {
            // Again we only change the result and left_most
            result[current_index].left = current_index;
            left_most_should++;
        }
        else{
            result[current_index].left = cats[left_most].index;

            if(current_index == left_most_should) left_most_should++;
        }

        marked[current_index] = true;
        if(r_index!=n && l_index>=0) {
            if(cats[r_index].val>cats[l_index].val){pre_queue.push(make_pair(cats[r_index].val,cats[r_index].index)); pre_index.push(current_index);}
            else {pre_queue.push(make_pair(cats[l_index].val,cats[l_index].index)); pre_index.push(current_index);}
        }
        else if(r_index!=n) {if(cats[r_index].val >= cats[current_index].val) {pre_queue.push(make_pair(cats[r_index].val,cats[r_index].index)); pre_index.push(current_index);}}
        else if(l_index>=0) {if(cats[l_index].val >= cats[current_index].val) { pre_queue.push(make_pair(cats[l_index].val,cats[l_index].index)); pre_index.push(current_index);}}
        

    }

    for(pair<int,int> p : result) cout<<p.first<<" "<<p.second<<endl;
}