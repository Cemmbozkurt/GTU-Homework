#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
using namespace std;


	enum class Cellinfo{empty, X, O, start_X, start_O, goal_X, goal_O, path_X, path_O};

class Hex
{

	private:
		int flag=0;
		int size;
		char opponent_choice;
		char letter_user;
		int number;
		int switch_player;
		string str1;
		string str2;
		int row;
		int col;
		int find_start_X;
		int find_start_O;
		char board_letters[27]="abcdefghijklmnopqrstuvwxyz";

			class Cell
			{
				public:
					Cell( );
					inline char getChar( ){return character;};
					inline void setCharinput(char x){character = x;};
					inline void setCharacter( ){character = character-32;};
					void setCharX( );
					void setCharO( );
					void setInfo_empty( );
					void setInfo_Xgoal( );
					void setInfo_Ogoal( );
					void setInfo_Xstart( );
					void setInfo_Ostart( );
					void setInfo_Xpath( );
					void setInfo_Opath( );
					inline Cellinfo getInfo( ){return info;};
					
						
				
				private:
					Cellinfo info;
					char character;
			};

			Cell myCell;
			vector<vector<Cell>> hexCells;
			vector<vector<Cell>> hexCellsX;
			vector<vector<Cell>> hexCellsO;


		public:
			Hex( );
			inline int getSize( ){return size;};
			inline char getOpponentchoice( ){return opponent_choice;};
			inline int getSwitchplayer( ){return switch_player;};
			inline void setFlag( ){flag = 1;};
			char getChar( ){return myCell.getChar( );};
			void setCharinput(char x){myCell.setCharinput(x);};
			void setCharX( ){myCell.setCharX( );};
			void setCharO( ){myCell.setCharO( );};
			void setCharacter( ){myCell.setCharacter( );};
			void setInfo_empty( ){myCell.setInfo_empty( );};
			void setInfo_Xgoal( ){myCell.setInfo_Xgoal( );};
			void setInfo_Ogoal( ){myCell.setInfo_Ogoal( );};
			void setInfo_Xstart( ){myCell.setInfo_Xstart( );};
			void setInfo_Ostart( ){myCell.setInfo_Ostart( );};
			void setInfo_Xpath( ){myCell.setInfo_Xpath( );};
			void setInfo_Opath( ){myCell.setInfo_Opath( );};
			Cellinfo getInfo( ){return myCell.getInfo( );};


			inline int getNumber( ){return number;};

			inline void setRow(int a){a = row;};
			inline void setCol(int a){a = col;};

			inline int getRow( ){return row;};
			inline int getCol( ){return col;};

			void playGame( );
			void initial_board( );
			void displayBoard( );

			void setString( );

			int count_length(string str);
			int controlTxt(string str);
			void convert_lowercase(string &str);
			int save_game(string &file,vector<vector<Cell>> &hexCells, vector<vector<Cell>> &hexCellsX,vector<vector<Cell>> &hexCellsO);
			int load_file(string &file,vector<vector<Cell>> &hexCells, vector<vector<Cell>> &hexCellsX,vector<vector<Cell>> &hexCellsO);
			int split_string( );
			int letter_cordinate( );
			int check_number( );
			int check_letter( );
			int check_location( );
			int check_location_AI(int x,int y);

			void fill_hexCellsX(vector<vector<Cell>> &hexCellsX);
			void fill_hexCellsO(vector<vector<Cell>> &hexCellsO);

			Hex(string loadFile);


			int control_finish_X( );
			int control_finish_O( );
			int control_start_X( );
			int control_start_O( );

			int winPath_X(int rows,int column,vector<vector<Cell>> &hexCellsX);
			int winPath_O(int rows,int column,vector<vector<Cell>> &hexCellsO);
			void make_winner_path_upper(vector<vector<Cell>> &hexc);
			void play(int row,int col);
			int play( );

			
};



