class Solution {
public:
     vector<vector<int>> generateMatrix(int n){
     
        vector<vector<int>> ans(n,vector<int>(n,0));
      

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n-1;
        int endingCol = n-1;

        int i=1;

        // chalu karte hai
        while(i<=n*n && startingRow<=endingRow && startingCol<=endingCol){
            // print starting row
            for(int index = startingCol ; i<=n*n && index<=endingCol ; index++){
                ans[startingRow][index]=i;
                i++;
            }          
            startingRow++;

            // print ending col
            for(int index = startingRow ; i<=n*n && index<=endingRow ; index++){
                ans[index][endingCol]=i;
                i++;
            }
            endingCol--;

            //print ending Row
            for(int index = endingCol ;i<=n*n && index>=startingCol ; index--){
                ans[endingRow][index]=i;
                i++;
            }
            endingRow--;

            //print starting colunmn
            for(int index = endingRow ; i<=n*n && index>=startingRow ; index--){
                ans[index][startingCol] = i;
                i++;
            }
            startingCol++;


        }

        return ans;
    }
};
