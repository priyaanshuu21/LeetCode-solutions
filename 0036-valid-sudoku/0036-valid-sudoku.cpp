class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //rows
        for(int i = 0; i < 9; i++){
            unordered_set<int> s; //check note why assigned it here.
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        //cols
        for(int i = 0; i < 9; i++){
            unordered_set<int> s; //check note why assigned it here.
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        }

        //grids

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                unordered_set<int> s;
                for(int sr = i; sr <= i+2; sr++){
                    for(int sc = j; sc <= j+2; sc++){
                        if(board[sr][sc] == '.') continue;
                        if(s.count(board[sr][sc])) return false;
                        s.insert(board[sr][sc]);
                    }
                }
                
            }
        }

        return true;


    }
};