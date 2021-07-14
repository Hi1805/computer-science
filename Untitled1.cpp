#include<iostream>
#include<fstream>
using namespace std;
//#define n 4
//int sol[4][4];
int m,n;
int **maze;
int **sol;
bool initMaze(){
	ifstream iff("Maze.txt");
	if(iff.fail()){
		return false;
	}
	iff>>m>>n;
	maze = new int* [m];
	sol =  new int* [m];
	
	for(int i = 0; i < m ; i++){
		maze[i] = new int[n];
		sol[i] = new int[n];
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n; j++){
			iff>>maze[i][j];
			sol[i][j] = 0;
			cout<<maze[i][j] << " ";
		}
		cout<<endl;
	
	}

	iff.close();
	
	return true;
}
bool isSafe(int**maze, int x ,int y){
	if(x >= 0  && x < m && y >= 0 && y < n && maze[x][y] == 1){
		return true;
	}
	return false;
}
bool solveMaze(int **maze ,int x,int y,int **&sol){
	if(x == m - 1 && y == n - 1){
		sol[x][y] = 1;
		return true;
	}
	if(isSafe(maze,x,y)){
		sol[x][y] = 1;
		if(solveMaze(maze,x+1,y,sol)){
			return true;
		}
		if(solveMaze(maze,x,y+1,sol)){
			return true;
		}	
			sol[x][y] = 0;
		}
	return false;
	
}
void printSol(int **sol){
	cout<<"SOLUTION : "<<endl;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	initMaze();
	if(solveMaze(maze,0,0,sol)){
		printSol(sol);
	}
	else cout<<"No solution";
}