int main( )
{
	Hex game,game1,game2,game3,game4;

	vector <Hex> testgames;


	int i = 0;
	int choice;
	int newgameCount=0;
	int showOptions;

	while(i == 0)
	{

		cout<<"1-Play Game\n";
		cout<<"2-New Game\n";
		cout<<"3-Exit Game\n";
		cin >> choice;

		switch(choice)
		{
		
		case 1:
			testgames.push_back(game);	
			testgames[0].playGame( );
			testgames[0].setFlag( );
			newgameCount++;
			break;	
		

		case 2:
			if(newgameCount == 1)
			{
				
				testgames.push_back(game1);			
				testgames[1].playGame( );
				testgames[1].setFlag( );
				newgameCount++;
			}
			break;

			if (newgameCount == 2)
			{
				testgames.push_back(game2);				
				testgames[2].playGame( );
				testgames[2].setFlag( );
				newgameCount++;
			}
			break;

			if (newgameCount == 3)
			{
				testgames.push_back(game3);				
				testgames[3].playGame( );
				testgames[3].setFlag( );
				newgameCount++;
				
			}
			break;

			if (newgameCount == 4)
			{
				testgames.push_back(game4);				
				testgames[4].playGame( );
				testgames[4].setFlag( );
				newgameCount++;
				
			}
			break;
		




		case 3:
			exit(1);
			break;



		default:
			cout<<"Invalid input!\n";
				cin.clear();			//For example if user enter 1a instead of a1/
				cin.ignore(10000,'\n');
			break;

	}

	
}

	return 0;
}

Hex::Hex( )
{
	switch_player = 1;
	find_start_X = 0;
	find_start_O = 0;

}


Hex::Cell::Cell( ){

	info = Cellinfo::empty;
	character = '*';

}





void Hex::initial_board( )
{
	
	int i,j;

	
	for (i = 0; i < size; ++i)
	{
		vector<Cell> temp;
		for (j = 0; j < size; ++j)
		{
			Hex::Cell fill;
			temp.push_back(fill);
		}

		hexCells.push_back(temp);
		hexCellsX.push_back(temp);
		hexCellsO.push_back(temp);
	}


}


void Hex::displayBoard( )
{
	int i,j,k,l;

	l=1;

	for(i=0; i < size; ++i)
	{
		cout <<"   "<< board_letters[i];
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
			cout << hexCells[i][j].getChar( ) << "   ";
		}
		cout << "\n\n";
	}

}



void Hex::setString( )
{
	string s1,s2;

	cin >> s1 >> s2;
	str1 = s1;
	str2 = s2;
}


int Hex::count_length(string str)
	{
		int count=0,i=0;

		while(str[i]!='\0')
		{			
			count++;
			i++;
		}

		return count;
	}


int Hex::controlTxt(string str2)
	{
		string txt=".TXT";
		int i=0;

		while(str2[i] != '\0'){

			if (str2[i] == '.')
			{
				if (str2[i+1] == 'T' && str2[i+2] == 'X' && str2[i+3] == 'T')
				{
					return 1;
				}
			}

			i++;
		}
		return 0;
	}	




int Hex::split_string( )
{
		string load = "LOAD";	


		string save = "SAVE";
		string txt = ".TXT";

		if (count_length(str1) == 1)
		{
			letter_user = str1[0];
			if (count_length(str2) == 1)
			{
				number = str2[0]-48;		//Char to int
			}

			else if(count_length(str2) == 2)		//If user enter two digit number.
			{
				number = stoi(str2);
			}
			
			return 1;		
		}

		else if (str1 == load || str1 == save)
		{
			if (controlTxt(str2) == 1)
			{
				return 2;
			}
		}

		return 0;
}

			/*
				CONTROL FUNCTIONS

			*/

int Hex::letter_cordinate( )
{
	int i=0;

	while(i<size)
	{
		if (board_letters[i] == letter_user)
		{
			return i;
		}

		else{
			i++;
		}
		
	}
	return 0;

}

int Hex::check_number( )	// Checking number that user entered.
{
	if (size >= number && number > 0)
	{
		return 1;
		
	}

	else{
		return 0;
	}
}

int Hex::check_letter( )
{
	int i=0;

	while(i < size)
	{
		if (board_letters[i] == letter_user)
		{
			return 1;
		}
		i++;
	}

	return 0;
}

int Hex::check_location( )
{

	if (hexCells[row][col].getChar( ) == 'x')
	{
		return 0;
	}

	else if(hexCells[row][col].getChar( ) == 'o')
	{
		return 0;

	}

	else{
		return 1;
	}

	return 0;
}


