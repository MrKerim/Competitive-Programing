string add(const string& num1, const string& num2,
int index1, int index2,int carry){

    int sum = 0;

    if(index1 < 0  && index2 < 0){
        if(carry == 0) return "";
        else return to_string(carry);
    }

    else if(index1 < 0)
        sum += num2[index2] - '0';
    else if(index2 < 0) sum += num1[index1] - '0';

    else sum = ( num1[index1] - '0' ) + (num2[index2] - '0');

    sum += carry;
    if(sum >= 10) return add(num1,num2,index1-1,index2-1,1) + to_string(sum%10);
    return add(num1,num2,index1-1,index2-1,0) + to_string(sum);
}

class Solution {
public:
    string addStrings(string num1, string num2) {
        return add(num1,num2,num1.length()-1,num2.length()-1,0);
    }
};