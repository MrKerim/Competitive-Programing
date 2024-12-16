#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int32_t main(){
    int n;cin>>n;
    vector<int> problems(n,0); vector<int> tests(n,0);
    for(int i=0;i<n;i++) cin>>problems[i];
    for(int i=0;i<n;i++) cin>>tests[i];

    priority_queue<int> problems_pq;
    priority_queue<int> tests_pq;
    
    // We will try every possible combination of problems and tests
    // to do this we will count from 1 to 2^n - 1 and convert the number to binary
    int max_score = 0;
    for (int i = 0; i < (1<<n); i++)
    {
        int bin_i = i;
        int bin_loc = 0;
        for(int j=0;j<n;j++)
        {
            if(bin_i%2 == 1){
                problems_pq.push(problems[bin_loc]);
                tests_pq.push(tests[bin_loc]);
                
            }
            else {tests_pq.push(tests[bin_loc]); tests_pq.push(tests[bin_loc]);} // pushed two times
            bin_i = bin_i/2; bin_loc++;

        }
        // Now we have initilized the priority queues
        int score = 0;
        while (!problems_pq.empty() && !tests_pq.empty())
        {  

            score = score + (problems_pq.top() + tests_pq.top())*tests_pq.top();
            problems_pq.pop(); tests_pq.pop();
        }
        problems_pq = priority_queue<int>();
        tests_pq = priority_queue<int>();
        max_score = max(max_score,score);
    }
    cout<<max_score<<endl;
}