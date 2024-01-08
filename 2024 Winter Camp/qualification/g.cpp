#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

int32_t main(){
    int n;cin >> n;
    vector<int> input(n,0);
    int pre_max = 0;
    int pre_min = 1;
    vector<int> lex_min;
    map<int,int> in_lex_min;
    for(int i=0;i<n;i++)
    {
        int current_max; cin >> current_max;
        input[i] = current_max;
        if (current_max > pre_max)
        {
            pre_max = current_max;
            lex_min.push_back(current_max);
            in_lex_min[current_max] = 1;
        }
        else
        {
            while (in_lex_min[pre_min]) pre_min++;
            lex_min.push_back(pre_min); in_lex_min[pre_min] = 1;
            pre_min++;
            
        }
    }

    pre_max = 0;
    vector<int> lex_max;
    map<int,int> in_lex_max;
    int pre_lex_max = 0;
    for(int i=0;i<n;i++)
    {
        
        int current_max; current_max = input[i];
        if (current_max > pre_max)
        {
            
            pre_lex_max = current_max;
            pre_max = current_max;
            lex_max.push_back(current_max);
            in_lex_max[current_max] = 1;
        }
        else
        {
            
            while (in_lex_max[pre_lex_max]) pre_lex_max--;
            lex_max.push_back(pre_lex_max); in_lex_max[pre_lex_max] = 1; pre_lex_max--;
            
        }
    }
    
    for (int i = 0; i < n-1; i++)
    {
        cout << lex_min[i] << " ";
    } cout << lex_min[n-1]<<endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << lex_max[i] << " ";
    } cout << lex_max[n-1]<<endl;
    
  
    
}