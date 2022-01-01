#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "HexArray1D.h"
using namespace std;

namespace GameHex
{




	void HexArray1D::reset( )
	{
		int newSize = getSize()*getSize();
		hexCells = (Cell*)malloc(newSize*sizeof(Cell));
		hexCellsX = (Cell*)malloc(newSize*sizeof(Cell));
		hexCellsO= (Cell*)malloc(newSize*sizeof(Cell));	
		int i;

		for(i=0; i < newSize; ++i)
		{
			hexCells[i].setInfo_empty();
			hexCellsX[i].setInfo_empty();
			hexCellsO[i].setInfo_empty();
		}


	}


	const AbstractHex::Cell& HexArray1D::operator()(int i, int j, int key) const
	{
		if(key == 0)	
			return hexCells[(getSize()*i) + j];

		else if(key == 1)
			return hexCellsX[(getSize()*i) + j];

		else
			return hexCellsO[(getSize()*i) + j];
	}


	void HexArray1D::update_hexCells_X( )
	{
		int i,j;

		for (i = 0; i < getSize(); ++i)
		{
			for (j = 0; j < getSize(); ++j)
			{
				if (hexCells[(getSize()*i) + j].getChar( ) == '*')
				{

					hexCellsX[(getSize()*i) + j].setInfo_empty( );
				}

				else if((j == getSize()-1) && hexCells[(getSize()*i) + j].getChar( ) == 'x')
				{
					hexCellsX[(getSize()*i) + j].setInfo_Xgoal( );
				}

				else if(j == 0  && hexCells[(getSize()*i) + j].getChar( ) == 'x')
				{
					hexCellsX[(getSize()*i) + j].setInfo_Xstart( );
				}

				else if(hexCells[(getSize()*i) + j].getChar( ) == 'x')
				{
					hexCellsX[(getSize()*i) + j].setCharX( );
				}

				else{
					hexCellsX[(getSize()*i) + j].setInfo_empty( );
				}

				
			}
		}

	}



	void HexArray1D::update_hexCells_O( )
	{
		int i,j;

		for (i = 0; i < getSize(); ++i)
		{
			for (j = 0; j < getSize(); ++j)
			{
				if (hexCells[(getSize()*i) + j].getChar( ) == '*')
				{

					hexCellsO[(getSize()*i) + j].setInfo_empty( );
				}

				else if((i == getSize()-1) && hexCells[(getSize()*i) + j].getChar( ) == 'o')
				{
					hexCellsO[(getSize()*i) + j].setInfo_Ogoal( );
				}

				else if(i == 0  && hexCells[(getSize()*i) + j].getChar( ) == 'o')
				{
					hexCellsO[(getSize()*i) + j].setInfo_Ostart( );
				}

				else if(hexCells[(getSize()*i) + j].getChar( ) == 'o')
				{
					hexCellsO[(getSize()*i) + j].setCharO( );
				}

				else{
					hexCellsO[(getSize()*i) + j].setInfo_empty( );
				}
				
			}
		}


	}





	int HexArray1D::isEnd_X(int rows, int column)
	{
	    
	    if (hexCellsX[(getSize()*rows) + column].getInfo( ) == Cellinfo::goal_X)
	    {

	        hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
	        return 1;
	    }


	    if(hexCellsX[(getSize()*rows) + column].getInfo( ) == Cellinfo::X || hexCellsX[(getSize()*rows) + column].getInfo( ) == Cellinfo::start_X)
	    {

	        hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
	        
	        	if(getSize()-1 > column){
		            if(isEnd_X(rows,column+1))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }
	        	}

		        if(column > 0){  
		            if(isEnd_X(rows,column-1))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }
		         }  

