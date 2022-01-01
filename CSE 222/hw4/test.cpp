#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "test1.h"
using namespace std;

int main( )
{

	Hex game[5];


	int i = 0;
	int choice;
	int currentGame = 0;
	int comp1,comp2;

	while(i == 0)
	{

		cout<<"1-Play Game\n";
		cout<<"2-New Game\n";
		cout<<"3-Compare Game\n";
		cout<<"4-Exit Game\n";
		cin >> choice;

		switch(choice)
		{

		case 1:
			game[currentGame].playGame( );
			currentGame++;
			break;

		
		case 2:
			game[currentGame].playGame( );
			currentGame++;
			break;

		case 3:
			cout << "select two game: ";
			cin >> comp1 >> comp2;	

			if(comp1 < currentGame + 1 && comp2 < currentGame + 1)
			{
				if(game[comp1] == game[comp2])
				{
					cout << "Currently games are equal" << endl;
				}
				else{
					cout << "Currently games are not equal" << endl;
				}
			}
			break;


		case 4:
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
	
	int i;
	hexCells = new Cell*[size];
	hexCellsX = new Cell*[size];
	hexCellsO = new Cell*[size];
	
	for (i = 0; i < size; i++)
	{
		hexCells[i] = new Cell[size];
		hexCellsX[i] = new Cell[size];
		hexCellsO[i] = new Cell[size];
	}

}



ostream& operator <<(ostream& outputStream, const Hex& obj)
{

	int i,j,k,l;

	l=1;

	int sizeP = obj.size;

	for(i=0; i < sizeP; ++i)
	{
		outputStream <<"   "<< obj.board_letters[i];
	}
	
	outputStream << "\n";

	for (i = 0; i < sizeP; ++i)
	{

		outputStream << l << "   ";
		l++;

		for (k = 0; k < i; ++k)
		{
			outputStream << "   ";
		}

		for (j = 0; j < sizeP; ++j)
		{
			outputStream << obj.hexCells[i][j].getChar( ) << "   ";
		}
		outputStream << "\n\n";
	}

	return outputStream;

}


Hex& Hex::operator--( )
{
	if(flag == 1)	//X wants undo
	hexCells[undorowX][undocolX].setInfo_empty( );

	else
	hexCells[undorowO][undocolO].setInfo_empty( );

	return *this;
}

Hex& Hex::operator--(int value)
{
	if(flag == 1)	//X wants undo
	hexCells[undorowX][undocolX].setInfo_empty( );

	else
	hexCells[undorowO][undocolO].setInfo_empty( );

	return *this;
}

bool operator ==(const Hex& obj1, const Hex& obj2)
{
	return(obj1.countMarked == obj2.countMarked);
}




int Hex::count_length(string str)const
{
		int count=0,i=0;

		while(str[i]!='\0')
		{			
			count++;
			i++;
		}

		return count;
}



int Hex::controlTxt(string str2)const
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

	
int Hex::letter_cordinate( )const
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

int Hex::check_number( )const	// Checking number that user entered.
{
	if (size >= number && number > 0)
	{
		return 1;
		
	}

	else{
		return 0;
	}
}

int Hex::check_letter( )const
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

int Hex::check_location( )const
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


int Hex::check_location_AI(int x, int y)const //checking location wheter is aviable.
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
	character = '*';
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



	int Hex::control_finish_X( )const
	{
		int i;
		int j = size-1; 

		for (i = 0; i < size; ++i)
		{
			if (hexCellsX[i][j].getInfo( )== Cellinfo::goal_X)
			{
				return 1;
			}		
		}
		return 0;
	}


	int Hex::control_finish_O( )const //Checking if there is finish point
	{
		int i = size-1;
		int j; //Because if there is a finish point it will be on last row.

		for (j = 0; j < size; ++j)
		{
			if (hexCellsO[i][j].getInfo( ) == Cellinfo::goal_O)
			{
				return 1;
			}			
		}
		return 0;
	}


	int Hex::control_start_X( )const
	{
		int i;
		int j = 0;	//Because if there is a start point it will be on first column

		for (i = 0; i < size; ++i)
		{
			if (hexCellsX[i][j].getInfo( ) == Cellinfo::start_X)
			{
				return 1;
			}		
		}
		return 0;
	}


	int Hex::control_start_O( )const
	{
		int i = 0;
		int j; //Because if there is a start point it will be on first row.

		for (j = 0; j < size; ++j)
		{
			if (hexCellsO[i][j].getInfo( ) == Cellinfo::start_O)
			{
				return 1;
			}			
		}
		return 0;
	}






void Hex::update_hexCells_X( )
{
	int i,j;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (hexCells[i][j].getChar( ) == '*')
			{

				hexCellsX[i][j].setInfo_empty( );
			}

			else if((j == size-1) && hexCells[i][j].getChar( ) == 'x')
			{
				hexCellsX[i][j].setInfo_Xgoal( );
			}

			else if(j == 0  && hexCells[i][j].getChar( ) == 'x')
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


void Hex::update_hexCells_O( )
{
	int i,j;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (hexCells[i][j].getChar( ) == '*')
			{

				hexCellsO[i][j].setInfo_empty( );
			}

			else if((i == size-1) && hexCells[i][j].getChar( ) == 'o')
			{
				hexCellsO[i][j].setInfo_Ogoal( );
			}

			else if(i == 0  && hexCells[i][j].getChar( ) == 'o')
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


int Hex::returnScore( )
{
	int i,j;
	int score = 0;

	for(i=0; i < size; i++)
	{
		for(j=0; j< size; j++)
		{
			if(hexCellsX[i][j].getInfo()==Cellinfo::path_X || hexCellsX[i][j].getInfo()==Cellinfo::start_X || hexCellsX[i][j].getInfo()==Cellinfo::goal_X)
			{
				score ++;
			}
		}
	}
	return score;

}


int Hex::checkWinner_X(int rows, int column)
{
    
    if (hexCellsX[rows][column].getInfo( ) == Cellinfo::goal_X)
    {

        hexCellsX[rows][column].setInfo_Xpath( );
        return 1;
    }


    if(hexCellsX[rows][column].getInfo( ) == Cellinfo::X || hexCellsX[rows][column].getInfo( ) == Cellinfo::start_X)
    {

        hexCellsX[rows][column].setInfo_Xpath( );
        
        	if(size-1 > column){
	            if(checkWinner_X(rows,column+1))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }
        	}

	        if(column > 0){  
	            if(checkWinner_X(rows,column-1))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }
	         }  

            if(size-1 > rows){
	            if(checkWinner_X(rows+1,column))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }
	         }

            if(rows > 0){
	            if(checkWinner_X(rows-1,column))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }
	         }

          	if(rows > 0 && column < size-1){
	            if(checkWinner_X(rows-1,column+1))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }
           	}

           	if(rows < size-1 && column > 0){

	            if(checkWinner_X(rows+1,column-1))
	            {
	                hexCellsX[rows][column].setInfo_Xpath( );
	                return 1;
	            }

       		 }
        

    }