int Hex::check_location_AI(int x, int y) //checking location wheter is aviable.
{
	if (hexCells[row][col].getChar( ) == 'x')
	{

		return 0;
	}

	else if(hexCells[row][col].getChar( ) == 'o')
	{
		return 0;

	}

	else{
		return 1;
	}

}


void Hex::Cell::setCharX( )
{
	character = 'x';
	info = Cellinfo::X;

}

void Hex::Cell::setCharO( )
{
	character = 'o';
	info = Cellinfo::O;

}

void Hex::Cell::setInfo_empty( )
{
	info = Cellinfo::empty;
}

void Hex::Cell::setInfo_Xgoal( )
{
	info = Cellinfo::goal_X;
}

void Hex::Cell::setInfo_Ogoal( )
{
	info = Cellinfo::goal_O;
}

void Hex::Cell::setInfo_Xstart( )
{
	 info = Cellinfo::start_X;
}

void Hex::Cell::setInfo_Ostart( )
{
	info = Cellinfo::start_O;
}

void Hex::Cell::setInfo_Xpath( )
{
	info = Cellinfo::path_X;
}

void Hex::Cell::setInfo_Opath( )
{
	 info = Cellinfo::path_O;
}



void Hex::play(int row,int col)
{
	if (switch_player == 1)
	{
		hexCells[row][col].setCharX( );
	}

	if (switch_player == 2)
	{
		hexCells[row][col].setCharO( );
	}
	
	
}



void Hex::fill_hexCellsO(vector<vector<Cell>> &hexCellsO)
	{

		int i,j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (hexCells[i][j].getChar( ) == '*')
				{
					hexCellsO[i][j].setInfo_empty( );
				}

				else if((i == size-1) && hexCells[i][j].getChar( ) == 'o' )
				{
					hexCellsO[i][j].setInfo_Ogoal( );
				}


				else if(i == 0  &&  hexCells[i][j].getChar( ) == 'o')
				{
					hexCellsO[i][j].setInfo_Ostart( );						
				}
		

				else if(hexCells[i][j].getChar( ) == 'o')
				{
					hexCellsO[i][j].setCharO( );					
				}

				else{
					hexCellsO[i][j].setInfo_empty( );						
				}			
			
			}
		}

	}



	void Hex::fill_hexCellsX(vector<vector<Cell>> &hexCellsX)
	{
		int i,j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (hexCells[i][j].getChar( ) == '*')
				{
					hexCellsX[i][j].setInfo_empty( );							
				}

				else if((j == size-1) && hexCells[i][j].getChar( ) == 'x' )
				{
					hexCellsX[i][j].setInfo_Xgoal( );										
				}


				else if(j == 0  &&  hexCells[i][j].getChar( ) == 'x')
				{
					hexCellsX[i][j].setInfo_Xstart( );											
				}
			

				else if(hexCells[i][j].getChar( ) == 'x')
				{
					hexCellsX[i][j].setCharX( );													
				}

				else{
					hexCellsX[i][j].setInfo_empty( );											
				}			
			
			}
		}

	}








int Hex::control_finish_X( )
{
	int x,y; //X is row, Y is column
	y = size - 1; //Because if there is a finish point it will be on last column.

	for (x = 0; x < size; ++x)
		{
			if (hexCellsX[x][y].getInfo( ) == Cellinfo::goal_X)
			{		
					return 1;
			}		
		}
		return 0;
}


int Hex::control_finish_O( )
{
	int x = size-1;
	int y; //Because if there is a finish point it will be on last row.

	for (y = 0; y < size; ++y)
		{
			if (hexCellsO[x][y].getInfo( ) == Cellinfo::goal_O)
			{
				return 1;
			}	

		}
		return 0;
}


int Hex::control_start_X( )
{
		int x;
		int y = 0;	//Because if there is a start point it will be on first column

		for (x = 0; x < size; ++x)
		{
			if (hexCellsX[x][y].getInfo( ) == Cellinfo::start_X)
			{
				return 1;
			}		
		}
		return 0;
}

