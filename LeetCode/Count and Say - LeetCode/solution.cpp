string encode(string s){
    
    char prev = s[0];
    int count = 1;
    string res = "";

    for(int i = 1;i<s.length();i++){
        char current = s[i];
        if(prev!=current){
            res+= to_string(count);
            res+= prev;
            prev = current;
            count = 1;
            continue;
        }
        count++;
    }
    res+= to_string(count);
    res+= prev;

    return res;
}


string rle(int n){
    if(n == 1) return "1";
    return encode(rle(n-1));
    

}

class Solution {
public:
    string countAndSay(int n) {
        return rle(n);   
    }
};