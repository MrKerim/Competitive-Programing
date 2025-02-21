class Solution {
public:

    string binaryAddition(string input){
        for(int i = input.length()-1;i>0; i--){
            if(input[i] == '0'){
                input[i] = '1';
                return input;
            }
            
            input[i] = '0';
        }
        input[0] = '1';
        return input;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        string counter = "";
        for(int i = 0; i<nums.size();i++) counter+= "0"; 
        sort(nums.begin(),nums.end());
        for(auto num : nums){
            if(counter != num) return counter;
            counter = binaryAddition(counter);
        }

        return counter;
    }
};