class Solution {
    private:
        bool knows(vector<vector<int> >& mat , int a, int b, int n){
            if(mat[a][b]==1){
                return true;
            }
            else{
                return false;
            }
        }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> s;
        for(int i = 0 ;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(mat,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        int ans = s.top();
        int zeroCount = 0;
        for(int i = 0 ;i<n;i++){
            if(mat[ans][i]==0){
                zeroCount++;
            }
        }
        if(zeroCount!=n){
            return -1;
        }
        int oneCount = 0;
        for(int i = 0 ; i<n ;i++){
            if(mat[i][ans]){
                oneCount++;
            }
        }
        if(oneCount!=n-1){
            return -1;
        }
        
        return ans;
        
    }
};
