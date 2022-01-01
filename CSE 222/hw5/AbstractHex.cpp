#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <stdexcept>
#include "AbstractHex.h"
using namespace std;


namespace GameHex
{


AbstractHex::AbstractHex( )
{
	switch_player = 1;
	find_start_X = 0;
	find_start_O = 0;
	number_moves = 0;
	count = 0;
	size = 6;
	flag = 0;

}


AbstractHex::Cell::Cell( ){

	info = Cellinfo::empty;
	character = '*';

}


bool AbstractHex::operator ==(const AbstractHex& other) const
{
		int size_c = other.getSize();

		int cnt = 0;

		char ch1;
		char ch2;

		if(getSize() == other.getSize())
		{
			
			for(int i = 0 ; i < size_c ; ++i){
				for(int j = 0 ; j < size_c ; ++j)
					{
						ch1 = other(i,j,0).getChar();
						ch2 = (*this)(i,j,0).getChar();

						if(ch1 != ch2)
						{
							return false;
						}

					}
				}	

		}

	return true;			
}		
					
	


	void AbstractHex::lastMove()
	{
		int returnRow,returnCol;
		if(number_moves == 0)
		{
			throw invalid_argument("there is no lastMove");
		}
		
		
	}



	void AbstractHex::print( )const
	{
		int i,j,k,l;

		l=1;

		string letters = getBoardletter( );


		for(i=0; i < getSize(); ++i)
		{
			cout <<"   "<< letters[i];
		}
		
		cout << "\n";

		for (i = 0; i < getSize(); ++i)
		{

			cout << l << "   ";
			l++;

			for (k = 0; k < i; ++k)
			{
				cout << "   ";
			}

			for (j = 0; j < getSize(); ++j)
			{
				cout << (*this)(i,j,0).getChar( ) << "   ";
			}
			cout << "\n\n";
		}

	}

	int AbstractHex::check_location( )const
	{
		int i,j;
		i = getRow();
		j = getCol();

		if ((*this)(i,j,0).getChar( ) == 'x')
		{
			return 0;
		}

		else if((*this)(i,j,0).getChar( ) == 'o')
		{
			return 0;

		}

		else{
			return 1;
		}

		return 0;
	}


	int AbstractHex::check_location_AI(int x, int y)const //checking location wheter is aviable.
	{
		int i,j;
		i = getRow();
		j = getCol();

		if ((*this)(i,j,0).getChar( ) == 'x')
		{

			return 0;
		}

		else if((*this)(i,j,0).getChar( ) == 'o')
		{
			return 0;

		}

		else{
			return 1;
		}

	}







	int AbstractHex::control_finish_X( )const
	{
		int i;
		int j = getSize()-1; 

		for (i = 0; i < getSize(); ++i)
		{
			if ((*this)(i,j,1).getInfo( )== Cellinfo::goal_X)
			{
				return 1;
			}		
		}
		return 0;
	}


	int AbstractHex::control_finish_O( )const //Checking if there is finish point
	{
		int i = getSize()-1;
		int j; //Because if there is a finish point it will be on last row.

		for (j = 0; j < getSize(); ++j)
		{
			if ((*this)(i,j,2).getInfo( ) == Cellinfo::goal_O)
			{
				return 1;
			}			
		}
		return 0;
	}


	int AbstractHex::control_start_X( )const
	{
		int i;
		int j = 0;	//Because if there is a start point it will be on first column

		for (i = 0; i < getSize(); ++i)
		{
			if ((*this)(i,j,1).getInfo( ) == Cellinfo::start_X)
			{
				return 1;
			}		
		}
		return 0;
	}


