#ifndef AbstractHex_H_
#define AbstractHex_H_


using namespace std;

namespace GameHex
{

	enum class Cellinfo{empty, X, O, start_X, start_O, goal_X, goal_O, path_X, path_O};

	class AbstractHex
	{
		public:
			class Cell
			{
				public:
					Cell( );
					inline char getChar ( )const {return character;};
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
					inline Cellinfo getInfo( )const {return info;};
					
						
				
				private:
					Cellinfo info;
					char character;
			};
			
			AbstractHex( );
			inline int getSize( )const {return size;};
			inline void setSize(int val){size = val;};
			inline char getOpponentchoice( )const {return opponent_choice;};
			inline void setOpponentchoice(char ch){opponent_choice = ch;};
			inline int getSwitchplayer( )const {return switch_player;};
			inline void setSwitchplayer(int val){switch_player = val;};
			inline string getBoardletter( )const{return board_letters;};


			inline int getRow( )const{return row;};
			inline int getCol()const{return col;};
			inline void setRow(int value){row = value;};
			inline void setCol(int value){col = value;};

			inline void setFindstartX(int value){find_start_X = value;};
			inline void setFindstartO(int value){find_start_O = value;};

			inline int getFindstartX()const{return find_start_X;};
			inline int getFindstartO()const{return find_start_O;};


			inline int getNumber( )const{return number;};
			inline void setNumber(int value){number = value;};
			inline int getCount()const{return count;};
			inline void setCount(int val){count = val;};
			inline string getStr1( )const{return str1;};
			inline string getStr2( )const{return str2;};
			inline void setStr1(string str){str1 = str;};
			inline void setStr2(string str){str2 = str;};

			inline void setLetteruser(char ch){letter_user = ch;};
			inline char getLetteruser()const{return letter_user;};

			inline void setFlag( ){flag = 1;};
			char getChar( )const {return myCell.getChar( );};
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
			Cellinfo getInfo( )const {return myCell.getInfo( );};
			
		
			virtual void reset()=0;	
			void print()const;
			virtual int readFromFile(string &file)=0;
			int writeToFile(string &file);


			virtual const AbstractHex::Cell& operator ()(int i, int j, int key)const=0;
			bool operator ==(const AbstractHex& other) const;

			virtual int isEnd_X(int rows, int column)=0;
			virtual int isEnd_O(int rows, int column)=0;

			void lastMove( );
			inline int numberOfMoves( )const{return number_moves;};
			inline void setnumberOfMoves(int val){number_moves = val;};

			int count_length(string str)const;
			int controlTxt(string str)const;
			void convert_lowercase(string &str);
			int check_location( )const;
			int check_location_AI(int x,int y)const;
			int control_finish_X( )const;
			int control_finish_O( )const;
			int control_start_X( )const;
			int control_start_O( )const;
			int split_string( );
			int letter_cordinate( )const;
			int check_number( )const;
			int check_letter( )const;
			
			virtual void play( )=0;
			virtual int play(int xxx)=0;
			virtual void playGame( )=0;

	private:
		int flag;
		int size;
		char opponent_choice;
		char letter_user;
		int number;
		int score;
		int switch_player;
		int count;
		int number_moves;

	

		string str1;
		string str2;
		int row;
		int col;
		int find_start_X;
		int find_start_O;
		string board_letters ="abcdefghijklmnopqrstuvwxyz";
		Cell myCell;


			
};

















}

#endif