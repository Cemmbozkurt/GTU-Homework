#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <stdexcept>
#include <deque>

#include "AbstractHex.h"
#include "HexVector.h"
#include "HexArray1D.h"
#include "HexAdapter.h"


using namespace std;
using namespace GameHex;

namespace
{
	template<int N>
	bool globalFunction(AbstractHex* (&objects)[N])
	{
		int i,j,k;
		int sizeHex;

		for(i = 0; i < N; ++i)
		{
			if(objects[i]->getSize() < 6 || objects[i]->getSize() > 27)
			{
				return false;
			}
		}
		
		return true;
	}


}



int main()
{

	
	int i = 0;
	int choice;
	int currentGame = 0;
	int boardChoice;

	HexArray1D game1D[2];
	HexVector gameV[2];

	while(i == 0)
	{

		cout<<"1-Play Game\n";
		cout<<"2-New Game\n";
		cout<<"4-Exit Game\n";
		cin >> choice;

		switch(choice)
		{

		case 1:
			cout<<"\n1-)To play with 1d board"<<endl;
			cout<<"2-)TO play with vector  board"<<endl;
			cin >> boardChoice;

			if(boardChoice == 1){
				game1D[currentGame].playGame( );
				currentGame++;
			}

			else if(boardChoice == 2)
			{
				gameV[currentGame].playGame( );
				currentGame ++;
			}

			else{
				cout<<"invalid choice\n";
			}

			break;

		
		case 2:
			cout<<"\n1-)To play with 1d board"<<endl;
			cout<<"2-)TO play with vector  board"<<endl;
			cin >> boardChoice;

			if(boardChoice == 1){
				game1D[currentGame].playGame( );
				currentGame++;
			}

			else if(boardChoice == 2)
			{
				gameV[currentGame].playGame( );
				currentGame ++;
			}

			else{
				cout<<"invalid choice\n";
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