int Hex::control_start_O( )
{
		int x = 0;
		int y; //Because if there is a start point it will be on first row.

		for (y = 0; y < size; ++y)
		{
			if (hexCellsO[x][y].getInfo( ) == Cellinfo::start_O)
			{
				return 1;
			}			
		}
		return 0;
}



	void Hex::convert_lowercase(string &str)
	{
		int i = 0;
											
		while(str[i]!='.')					
		{
			i++;
		}

		if (i == '.')
		{
			str[i+1] +=32;
			str[i+2] +=32;
			str[i+3] +=32;

		}

	}



int Hex::save_game(string &file_name, vector<vector<Cell>> &hexCells, vector<vector<Cell>> &hexCellsX, vector<vector<Cell>> &hexCellsO)
{

	ofstream saveFile;

		convert_lowercase(file_name);

		saveFile.open(file_name);

			if(saveFile.is_open()){	//checking if file open correctly

				saveFile << "Choice" << endl;
				saveFile << opponent_choice << endl;
				saveFile << "Size" << endl;
				saveFile << size << endl;
				saveFile << "Player" << endl;
				saveFile << switch_player << endl;

				int i,j;

				saveFile <<"chBoard" << endl;

				for (i = 0; i < size; ++i)
				{
					for (j = 0; j < size; ++j)
					{
						saveFile << hexCells[i][j].getChar( );
					}
					saveFile << "\n";
				}


				saveFile <<"marked_X" << endl;

				for (i = 0; i < size; ++i)
				{
					for (j = 0; j < size; ++j)
					{
						saveFile << hexCellsX[i][j].getChar( );
					}
					saveFile << "\n";
				}



				saveFile <<"marked_O" << endl;

				for (i = 0; i < size; ++i)
				{
					for (j = 0; j < size; ++j)
					{
						saveFile << hexCellsO[i][j].getChar( );
					}

					saveFile << "\n";
				}

			}

		else{
			cerr <<"file save error" << endl;
			return 0;
		}


		saveFile.close();
		return 1;

}





	int Hex::load_file(string &file_name, vector<vector<Cell>> &hexCells, vector<vector<Cell>> &hexCellsX, vector<vector<Cell>> &hexCellsO)		//Load file
	{
		ifstream loadFile;
		convert_lowercase(file_name);

		loadFile.open(file_name);


		
				string line;

				string zero = "Choice";
				string first = "Size";
				string second = "Player";
				string third = "chBoard";
				string fourth = "marked_X";
				string fifth = "marked_O";

				int i,j;
				int count;

				if (loadFile.is_open()){	//checking if file open correctly
								

				while(getline(loadFile,line)){


						if (line == zero)
						{	
							
							getline(loadFile,line);
							opponent_choice = line[0];

						}

						else if (line == first)
						{
							
							getline(loadFile,line);
							size = stoi(line);

						}

						else if (line == second)
						{
							
							getline(loadFile,line);
							switch_player = stoi(line);
						}	

						else if (line == third)
						{
							
							i=0;
							while(line != fourth)
							{

							
								getline(loadFile,line);
								if (line != fourth){
								j=0;
														
								while(line[j]!='\0')
								{
									hexCells[i][j].setCharinput(line[j]);
									j++;
								}

								i++;

							}
						}
														
						}


						else if (line == fourth)
						{
						
							i=0;
							while(line != fifth)
							{
								getline(loadFile,line);
								if(line != fifth){
								j=0;
							
								while(line[j]!='\0')
								{
									hexCellsX[i][j].setCharinput(line[j]);
									j++;
								
								}

								i++;
							 }
							}	
						}



						else if (line == fifth)
						{
							
							i=0;
							while(getline(loadFile,line))
							{
								j=0;

								while(line[j]!='\0')
								{
									hexCellsO[i][j].setCharinput(line[j]);
									j++;
								}

								i++;
							}	
						}
				
					}

			}

				else{
					cerr << "File does not exist!" << endl;
					return 0;
					
				}

				loadFile.close();
				return 1;

	}



