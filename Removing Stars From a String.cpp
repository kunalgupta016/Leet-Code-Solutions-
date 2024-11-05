class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i = 0 ; i<s.length() ;i++){
            char ch = s[i];
            if(ch!='*'){
                st.push(ch);
            }
            else{
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            ans.push_back(ch);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