return 0;
}



int Hex::checkWinner_O(int rows,int column){


		if (hexCellsO[rows][column].getInfo( ) == Cellinfo::goal_O)		
		{
			hexCellsO[rows][column].setInfo_Opath( );
			return 1;
		}


		if ((hexCellsO[rows][column].getInfo( ) == Cellinfo::O) || (hexCellsO[rows][column].getInfo( ) == Cellinfo::start_O))
		{		
			hexCellsO[rows][column].setInfo_Opath( );
			


			if(size-1 > column){

				if (checkWinner_O(rows,column+1))		//East
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}

				if(column > 0){
					if (checkWinner_O(rows,column-1))		//West
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}
					

				if(size-1 > rows){
					if (checkWinner_O(rows+1,column))		//south
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}

				if(rows > 0){
					if (checkWinner_O(rows-1,column))		//north
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}


				if(rows > 0 && size-1 > column){
					if (checkWinner_O(rows-1,column+1))	//north east
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}	

				if(size-1 > rows && column > 0){
					if (checkWinner_O(rows+1,column-1))	//south west
					{
						hexCellsO[rows][column].setInfo_Opath( );
						return 1;
					}
				}	
		
		}

	return 0;

	}


int Hex::save_game(string &file_name)
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



int Hex::load_file(string &file_name)		//Load file
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



void Hex::make_winner_path_upperX( )
	{
		int i,j;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				if (hexCellsX[i][j].getInfo( ) == Cellinfo::path_X)
				{
					hexCells[i][j].setCharacter( );
				}			
			}
		}

	}

void Hex::make_winner_path_upperO( )
	{
		int i,j;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				if (hexCellsO[i][j].getInfo( ) == Cellinfo::path_O)
				{
					hexCells[i][j].setCharacter( );
				}			
			}
		}

	}	





int Hex::play(int xxx)	// int xxx just for make overload.
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


