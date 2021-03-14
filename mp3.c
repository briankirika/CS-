#include "mp3.h"



int display_op(void)
{
	

int option = 0;
	
	

		system("cls");


		printf("---------Operaions---------\n\n");
		printf("please enter command .\n");
		printf("(1) Load\n");
		printf("(2) Store\n");
		printf("(3) Display\n");
		printf("(4) Insert\n");
		printf("(5) Delete\n");
		printf("(6) Edit\n");
		printf("(7) Sort\n");
		printf("(8) Rate\n");
		printf("(9) Play\n");
		printf("(10) Shuffle\n");
		printf("(11) Exit\n");
	scanf("%d", &option);
		

	
	return option;
}



Node* makeNode(char nArtist, char nAlbum, char nSong, char nGenre, int min, int sec, int played, int rated)
{
	Node* pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));

	if (pMem!=NULL)
	{

		strcpy(pMem->data.album, nAlbum);
		strcpy(pMem->data.artist, nArtist);
		strcpy(pMem->data.song, nSong);
		strcpy(pMem->data.genre, nGenre);
		pMem->data.song_length.min = min;
		pMem->data.song_length.sec = sec;
		pMem->data.played = played;
		pMem->data.rating = rated;


		pMem->pNext = NULL;
		pMem->pPrev = NULL;


	}
	return pMem;

}



void display(Node* pRecord)
{

	char artist[50];

	Node* temp = NULL;
	temp = pRecord;

	printf("Enter list or just artist's name");
	scanf("%s", &artist);

	if (strcmp(artist, "list"))  {

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
	infile = fopen("musicPlayList.csv", "r");

	char line[100] = "";
	char artist[50] = "",album[50] = "", song[50] = "", genre[50] = "", time[50] = "";
	int min=0, sec=0, play=0, rating = 0;
	Node* pMem = NULL, * pPrev = NULL;
	
	

	if (infile != NULL)
	{
		pRecord=fgets(line, 100, infile);
		
		while (!feof(infile))
		{
			strcpy(artist, strtok(line, "\""));
			strcpy(album, strtok(NULL, ","));
			strcpy(song, strtok(NULL, ","));
			strcpy(genre, strtok(NULL, ","));
			strcpy(time, strtok(NULL, ","));
			play = atoi(strtok(NULL, ","));
			rating = atoi(strtok(NULL, ","));
			min = atoi(strtok(time, ":"));
			sec = atoi(strtok(NULL, ","));
			

			pMem = makeNode(artist, album, song, genre, min, sec, play, rating);

		}
		//Andy function insert
		if (pMem != NULL)
		{
			pMem->pNext = *pRecord;
								
			if (*pRecord != NULL) 
			{
				(*pRecord)->pPrev = pMem;
			}
			else 
			{
				
			}
			*pRecord = pMem;
		}
		
	}
	else
	{
	printf("Error opening file ");
	}

	fclose(infile);
	return pMem;

	
}


void store(Node* pRecord, FILE* outfile)
{
	Node* pMem = pRecord;

	outfile = fopen("musicPlayList.csv", "w");

	

	
	
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
	
	if (outfile == NULL)
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









