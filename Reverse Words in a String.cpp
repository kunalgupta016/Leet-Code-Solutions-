class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp="";
        string ans="";
        int i=0;
        while(i<n){
            temp="";
            while(s[i] !=' '&& i<n){
                temp = temp+s[i];
                i++;
            }
            while(s[i] == ' ' && i<n){
                i++;
            }
            if(!temp.empty()){
                if(ans.empty()){
                    ans = ans+temp;
                }
                else{
                    ans = temp + ' ' + ans;
                }
            }

        }
        return ans;
        
    }
};
