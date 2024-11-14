class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        int n = arr.size();
        
        deque<int> dq;
        vector<int> ans;
        // add first element of k window 
        for(int i=0 ; i<k ;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        
        // answer me push kiya 
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        // window ko aage badhya 
        for(int i = k ; i<n;i++){
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            
            // add
            if(arr[i]<0){
                dq.push_back(i);
            }
            
            // ans
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        
            
        }
    
        return ans;
        
        
    }
};
