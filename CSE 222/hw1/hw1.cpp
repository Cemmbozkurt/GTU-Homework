#include <iostream>
#include <random>
#define MAX_SIZE 12
using namespace std;
#include "controlFunctions.h"
#include "board.h"
#include "path.h"


void new_board (char board[MAX_SIZE][MAX_SIZE],char letters[],int size, char opponent_choice, int marked_X[MAX_SIZE][MAX_SIZE], int marked_O[MAX_SIZE][MAX_SIZE])
{
	char letter_user;
	int number;
	int column,row;
	int count=0;
	int switch_player=1;

	int control_player=0;

	
	int find_start_X,find_start_O;

	while(count < size*size)	//Count is checking if board is full or not.
	{	

		while(switch_player == 1)
		{
			cout << "Make your move(X): ";
			cin >> letter_user >> number;

			if (check_letter(letter_user,letters,size) == 1 && check_number(number,size) == 1)
			{
				column = letter_coordinate(letters,letter_user,size);
				row = number-1;

				if (check_location(board,row,column) == 1)
				{			
					board[row][column]='x';
					count++;
					print_board(board, letters, size);
					fill_marked_X(board,marked_X,size);		
					find_start_X = 0;

					if (control_start_X(marked_X,size) == 1  &&  control_finish_X(marked_X,size) == 1)
					{
						while(size > find_start_X)
						{
							if (marked_X[find_start_X][0] == 3)	//Start point will be on First column and I must check all start points.
							{	
																// 3 is the X's start number (due to enum Path_X)
								if (winPath_X(find_start_X,0,marked_X,size) == 1)	//I should pass start point to the function.
								{
									make_winner_path_upper(board,marked_X,size);
									print_board(board,letters,size);
									cout << "(X) GAME OVER (X)\n";
									cout << "\nPlayer (X) is the winner\n"<<endl;
									find_start_X = 13;	//MAX_SIZE is 12.
									count = 145;	// To finish program
								}
							}

							else
							find_start_X++;	
						}
						
					}

					if (count == 145)
					{
						switch_player=3;
					}

					else
					switch_player=2;
				}

				else{
					cout << "Invalid move!\n";
				}	
			}




			else
			{
				cout << "\nInvalid number or letter! (for example: a1, c2, d3)\n";
			}

			cin.clear();			//For example if user enter 1a instead of a1/
			cin.ignore(10000,'\n');

		}

		
			if (opponent_choice == 'a') // play against computer
			{
				while(switch_player == 2)
				{	
					control_player=computer_play(board,size,count,row,column);
					fill_marked_O(board,marked_O,size);
					print_board(board,letters,size);
					find_start_O = 0;
					count++;

					if (control_start_O(marked_O,size) == 1  &&  control_finish_O(marked_O,size) == 1)
					{
							while(size > find_start_O)
									{
										if (marked_O[0][find_start_O] == 3)	//Start point will be on First row and I must check all start points.
										{
																			// 3 is the X's start number (due to enum Path_O)
											if (winPath_O(0,find_start_O,marked_O,size) == 1)	//I should pass start point to the function.
											{
												make_winner_path_upper(board,marked_O,size);
												print_board(board,letters,size);
												cout << "\n(O) GAME OVER (O)\n";
												cout << "\n Computer is the winner\n"<<endl;
												find_start_O = 13;	//MAX_SIZE is 12.
												count = 145;	// To finish program
											}

										}
										else
											find_start_O++;

									}
					}

					if (control_player == 1)
					{
						switch_player = 1;
					}

				}
			}





			
		
			if (opponent_choice == 'b')	// play against human
			{
				while(switch_player == 2)
				{
					cout << "Make your move(O): ";
					cin >> letter_user >> number;

					if (check_letter(letter_user,letters,size) == 1 && check_number(number,size) == 1)
					{
						column = letter_coordinate(letters,letter_user,size);
						row = number-1;
					

						if (check_location(board,row,column) == 1)
							{			
								board[row][column]='o';
								count++;
								print_board(board, letters, size);
								fill_marked_O(board,marked_O,size);	
								find_start_O = 0;
							


								if (control_start_O(marked_O,size) == 1  &&  control_finish_O(marked_O,size) == 1)
								{

									while(size > find_start_O)
									{
										if (marked_O[0][find_start_O] == 3)	//Start point will be on First row and I must check all start points.
										{
																			// 3 is the X's start number (due to enum Path_O)
											if (winPath_O(0,find_start_O,marked_O,size) == 1)	//I should pass start point to the function.
											{
												make_winner_path_upper(board,marked_O,size);
												print_board(board,letters,size);
												cout << "\n(O)  GAME OVER  (O)\n";
												cout << "\nPlayer (O) is the winner\n"<<endl;
												find_start_O = 13;	//MAX_SIZE is 12.
												count = 145;	// To finish program
											}
										}

										else
										find_start_O++;	
									}
						
								}

								if (count == 145)
								{
									switch_player=3;	//	To finish program
								}

								else
								switch_player=1;
							}	



						else{

							cout <<"Invalid move!\n";
						}
					}
					


					else
					{
						
						cout << "\nInvalid number or letter! (for example: a1, c2, d3)\n";
					}

					cin.clear();			//For example if user enter 1a instead of a1/
					cin.ignore(10000,'\n');		

		 
				}
			}	

	}

}

int main(){

	char board [MAX_SIZE][MAX_SIZE];
	int marked_X [MAX_SIZE][MAX_SIZE];
	int marked_O [MAX_SIZE][MAX_SIZE];


	char letters[]="abcdefghijkl";
	initial_board(board);
	int size;
	int control_size=1;
	char opponent_choice;

	while(control_size>0)
	{
		cout << "Enter board size:\n";
		cin	 >> size;
	
		if (size > MAX_SIZE || size < 6)
		{
			control_size=1;
			cout << "!Number must between six and twelve!\n";
			cin.clear();			//If user enter char instead of integer.
			cin.ignore(10000,'\n');			
		}

		else{
			control_size=0;
		}

	}

	while(1 > control_size)
	{	

		cout << "Press (a) to play against computer\n";
		cout << "Press (b) to play with real opponent\n";
		cin >> opponent_choice;

		if (opponent_choice == 'a' || opponent_choice == 'b')
		{
			control_size=1;
		}

		else{
			control_size = 0;
			cout << "!Your choice should be a or b!\n\n";
			cin.clear();			//If user enter char instead of integer.
			cin.ignore(10000,'\n');
		}

	}

	print_board(board, letters, size);
	new_board(board, letters, size,opponent_choice,marked_X,marked_O);
	
	return 0;
}
