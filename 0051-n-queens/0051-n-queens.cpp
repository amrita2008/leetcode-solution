class Solution 
{
public:
    bool canplace(vector<string>& board, int r, int c)
{
    int n = board.size();
 
    for(int i = 0; i < r; i++)
    {
        if(board[i][c] == 'Q') return false;
    }
 
    int row = r - 1, col = c - 1;
    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row--; col--;
    }
 
    row = r - 1; col = c + 1;
    while(row >= 0 && col < n)
    {
        if(board[row][col] == 'Q') return false;
        row--; col++;
    }

    return true;
}
    void solve(int n,vector<vector<string>> &ans,vector<string> &board,int row)
    {
        if(row==n )
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(canplace(board,row,col))
            {
                board[row][col]='Q';
                solve(n,ans,board,row+1);
                board[row][col]='.';
            }
        }
        return; 
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string>board(n,string(n,'.')); 
        solve(n,ans,board,0);
        return ans;
    }
};