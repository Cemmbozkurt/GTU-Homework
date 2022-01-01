#ifndef HexVector_H_
#define HexVector_H_

#include <vector>

#include "AbstractHex.h"
using namespace std;

namespace GameHex
{

	class HexVector : public AbstractHex
	{		

	public:
		virtual void reset()override;	
		virtual int readFromFile(string &file)override;
		virtual void play( )override;
		virtual int play(int xxx)override;
		virtual void playGame( )override;
		virtual const Cell& operator ()(int i, int j, int key)const override;
		virtual int isEnd_X(int rows, int column)override;
		virtual int isEnd_O(int rows, int column)override;

	private:
	void update_hexCells_X( );
	void update_hexCells_O( );	
	void make_winner_path_upperX( );
	void make_winner_path_upperO( );
	vector<vector<Cell>> hexCells;
	vector<vector<Cell>> hexCellsX;
	vector<vector<Cell>> hexCellsO;

	};


}



































#endif