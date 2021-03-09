#include "mp3.h"



int display_op(void)
{
	

	int option = 0;
	
	do {

		system("cls");


		printf("---------Operaions---------\n\n");
		printf("please enter command with corrasponding number.\n"
			"(1)   load\n"
			"(2)   store\n"
			"(3)   display\n"
			"(4)   insert\n"
			"(5)   delete\n"
			"(6)   edit\n"
			"(7)   sort\n"
			"(8)   rate\n"
			"(9)   play\n"
			"(10) shuffle\n"
			"(11) exit\n");
		scanf("%d\n", &option);
		system("cls");


	} 
	while (option != 11);
	{
		system("cls");
		return option;
	}

}



Node* makeNode(Record nNode)
{
	Node* pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));

	if (pMem)
	{
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		memcpy(&pMem->data, &nNode, sizeof(Record));


	}
	return pMem;

}



void display(Node* pRecord)
{

	char artist[50];

	Node* temp = NULL;
	temp = pRecord;

	printf("Enter list for list of artists or just artist's name");
	scanf("%s", &artist);

	if (strcmp(artist, "list") == 0) {

		while (temp != NULL)
		{

			fprintf("Artist: %s\n", pRecord->data.artist); 
			fprintf("Album: %s\n", pRecord->data.album);
			fprintf("Song Title: %s\n", pRecord->data.song);
			fprintf("Genre: %s\n", pRecord->data.genre);
			fprintf("Length: %d:%d\n", pRecord->data.song_length.min, pRecord->data.song_length.sec);
			fprintf("Times Played: %d\n", pRecord->data.played);
			fprintf("Rating: %d\n", pRecord->data.rating);

			temp = temp->pNext;
		}
	
	}
	else
	{


		while (temp != NULL)
		{
			if (strcmp(temp->data.artist, artist) == 0)
			{

				fprintf("Artist: %s\n", pRecord->data.artist);
				fprintf("Album: %s\n", pRecord->data.album);
				fprintf("Song Title: %s\n", pRecord->data.song);
				fprintf("Genre: %s\n", pRecord->data.genre);
				fprintf("Length: %d:%d\n", pRecord->data.song_length.min, pRecord->data.song_length.sec);
				fprintf("Times Played: %d\n", pRecord->data.played);
				fprintf("Rating: %d\n", pRecord->data.rating);

				temp = temp->pNext;


			}
			else {
				temp = temp->pNext;
			}



		}
		
		
	}


	putchar('\n');
	system("Pause");




}


void load(Node** pRecord, FILE* infile)
{
	char line[100] = "", artist[50] = "",* data;
	Record temp = { '\0' };
	Node* pMem = NULL, * pCur = NULL, * pPrev = NULL;

	infile = fopen("musicPlayList.csv", "r");


	if (infile != NULL)
	{
		fgets(line, 100, infile);

		while (!feof(infile))
		{
			strcpy(artist, strtok(line, "\""));

			if (strlen(artist) > 50)
			{
				strcpy(artist, strtok(line, ","));
			}

			data = strtok(NULL, ",");
			strcpy(temp.album, data);
			data = strtok(NULL, ",");
			strcpy(temp.song, data);
			data = strtok(NULL, ",");
			strcpy(temp.genre, data);
			data = strtok(NULL, ":");
			temp.song_length.min = atoi(data);
			data = strtok(NULL, ",");
			temp.song_length.sec = atoi(data);
			data = strtok(NULL, ",");
			temp.played = atoi(data);
			data = strtok(NULL, "\n");
			temp.rating = atoi(data);

			pMem = makeNode(temp, data);

		}
		// code from Andy O'Fallon's function insertatFront
		if (pMem != NULL)
		{
			pMem->pNext = *pRecord; // or = pCur
								  // Is the list empty?
			if (*pRecord != NULL) // no
			{
				(*pRecord)->pPrev = pMem;
			}
			else // yes
			{
				// nothing else to be done!
			}
			*pRecord = pMem;
		}
		fgets(line, 100, infile);
	}
	else
	{
	printf("Error opening file ");
	}

	fclose(infile);
}


