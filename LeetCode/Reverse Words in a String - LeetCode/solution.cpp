class Solution {
public:
    string reverseWords(string s) {

        string result = "";
        string word = "";
        int index = s.length();
        bool found = false;
        while(index--){
            if(word == "" && s[index] == ' ') continue;
            if(word != "" && s[index] == ' ') {
                if(found) result = result + " " + word;
                else {result = word; found = true;}
                word = "";
                continue;
            }

            word = s[index] + word;
        }

        if(word != "" && found) result = result + " " + word;
        if(word != "" && !found) result = word;

        return result;
    }
};