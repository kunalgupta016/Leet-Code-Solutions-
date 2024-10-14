class Solution {
    private:
        void solve(vector<vector<int>> &ans, vector<int>output , vector<int>nums , int index){
            // base class
                if(index>=nums.size()){
                    ans.push_back(output);
                    return;
                }
                // exclude
                solve(ans,output,nums,index+1);
                // include
                int ele = nums[index];
                output.push_back(ele);
                solve(ans,output,nums,index+1);

        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>output;
        int index = 0;
        solve(ans,output,nums,index);
        return ans;
    }
};