	            if(getSize()-1 > rows){
		            if(isEnd_X(rows+1,column))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }
		         }

	            if(rows > 0){
		            if(isEnd_X(rows-1,column))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }
		         }

	          	if(rows > 0 && column < getSize()-1){
		            if(isEnd_X(rows-1,column+1))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }
	           	}

	           	if(rows < getSize()-1 && column > 0){

		            if(isEnd_X(rows+1,column-1))
		            {
		                hexCellsX[(getSize()*rows) + column].setInfo_Xpath( );
		                return 1;
		            }

	       		 }
	        

	    }

	return 0;
	}






		int HexArray1D::isEnd_O(int rows,int column){


		if (hexCellsO[(getSize()*rows) + column].getInfo( ) == Cellinfo::goal_O)		
		{
			hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
			return 1;
		}


		if ((hexCellsO[(getSize()*rows) + column].getInfo( ) == Cellinfo::O) || (hexCellsO[(getSize()*rows) + column].getInfo( ) == Cellinfo::start_O))
		{		
			hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
			


			if(getSize()-1 > column){

				if (isEnd_O(rows,column+1))		//East
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}

				if(column > 0){
					if (isEnd_O(rows,column-1))		//West
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}
					

				if(getSize()-1 > rows){
					if (isEnd_O(rows+1,column))		//south
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}

				if(rows > 0){
					if (isEnd_O(rows-1,column))		//north
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}


				if(rows > 0 && getSize()-1 > column){
					if (isEnd_O(rows-1,column+1))	//north east
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}	

				if(getSize()-1 > rows && column > 0){
					if (isEnd_O(rows+1,column-1))	//south west
					{
						hexCellsO[(getSize()*rows) + column].setInfo_Opath( );
						return 1;
					}
				}	
		
		}

	return 0;

	}




	void HexArray1D::make_winner_path_upperX( )	//bura 
	{
		int i,j;
		for (i = 0; i < getSize(); ++i)
		{
			for (j = 0; j < getSize(); ++j)
			{
				if (hexCellsX[(getSize()*i) + j].getInfo( ) == Cellinfo::path_X)
				{
					hexCells[(getSize()*i) + j].setCharacter( );
				}			
			}
		}

	}

	void HexArray1D::make_winner_path_upperO( )
	{
		int i,j;
		for (i = 0; i < getSize(); ++i)
		{
			for (j = 0; j < getSize(); ++j)
			{
				if (hexCellsO[(getSize()*i) + j].getInfo( ) == Cellinfo::path_O)
				{
					hexCells[(getSize()*i) + j].setCharacter( );
				}			
			}
		}
	}


	int HexArray1D::readFromFile(string &file_name)		//Load file
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
				char ch;
				int val;

				if (loadFile.is_open()){	//checking if file open correctly
								

				while(getline(loadFile,line)){


						if (line == zero)
						{								
							getline(loadFile,line);
							ch = line[0];
							setOpponentchoice(ch);
						}

						else if (line == first)
						{
							
							getline(loadFile,line);
							val = stoi(line);
							setSize(val);

						}

						else if (line == second)
						{
							
							getline(loadFile,line);
							val = stoi(line);
							setSwitchplayer(val);
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
									hexCells[(getSize()*i) + j].setCharinput(line[j]);
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
									hexCellsX[(getSize()*i) + j].setCharinput(line[j]);
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
									hexCellsO[(getSize()*i) + j].setCharinput(line[j]);
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



	int HexArray1D::play(int xxx)	// int xxx just for make overload.
	{
		int random_row;
		int random_col;

		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<double> dist(0,getSize());		//to generate random numbers

		// I observed that trying to capture middle of the game is important so that I am trying to achive that.

		
		
			if (hexCells[(getSize()/2*(getSize()) + getSize()/2)].getChar( ) == '*')
			{
				hexCells[(getSize()/2*(getSize()) + getSize()/2)].setCharO( );
				return 1;				
			}

			if(hexCells[(getSize()/2*(getSize()) + getSize()/2)].getChar( ) == '*'){
				hexCells[(getSize()/2*(getSize()) + getSize()/2)].setCharO( );
				return 1;			
			}

						// Here I am trying to do defence. Trying to block users path.						

	if (getCol()+1 < getSize())
	{
		

		if (check_location_AI(getRow(),getCol()+1) == 1)
		{		
			hexCells[(getRow()*getSize())+ getCol()+1].setCharO( );
			return 1;
		}

		if (check_location_AI(getRow()-1,getCol()+1) == 1)
		{
			hexCells[((getRow()-1)*getSize())+ getCol()+1].setCharO( );
			return 1;
		}

	}

		if (check_location_AI(getRow()-1,getCol()) == 1)
		{
			hexCells[((getRow()-1)*getSize())+ getCol()].setCharO( );			
			return 1;
		}


		if (check_location_AI(getRow()+1,getCol()) == 1)
		{
			hexCells[((getRow()+1)*getSize())+ getCol()].setCharO( );
			return 1;
		}


	

		while(1>0)		//Since conditions are not useful anymore then it will assign random numbers.
		{
			random_col = dist(mt);
			random_row = dist(mt);

			if (hexCells[(random_row * getSize()) + random_col].getChar( ) == '*')
			{
				hexCells[(random_row * getSize()) + random_col].setCharO( );
				return 1;
			}

		}

		return 0;
}




void HexArray1D::play( )		
{
int score;
string istr1, istr2;
int colx;
int rowx;
int adder;

while(getSize()*getSize() > getCount()){

	while(getSwitchplayer() == 1 && getCount() < 1000)
		{
			cout << "Make your move(X): ";
			cin >> istr1 >> istr2;

			setStr1(istr1);
			setStr2(istr2);

		if(getStr1() !="QUIT" || getStr2() !="GAME"){	

			if(split_string( ) == 2){

				if (getStr1() == "LOAD")
				{
					if(readFromFile(istr2)==1){
					cout <<"\n\n ***Game is loaded!***" << endl;
					print();
					}
				}

				else if(getStr1() == "SAVE"){

					if(writeToFile(istr2)==1)
					cout <<"\n ***Game is saved!***" << endl;
					
				}

			}


			else if(split_string( ) == 1)
			{
				if (check_letter( ) == 1 && check_number( ) == 1)
				{
					colx = letter_cordinate( );
					rowx = getNumber() - 1;

					setRow(rowx);
					setCol(colx);

					//undorowX = row;
					//undocolX = col;

					if(check_location( ) == 1)
					{	
						hexCells[(getRow()*getSize())+ getCol()].setCharX( );
						//displayBoard( );
						print();
						adder = numberOfMoves() + 1;
						setnumberOfMoves(adder);
						//countMarked++;
						update_hexCells_X();
						
						setFindstartX(0);
						//score = returnScore( );
						//cout <<"SCORE FOR X is: " << score << endl;
						if(control_start_X() == 1 && control_finish_X() == 1)
						{
							while(getSize() > getFindstartX())
							{
								if (hexCellsX[(getFindstartX()*getSize())+0].getInfo( ) == Cellinfo::start_X)	//Start point will be on First column and I must check all start points.
								{
									if(isEnd_X(getFindstartX(),0) == 1)	//I should pass start point to the function.
									{
										//score = returnScore( )+score;
										//cout <<"SCORE FOR X is: " << score << endl;
										make_winner_path_upperX();
										//displayBoard( );
										print();
										cout << "(X) GAME OVER (X)\n";
										cout << "\nPlayer (X) is the winner\n"<<endl;
										setCount(1000);
										
									}
										
								}
								else
									adder = getFindstartX() + 1;
									setFindstartX(adder);

								
							}
						}

						if (getCount() == 1000)
						{
							setSwitchplayer(3);
						}
						else
							setSwitchplayer(2);
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

		else{
				cout << "\n Quiting...\n\n";
	 			setCount(1000);
	 			}
		}

	//end of while


if(getOpponentchoice() == 'b'){

	while(getSwitchplayer() == 2 && getCount() < 1000)
		{
			cout << "Make your move(O): ";
			cin >> istr1 >> istr2;
			setStr1(istr1);
			setStr2(istr2);

		if(getStr1() !="QUIT" || getStr2() !="GAME"){

			if(split_string( ) == 2){

				if (getStr1() == "LOAD")
				{
					if(readFromFile(istr2)==1){
					cout <<"\n\n ***Game is loaded!***" << endl;
					//displayBoard( );
					print();
					}
				}

				else if(getStr1()== "SAVE"){

					if(writeToFile(istr2)==1)
					cout <<"\n ***Game is saved!***" << endl;
					
				}

			}

			//else if(getStr1() == "undo" && getStr1() == "move")
			//{
				//flag = 2;
			//	--*this;
			//	cout <<*this;
			//}

			else if(split_string( ) == 1)
			{
				if (check_letter( ) == 1 && check_number( ) == 1)
				{
					colx = letter_cordinate( );
					rowx = getNumber() - 1;

					setRow(rowx);
					setCol(colx);

					if(check_location( ) == 1)
					{

						hexCells[(getRow()*getSize())+getCol()].setCharO( );
							
						//cout<<*this;
						print();
						adder = numberOfMoves() + 1;
						setnumberOfMoves(adder);
						//countMarked++;
						update_hexCells_O();						
			
						setFindstartO(0);

						if(control_start_O() == 1 && control_finish_O() == 1)
						{
							
							while(getSize() > getFindstartO())
							{
								if (hexCellsO[getFindstartO()].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
								{
									if(isEnd_O(0,getFindstartO()) == 1)	//I should pass start point to the function.
									{
										make_winner_path_upperO();
										print();
										//cout<<*this;
										cout << "(O) GAME OVER (O)\n";
										cout << "\nPlayer (O) is the winner\n"<<endl;
										setCount(1000);
										
									}
										
								}
								else
									//find_start_O++;
									adder = getFindstartO()+1;
									setFindstartO(adder);							
							}
						}


						if (getCount() == 1000)
						{
							setSwitchplayer(3);
						}
						else
							setSwitchplayer(1);

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

			 else{
			 	cout << "\n Quiting... \n";
				setCount(1000);
			 }

		}//end of while	

	}




	if (getOpponentchoice() == 'a')
	{
		while(getSwitchplayer() == 2)
		{
			play(1);
			//displayBoard( );
			print();
			//cout<<*this;
			update_hexCells_O();
			//countMarked++;
			adder = numberOfMoves() + 1;
			setnumberOfMoves(adder);
			setSwitchplayer(1);
			setFindstartO(0);
			//count++;

			if(control_start_O() == 1 && control_finish_O() == 1)
				{
							
					while(getSize() > getFindstartO())
					{
						if (hexCellsO[getFindstartO()].getInfo( ) == Cellinfo::start_O)	//Start point will be on First column and I must check all start points.
						{
							if(isEnd_O(0,getFindstartO()) == 1)	//I should pass start point to the function.
							{
								make_winner_path_upperO( );
								print();
								//cout<<*this;
								cout << "(O) GAME OVER (O)\n";
								cout << "\nCOMPUTER (O) is the winner\n"<<endl;
								setCount(1000);
										
							}
										
						}

						else
							adder = getFindstartO() + 1;
							setFindstartO(adder);							
					}


				}


				if (getCount() == 1000)
				{
					setSwitchplayer(3);
				}
					else
					setSwitchplayer(1);

		}
	
	}





}//size*size>count


}



void HexArray1D::playGame( )
{
	string s1,s2;
	int i = 1;
	int argument;
	int user_size;
	setCount(0);

	while(i == 1)
	{
		cout << "Enter board size:\n";
		cin	 >> user_size;



		if (user_size < 27 && user_size > 5)
		{
			setSize(user_size);
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
			setOpponentchoice(choice);
			i=0;
		}

		else{
			cerr << "!Your choice should be a or b!\n";
			cin.clear();			
			cin.ignore(10000,'\n');
		}
	}
	reset();

	print();
	play( );
}
















}