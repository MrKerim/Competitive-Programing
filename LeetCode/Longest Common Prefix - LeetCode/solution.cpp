class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string,int> mp;

        string common = "";
        for(int index = 0;index < strs[0].size();index++){
            char c = strs[0][index];
            bool fin = false;

            for(int i = 1; i < strs.size();i++){
                if(index >= strs[i].size()){
                    fin = true;
                    break;
                }

                if(c != strs[i][index]){
                    fin = true;
                    break;
                }

            }
            if(fin) break;
            common += c;
        }

        return common;
    }
};