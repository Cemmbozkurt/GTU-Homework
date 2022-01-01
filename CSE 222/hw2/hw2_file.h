using namespace std;

	void convert_lowercase(string &str,int i = 1)
	{
		
											//Function use default argument.
		while(str[i]!='.')					// int i is the counter.
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


	// I save the choice(against computer or human), size , player turn, Boards current position, and Marked_O and MArked_X
	int save_game (char board[MAX_SIZE][MAX_SIZE], int marked_X[MAX_SIZE][MAX_SIZE], int marked_O[MAX_SIZE][MAX_SIZE], int size, int switch_player,char opponent_choice ,string &file_name){

		ofstream saveFile;

		convert_lowercase(file_name,0);

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
						saveFile << board[i][j];
					}
					saveFile << "\n";
				}


				saveFile <<"marked_X" << endl;

				for (i = 0; i < size; ++i)
				{
					for (j = 0; j < size; ++j)
					{
						saveFile << marked_X[i][j];
					}
					saveFile << "\n";
				}



				saveFile <<"marked_O" << endl;

				for (i = 0; i < size; ++i)
				{
					for (j = 0; j < size; ++j)
					{
						saveFile << marked_O[i][j];
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

	//Load function, load that user have input the game file. If there is no such a file that user entered then it gives error message to user.
	int load_game(char board[MAX_SIZE][MAX_SIZE], int marked_X[MAX_SIZE][MAX_SIZE], int marked_O[MAX_SIZE][MAX_SIZE], int *size, int *switch_player, char *opponent_choice ,string file_name){	//Dosya ismi icin degisken eklicem

		ifstream loadFile;
		convert_lowercase(file_name,0);

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
							*opponent_choice = line[0];

						}

						else if (line == first)
						{
							getline(loadFile,line);
							*size = stoi(line);

						}

						else if (line == second)
						{
							getline(loadFile,line);
							*switch_player = stoi(line);
						}

						else if (line == third)
						{
							i=0;
							while(line != fourth)
							{
								getline(loadFile,line);

								j=0;

								while(line[j]!='\0')
								{
									board[i][j] = line[j];
									j++;
								}

								i++;

							}					
						}


						else if (line == fourth)
						{
							i=0;
							while(line != fifth)
							{
								getline(loadFile,line);

								j=0;

								while(line[j]!='\0')
								{
									marked_X[i][j] = line[j];
									j++;
								}

								i++;

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
									marked_O[i][j] = line[j];
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


	int count_length(string str)
	{
		int count=0,i=0;

		while(str[i]!='\0')
		{			
			count++;
			i++;
		}

		return count;
	}


	int controlTxt(string str2)
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



	int split_string(string str1, string str2, char *letter_user, int *number){

		decltype(str1) load;
		load = "LOAD";	


		auto save = "SAVE";
		string txt = ".TXT";

		if (count_length(str1) == 1)
		{
			*letter_user = str1[0];
			if (count_length(str2) == 1)
			{
				*number = str2[0]-48;		//Char to int
			}

			else if(count_length(str2) == 2)		//If user enter two digit number.
			{
				*number = stoi(str2);
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
