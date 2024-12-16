    #include <iostream>
    #include <stack>
    #include <vector>
    using namespace std;

    int32_t main(){
        int n; cin>>n;
        stack<string> exc;
        for(int i=0;i<n;i++){
            string input; cin>>input;
            if(exc.empty()) exc.push(input);
            else{
                if(exc.top()==input)exc.pop();
                else exc.push(input);
            }
    }
    vector<string> result;
    int s = exc.size();
        for (int i = 0; i < s; i++)
        {
            result.push_back(exc.top());
            exc.pop();
        }
        for (int i = s -1;i>=0 ;i--)
        {
            cout<<result[i]<<" ";
        }
        
        
    }