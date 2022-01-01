using namespace std;


int check_letter(char letter_user,char letters[],int size)	// Checking letter whether it is valid.
{
	int i=0;

	while(i < size)
	{
		if (letters[i] == letter_user)
		{
			return 1;
		}
		i++;
	}

	return 0;
}



int check_number(int number,int size)	// Checking number that user entered.
{
	if (size >= number && number > 0)
	{
		return 1;
		
	}

	else{
		return 0;
	}
}




int letter_coordinate(char letters[], char letter_user, int size)	// determine the letters column
{
	int i=0;

	while(i<size)
	{
		if (letters[i] == letter_user)
		{
			return i;
		}

		else{
			i++;
		}
		
	}
	return 0;
}





int check_location(char board[MAX_SIZE][MAX_SIZE], int row, int column) //checking location wheter is aviable.
{
	if (board[row][column] == 'x')
	{

		return 0;
	}

	else if(board[row][column] == 'o')
	{
		return 0;

	}

	else{
		return 1;
	}

}

int computer_play(char board[MAX_SIZE][MAX_SIZE],int size, int count, int row, int col)
{
		int random_row;
		int random_col;

		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<double> dist(0,size);		//to generate random numbers


	

		// I observed that trying to capture middle of the game is important so that I am trying to achive that.

		if (count < 2)
		{
			if (board[size/2][size/2] == '*')
			{
				board[size/2][size/2] = 'o';
				return 1;				
			}

			else
				board[(size/2)+1][size/2] = 'o';
				return 1;			
		}

						// Here I am trying to do defence. Trying to block users path.

						

	if (col+1 < size)
	{

		if (check_location(board,row,col+1) == 1)
		{		
			board[row][col+1] = 'o';
			return 1;
		}

		if (check_location(board,row-1,col+1) == 1)
		{
			board[row-1][col+1] = 'o';
			return 1;
		}

	}

		if (check_location(board,row-1,col) == 1)
		{
			board[row-1][col] = 'o';			
			return 1;
		}


		if (check_location(board,row+1,col) == 1)
		{
			board[row+1][col] = 'o';
			return 1;
		}


	

		while(1>0)		//Since conditions are not useful anymore then it will assign random numbers.
		{
			random_col = dist(mt);
			random_row = dist(mt);

			if (board[random_row][random_col] == '*')
			{
				board[random_row][random_col] = 'o';
				return 1;
			}

		}

		return 0;
}