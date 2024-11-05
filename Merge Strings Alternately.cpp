class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i=0;
        int j=0;
        int n1 = word1.size();
        int n2 = word2.size();
        while(i<n1 && j<n2){
            result.push_back(word1[i]);
            result.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<n1){
            result.push_back(word1[i]);
            i++;
        }
        while(j<n2){
            result.push_back(word2[j]);
            j++;
        }
        return result;
    }
};