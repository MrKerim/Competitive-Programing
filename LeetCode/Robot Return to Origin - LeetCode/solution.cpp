class Solution {
public:
    bool judgeCircle(string moves) {
        int ver = 0;
        int hor = 0;
        for(char move : moves){
            if(move == 'U') ver += 1;
            if(move == 'D') ver -= 1;
            if(move == 'R') hor += 1;
            if(move == 'L') hor -= 1;          
        }

        if(hor == 0 && ver == 0) return true;
        return false;
    }
};