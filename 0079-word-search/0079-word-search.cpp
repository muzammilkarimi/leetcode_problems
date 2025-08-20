class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,int r,int c,int idx){
        if(idx== word.size()) return true;

        // out of bound and visited case
        if(r<0 or c<0 or r>=board.size() or c>=board[0].size() or word[idx]!=board[r][c]) return false;

        // visited 
        char temp = board[r][c];
        board[r][c] = '#';
        // all direction 
        bool found = dfs(board,word,r+1,c,idx+1) or 
                    dfs(board,word,r-1,c,idx+1) or
                    dfs(board,word,r,c+1,idx+1) or
                    dfs(board,word,r,c-1,idx+1);
        
        board[r][c]=temp;
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
        
    }
};