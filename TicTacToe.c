#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

bool	checkWin(char tictactoe[3][3], bool potracker[10], char x, char o);
int		computerTurn(char tictactoe[3][3], bool potracker[10], char playerToken, char computerToken);
void	updateBoard(char tictactoe[3][3], bool potracker[10], int position, char playerToken);
void	printBoard(char tictactoe[3][3]);


int main(void)
{
	char end = 'a';
	printf("Created By: Dustin + julion\n\n");
	printf("Instructions:\n");
	printf("If 'X' is chosen you go first and if 'O' is chosen the computer goes first\n");
	printf("Numbers correlate to position:\n\n");
	
	/*
	 1 | 2 | 3 
	-----------
	 4 | 5 | 6 
	-----------
	 7 | 8 | 9 
	*/
	while(end != 'e'){
		char playerToken;
		char computerToken;
		//const char x = 'x';
		//const char o = 'o';
		//int var = 0;
		char tictactoe[3][3] = {{'1','4','7'},{'2','5','8'},{'3','6','9'}};
		int position = 0;
		bool win = false;
		bool potracker[10] = {false,false,false,false,false,false,false,false,false,false};
		//end = 'a';
		
		printf("Choose X or O: \n");
		scanf(" %c", &playerToken);
		
		//Scan check
		while(playerToken != 'x' || playerToken != 'X' || playerToken != 'o' || playerToken != 'O')
		{
			printf("Try again: Choose X or O: \n");
			scanf(" %c", &playerToken);
				if(playerToken == 'x' || playerToken == 'X' || playerToken == 'o' || playerToken == 'O')
				{
					break;
				}
		}
		
		while(playerToken != 'x' || playerToken != 'o' || playerToken != 'X' || playerToken != 'O'){
			if(playerToken != 'x' || playerToken != 'o' || playerToken != 'X' || playerToken != 'O'){
				break;
			}
			scanf("%c", &playerToken);
		}
		playerToken = toupper(playerToken);
		if(playerToken == 'X'){
			computerToken = 'O';
		}
		else if(playerToken == 'O'){
			computerToken = 'X';
		}
		
		printf("Selection Confirmed\n");
		printf(" 1 | 2 | 3 \n");
		printf("-----------\n");
		printf(" 4 | 5 | 6 \n");
		printf("-----------\n");
		printf(" 7 | 8 | 9 \n");
		
		
		
		while(win == false){
			if(playerToken == 'X'){
				////////////////////////////////////// player turn /////////////////////////////
				printf("Your Turn:\n");
				printf("Enter Position: ");
				scanf("%d", &position);
				
				while(position > 9 || position < 1){
					printf("invalid input - try again\n");
					scanf("%d", &position);
				}	
					
				while(potracker[position] == true){
					position = 0;				
					printf("Try a differnt location:\n");
					scanf("%d", &position);
				}
			
				potracker[position] = true;
				updateBoard(tictactoe, potracker, position, playerToken);
				printBoard(tictactoe);
				
				win = checkWin(tictactoe, potracker, playerToken, computerToken);
			
				if(win)break;
				
			
				/////////////////////////////////// computer turn //////////////////////////////
			
				printf("Computer's Turn:\n");
				position = computerTurn(tictactoe, potracker, playerToken, computerToken);
				
				potracker[position] = true;
				updateBoard(tictactoe, potracker, position, computerToken);
				printBoard(tictactoe);
				
				win = checkWin(tictactoe, potracker, playerToken, computerToken);
			}
		
			else if(playerToken == 'O'){
				/////////////////////////////////////// computer turn ////////////////////////
				printf("Computer's Turn:\n");
				position = computerTurn(tictactoe, potracker, playerToken, computerToken);
				
				potracker[position] = true;
				updateBoard(tictactoe, potracker, position, computerToken);
				printBoard(tictactoe);
				
				win = checkWin(tictactoe, potracker, playerToken, computerToken);
			
				if(win)break;
				//////////////////////////////////// player turn /////////////////////////////////
			
				printf("Your Turn:\n");
				printf("Enter Position: ");
				scanf("%d", &position);
				
				while(position > 9 || position < 1){
					printf("invalid input - try again\n");
					scanf("%d", &position);
				}
				
				while(potracker[position] == true){
					position = 0;
					printf("Try a differnt location:\n");
					scanf("%d", &position);
				}
					
				potracker[position] = true;
				updateBoard(tictactoe, potracker, position, playerToken);
				printBoard(tictactoe);
				
				win = checkWin(tictactoe, potracker, playerToken, computerToken);
			}
			
		}
		
		if(end != 'e'){
			printf("Press 'r' to restart or 'e' to exit\n");
			scanf(" %c", &end);
		}
	
	}

	
return 0;
}

