using namespace std;
	enum Path_X{	// TO make easier I decided to give code for every index.
		wall_X,
		X,
		X_path,
		X_start,
		X_goal	
	};

	enum Path_O{		//Wall means it can't be part of winning path.
		wall_O,
		O,
		O_path,
		O_start,
		O_goal
	};


	/*
		Also I decided that It would be easier if I make 2 diffrent marked array.

	*/
	void fill_marked_O(char board[MAX_SIZE][MAX_SIZE],int marked[MAX_SIZE][MAX_SIZE],int size)
	{

		int i,j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (board[i][j] == '*')
				{
					marked[i][j] = wall_O;
				}

				else if((i == size-1) && board[i][j] == 'o' )
				{
					marked[i][j] = O_goal;
				}


				else if(i == 0  &&  board[i][j] == 'o')
				{
					marked[i][j] = O_start;
				}
		

				else if(board[i][j] == 'o')
				{
					marked[i][j] = O;
				}

				else{
					marked[i][j] = wall_O;
				}			
			
			}
		}

	}


	void fill_marked_X(char board[MAX_SIZE][MAX_SIZE],int marked [MAX_SIZE][MAX_SIZE],int size)
	{
		int i,j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (board[i][j] == '*')
				{
					marked[i][j] = wall_X;
				}

				else if((j == size-1) && board[i][j] == 'x' )
				{
					marked[i][j] = X_goal;
				}


				else if(j == 0  &&  board[i][j] == 'x')
				{
					marked[i][j] = X_start;
				}
			

				else if(board[i][j] == 'x')
				{
					marked[i][j] = X;
				}

				else{
					marked[i][j] = wall_X;
				}			
			
			}
		}

	}


  /* 
	Because I make of two diffrent marked array, I made 2 diffrent Win control function because
	it is easier and due to position of Start points and their type (X,O) It changes that how can
	they connected.

	I assume that start point for X is Left side of parallelogram and finish point is right side of parallelogram
	and for O I assume that start point is top side of parallelogram and finish point is bottom side of parallelogram.

	(With parallelogram I mean figure that in 2nd page of Homework PDF)

  */

	/*
		Logis is same for both winPath_X and winPath_O but there is diffrent about searching directiouns.
		
		When function reach the goal point(X_goal and O_goal) recursive function is finished.
		Paths are 

	*/



	int winPath_X(int row,int column,int marked[MAX_SIZE][MAX_SIZE],int size){


		if (marked[row][column] == X_goal)
		{
			marked[row][column] == X_path;
			return 1;
		}



		if ((marked[row][column] == X) || (marked[row][column] == X_start))
		{
			marked[row][column] = X_path;

			if (row == 0  &&  column == 0  &&  marked[0][0] == X_start)	//if start point is on left top corner.
			{
				if (winPath_X(row-1,column,marked,size))	// South
					{
						marked[row][column] = X_path;
						return 1;
					}

				if (winPath_X(row,column+1,marked,size))	// East
					{
						marked[row][column] = X_path;
						return 1;
					}	
				
			}


			else if (row == size-1 && column == 0 && marked[row][column] == X_start)	//if start point is on left bottom corner.
			{
				if (winPath_X(row+1,column,marked,size))	//North
					{
						marked[row][column] = X_path;
						return 1;
					}

				if (winPath_X(row,column+1,marked,size))	//East
					{
						marked[row][column] = X_path;
						return 1;
					}
					

				if (winPath_X(row-1,column+1,marked,size))	// north east
					{
						marked[row][column] = X_path;
						return 1;
					}		
			}


			else if (marked[row][column] == X_start)	//For first column moving is diffrent (if it is between the left sides corner)
				{
					if (winPath_X(row-1,column,marked,size))
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row+1,column,marked,size))
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row,column+1,marked,size))
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row-1,column+1,marked,size))
					{
						marked[row][column] = X_path;
						return 1;
					}
				}


				else{											

					if (winPath_X(row,column+1,marked,size))		//East
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row,column-1,marked,size))		//West
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row+1,column,marked,size))		//south
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row-1,column,marked,size))		//north
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row-1,column+1,marked,size))	// north east
					{
						marked[row][column] = X_path;
						return 1;
					}

					if (winPath_X(row+1,column-1,marked,size))	//south west
					{
						marked[row][column] = X_path;
						return 1;
					}

				}
			
		}

	return 0;

	}




	int winPath_O(int row,int column,int marked[MAX_SIZE][MAX_SIZE],int size){


		if (marked[row][column] == O_goal)		
		{
			marked[row][column] = O_path;
			return 1;
		}



		if ((marked[row][column] == O) || (marked[row][column] == O_start))
		{
			marked[row][column] = O_path;

			if (row == 0  &&  column == 0  &&  marked[0][0] == O_start)	//if start point is on left top corner.
			{
				if (winPath_O(row-1,column,marked,size))	// South
					{
						marked[row][column] = O_path;
						return 1;
					}

				if (winPath_O(row,column+1,marked,size))	// East
					{
						marked[row][column] = O_path;
						return 1;
					}	
				
			}



			else if(row == 0  &&  column == size-1 && marked[row][column] == O_start)	// if start point os on right top corner.
			{
				if (winPath_O(row-1,column,marked,size))	// South
					{
						marked[row][column] = O_path;
						return 1;
					}

				if (winPath_O(row,column-1,marked,size))	//West
					{
						marked[row][column] = O_path;
						return 1;
					}
					

					if (winPath_O(row+1,column-1,marked,size))	//south west
					{
						marked[row][column] = O_path;
						return 1;
					}
			}

				else if (marked[row][column] == O_start)	//For first row moving is diffrent.
				{
					if (winPath_O(row+1,column-1,marked,size)) //south west	
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row+1,column,marked,size))	//South
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row,column+1,marked,size))	//East
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row,column-1,marked,size))	//West
					{
						marked[row][column] = O_path;
						return 1;
					}
				}


				else{

					if (winPath_O(row,column+1,marked,size))		//East
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row,column-1,marked,size))		//West
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row+1,column,marked,size))		//south
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row-1,column,marked,size))		//north
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row-1,column+1,marked,size))	//north east
					{
						marked[row][column] = O_path;
						return 1;
					}

					if (winPath_O(row+1,column-1,marked,size))	//south west
					{
						marked[row][column] = O_path;
						return 1;
					}

				}
			
		}

	return 0;

	}



	int control_finish_X(int marked[MAX_SIZE][MAX_SIZE],int size) //Checking if there is finish point
	{
		int row;
		int col = size-1; //Because if there is a finish point it will be on last column.

		for (row = 0; row < size; ++row)
		{
			if (marked[row][col] == X_goal)
			{
				return 1;
			}		
		}
		return 0;
	}


	int control_finish_O(int marked[MAX_SIZE][MAX_SIZE],int size) //Checking if there is finish point
	{
		int row = size-1;
		int col; //Because if there is a finish point it will be on last row.

		for (col = 0; col < size; ++col)
		{
			if (marked[row][col] == O_goal)
			{
				return 1;
			}			
		}
		return 0;
	}


	int control_start_X(int marked[MAX_SIZE][MAX_SIZE],int size)
	{
		int row;
		int col = 0;	//Because if there is a start point it will be on first column

		for (row = 0; row < size; ++row)
		{
			if (marked[row][col] == X_start)
			{
				return 1;
			}		
		}
		return 0;
	}


	int control_start_O(int marked[MAX_SIZE][MAX_SIZE],int size)
	{
		int row = 0;
		int col; //Because if there is a start point it will be on first row.

		for (col = 0; col < size; ++col)
		{
			if (marked[row][col] == O_start)
			{
				return 1;
			}			
		}
		return 0;
	}


	void make_winner_path_upper (char board[MAX_SIZE][MAX_SIZE],int marked[MAX_SIZE][MAX_SIZE],int size)	// Since I made both enum in same order, I can use this function for both.
	{
		int i,j;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				if (marked[i][j] == X_path || marked[i][j] == O_path)
				{
					board[i][j] = board[i][j]-32;					
				}
				
			}
		}


	}