//Time Complexity-O(m*n)
//Space Complexity-O(m*n)---> but number of elements stored in queue in worst case will be greater than m+n and less
//                            than m*n. But taking higher order term for Big O notation, it will be O(m*n)
// Did the code execute on Leetcode? Yes

class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
    int getmines(vector<vector<char>> board,int row,int col)
    {
        int count=0;
        for(int i=0;i<dir.size();i++)
        {
            vector<int>temp=dir[i];
            int r=temp[0]+row;
            int c=temp[1]+col;
            if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]=='M')
            {
                count++;
            }
               
        }
        return count;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size()==0)
        {
            return board;
        }
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        queue<vector<int>>m;
        m.push(click);
        while(!m.empty())
        {
            vector<int>temp=m.front();
            m.pop();
            int mines=getmines(board,temp[0],temp[1]);
            if(mines==0)
            {
                board[temp[0]][temp[1]]='B';
                for(int i=0;i<dir.size();i++)
                {
                    vector<int>k=dir[i];
                    int row=temp[0]+k[0];
                    int col=temp[1]+k[1];
                    if(row>=0 && row<board.size() && col>=0 && col<board[0].size())
                    {
                        if(board[row][col]=='E')
                        {
                            board[row][col]='A';
                            m.push({row,col});
                        }
                    }
                }
            }
            else
            {
                board[temp[0]][temp[1]]=(char)mines+'0';
            }
        }
        return board;
    }
};