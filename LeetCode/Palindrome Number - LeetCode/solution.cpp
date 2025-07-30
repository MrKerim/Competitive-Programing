class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp_x = x;
        string s = "";
        while(temp_x>0){
            s+= to_string(temp_x%10);
            temp_x = temp_x/10;
        }

        for(int i = 0;i<s.length()/2;i++){
            if(s[i] != s[s.length()-1 - i]) return false;
        }

        return true;
    }
};