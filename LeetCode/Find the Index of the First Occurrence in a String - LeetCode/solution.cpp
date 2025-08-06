bool search(int index, string& needle, string& haystack){
    for(char c : needle){
        if(index == haystack.length()) return false;
        if(c == haystack[index]) index++;
        else return false;
    }
    return true;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0;i<haystack.length();i++){
            if(haystack[i] == needle[0])
                if(search(i,needle,haystack)) return i;
        }
    return -1;
    }

};