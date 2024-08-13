int firstOccurence(vector<int>& nums , int  n , int key){
	
	int s=0,e=n-1;
	int mid = s+(e-s)/2;
	int ans=-1;
	while(s<=e){
		if(nums[mid]==key){
			ans=mid;
			e=mid-1;
		}
		else if(key>nums[mid]){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
		
	}
	return ans;
	
	
}
int LastOccurence(vector<int>& nums, int  n , int key){
	
	int s=0,e=n-1;
	int mid = s+(e-s)/2;
	int ans=-1;
	while(s<=e){
		if(nums[mid]==key){
			ans=mid;
			s=mid+1;
		}
		else if(key>nums[mid]){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
		
	}
	return ans;
	
	
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ne;
        int n=nums.size();
        ne.push_back(firstOccurence(nums,n,target ));
        ne.push_back(LastOccurence(nums,n,target));
        return ne; 
        }
    
};
