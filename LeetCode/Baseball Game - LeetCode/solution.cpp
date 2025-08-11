class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for(string oper : operations){
            if(oper == "+")
                score.push_back( 
                    score[score.size()-1]
                    +
                    score[score.size()-2]
                );
            else if(oper == "D")
                score.push_back( 2*score[score.size()-1]);
            else if(oper == "C")
                score.pop_back();
            else score.push_back(stoi(oper));
        }

        return accumulate(score.begin(),score.end(),0);
    }
};