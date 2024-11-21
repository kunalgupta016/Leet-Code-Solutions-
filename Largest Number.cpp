class Solution {
public:

static bool comp(string a, string b){
    return a+b>b+a;
}


string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int n:nums){
            str.push_back(to_string(n));
        }

        sort(str.begin(), str.end(),comp);
        if(str[0] == "0") 
            return "0";
        string ans = "";

        for(string s:str){
            ans += s;
        }
        return ans;
    }

};
