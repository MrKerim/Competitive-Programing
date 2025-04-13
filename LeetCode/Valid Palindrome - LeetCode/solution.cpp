class Solution {
public:
    bool isPalindrome(string s) {
        string inp = "";
        for(char c : s) if(isalnum(c)) inp+= tolower(c);
        if(inp.length() <= 1) return true;
        int isOdd = inp.length()%2;
        int l = inp.length()/2-1;
        int r = inp.length()/2 + isOdd;

        while(l>=0){
            //cout<<inp[l]<<" <-> "<<inp[r]<<"\n";
            if(inp[l] != inp[r]) return false;
            l--;
            r++;
        }
        return true;
    }
};