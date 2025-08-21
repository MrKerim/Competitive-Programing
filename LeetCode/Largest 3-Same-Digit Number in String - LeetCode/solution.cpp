class Solution {
public:
    string largestGoodInteger(string num) {
        int imax = INT_MIN;
        for(int i = 0; i<num.length()-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                if((num[i] - '0')>imax) imax = (num[i] - '0');
        }

        if(imax == INT_MIN) return "";
        return to_string(imax) + to_string(imax) + to_string(imax);

    }
};