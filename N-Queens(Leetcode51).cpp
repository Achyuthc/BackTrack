/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 */


class Solution {
public:
    vector<vector<string>> ans;
    int negdiagonal[20],posdiagonal[20],rows[10],cols[10];
    int N;
    
    bool isSafe(int i,int indx)
    {
        if(posdiagonal[i+indx]==0&&negdiagonal[i-indx+N]==0&&rows[i]==0&&cols[indx]==0)
        {
            return true;
        }
        return false;
    }
    void backTrack(int indx,vector<string> &v)
    {
        if(indx==v.size())
            ans.push_back(v);
        for(int i=0;i<N;i++)
        {
            if(isSafe(i,indx))
            {
                posdiagonal[i+indx]=1;
                negdiagonal[i-indx+N]=1;
                rows[i]=1;
                cols[indx]=1;
                v[i][indx]='Q';
                backTrack(indx+1,v);
                v[i][indx]='.';
                posdiagonal[i+indx]=0;
                negdiagonal[i-indx+N]=0;
                rows[i]=0;
                cols[indx]=0;
            }
        }
            
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> v;
        string str="";
        for(int i=0;i<n;i++)
        {
            str.push_back('.');
        }
        for(int i=0;i<n;i++)
            v.push_back(str);
        backTrack(0,v);
        return ans;
        
    }
};
