#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int32_t main(){
  int n;cin>>n;
  vector<int> bludgers(n,0);
  for (int i = 0; i < n; i++) cin>>bludgers[i];
  stack<int> right;
  int left_result = 0;
  for (int i = 0; i < n; i++)
  {
    char type; cin>>type;
    if(type == 'L'){
      if(right.empty()) left_result++;
      
      else{
      // Since there are several bludgers on going right we need to check

      while (!right.empty() && right.top()<bludgers[i])
      {
        right.pop();
      }
      if(right.empty()) left_result++;
      else if(right.top()==bludgers[i]) right.pop();
      }

    }
    else right.push(bludgers[i]);
  }

  cout<< left_result + right.size() <<endl;
  }