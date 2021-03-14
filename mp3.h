#ifndef MP3_H
#define MP3_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


typedef struct duration
{
    unsigned int min;
    unsigned int sec;
}Duration;


typedef struct record
{
    char artist[50];
    char album[50];
    char song[50];
    char genre[50];
    unsigned int played;
    unsigned int rating;
    Duration song_length;
}Record;

typedef struct node
{
    Record data;
    struct node* pPrev;
    struct node* pNext;
}Node;





int display_op(void);

Node* makeNode(char nArtist, char nAlbum, char nSong, char nGenre, int min, int sec, int played, int rated);

void display(Node* pRecord);

void load(Node**pRecord, FILE *infile);

void store(Node* pRecord, FILE* outfile);

void edit(Node* pRecord);

void rate(Node* pRecord);

void edit_Album(Node* pMem);

void play(Node* pRecord);








#endif