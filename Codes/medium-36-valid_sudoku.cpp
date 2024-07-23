// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 

// Example 1:

/* Input: board = 
*  [["5","3",".",".","7",".",".",".","."]
* ,["6",".",".","1","9","5",".",".","."]
* ,[".","9","8",".",".",".",".","6","."]
* ,["8",".",".",".","6",".",".",".","3"]
* ,["4",".",".","8",".","3",".",".","1"]
* ,["7",".",".",".","2",".",".",".","6"]
* ,[".","6",".",".",".",".","2","8","."]
* ,[".",".",".","4","1","9",".",".","5"]
* ,[".",".",".",".","8",".",".","7","9"]]
*/
// Output: true

// Example 2:

/* Input: board = 
* [["8","3",".",".","7",".",".",".","."]
* ,["6",".",".","1","9","5",".",".","."]
* ,[".","9","8",".",".",".",".","6","."]
* ,["8",".",".",".","6",".",".",".","3"]
* ,["4",".",".","8",".","3",".",".","1"]
* ,["7",".",".",".","2",".",".",".","6"]
* ,[".","6",".",".",".",".","2","8","."]
* ,[".",".",".","4","1","9",".",".","5"]
* ,[".",".",".",".","8",".",".","7","9"]]
*/
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


class Solution {
    bool validate(vector<vector<char>> &board,int direct,int op){
        bool visited[9];
        for(int i=0;i<9;i++)
            visited[i]=0;
        if(op==0){
            for(int i=0;i<9;i++){
                if(board[i][direct]!='.'&&visited[board[i][direct]-49]==1){
                    return false;
                }
                if(board[i][direct]!='.')
                    visited[board[i][direct]-49]=1;
            }
            return true;
        }
        if(op==1){
            for(int i=0;i<9;i++){
                if(board[direct][i]!='.'&& visited[board[direct][i]-49]==1){
                    return false;
                }
                if(board[direct][i]!='.')
                    visited[board[direct][i]-49]=1;
            }
            return true;
        }
        return false;
    }
    bool validate_cubes(vector<vector<char>>& board){
        bool visited[9];
        for(int i=0;i<9;i++)
            visited[i]=0;
        for(int i=0;i<7;i+=3){
            for(int j=0;j<7;j+=3){
                for(int k=0;k<9;k++)
                    visited[k]=0;
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        if(board[a][b]!='.'){
                            if(visited[board[a][b]-49]==1)
                                return false;
                            visited[board[a][b]-49]=1;
                        }
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!validate(board,i,0)){
                return false;
            }
            if(!validate(board,i,1)){
                return false;
            }
        }
        return validate_cubes(board);
    }
};
