class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string s1 = "";
        int i=0;
        while(i<n){
            if(s1.empty() || s[i]!=s1.back()){
                s1.push_back(s[i]);
            }
            else{
                s1.pop_back();
            }
            i++;
        }
        return s1;
    }
};
