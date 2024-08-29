class Solution {
private:
    bool isEqual(int a[26] , int b[26]){
        for(int i =0 ;i<26;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int count[26]={0};
        for(int i=0;i<s1.size();i++){
            int idx = s1[i]-'a';
            count[idx]++;
        }
        int count2[26]={0};
        int window = s1.length();
        int i=0;
        while(i<window && i<s2.length()){
            int idx = s2[i]-'a';
            count2[idx]++;
            i++;
        }
        if(isEqual(count,count2)){
            return 1;
        }


        while(i<s2.length()){
            char newChar = s2[i];
            int idx = newChar-'a';
            count2[idx]++;
            
            char oldChar = s2[i-window];
            idx = oldChar-'a';
            count2[idx]--;
              i++;
            if(isEqual(count,count2)){
            return 1;
          
        }
        
        }

        return 0;
        
 }
};
