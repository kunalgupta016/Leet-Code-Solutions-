class Solution {
public:
    int getPivot(vector<int>& nums , int n){
        int s=0;
	    int e=n-1;
	    int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s=mid+1;
                
            }
            else{
                e = mid;
            }   
            mid=s+(e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int>& nums , int st ,int en , int key ){
        int s=st;
        int e =en;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(nums[mid]==key){
                return mid;
            }
            else if(nums[mid]>key){
                e=mid-1;

            }

            else{
                 s=mid+1;
            }
            mid = s+(e-s)/2;

        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans =2;
        int pivot = getPivot(nums,n);
        if(nums[pivot]<=target && target<=nums[n-1]){
           ans=binarySearch(nums,pivot,n-1,target);
        }
        else{
            ans=binarySearch(nums,0,pivot-1,target);
        }
    return ans;
    }
};
