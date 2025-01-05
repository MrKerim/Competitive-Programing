class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        vector<int> prefix(s.length(),0);
        for(auto v : shifts){
            prefix[v[0]] += v[2]*2 - 1;
            if(v[1] != s.length()-1)
            prefix[v[1]+1] += -1*(v[2]*2 -1);
        }

        prefix[0] = prefix[0]%26;
        for(int i = 1;i<s.length();i++){
        prefix[i] += prefix[i-1];
        prefix[i] = prefix[i]%26;
        }

        string res = "";

        for(int i = 0;i<s.length();i++){
            int n = s[i] + prefix[i];
            
            if(n<97)  n = n-97+123;
            else if(n>122) n = n-122 + 96;
            
            res += char(n);
        }
        

        return res;
    }
};