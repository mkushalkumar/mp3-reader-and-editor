#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edit.h"

int edit(char file[], int argc, char *argv[])
{
    FILE *fptr = fopen(file, "rb");//open sourcefile in read mode
    FILE *tptr = fopen("temp.mp3", "wb");//open temp file as destination file.

    if (!fptr || !tptr)//checks whether file is opened.
    {
        printf("File open error\n");
        return 1;
    }

    Edit edit;//structure
    mapping(argv[3], &edit);

    /* Copy ID3 header */
    fread(edit.buffer, 10, 1, fptr);//read header in sourcefile and store in buffer.
    fwrite(edit.buffer, 10, 1, tptr);//store header in destination file from buffer.

    while (fread(edit.tag, 4, 1, fptr) == 1)
    {
        edit.tag[4] = '\0';

        fread(&edit.size, 4, 1, fptr);
        convert(&edit.size);

        fread(edit.flags, 2, 1, fptr);

        if (edit.size < sizeof(edit.info))
            fread(edit.info, edit.size, 1, fptr);
        else
            fseek(fptr, edit.size, SEEK_CUR);

        if (strcmp(edit.option_tag, edit.tag) == 0)
        {
            /*copy the selected data.*/
            printf("Enter new value: ");
            scanf("%[^\n]", edit.new_info);

            edit.new_size = strlen(edit.new_info) + 1;

            fwrite(edit.tag, 4, 1, tptr);

            int temp = edit.new_size;
            convert(&temp);
            fwrite(&temp, 4, 1, tptr);

            fwrite(edit.flags, 2, 1, tptr);
            fwrite(edit.new_info, edit.new_size, 1, tptr);
        }
        else
        {
            /*copy the remaining data*/
            fwrite(edit.tag, 4, 1, tptr);

            int temp = edit.size;
            convert(&temp);
            fwrite(&temp, 4, 1, tptr);

            fwrite(edit.flags, 2, 1, tptr);
            fwrite(edit.info, edit.size, 1, tptr);
        }
    }

    fclose(fptr);
    fclose(tptr);

    remove(file);//remove the file
    rename("temp.mp3", file);//rename the file.

    return 0;
}

/*to map the option entered with the tag.*/
int mapping(char option[], Edit *edit)
{
    char tag[6][10] = {"-t", "-y", "-a", "-g", "-A", "-c"};
    char tag_name[6][10] = {"TIT2", "TYER", "TALB", "TCON", "TPE1", "COMM"};

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(option, tag[i]) == 0)
        {
            strcpy(edit->option_tag, tag_name[i]);
            return 0;
        }
    }
    return 1;
}