	int AbstractHex::control_start_O( )const
	{
		int i = 0;
		int j; //Because if there is a start point it will be on first row.

		for (j = 0; j < getSize(); ++j)
		{
			if ((*this)(i,j,2).getInfo( ) == Cellinfo::start_O)
			{
				return 1;
			}			
		}
		return 0;
	}


int AbstractHex::count_length(string str)const
{
		int count=0,i=0;

		while(str[i]!='\0')
		{			
			count++;
			i++;
		}

		return count;
}



int AbstractHex::controlTxt(string str2)const
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




int AbstractHex::split_string( )
{
		string load = "LOAD";
		string str11 = getStr1();	
		string str22 = getStr2();	
		char ch;
		int val;

		string save = "SAVE";
		string txt = ".TXT";

		if (count_length(str11) == 1)
		{
			ch = str11[0];
			setLetteruser(ch);

			if (count_length(str22) == 1)
			{
				val = str22[0]-48;		//Char to int
				setNumber(val);
			}

			else if(count_length(str22) == 2)		//If user enter two digit number.
			{
				val = stoi(str22);
				setNumber(val);
			}
			
			return 1;		
		}

		else if (str11 == load || str11 == save)
		{
			if (controlTxt(str22) == 1)
			{
				return 2;
			}
		}

		return 0;
}

	
int AbstractHex::letter_cordinate( )const
{
	int i=0;
	string letters = getBoardletter( );

	while(i<getSize())
	{
		if (letters[i] == getLetteruser())
		{
			return i;
		}

		else{
			i++;
		}
		
	}
	return 0;
}


int AbstractHex::check_number( )const	// Checking number that user entered.
{
	if (getSize() >= getNumber() && getNumber() > 0)
	{
		return 1;
		
	}

	else{
		return 0;
	}
}

int AbstractHex::check_letter( )const
{
	int i=0;
	string letters = getBoardletter();
	char ch = getLetteruser();

	while(i < getSize())
	{
		if (letters[i] == ch)
		{
			return 1;
		}
		i++;
	}

	return 0;
}







void AbstractHex::Cell::setCharX( )
{
	character = 'x';
	info = Cellinfo::X;

}

void AbstractHex::Cell::setCharO( )
{
	character = 'o';
	info = Cellinfo::O;

}

void AbstractHex::Cell::setInfo_empty( )
{
	character = '*';
	info = Cellinfo::empty;
}

void AbstractHex::Cell::setInfo_Xgoal( )
{

	info = Cellinfo::goal_X;
}

void AbstractHex::Cell::setInfo_Ogoal( )
{
	info = Cellinfo::goal_O;
}

void AbstractHex::Cell::setInfo_Xstart( )
{
	 info = Cellinfo::start_X;
}

void AbstractHex::Cell::setInfo_Ostart( )
{
	info = Cellinfo::start_O;
}

void AbstractHex::Cell::setInfo_Xpath( )
{
	info = Cellinfo::path_X;
}

void AbstractHex::Cell::setInfo_Opath( )
{
	 info = Cellinfo::path_O;
}



void AbstractHex::convert_lowercase(string &str)
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




	int AbstractHex::writeToFile(string &file_name)
	{

	ofstream saveFile;

		convert_lowercase(file_name);

		saveFile.open(file_name);

			if(saveFile.is_open()){	//checking if file open correctly

				saveFile << "Choice" << endl;
				saveFile << getOpponentchoice() << endl;
				saveFile << "Size" << endl;
				saveFile << getSize() << endl;
				saveFile << "Player" << endl;
				saveFile << getSwitchplayer() << endl;

				int i,j;

				saveFile <<"chBoard" << endl;

				for (i = 0; i < getSize(); ++i)
				{
					for (j = 0; j < getSize(); ++j)
					{
						saveFile << (*this)(i,j,0).getChar( );
					}
					saveFile << "\n";
				}


				saveFile <<"marked_X" << endl;

				for (i = 0; i < getSize(); ++i)
				{
					for (j = 0; j < getSize(); ++j)
					{
						saveFile << (*this)(i,j,1).getChar( );
					}
					saveFile << "\n";
				}



				saveFile <<"marked_O" << endl;

				for (i = 0; i < getSize(); ++i)
				{
					for (j = 0; j < getSize(); ++j)
					{
						saveFile << (*this)(i,j,2).getChar( );
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



	


}