bool checkWin(char tictactoe[3][3], bool potracker[10], char x, char o){
    if ((tictactoe[0][0] == tictactoe[1][0] && tictactoe[1][0] == tictactoe[2][0] && tictactoe[2][0] == x) ||
        (tictactoe[0][1] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][1] && tictactoe[2][1] == x) ||
        (tictactoe[0][2] == tictactoe[1][2] && tictactoe[1][2] == tictactoe[2][2] && tictactoe[2][2] == x) ||
        (tictactoe[0][0] == tictactoe[0][1] && tictactoe[0][1] == tictactoe[0][2] && tictactoe[0][2] == x) ||
        (tictactoe[1][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[1][2] && tictactoe[1][2] == x) ||
        (tictactoe[2][0] == tictactoe[2][1] && tictactoe[2][1] == tictactoe[2][2] && tictactoe[2][2] == x) ||
        (tictactoe[0][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][2] && tictactoe[2][2] == x) ||
        (tictactoe[0][2] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][0] && tictactoe[2][0] == x)){
        printf("You Win!\n");
        return true;
    } 
	else if ((tictactoe[0][0] == tictactoe[1][0] && tictactoe[1][0] == tictactoe[2][0] && tictactoe[2][0] == o) ||
               (tictactoe[0][1] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][1] && tictactoe[2][1] == o) ||
               (tictactoe[0][2] == tictactoe[1][2] && tictactoe[1][2] == tictactoe[2][2] && tictactoe[2][2] == o) ||
               (tictactoe[0][0] == tictactoe[0][1] && tictactoe[0][1] == tictactoe[0][2] && tictactoe[0][2] == o) ||
               (tictactoe[1][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[1][2] && tictactoe[1][2] == o) ||
               (tictactoe[2][0] == tictactoe[2][1] && tictactoe[2][1] == tictactoe[2][2] && tictactoe[2][2] == o) ||
               (tictactoe[0][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][2] && tictactoe[2][2] == o) ||
               (tictactoe[0][2] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][0] && tictactoe[2][0] == o)){
        printf("You Lose!\n");
        return true;
    }
	else if (potracker[1] && potracker[2] && potracker[3] && potracker[4] && potracker[5] &&
             potracker[6] && potracker[7] && potracker[8] && potracker[9]){
        printf("DRAW!\n");
        return true;
    }
    return false;
}

