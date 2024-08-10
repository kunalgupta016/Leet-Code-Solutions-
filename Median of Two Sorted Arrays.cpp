class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>num;
        int i=0;
        int j=0;
        while(i<nums1.size()){
            num.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            num.push_back(nums2[j]);
            j++;
        }
        sort(num.begin(),num.end());
        int s=0;
        int e=num.size()-1;
        int mid;
        mid=s+(e-s)/2;
        double ans;
        if((num.size())%2==0){
            ans=(double)(num[mid]+num[(mid+1)])/(double)2;
        }
        else{
            ans=num[mid];
        }
        return ans;
    }
};