void store(Node* pRecord, FILE* outfile)
{
	Node* pMem = NULL;

	outfile = fopen("musicPlayList.csv", "w");

	pMem = pRecord;

	if (outfile != NULL)
	{
		while (pMem != NULL)
		{

			fprintf(outfile,"Artist: %s\n", pMem->data.artist);
			fprintf(outfile,"Album: %s\n", pMem->data.album);
			fprintf(outfile,"Song Title: %s\n", pMem->data.song);
			fprintf(outfile,"Genre: %s\n", pMem->data.genre);
			fprintf(outfile,"Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
			fprintf(outfile,"Times Played: %d\n", pMem->data.played);
			fprintf(outfile,"Rating: %d\n", pMem->data.rating);

			pMem = pMem->pNext;
		}
		printf("files loaded");
	}
	else
	{
		printf("Error opening file");
	}

	system("pause");
	fclose(outfile);
}



void edit(Node* pRecord)
{
	int album = 0;
	char artist1[50], songs[50], ch = '\0';
	Node* pMem = NULL, * change = NULL;
	pMem = pRecord;

	printf("Name of artist's to edit:");
	scanf("s%", &artist1);
	
	while (pMem != NULL)
	{
		if (strcmp(pMem->data.artist, artist1) == 0)
		{
			printf( "Artist: %s\n", pMem->data.artist);
			printf( "Album: %s\n", pMem->data.album);
			printf( "Song Title: %s\n", pMem->data.song);
			printf( "Genre: %s\n", pMem->data.genre);
			printf("Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
			printf("Times Played: %d\n", pMem->data.played);
			printf( "Rating: %d\n", pMem->data.rating);

			change = pMem;

			pMem = pMem->pNext;
			++album;


		}
		else
		{
			pMem = pMem->pNext;
		}
	}
	if (album > 1)
	{
		printf("Enter name of song to edit: ");
		scanf("s%", &songs);

		pMem = pRecord;
		while (pMem != NULL)
		{
			if (strcmp(pMem->data.song, songs) == 0)
			{
				printf("Artist: %s\n", pMem->data.artist);
				printf("Album: %s\n", pMem->data.album);
				printf("Song Title: %s\n", pMem->data.song);
				printf("Genre: %s\n", pMem->data.genre);
				printf("Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
				printf("Times Played: %d\n", pMem->data.played);
				printf("Rating: %d\n", pMem->data.rating);
				edit_Album(pMem);
				pMem = pMem->pNext;
			}
			else
			{
				pMem = pMem->pNext;
			}
		}
	}
	else
	{
		edit_Album(change);
	}




}

void edit_Album(Node* pMem)
{
	int option = 1, min = 0, sec = 0, times_played = 0, rating = 0;
	char artist[50], album[50], song1[50], genre[50];
	do
	{
		system("cls");


		printf("(1) Artist\n");
		printf("(2) Albulm Title\n");
		printf("(3) Song Title\n");
		printf("(4) Genre\n");
		printf("(5) Minutes\n");
		printf("(6) Seconds\n");
		printf("(7) Times Played\n");
		printf("(8) Rating\n");
		printf("(9) Exit \n");
		printf("Enter the info to edit: ");
		scanf("%d", &option);
	
		if (option != 9)
		{
			printf("Enter new data: ");
		}

		switch (option)
		{
		case 1:
			scanf("%s", &artist);
			
			gets(artist);
			strcpy(pMem->data.artist, artist);
			break;
		case 2:
			scanf("%s", &album);
			gets(album);
			strcpy(pMem->data.album, album);
			break;
		case 3:
			scanf("%s", &song1);
			gets(song1);
			strcpy(pMem->data.song, song1);
			break;
		case 4:
			scanf("%s", &genre);
			gets(genre);
			strcpy(pMem->data.genre, genre);
			break;
		case 5:
			scanf("%d", &min);
			pMem->data.song_length.min = min;
			break;
		case 6:
			scanf("%d", &sec);
			pMem->data.song_length.sec = sec;
			break;
		case 7:
			scanf("%d", &times_played);
			pMem->data.played = times_played;
			break;
		case 8:
			scanf("%d", &rating);
			pMem->data.rating = rating;
			break;
		case 9:
			printf("New Record:\n");
			printf("Artist: %s\n", pMem->data.artist);
			printf("Album: %s\n", pMem->data.album);
			printf("Song Title: %s\n", pMem->data.song);
			printf("Genre: %s\n", pMem->data.genre);
			printf("Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
			printf("Times Played: %d\n", pMem->data.played);
			printf("Rating: %d\n", pMem->data.rating);


			system("pause");
			system("cls");
			break;
		default:
			break;
			system("cls");
		}
	} while (option != 9);


}



void rate(Node* pRecord)
{
	char title[50];
	int rating = 0;
	Node* pMem = NULL;

	pMem = pRecord;

	printf("Which song to rate: ");
	scanf("%s",title);
	gets(title);

	while (pMem != NULL)
	{
		if (strcmp(title, pMem->data.song) == 0)
		{
			do {
				printf("Enter a rating out of 5: ");
				scanf("%d", &rating);
			} while (rating < 1 && rating > 6);

			pMem->data.rating = rating;
			pMem = pMem->pNext;
		}
		else
		{
			pMem = pMem->pNext;
		}
	}



}

void play(Node* pRecord)
{
	char title[50];

	Node* pMem = NULL;

	pMem = pRecord;

	printf("Which song you want to play: ");
	scanf("%s", title);
	gets(title);

	if (strcmp(title, pMem->data.song) == 0)
	{
		printf("Artist: %s\n", pMem->data.artist);
		printf("Album: %s\n", pMem->data.album);
		printf("Song Title: %s\n", pMem->data.song);
		printf("Genre: %s\n", pMem->data.genre);
		printf("Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
		printf("Times Played: %d\n", pMem->data.played);
		printf("Rating: %d\n", pMem->data.rating);

		pMem = pMem->pNext;

	}
	else
	{
		pMem = pMem->pNext;
	
	}
	while (pMem != NULL)
	{
		printf("Next song.....");
		system("pause");
		system("cls");

		printf("Artist: %s\n", pMem->data.artist);
		printf("Album: %s\n", pMem->data.album);
		printf("Song Title: %s\n", pMem->data.song);
		printf("Genre: %s\n", pMem->data.genre);
		printf("Length: %d:%d\n", pMem->data.song_length.min, pMem->data.song_length.sec);
		printf("Times Played: %d\n", pMem->data.played);
		printf("Rating: %d\n", pMem->data.rating);
		pMem = pMem->pNext;
	}
	printf("NO MORE TUNES.");
	system("pause");
	system("cls");


}









