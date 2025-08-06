class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int i = s.length()-1;
        bool found = false;
        while(i>=0){
            if(!found && s[i]==' '){ i--; continue;}
            if(found && s[i]==' ') return result;
            
            found = true;
            result++;
            i--; 
        }

        return result;
    }
};