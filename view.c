#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"

int view(char file[])
{
    FILE *fptr = fopen(file, "r");

    int count = 0;
    
    char tag[6][5] = {"TIT2", "TYER", "TALB", "TPE1", "TCON", "COMM"};//tags
    
    char tag_name[6][10] = {"Title", "Year", "Album", "Artist", "Genre", "Comment"};//tag name
    
    View view;//structure

    fseek(fptr, 10, SEEK_SET); // skip ID3 header

    while (count != 6)//runs until given 6 tag is found.
    {
        fread(view.tag, 4, 1, fptr);
        view.tag[4] = '\0';

        fread(&view.size, 4, 1, fptr);
        convert(&view.size);

        fseek(fptr, 3, SEEK_CUR);          // skip flags
       

        fread(view.info, view.size - 1, 1, fptr);
        view.info[view.size - 1] = '\0';

        for (int i = 0; i < 6; i++)//checks the read tag is match with required tag.
        {
            
            if (strcmp(view.tag, tag[i]) == 0)
            {
                printf("%s  -> %s\n", tag_name[i], view.info);
                count++;
            }
        }
    }
    printf("Info Done\n");
    fclose(fptr);
}

/*converts the endians of system*/
void convert(int *size)
{
    char *ptr = (char *)size;
    char temp;

    temp = ptr[0];
    ptr[0] = ptr[3];
    ptr[3] = temp;

    temp = ptr[1];
    ptr[1] = ptr[2];
    ptr[2] = temp;
}


/*validate the file is correct extension or not*/
int validation(char file[])
{
    if (strstr(file, ".mp3") != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