int Hex::winPath_X(int rows,int column,vector<vector<Cell>> &hexCellsX)
{


		if (hexCellsX[rows][column].getInfo( ) == Cellinfo::goal_X)
		{
			hexCellsX[rows][column].setInfo_Xpath( );					
			return 1;
		}



		if ((hexCellsX[rows][column].getInfo( ) == Cellinfo::X) || ((hexCellsX[rows][column].getInfo( ) == Cellinfo::start_X)))
		{
			hexCellsX[rows][column].setInfo_Xpath( );

			if (rows == 0  &&  column == 0  &&  hexCellsX[0][0].getInfo( ) == Cellinfo::start_X)	//if start point is on left top corner.
			{
				if (winPath_X(rows-1,column,hexCellsX))	// South
					{
						hexCellsX[rows][column].setInfo_Xpath( );	
						return 1;
					}

				if (winPath_X(rows,column+1,hexCellsX))	// East
					{
						hexCellsX[rows][column].setInfo_Xpath( );	
						return 1;
					}	
				
			}


			else if (rows == size-1 && column == 0 && hexCellsX[rows][column].getInfo( ) == Cellinfo::start_X)	//if start point is on left bottom corner.
			{
				if (winPath_X(rows+1,column,hexCellsX))	//North
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

				if (winPath_X(rows,column+1,hexCellsX))	//East
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}
					

				if (winPath_X(rows-1,column+1,hexCellsX))	// north east
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}		
			}


			else if (hexCellsX[rows][column].getInfo( ) == Cellinfo::start_X)	//For first column moving is diffrent (if it is between the left sides corner)
				{
					if (winPath_X(rows-1,column,hexCellsX))
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows+1,column,hexCellsX))
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows,column+1,hexCellsX))
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows-1,column+1,hexCellsX))
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}
				}


				else{											

					if (winPath_X(rows,column+1,hexCellsX))		//East
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows,column-1,hexCellsX))		//West
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows+1,column,hexCellsX))		//south
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows-1,column,hexCellsX))		//north
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows-1,column+1,hexCellsX))	// north east
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

					if (winPath_X(rows+1,column-1,hexCellsX))	//south west
					{
						hexCellsX[rows][column].setInfo_Xpath( );
						return 1;
					}

				}
			
		}

	return 0;

	}




int Hex::winPath_O(int rows,int column,vector<vector<Cell>> &hexCellsO)
{


		if (hexCellsO[rows][column].getInfo( ) == Cellinfo::goal_O)
		{
			hexCellsO[rows][column].setInfo_Opath( );					
			return 1;
		}



		if ((hexCellsO[rows][column].getInfo( ) == Cellinfo::O) || ((hexCellsO[rows][column].getInfo( ) == Cellinfo::start_O)))
		{
			hexCellsO[rows][column].setInfo_Opath( );

			if (rows == 0  &&  column == 0  &&  hexCellsO[0][0].getInfo( ) == Cellinfo::start_O)	//if start point is on left top corner.			
				if (winPath_O(rows-1,column,hexCellsO))	// South
					{
						hexCellsO[rows][column].setInfo_Opath( );	
						return 1;
					}

				if (winPath_O(rows,column+1,hexCellsO))	// East
					{
						hexCellsO[rows][column].setInfo_Opath( );	
						return 1;
					}	
				
			


			else if (rows == 0 && column == size-1 && hexCellsO[rows][column].getInfo( ) == Cellinfo::start_O)	// if start point os on right
			{
				if (winPath_O(rows-1,column,hexCellsO))	//South
					{
						hexCellsO[rows][column].setInfo_Opath( );	
						return 1;
					}

				if (winPath_O(rows,column-1,hexCellsO))	//west
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
					

				if (winPath_O(rows+1,column-1,hexCellsO))	//south west
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}		
			}


			else if (hexCellsO[rows][column].getInfo( ) == Cellinfo::start_O)	//For first row moving is diffrent.
				{
					if (winPath_O(rows+1,column-1,hexCellsO))  //south west
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}

					if (winPath_O(rows+1,column,hexCellsO))	//South
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}

					if (winPath_O(rows,column+1,hexCellsO))	//East
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}

					if (winPath_O(rows,column-1,hexCellsO))	//West
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}


				else{											

						if (winPath_O(rows,column+1,hexCellsO))		//East
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

						if (winPath_O(rows,column-1,hexCellsO))		//West
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

						if (winPath_O(rows+1,column,hexCellsO))		//south
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

						if (winPath_O(rows-1,column,hexCellsO))		//north
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

						if (winPath_O(rows-1,column+1,hexCellsO))	// north east
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

						if (winPath_O(rows+1,column-1,hexCellsO))	//south west
						{
							hexCellsO[rows][column].setInfo_Opath( );
							return 1;
						}

				}

			}
			return 0;
}







