class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        vector<int> v;
        while(i<nums.size()){
            int ans = nums[i]*nums[i];
            v.push_back(ans);
            i++;
        }
        sort(v.begin(),v.end());
        return v;
    }
};
