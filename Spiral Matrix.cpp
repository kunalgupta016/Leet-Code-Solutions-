class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();


        vector<int> ans;
        int count = 0;
        int total = row*col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;

        // chalu karte hai
        while(count<total){
            // print starting row
            for(int index = startingCol ; count<total && index<=endingCol ; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }          
            startingRow++;

            // print ending col
            for(int index = startingRow ; count<total && index<=endingRow ; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            //print ending Row
            for(int index = endingCol ;count<total && index>=startingCol ; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            //print starting colunmn
            for(int index = endingRow ; count<total && index>=startingRow ; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;


        }

        return ans;
    }
};
