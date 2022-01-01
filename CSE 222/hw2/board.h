using namespace std;


void initial_board (char board[MAX_SIZE][MAX_SIZE])	//Fill the initial board
{
	int i,j;

	for (i = 0; i < MAX_SIZE; ++i)
	{
		for (j = 0; j < MAX_SIZE; ++j)
		{
			board[i][j]='*';
		}		
	}

}


void print_board (char board[MAX_SIZE][MAX_SIZE],char letters[],int size)	//Printing board
{
	int i,j,k,l;

	l=1;

	for(i=0; i < size; ++i)
	{
		cout <<"   "<< letters[i];
	}
	
	cout << "\n";

	for (i = 0; i < size; ++i)
	{

		cout << l << "   ";
		l++;

		for (k = 0; k < i; ++k)
		{
			cout << "   ";
		}

		for (j = 0; j < size; ++j)
		{
			cout << board[i][j] << "   ";
		}
		cout << "\n\n";
	}

}


