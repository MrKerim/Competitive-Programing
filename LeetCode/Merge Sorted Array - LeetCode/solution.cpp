class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m,0);
        for(int i = 0; i<m ; i++) nums3[i] = nums1[i];

        if(n == 0) return;
        if(m == 0) {
            for(int i = 0; i<n ; i++) nums1[i] = nums2[i];
            return;
        }

        int left2 = 0;
        int left3 = 0;

        for(int i = 0; i<n+m;i++){
            if(left3 == m) {
                nums1[i] = nums2[left2];
                left2++;
                continue;
            }
            if(left2 == n) {
                nums1[i] = nums3[left3];
                left3++;
                continue;
            }

            if(nums2[left2] > nums3[left3]){
                nums1[i] = nums3[left3];
                left3++;
                continue;
            }
            else{
                nums1[i] = nums2[left2];
                left2++;
                continue;
            }
        }

    }
};