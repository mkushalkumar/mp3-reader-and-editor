#ifndef VIEW_H
#define VIEW_H

typedef struct
{
    char tag[5];
    char info[100];
    int size;
    
} View;

int view(char file[]);
void convert(int *size);
int validation(char file[]);


#endif