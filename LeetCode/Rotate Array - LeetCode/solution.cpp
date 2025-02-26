class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k == 0) return;

        int counter = 0;
        int start_index = -1;

        while(counter < n){
            start_index = (start_index + 1) % n;
            int temp = nums[start_index];

            int current_index = start_index;
            
            while(current_index != (start_index + k)%n){
                counter++;
                nums[current_index] = nums[(current_index - k + n)%n];
                current_index = (current_index - k + n) % n;
            }
            nums[current_index] = temp;
            counter++;
        }
    }
};