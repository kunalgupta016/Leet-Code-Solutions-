class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans=0;
        int x;
        for(auto &x: nums){
            sort(x.begin(),x.end());
        }
        int row = nums.size();
        int col = nums[0].size();
        for(int i=0 ; i<col ; i++){
            int maxi = INT_MIN;
            // int sum = 0;
            for(int j=0 ; j<row ; j++){
                if(nums[j][i]>maxi){
                    maxi=nums[j][i];
                }   
            }

            ans = ans + maxi;
            
        }
        return ans;

    }
};
