class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        // stack 
        stack<int> s;
        // queue se stack;=
        int i = 0 ;
        while(!q.empty() && i<k ){
            int ele = q.front();
            q.pop();
            s.push(ele);
            i++;
        }
        
        // stack se queue
        
        
        while(!s.empty()){
            int ele = s.top();
            s.pop();
            q.push(ele);
        }
        
        // feych first n-k ele form queue
        
        int t = q.size()-k;
        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
        
    }
};
