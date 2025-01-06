#include<stdio.h>

char board[3][3];
char currentPlayer;
int i,j;


void initializeBoard();
void printBoard();
void switchPlayer();
void playerMove();
int checkWin();


int main(){
	int gameStatus = 0;
	currentPlayer='X';
	initializeBoard();
	
	printf("\nWelcome to Tic-Tac-Toe!\n");
	printBoard();
	
	while(1){
		playerMove();
		printBoard();
		
		gameStatus=checkWin();
		
		if (gameStatus==1){
		
		printf("%c player wins.\n",currentPlayer);
		break;
	}
	else if(gameStatus==-1){
		printf("It's a draw.\n");
		break;
	}
	switchPlayer();
	
	}
	return 0;
}
void initializeBoard(){
	char num='1';
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=num++;
		}
	}
}

void printBoard(){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %c ",board[i][j]);
			if(j<2)
			printf(" | ");
		}
		printf("\n");
	if(i<2)
	printf("----|-----|----\n");
	}
	printf("\n");
}
void switchPlayer(){
	currentPlayer = (currentPlayer=='X')? 'O' : 'X';
}


void playerMove(){
	int move;
	printf("Player %c, enter your move(1-9): ",currentPlayer);
	while(1){
		scanf("%d", &move);
		if(move<1 || move>9){
			printf("Invalid move. Try again!");
			continue;
		}
		
		int row= (move-1)/3;
		int col= (move-1)%3;
		
		if(board[row][col]!='O' && board[row][col]!='X'){
			board[row][col]=currentPlayer;
			break;
		}
		else
		printf("Space already taken. Try again.");
	}
}

int checkWin(){
	for(i=0;i<3;i++){
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
		return 1;
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
		return 1;
	}
		if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
		return 1;
		if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
		return 1;
		
		int movesLeft=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
		if(board[i][j]!='O' && board[i][j]!='X')
		movesLeft = 1;
			}
		}
	
	if(!movesLeft) return -1;
	return 0;
}
