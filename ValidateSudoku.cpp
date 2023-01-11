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
