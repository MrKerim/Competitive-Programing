class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int arr[10010];

        for(int i = 3;i<10010;i = i + 3){
            if(arr[i] == 0)
                arr[i] = 3;
        }

        for(int i = 5;i<10010;i = i + 5){
            if(arr[i] == 0)
                arr[i] = 5;
            else if(arr[i] == 3)
                arr[i] = 15;
        }

        vector<string> result;
        for(int i = 1;i<=n;i++){
            if(arr[i] == 3)
                result.push_back("Fizz");
        else if(arr[i] == 5)
                result.push_back("Buzz");
        else if(arr[i] == 15)
                result.push_back("FizzBuzz");
        else result.push_back(to_string(i));
            
        }   

        return result;
    }
};