class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        int index = 0;
        for(char c : num_str){
            if(c == '6') break;
            index++;
        }

        if(index<num_str.length()) num_str[index] = '9';

        return stoi(num_str);
    }
};