void Hex::make_winner_path_upper(vector<vector<Cell>> &hexc)
	{
		char ch;
		int i,j;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				if (hexc[i][j].getInfo( ) == Cellinfo::path_X || hexc[i][j].getInfo( ) == Cellinfo::path_O )
				{
					hexc[i][j].setCharacter( );				
				}			
			}
		}

	}



int Hex::play( )
{
		int random_row;
		int random_col;

		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<double> dist(0,size);		//to generate random numbers


	

		// I observed that trying to capture middle of the game is important so that I am trying to achive that.

		
			if (hexCells[size/2][size/2].getChar( ) == '*')
			{
				hexCells[size/2][size/2].setCharO( );
				return 1;				
			}

			if(hexCells[(size/2)+1][size/2].getChar( ) == '*'){
				hexCells[(size/2)+1][size/2].setCharO( );
				return 1;			
			}

						// Here I am trying to do defence. Trying to block users path.

						

	if (col+1 < size)
	{

		if (check_location_AI(row,col+1) == 1)
		{		
			hexCells[row][col+1].setCharO( );
			return 1;
		}

		if (check_location_AI(row-1,col+1) == 1)
		{
			hexCells[row-1][col+1].setCharO( );
			return 1;
		}

	}

		if (check_location_AI(row-1,col) == 1)
		{
			hexCells[row-1][col].setCharO( );			
			return 1;
		}


		if (check_location_AI(row+1,col) == 1)
		{
			hexCells[row+1][col].setCharO( );
			return 1;
		}


	

		while(1>0)		//Since conditions are not useful anymore then it will assign random numbers.
		{
			random_col = dist(mt);
			random_row = dist(mt);

			if (hexCells[random_row][random_col].getChar( ) == '*')
			{
				hexCells[random_row][random_col].setCharO( );
				return 1;
			}

		}

		return 0;



}	




