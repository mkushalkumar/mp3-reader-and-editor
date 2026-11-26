#ifndef EDIT_H
#define EDIT_H

typedef struct
{
    char buffer[1000];
    char tag[5];
    char option_tag[5];
    char info[100];
    char new_info[100];
    int size;
    int new_size;
    char flags[2];

} Edit;



int mapping(char option[],Edit* edit);
int view(char file[]);
void convert(int *size);
int edit(char file[],int argc,char *argv[]);


#endif