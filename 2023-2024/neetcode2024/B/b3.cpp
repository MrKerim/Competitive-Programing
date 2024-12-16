#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int num1, num2;
        num1 = stoi(tokens[0]);

        for(int it = 1; it < tokens.size(); it+=2){
            num2 = stoi(tokens[it]);
            string oprtr = tokens[it+1];

            if (oprtr == "+") num1 = num1 + num2;
            else if (oprtr == "-") num1 = num1 - num2;
            else if (oprtr == "*") num1 = num1 * num2;
            else if (oprtr == "/") num1 = num1 / num2;


        }
        return num1;
    }
};