int	computerTurn(char tictactoe[3][3], bool potracker[10], char playerToken, char computerToken){
    //bool aisturn = true;
	srand(time(NULL));
    int position = 0;
	
	////////////////////////////////////////// blocking moves ////////////////////////////////////
	// X | X | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | 9 
	if(tictactoe[0][0] == playerToken && tictactoe[1][0] == playerToken && !potracker[3])position  = 3;
	// X | 2 | X 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][0] == playerToken && tictactoe[2][0] == playerToken && !potracker[2])position  = 2;
	// 1 | X | X 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[1][0] == playerToken && tictactoe[2][0] == playerToken && !potracker[1])position  = 1;
	// 1 | 2 | 3 
	//-----------
	// X | X | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][1] == playerToken && tictactoe[1][1] == playerToken && !potracker[6])position  = 6;
	// 1 | 2 | 3 
	//-----------
	// X | 5 | X 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][1] == playerToken && tictactoe[2][1] == playerToken && !potracker[5])position  = 5;
	// 1 | 2 | 3 
	//-----------
	// 4 | X | X 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[1][1] == playerToken && tictactoe[2][1] == playerToken && !potracker[4])position  = 4;
	// 1 | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// X | X | 9  
	else if(tictactoe[0][2] == playerToken && tictactoe[1][2] == playerToken && !potracker[9])position  = 9;
	// 1 | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// X | 8 | X 
	else if(tictactoe[0][2] == playerToken && tictactoe[2][2] == playerToken && !potracker[8])position  = 8;
	// 1 | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | X | X 
	else if(tictactoe[1][2] == playerToken && tictactoe[2][2] == playerToken && !potracker[7])position  = 7;
	// X | 2 | 3 
	//-----------
	// X | 5 | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][0] == playerToken && tictactoe[0][1] == playerToken && !potracker[7])position  = 7;
	// X | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// X | 8 | 9 
	else if(tictactoe[0][0] == playerToken && tictactoe[0][2] == playerToken && !potracker[4])position  = 4;
	// 1 | 2 | 3 
	//-----------
	// X | 5 | 6 
	//-----------
	// X | 8 | 9 
	else if(tictactoe[0][1] == playerToken && tictactoe[0][2] == playerToken && !potracker[1])position  = 1;
	// 1 | X | 3 
	//-----------
	// 4 | X | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[1][0] == playerToken && tictactoe[1][1] == playerToken && !potracker[8])position  = 8;
	// 1 | X | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | X | 9 
	else if(tictactoe[1][0] == playerToken && tictactoe[1][2] == playerToken && !potracker[5])position  = 5;
	// 1 | 2 | 3 
	//-----------
	// 4 | X | 6 
	//-----------
	// 7 | X | 9 
	else if(tictactoe[1][1] == playerToken && tictactoe[1][2] == playerToken && !potracker[2])position  = 2;
	// 1 | 2 | X 
	//-----------
	// 4 | 5 | X 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[2][0] == playerToken && tictactoe[2][1] == playerToken && !potracker[9])position  = 9;
	// 1 | 2 | X 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | X 
	else if(tictactoe[2][0] == playerToken && tictactoe[2][2] == playerToken && !potracker[6])position  = 6;
	// 1 | 2 | 3 
	//-----------
	// 4 | 5 | X 
	//-----------
	// 7 | 8 | X 
	else if(tictactoe[2][1] == playerToken && tictactoe[2][2] == playerToken && !potracker[3])position  = 3;
	// X | 2 | 3 
	//-----------
	// 4 | X | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][0] == playerToken && tictactoe[1][1] == playerToken && !potracker[9])position  = 9;
	// X | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | X 
	else if(tictactoe[0][0] == playerToken && tictactoe[2][2] == playerToken && !potracker[5])position  = 5;
	// 1 | 2 | 3 
	//-----------
	// 4 | X | 6 
	//-----------
	// 7 | 8 | X 
	else if(tictactoe[1][1] == playerToken && tictactoe[2][2] == playerToken && !potracker[1])position  = 1;
	// 1 | 2 | X 
	//-----------
	// 4 | X | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[2][0] == playerToken && tictactoe[1][1] == playerToken && !potracker[7])position  = 7;
	// 1 | 2 | X 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// X | 8 | 9 
	else if(tictactoe[2][0] == playerToken && tictactoe[0][2] == playerToken && !potracker[5])position  = 5;
	// 1 | 2 | 3 
	//-----------
	// 4 | X | 6 
	//-----------
	// X | 8 | 9 
	else if(tictactoe[0][2] == playerToken && tictactoe[1][1] == playerToken && !potracker[3])position  = 3;
	
	///////////////////////////////////////////// winning moves ///////////////////////////////////
	// O | O | O 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][0] != playerToken && tictactoe[1][0] != playerToken && tictactoe[2][0] != playerToken && (tictactoe[0][0] == computerToken || tictactoe[1][0] == computerToken || tictactoe[2][0] == computerToken)){
			if(!potracker[1]) position = 1;
			else if(!potracker[2]) position = 2;
			else if(!potracker[3]) position = 3;
	}
	// 1 | 2 | 3 
	//-----------
	// O | O | O 
	//-----------
	// 7 | 8 | 9 
	else if(tictactoe[0][1] != playerToken && tictactoe[1][1] != playerToken && tictactoe[2][1] != playerToken && (tictactoe[0][1] == computerToken || tictactoe[1][1] == computerToken || tictactoe[2][1] == computerToken)){
		if(!potracker[4]) position = 4;
		else if(!potracker[5]) position = 5;
		else if(!potracker[6]) position = 6;
	}
	// 1 | 2 | 3 
	//-----------
	// 4 | 5 | 6 
	//-----------
	// O | O | O 
	else if(tictactoe[0][2] != playerToken && tictactoe[1][2] != playerToken && tictactoe[2][2] != playerToken && (tictactoe[0][2] == computerToken || tictactoe[1][2] == computerToken || tictactoe[2][2] == computerToken)){
		if(!potracker[7]) position = 7;
		else if(!potracker[8]) position = 8;
		else if(!potracker[9]) position = 9;
	}
	// O | 2 | 3 
	//-----------
	// O | 5 | 6 
	//-----------
	// O | 8 | 9 
	else if(tictactoe[0][0] != playerToken && tictactoe[0][1] != playerToken && tictactoe[0][2] != playerToken && (tictactoe[0][0] == computerToken || tictactoe[0][1] == computerToken || tictactoe[0][2] == computerToken)){
		if(!potracker[1]) position = 1;
		else if(!potracker[4]) position = 4;
		else if(!potracker[7]) position = 7;
	}
	// 1 | O | 3 
	//-----------
	// 4 | O | 6 
	//-----------
	// 7 | O | 9 
	else if(tictactoe[1][0] != playerToken && tictactoe[1][1] != playerToken && tictactoe[1][2] != playerToken && (tictactoe[1][0] == computerToken || tictactoe[1][1] == computerToken || tictactoe[1][2] == computerToken)){
		if(!potracker[2]) position = 2;
		else if(!potracker[5]) position = 5;
		else if(!potracker[8]) position = 8;
	}
	// 1 | 2 | O 
	//-----------
	// 4 | 5 | O 
	//-----------
	// 7 | 8 | O 
	else if(tictactoe[2][0] != playerToken && tictactoe[2][1] != playerToken && tictactoe[2][2] != playerToken && (tictactoe[2][0] == computerToken || tictactoe[2][1] == computerToken || tictactoe[2][2] == computerToken)){
		if(!potracker[3]) position = 3;
		else if(!potracker[6]) position = 6;
		else if(!potracker[9]) position = 9;
	}
	// O | 2 | 3 
	//-----------
	// 4 | O | 6 
	//-----------
	// 7 | 8 | O 
	else if(tictactoe[0][0] != playerToken && tictactoe[1][1] != playerToken && tictactoe[2][2] != playerToken && (tictactoe[0][0] == computerToken || tictactoe[1][1] == computerToken || tictactoe[2][2] == computerToken)){
		if(!potracker[1]) position = 1;
		else if(!potracker[5]) position = 5;
		else if(!potracker[9]) position = 9;
	}
	// 1 | 2 | O 
	//-----------
	// 4 | O | 6 
	//-----------
	// O | 8 | 9 
	else if(tictactoe[2][0] != playerToken && tictactoe[1][1] != playerToken && tictactoe[0][2] != playerToken && (tictactoe[2][0] == computerToken || tictactoe[1][1] == computerToken || tictactoe[0][2] == computerToken)){
		if(!potracker[3]) position = 3;
		else if(!potracker[5]) position = 5;
		else if(!potracker[7]) position = 7;
	}
	
	//////////////////////////////////////// random moves /////////////////////////////////////////
	else{
		while (1)
		{
			position = (rand() % 9) + 1;
			
			if (potracker[position] == true){
				position = (rand() % 9) + 1;
			} 
			else{
				break;
			}
		}
	}
	return position;
}

void	updateBoard(char tictactoe[3][3], bool potracker[10], int position, char playerToken){
	switch(position) {
		case 1 :
			tictactoe[0][0] = playerToken;
			break;
		case 2 :
			tictactoe[1][0] = playerToken;
			break;
		case 3 :
			tictactoe[2][0] = playerToken;
			break;
		case 4 :
			tictactoe[0][1] = playerToken;
			break;
		case 5 :
			tictactoe[1][1] = playerToken;
			break;
		case 6 :
			tictactoe[2][1] = playerToken;
			break;
		case 7 :
			tictactoe[0][2] = playerToken;
			break;
		case 8 :
			tictactoe[1][2] = playerToken;
			break;
		case 9 :
			tictactoe[2][2] = playerToken;
			break;
		 
		default :
			printf("Invalid Response\n");
		}
}

void printBoard(char tictactoe[3][3]){
	printf(" %c | %c | %c \n", tictactoe[0][0], tictactoe[1][0], tictactoe[2][0]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", tictactoe[0][1], tictactoe[1][1], tictactoe[2][1]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", tictactoe[0][2], tictactoe[1][2], tictactoe[2][2]);
}