class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> aux;
        aux.push_back({1});
        vector<int> res1;
        if(rowIndex==0) {
            res1.push_back(1);
            return res1;
        } 
        int i,j;
        for(i=1;i<rowIndex+1;i++) {
            vector<int> row;
            row.push_back(1);
            for(j=1;j<i;j++) {
                row.push_back(aux[i-1][j-1] + aux[i-1][j]);
            }
            row.push_back(1);
            aux.push_back(row);
            res1 = row;
        }
        
        return res1;
    }
};