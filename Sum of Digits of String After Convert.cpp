class Solution {
public:
    int getLucky(string s, int k) {
        string n = "";
        for(int i=0 ;i<s.size();i++){
            n = n+to_string(s[i]-'a'+1);
        }
        while(k>0){
            int temp = 0;
            for(int j=0;j<n.size();j++){
                temp = temp + n[j] - '0';
            }
            n  = to_string(temp);
            k--;
        }
        return stoi(n);
    }
};
