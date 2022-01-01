using namespace std;



enum class Cellinfo{empty, X, O, start_X, start_O, goal_X, goal_O, path_X, path_O};

class Hex
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
			

			Hex( );
			inline int getSize( )const {return size;};
			inline char getOpponentchoice( )const {return opponent_choice;};
			inline int getSwitchplayer( )const {return switch_player;};
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

			static int returnMarked( ) {return countMarked;};


			
			void initial_board( );
		//	void displayBoard( );			
			friend ostream& operator <<(ostream& outputStream, const Hex& hexCells);
			friend bool operator ==(const Hex& obj1, const Hex& obj2);
			Hex& operator --(int value);
			Hex& operator --( );

			int count_length(string str)const;
			int controlTxt(string str)const;
			void convert_lowercase(string &str);
			int save_game(string &file);
			int load_file(string &file);

			int control_finish_X( )const;
			int control_finish_O( )const;
			int control_start_X( )const;
			int control_start_O( )const;

			void update_hexCells( );
			void update_hexCells_X( );
			void update_hexCells_O( );
			
			int returnScore( );

			void make_winner_path_upperX( );
			void make_winner_path_upperO( );

			int split_string( );
			int letter_cordinate( )const;
			int check_number( )const;
			int check_letter( )const;
			int check_location( )const;
			int check_location_AI(int x,int y)const;

			

			Hex(string loadFile);


			int checkWinner_X(int rows, int column);
			int checkWinner_O(int rows, int column);
			void play( );
			int play(int xxx);
			void playGame( );

			


	private:

		int undorowX;
		int undorowO;
		int undocolX;
		int undocolO;

		int flag;
		int size;
		char opponent_choice;
		char letter_user;
		int number;
		int score;
		int switch_player;
		int count;
		int control_player;

		string str1;
		string str2;
		int row;
		int col;
		int find_start_X;
		int find_start_O;
		char board_letters[27]="abcdefghijklmnopqrstuvwxyz";

		Cell myCell;

		Cell**hexCells;
		Cell** hexCellsX;
		Cell** hexCellsO;
		
		static int countMarked;	

			
};
int Hex::countMarked = 0;