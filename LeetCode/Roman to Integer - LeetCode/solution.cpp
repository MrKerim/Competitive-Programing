class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;


        int result = 0;
        int cumulative = 0;

        for(int i = 0;i<s.length()-1;i++){

            if(mp[s[i]] == mp[s[i+1]]){
                cumulative += mp[s[i]];
                continue;
            }
            else if(mp[s[i]] < mp[s[i+1]]){
                result = result - cumulative - mp[s[i]];
                cumulative = 0;
                continue;
            }

            result += mp[s[i]] + cumulative;
            cumulative = 0;

        }

        return result + cumulative + mp[s[s.length()-1]];
       
    }
};