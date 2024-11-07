class Solution {
    private:
        vector<int> nextElement(vector<int>& heights,int n){
            stack<int> s;
            s.push(-1);
            vector<int> ans(n);
            for(int i = n-1 ;i >=0 ;i--){
                int crr = heights[i];
                while(s.top()!=-1 && heights[s.top()]>=crr){
                    s.pop();
                }
                ans[i] = s.top();
                s.push(i);    
            }
            return ans;
        }

        vector<int> preElement(vector<int>& heights,int n){
            stack<int> s;
            s.push(-1);
            vector<int>ans(n);
            for(int i= 0 ; i<n ;i++){
                int crr  = heights[i];
                while(s.top()!=-1 && heights[s.top()]>=crr){
                    s.pop();
                }
                ans[i] = s.top();
                s.push(i);
            }
            return ans;
        }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextElement(heights,n);
        vector<int> pre(n);
        int area = 0;
        pre = preElement(heights,n);
        for(int i = 0  ; i<n ;i++){
            int l = heights[i];

            if(next[i]==-1){
                next[i]=n;
            }
            int w = next[i] - pre[i] -1;
            int newarea = l*w;
            area = max(area,newarea);
        }
        return area;

    }
};