void Hex::play( )
{
	int score;
while(size*size > count){

	while(switch_player == 1)
		{
			cout << "Make your move(X): ";
			cin >> str1 >> str2;

			if(split_string( ) == 2){

				if (str1 == "LOAD")
				{
					if(load_file(str2)==1){
					cout <<"\n\n ***Game is loaded!***" << endl;
					//displayBoard( );
					cout<<*this;
					}
				}

				else if(str1 == "SAVE"){

					if(save_game(str2)==1)
					cout <<"\n ***Game is saved!***" << endl;
					
				}

			}

			else if(str1 == "undo" && str2 == "move")
			{
				flag = 1;
				--*this;
				cout <<*this;
			}

			else if(split_string( ) == 1)
			{
				if (check_letter( ) == 1 && check_number( ) == 1)
				{
					col = letter_cordinate( );
					row = number - 1;
					undorowX = row;
					undocolX = col;

					if(check_location( ) == 1)
					{
						hexCells[row][col].setCharX( );
						//displayBoard( );
						cout<<*this;
						countMarked++;
						update_hexCells_X();
						find_start_X = 0;
						score = returnScore( );
						cout <<"SCORE FOR X is: " << score << endl;
						if(control_start_X() == 1 && control_finish_X() == 1)
						{
							while(size > find_start_X)
							{
								if (hexCellsX[find_start_X][0].getInfo( ) == Cellinfo::start_X)	//Start point will be on First column and I must check all start points.
								{
									if(checkWinner_X(find_start_X,0) == 1)	//I should pass start point to the function.
									{
										score = returnScore( )+score;
										cout <<"SCORE FOR X is: " << score << endl;
										make_winner_path_upperX();
										//displayBoard( );
										cout<<*this;
										cout << "(X) GAME OVER (X)\n";
										cout << "\nPlayer (X) is the winner\n"<<endl;
										count = 1000;
										
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

				else
					cout << "Invalid move!\n";

				}

			else
			{
				cout << "\nInvalid number or letter! (for example: a1, c2, d3)\n";
			}

			cin.clear();			//For example if user enter 1a instead of a1/
			cin.ignore(10000,'\n');
			}//


			else{
				cout << "Invalid command!\n";
				cin.clear( );
				cin.ignore(10000,'\n');
			}	

		}




if(opponent_choice == 'b'){

while(switch_player == 2)
		{
			cout << "Make your move(O): ";
			cin >> str1 >> str2;

			if(split_string( ) == 2){

				if (str1 == "LOAD")
				{
					if(load_file(str2)==1){
					cout <<"\n\n ***Game is loaded!***" << endl;
					//displayBoard( );
					cout<<*this;
					}
				}

				else if(str1 == "SAVE"){

					if(save_game(str2)==1)
					cout <<"\n ***Game is saved!***" << endl;
					
				}

			}

			else if(str1 == "undo" && str2 == "move")
			{
				flag = 2;
				--*this;
				cout <<*this;
			}

			else if(split_string( ) == 1)
			{
				if (check_letter( ) == 1 && check_number( ) == 1)
				{
					col = letter_cordinate( );
					row = number - 1;
					undorowO = row;
					undocolO = col;

					if(check_location( ) == 1)
					{

						hexCells[row][col].setCharO( );
							
						cout<<*this;
						countMarked++;
						update_hexCells_O();						
						find_start_O = 0;

						if(control_start_O() == 1 && control_finish_O() == 1)
						{
							
							while(size > find_start_O)
							{
								if (hexCellsO[0][find_start_O].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
								{
									if(checkWinner_O(0,find_start_O) == 1)	//I should pass start point to the function.
									{
										make_winner_path_upperO();
										//displayBoard( );
										cout<<*this;
										cout << "(O) GAME OVER (O)\n";
										cout << "\nPlayer (O) is the winner\n"<<endl;
										count = 1000;
										
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

				else
					cout << "Invalid move!\n";

				}

			else
			{
				cout << "\nInvalid number or letter! (for example: a1, c2, d3)\n";
			}

			cin.clear();			//For example if user enter 1a instead of a1/
			cin.ignore(10000,'\n');
			}//	

			else{
				cout << "Invalid command!\n";
				cin.clear( );
				cin.ignore(10000,'\n');
				}	

		}	

	}




	if (opponent_choice == 'a')
	{
		while(switch_player == 2)
		{
			play(1);
			//displayBoard( );
			cout<<*this;
			update_hexCells_O();
			countMarked++;
			switch_player = 1;
			find_start_O = 0;
			count ++;

			if(control_start_O() == 1 && control_finish_O() == 1)
				{
							
					while(size > find_start_O)
					{
						if (hexCellsO[0][find_start_O].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
						{
							if(checkWinner_O(0,find_start_O) == 1)	//I should pass start point to the function.
							{
								make_winner_path_upperO( );
								//displayBoard( );
								cout<<*this;
								cout << "(O) GAME OVER (O)\n";
								cout << "\nCOMPUTER (O) is the winner\n"<<endl;
								count = 1000;
										
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
	
	}





}//size*size>count







}	




void Hex::playGame( )
{
	string s1,s2;
	int i = 1;
	int argument;
	int user_size;
	count = 0;
	control_player = 0;

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

	//displayBoard( );
	cout << *this;
	play( );


}