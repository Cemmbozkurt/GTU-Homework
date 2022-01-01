#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <stdexcept>
#include<deque>

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

	HexArray1D arr1dObj;
	HexVector vectorObj;

	AbstractHex *obj1 = &arr1dObj;
	AbstractHex *obj2 = &vectorObj;

	AbstractHex* array [] = {obj1,obj2};

	if(globalFunction(array) == true){
		cout<<"setup looks fine!\n";

		try{
			obj1->lastMove();
		} catch (exception& e) {
			cerr << "exceptions: "<<e.what() << endl;
		}

	cout<<"\n\nWhen it is time to make move You can type 'QUIT GAME' and finish the game!"<<endl;
	cout<<"First one is 1D board" << endl;
	array[0]->playGame();
	cout<<"Second one is Vector board" << endl;
	array[1]->playGame();

	if((*obj1) == (*obj2))
	{
		cout<<"Games are equal" << endl;

	}
	else{
		cout<<"Games are not equal" << endl;
	}

}



return 0;
}