#include"mp3.h"

int main(int argc, char *argv[])
{

	int input = 0;

	FILE* infile = NULL;
	FILE *outfile = NULL;

	Node* pRecord = NULL;

	


	printf("Welcome to your spotify playlist\n\n");

	do
	{
		printf("Main menu:\n1. Play_list OP\n2.Functions Info\n3. Exit\n");
		scanf("%d", &input);
		

	} while ((input != 1) && (input != 2) && (input != 3));

	if (input <= 3)
	{
		switch (input)
		{
		case 1:
			system("cls");

			int op = 0;
			do {
				op = display_op();

					switch (op)
					{
					case 1: //load op

						load(&pRecord, infile);

						break;


					case 2://store
						store(pRecord, outfile);
						printf("Songs stored. press any key\n");
						system("pause");

						break;


					case 3://display
						display(pRecord);
						break;

					case 4://insert

						break;

					case 5://delete

						break;

					case 6://edits
						printf("Chose a song to edit.\n");
						edit(pRecord);
						break;

					case 7://sort

						break;

					case 8://rate
						printf("What song do you want to rate.\n");
						rate(pRecord);
						break;

					case 9://play
						printf("Choose a song to jam to.\n");
						play(pRecord);
						break;

					case 10://shuffle

						break;

					case 11://exit
						printf("Music save to libaray,returning to menu\n");
						store(pRecord, outfile);

						break;
					default:
						break;
					}
				
				} while ((op!= 11));
				break;
			
		case 2://function op guide


			printf("The ---store--- command writes the current records, in the dynamic doubly linked list,\n");
			printf("to the musicPlayList.csv file.The store will completely overwrite the previous contents in the file.\n\n");
			printf("The ---display--- command prints records to the screen.This command must support two methods, one of which is selected by the user :\n\n");
			printf("The ---edit--- command must allow the user to find a record in the list by artist.\n\n");
			printf("If there are multiple records with the same artist, then your program must prompt the user which one to edit.\n");
			printf("The user may modify all of the attributes in the record.\n\n");
			printf("The ---rate--- command must allow the user to assign a value of 1 – 5 to a song; 1 is the lowest \n");
			printf("rating and 5 is the highest rating.The rating will replace the previous rating.\n\n");
			printf("The ---play--- command must allow the user to select a song, and must start “playing” each song in order\n");
			printf("from the current song.“Playing” the song for this assignment means displaying the contents of the record\n");
			printf("that represents the song for a short period of time, clearing the screenand showing the next record in the list, etc.This continues until all songs have been played.\n");
			printf("The ---exit--- command saves the most recent list to the musicPlayList.csv file.\n");
			printf("This command will completely overwrite the previous contents in the file.\n");
			
			break;
		case 3:
		
			break;
		default:
			printf("Enter a valid respounce.\n");
			break;
		}

	} 


	return 0;

	}



