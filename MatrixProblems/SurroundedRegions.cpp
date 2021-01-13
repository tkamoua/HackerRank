class Solution {
public:


    //recursive
    //for each position in the board
    //create unordered set of previously visited positions 
    //check if the left right up down are surrounded
    //      (if current position is off the board, return false. if current position is x, return true.else add current position to visitedPositions set and return surrounded(current position+1) && surrounded )
    // 
    bool isSurrounded(int row,int col, vector<vector<char>> & board, set<pair<int,int>> &visited){
          pair<int,int> pos;
            pos.first = row;
            pos.second = col;

        if(row <0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return false;
        }
        else if(board[row][col] == 'X' || (visited.find(pos) != visited.end())){
            return true;
        }
        else{
            //cout<<"pos " <<pos.first << " " << pos.second <<endl;
            visited.insert(pos);
            return isSurrounded(row+1,col,board,visited) && isSurrounded(row-1,col,board,visited) && isSurrounded(row,col+1,board,visited) && isSurrounded(row,col-1,board,visited);
            
        }
}
      void getOutput(vector<vector<char>> & board){
          //cout<< board.size() << endl;
          //cout<<board[0].size()<<endl;
          //cout<<endl;
         for(int i = 0; i < board.size();++i){
             for(int j = 0; j < board[i].size();++j){
                 set<pair<int,int>> visited; 
                    //cout<<i<<" " << j <<endl;
                 if(isSurrounded(i,j,board,visited)){
                     
                     for (const auto& elem: visited) {
                        int row = elem.first;
                         int col = elem.second;
                         //cout<<"pair ";
                         cout<<row<<" " << col << endl;
                         board[row][col] = 'X';
                       }
                 }
              
             }
         }
    }
    void solve(vector<vector<char>>& board) {
         getOutput(board);

    
    }
};