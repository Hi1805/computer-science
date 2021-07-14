#include<iostream>
using namespace std;

bool usedInBox(int g[9][9], int sr,int sc,int n){
	for(int r = 0; r < 3 ; r++){
		for(int c = 0; c < 3; c++){
			if(g[r + sr ][c+sc] == n)
				return true;
		}
	}
	return false;
}
bool usedInRow(int g[9][9], int r,int n){
	for(int c = 0 ; c < 9 ; c++){
		if(g[r][c] == n){
			return true;
		}
	}
	return false;
}

bool usedInCool(int g[9][9],int c,int n){
	for(int r = 0 ; r < 9 ; r++){
		if(g[r][c] == n){
			return true;
		}
	}
	return false;
}

bool isSafe(int g[9][9], int r,int c,int n){
	return !usedInRow(g,r,n) && !usedInCool(g,c,n) && usedInBox(g,r*r%3,c*c%3,n) && g[r][c]==0; 
}
bool emptyCell(int g[9][9], int &r, int &c ){
	for( r = 0 ; r<9;r++){
		for(c = 0 ; c < 9 ; c++){
			if(g[r][c] == 0) return true;
		}
	}
	return false;
}
bool solveSudoku(int g[9][9]){
	int r , c;
	if(!emptyCell(g,r,c) ) return true;
	for(int num = 1 ; num<=9; num++){
		if(isSafe(g,r,c,num)){
			g[r][c] = num
		}
		if(solveSudoku(g)) return true;
		g[r][c] =0;
	}
	return false;
}
int main(){
	if(solveSudoku())
}
