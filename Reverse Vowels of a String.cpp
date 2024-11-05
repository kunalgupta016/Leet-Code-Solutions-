class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;

        while(i<j){
            if(  ( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
            || s[i]=='A' ||s[i]=='I' || s[i]=='E' ||s[i]=='O' || s[i]=='U' )  && 
            
            
            ( s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' 
            || s[j]=='A' || s[j]=='I' || s[j]=='E' || s[j]=='O' || s[j]=='U' )
            
             ) {
                swap(s[i++],s[j--]);

             }



             else if  ( ( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
            || s[i]=='A' ||s[i]=='I' || s[i]=='E' ||s[i]=='O' || s[i]=='U' )  && ( s[j]!='a' || s[j]!='e' || s[j]!='i' || s[j]!='o' || s[j]!='u' 
            || s[j]!='A' || s[j]!='I' || s[j]!='E' || s[j]!='O' || s[j]!='U' ))
            {
                j--;

            }

            
            else if  ( ( s[i]!='a' || s[i]!='e' || s[i]!='i' || s[i]!='o' || s[i]!='u' 
            || s[i]!='A' ||s[i]!='I' || s[i]!='E' ||s[i]!='O' || s[i]!='U' )  && 
            
            
            ( s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' 
            || s[j]=='A' || s[j]=='I' || s[j]=='E' || s[j]=='O' || s[j]=='U' ))
            {
                i++;

            }




             else{
                i++;
                j--;
             }
        }

        return s;

    }
};