void Hex::playGame( )
{
	string s1,s2;
	int i = 1;
	int user_size;
	int count=0;
	int control_player = 0;

if(flag==0){
	while(i == 1)
	{
		cout << "Enter board size:\n";
		cin	 >> user_size;

		if (user_size < 27 && user_size > 5)
		{
			size = user_size;
			i++;	
		}
		else{
			cerr << "!Size must greater than 5 and smaller than 27!\n";
			cin.clear();			
			cin.ignore(10000,'\n');			
		}
	}



	char choice;
	i=1;

	while(i>0){
		cout << "Press (a) to play against computer\n";
		cout << "Press (b) to play with real opponent\n";
		cin >> choice;
		
		if (choice == 'a' || choice == 'b')
		{
			opponent_choice = choice;
			i=0;
		}

		else{
			cerr << "!Your choice should be a or b!\n";
			cin.clear();			
			cin.ignore(10000,'\n');
		}
	}
	initial_board( );
	displayBoard( );
}
	

while(count < size*size)
{	
	while(switch_player == 1 && count < 1000)
	{
		
		cout << "Make your move(X): ";
		cin >> str1 >> str2;

		if (str1 !="QUIT" || str2 !="GAME")
		{
	
			if (split_string( ) == 2)
			{

				if (str1 == "LOAD")
					{
						if(load_file(str2,hexCells,hexCellsX,hexCellsO)==1){
						cout <<"\n\n ***Game is loaded!***" << endl;
						displayBoard( );
						}
					}

				else if(str1 == "SAVE"){

						if(save_game(str2,hexCells,hexCellsX,hexCellsO)==1)
						cout <<"\n ***Game is saved!***" << endl;

						}
			}


		if (split_string( ) == 1)
		{
			if (check_letter( ) == 1 && check_number( ) == 1)
			{
				col = letter_cordinate( );
				row = number - 1;

				if (check_location( ) == 1)
				{				
					play(row,col);
					displayBoard( );
					fill_hexCellsX(hexCellsX);
					find_start_X = 0;
					count++;
					if (control_start_X( ) == 1 && control_finish_X( ) == 1)
					{
					
						while(size > find_start_X)
						{
							if (hexCellsX[find_start_X][0].getInfo( ) == Cellinfo::start_X)	//Start point will be on First column and I must check all start points.
							{	
																				
								if (winPath_X(find_start_X,0,hexCellsX) == 1)	//I should pass start point to the function.
								{
									make_winner_path_upper(hexCellsX);
									displayBoard( );
									cout << "(X) GAME OVER (X)\n";
									cout << "\nPlayer (X) is the winner\n"<<endl;
									find_start_X = 27;	//MAX_SIZE is 26.
									count = 1000;	// To finish program
								}
							}

							else

							find_start_X++;	
						}					

					}

					if (count == 1000)
					{
						switch_player = 3;
					}
					else
						switch_player = 2;
				}

				else{
					cerr << "Invalid move!\n";
				}
				
			}

			else
			{
				cerr << "\nInvalid number or letter! (for example: a 1, c 2, d 3)\n";
			}

			cin.clear();			
			cin.ignore(10000,'\n');

		}

	 }
	 else{
	 		cout << "\n Quiting...\n\n";
	 		count = 1000;
	 		}////
	}



		if (opponent_choice == 'b')
		{

		while(switch_player == 2 && count < 1000)
		{
		cout << "Make your move(O): ";
		cin >> str1 >> str2;

		if (str1 !="QUIT" || str2 !="GAME"){
		

		if (split_string( ) == 2)
		{
			if (str1 == "LOAD")
					{
						if(load_file(str2,hexCells,hexCellsX,hexCellsO)==1){
						cout <<"\n\n ***Game is loaded!***" << endl;
						displayBoard( );
						}
					}

				else if(str1 == "SAVE"){

						if(save_game(str2,hexCells,hexCellsX,hexCellsO)==1)
						cout <<"\n ***Game is saved!***" << endl;

					}
		}


		if (split_string( ) == 1)
		{
			if (check_letter( ) == 1 && check_number( ) == 1)
			{
				col = letter_cordinate( );
				row = number - 1;

				if (check_location( ) == 1)
				{				
					play(row,col);
					displayBoard( );
					fill_hexCellsO(hexCellsO);
					find_start_O = 0;
					count++;
					if (control_start_O( ) == 1 && control_finish_O( ) == 1)
					{
						while(size > find_start_O)
						{
							if (hexCellsO[0][find_start_O].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
							{	
																				
								if (winPath_O(0,find_start_O,hexCellsO) == 1)	//I should pass start point to the function.
								{
									make_winner_path_upper(hexCellsO);
									displayBoard( );
									cout << "(O) GAME OVER (O)\n";
									cout << "\nPlayer (O) is the winner\n"<<endl;
									find_start_O = 27;	//MAX_SIZE is 26.
									count = 1000;	// To finish program
								}
							}

							else

							find_start_O++;	
						}					

					}

					if (count == 1000)
					{
						switch_player = 3;
					}
					else
						switch_player = 1;
				}

				else{
					cerr << "Invalid move!\n";
				}
				
			}

			else
			{
				cerr << "\nInvalid number or letter! (for example: a 1, c 2, d 3)\n";
			}

			cin.clear();			//For example if user enter 1a instead of a1/
			cin.ignore(10000,'\n');

		}

	  }

	  else{
	  			cout << "\n Quiting... \n";
				count = 1000;

	  }


	}	

		
			
	}


		if (opponent_choice == 'a')
		{
			while(switch_player == 2)
				{	
					control_player=play( );
					fill_hexCellsO(hexCellsO);
					displayBoard( );
					find_start_O = 0;
					count++;

					if (control_start_O( ) == 1 && control_finish_O( ) == 1)
					{
							while(size > find_start_O)
									{
										if (hexCellsO[0][find_start_O].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
										{	
																							
											if (winPath_O(0,find_start_O,hexCellsO) == 1)	//I should pass start point to the function.
											{
												make_winner_path_upper(hexCellsO);
												displayBoard( );
												cout << "(O) GAME OVER (O)\n";
												cout << "\nPlayer (O) is the winner\n"<<endl;
												find_start_O = 27;	//MAX_SIZE is 26.
												count = 1000;	// To finish program
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





}





}