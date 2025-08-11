int rec(int input){
    int sum = 0;
    while(input>0){
        sum += input % 10;
        input = input / 10;
    }
    if(sum >= 10) return rec(sum);
    else return sum;
}

class Solution {
public:
    int addDigits(int num) {
        return rec(num);
    }
};