#include <iostream>

using namespace std;

bool isSafe(int board[][4],int row,int col,int n){

	for(int i=0;i<row;i++){
		if(board[i][col]){
			return false;
		}
	}

	int x = row;
	int y = col;

	while(x>=0 and y>=0){
		if(board[x][y]){
			return false;
		}
		x--;
		y--;
	}

	x = row;
	y = col;

	while(x>=0 and y<n){
		if(board[x][y]){
			return false;
		}
		x--;
		y++;
	}

	return true;
}
	
bool NQueens(int board[][4],int row,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<"Q_";
				}else{
					cout<<" _";
				}
			}
			cout<<endl;
		}

		return true;
	}

	for(int col=0;col<n;col++){

		if(isSafe(board,row,col,n)){
			board[row][col] = 1;

			bool rest_of_the_queens = NQueens(board,row+1,n);
			if(rest_of_the_queens){
				return true;
			}

			board[row][col] = 0;
		}
	}

	return false;
}

void printNQueens(int board[][4],int row,int n){
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<"Q_";
				}else{
					cout<<" _";
				}
			}
			cout<<endl;
		}

		cout<<"*************"<<endl;

		return;
	}

	for(int col=0;col<n;col++){

		if(isSafe(board,row,col,n)){
			board[row][col] = 1;

			printNQueens(board,row+1,n);
			//
			board[row][col] = 0;
		}
	}

	return;
}

int countNQueens(int board[][4],int row,int n){
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<"Q_";
				}else{
					cout<<" _";
				}
			}
			cout<<endl;
		}

		cout<<"*************"<<endl;

		return 1;
	}

	int count = 0;

	for(int col=0;col<n;col++){

		if(isSafe(board,row,col,n)){
			board[row][col] = 1;

			count+=countNQueens(board,row+1,n);
			
			board[row][col] = 0;
		}
	}

	return count;
}

bool ratInMaze(char maze[][4],int sol[][4],int row,int col,int endrow,int endcol){

	if(row==endrow and col==endcol){
		
		sol[endrow][endcol] = 1;

		for(int i=0;i<=endrow;i++){
			for(int j=0;j<=endcol;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"******************"<<endl;

		return true;
	}

	if(row>endrow or col>endcol){
		return false;
	}

	if(maze[row][col]=='X'){
		return false;
	}

	sol[row][col] = 1;

	bool horizontalWay = ratInMaze(maze,sol,row,col+1,endrow,endcol);
	bool verticalWay = ratInMaze(maze,sol,row+1,col,endrow,endcol);

	sol[row][col] = 0;

	if(horizontalWay or verticalWay){
		return true;
	}

	return false;

}

bool canWePlace(int mat[][9],int row,int col,int n,int number){

	for(int i=0;i<n;i++){
		if(mat[i][col]==number or mat[row][i]==number){
			return false;
		}
	}

	int starting_x = (row/3)*3;
	int starting_y = (col/3)*3;

	for(int i = starting_x; i < starting_x + 3;i++){
		for(int j = starting_y; j < starting_y + 3; j++){
			if(mat[i][j]==number){
				return false;
			}
		}
	}

	return true;

}

bool sudokuSolver(int mat[][9],int row,int col,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}

	if(col==n){
		return sudokuSolver(mat,row+1,0,n);
	}

	if(mat[row][col]!=0){
		return sudokuSolver(mat,row,col+1,n);
	}


	for(int options = 1; options<=9; options++){

		if(canWePlace(mat,row,col,n,options)){

			mat[row][col] = options;

			bool rest_of_the_sudoku = sudokuSolver(mat,row,col+1,n);
			if(rest_of_the_sudoku){
				return true;
			}

		}

	}

	mat[row][col] = 0;
	return false;
}


int main(){

	int board[4][4] = {0};
	// cout<<NQueens(board,0,4)<<endl;
	// printNQueens(board,0,4);
	// cout<<countNQueens(board,0,4)<<endl;

	// int arr[][3] = {1,2,3,4,5,6};
	// int m,n;

	// cin>>m>>n;

	// int arr[m][n];

	// check(arr,m,n);

	// char maze[][4] = {
	// 	{'0','0','0','0'},
	// 	{'0','0','0','0'},
	// 	{'0','0','X','0'},
	// 	{'0','X','0','0'},
	// };

	// int sol[4][4] = {0};

	// cout<<ratInMaze(maze,sol,0,0,3,3)<<endl;

	int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };

    cout<<sudokuSolver(mat,0,0,9)<<endl;

	return 0;
}