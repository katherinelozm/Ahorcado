#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void hangmanprint(char**, int, int, int); 
void read(char**);

int main(){
	srand(time(0));
	char** words = new char*[20];
	for (int WORD = 0; WORD < 20; WORD++){
		words[WORD] = new char[50];
	}
	read(words);
	int answer;
	int randword;
	bool iswrong, findletter;
	int ans;
	char letter;
	char* wordguessed;
	char* word;
	char* guessedletters;
	const int rows = 20;
	const int columns = 24;
	int wrongs;
	char** hangman;
	do{
		cout << endl << endl << "AHORCADO" << endl << endl;
		randword = rand() % 19;
		wordguessed = new char[50];
		word = new char[50];
		strcpy(word, words[randword]);
		guessedletters = new char[strlen(word)];
		wrongs = 0;
		hangman = new char*[rows];
		for (int ROW = 0; ROW < rows; ROW++){
			hangman[ROW] = new char[columns];
		}
		for (int LETTER = 0; LETTER < strlen(word); LETTER++){
			guessedletters[LETTER] = '_';
		}
		while(wrongs < 9){
			hangmanprint(hangman, rows, columns, wrongs);
			for (int LETTER = 0; LETTER < strlen(word); LETTER++){
				cout << setw(3) << guessedletters[LETTER];
			}
			cout << endl;
			if (wrongs<8){
				cout << endl << "¿Que desea ingresar?" << endl;
				cout << "1. Letra" << endl;
				cout << "2. Palabra" << endl;
				cin >> ans;
				cout << endl;
				if (ans==1){
					cout << "Ingrese una letra: ";
					cin >> letter;
					for (int i = 0; i < strlen(word); i++){
						if (word[i] == letter){
							findletter = true;
							break;
						} else {
							findletter = false;
						}
					}
					if (findletter == true){
						for (int i = 0; i < strlen(word); i++){
							if (word[i] == letter){
								guessedletters[i] = letter;
							}
						}
						cout << endl << "CORRECTO" << endl;
					} else {
						cout << endl << "INCORRECTO" << endl;
						wrongs++;
					}
				} else if (ans==2){
					bool guessed = false;
					cout << "Ingrese una palabra: ";
					cin >> wordguessed;
					if (strlen(wordguessed) == strlen(word)){
						for (int i = 0; i < strlen(word); i++){
							if (wordguessed[i]==word[i]){
								guessed = true;
							} else {
								guessed = false;
								break;
							}
						}
					}
					if (guessed == true){
						cout << endl << "GANASTE!!!" << endl;
						break;
					} else {
						cout << endl << "INCORRECTO" << endl;
						cout << endl;
						wrongs++;
					}
				}
			} else {
				cout << endl << "La palabra era: " << endl;
				for (int i = 0; i < strlen(word); i++){
					cout << setw(3) << word[i];
				}
				cout << endl << endl << "GAME OVER" << endl;
				wrongs++;
			}
		}
		cout << endl << "¿Desea jugar otra vez? 1. Si" << endl;
		cin >> answer;
	}while(answer == 1);

	delete[] wordguessed;
	delete[] word;
	delete[] guessedletters;
	for (int i = 0; i < 20; i++){
		delete[] words[i];
	}
	delete[] words;
	for (int i = 0; i < rows; i++){
		delete[] hangman[i];
	}
	delete[] hangman;
	return 0;
}

void hangmanprint(char** hangman, int rows, int columns, int wrongs){
	int cont = 1;
	if (wrongs==0){
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (COLUMN == 0 && ROW < rows-1){
					hangman[ROW][COLUMN] = '|';
				} else if (ROW == rows-1){
					hangman[ROW][COLUMN] = '-';
				} else {
					hangman[ROW][COLUMN] = ' ';
				}
			}
		}
	} else if (wrongs==1){
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW == 0 && COLUMN < columns/2){
					hangman[ROW][COLUMN] = '-';
				}
			}
		}
	} else if (wrongs==2){
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW < 3 && ROW > 0 && COLUMN == columns/2){
					hangman[ROW][COLUMN] = '|';
				}
			}
		}
	} else if (wrongs==3){
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW == 3 && COLUMN > (columns/2)-2 && COLUMN < (columns/2)+2){
					hangman[ROW][COLUMN] = '-';
				}
				if ((ROW == 4 || ROW == 5) && COLUMN == (columns/2)-2){
					hangman[ROW][COLUMN] = '|';
				}
				if ((ROW == 4 || ROW == 5) && COLUMN == (columns/2)+2){
					hangman[ROW][COLUMN] = '|';
				}
				if (ROW == 6 && COLUMN > (columns/2)-2 && COLUMN < (columns/2)+2){
					hangman[ROW][COLUMN] = '-';
				}
			}
		}
	} else if (wrongs==4){
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW > 6 && ROW < 14 && COLUMN == columns/2){
					hangman[ROW][COLUMN] = '|';
				}
			}
		}
	} else if (wrongs==5){
		cont = 1;
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW > 7 && ROW < 11 && COLUMN == (columns/2)-cont){
					hangman[ROW][COLUMN] = '/';
					cont++;
				}			
			}
		}
	} else if (wrongs==6){
		cont = 1;
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW > 7 && ROW < 11 && COLUMN == (columns/2)-cont){
					hangman[ROW][COLUMN] = '/';
					cont++;
				}
				if (ROW > 7 && ROW < 11 && COLUMN == (columns/2)+cont){
					hangman[ROW][COLUMN] = '\\';
				}	
			}
		}
	} else if (wrongs==7){
		cont = 1;
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW > 13 && ROW < 17 && COLUMN == (columns/2)-cont){
					hangman[ROW][COLUMN] = '/';
					cont++;
				}	
			}
		}
	} else if (wrongs==8){
		cont = 1;
		for (int ROW = 0; ROW < rows; ROW++){
			for (int COLUMN = 0; COLUMN < columns; COLUMN++){
				if (ROW > 13 && ROW < 17 && COLUMN == (columns/2)-cont){
					hangman[ROW][COLUMN] = '/';
					cont++;
				}
				if (ROW > 13 && ROW < 17 && COLUMN == (columns/2)+cont){
					hangman[ROW][COLUMN] = '\\';
				}
			}
		}
	}
	for (int ROW = 0; ROW < rows; ROW++){
		for (int COLUMN = 0; COLUMN < columns; COLUMN++){
			cout << hangman[ROW][COLUMN];
		}	
		cout << endl;
	}
	cout << endl;
}

void read(char** words){
	int cont = 0;
	ifstream diccfile;
	diccfile.open("diccionario.txt");
	if (diccfile.is_open()) {
		while (!diccfile.eof()) {
			diccfile >> words[cont];
		    cont++;
		}
	}
	diccfile.close();
}

