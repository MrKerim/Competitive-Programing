class Solution {
public:
    string addBinary(string a, string b) {

        string res = "";


        if(a.length() < b.length()){
            string temp = b;
            b = a;
            a = temp;
        }

        int a_i = a.length()-1;
        int b_i = b.length()-1;
        int cary = 0;


        while(a_i >= 0 || b_i >= 0){

            if(b_i<0){
                int sum = (a[a_i] - '0') ^ cary;
                cary = ( (a[a_i]- '0') + cary ) >= 2;
                res = to_string(sum) + res;
            }
            else{

            
            int sum = (a[a_i]- '0') ^ ( b[b_i]- '0') ^ cary;
            cary = ( (a[a_i]- '0') + (b[b_i]- '0') + cary ) >= 2;
            res = to_string(sum) + res;
            }
            a_i--;
            b_i--;
        }

        if(cary == 1) res = '1' + res;

        return res;
    }
};