/*documentation :-

Name :- kushal kumar
start date :- 9/01/2025
description :-  The project name is mp3 tag reader. This project about editing and
                viewing mp3 tag reader details.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "edit.h"

int main(int argc, char *argv[])
{
    char *operation = argv[1];
   
    char *file = argv[2];

    if (strcasecmp("-v", operation) == 0)
    {
        if (validation(file) == 1)
        {
            view(file);
        }
        else
        {
            printf("Enter valid file name !\n");
        }
    }
    else if (strcasecmp("-e", operation) == 0)
    {
        if (validation(file) == 1)
        {
            edit(file, argc, argv);
        }
        else
        {
            printf("Enter valid file name !\n");
        }
    }
    else if (strcasecmp("-h", operation) == 0)
    {
        printf("------------------------------------------\n");
        printf("************ HELP ************  \n");
        printf("------------------------------------------\n");
        printf("\n");

        printf("******************************************\n");

        printf("************ TAGS ************  \n");
        printf("******************************************\n");
        printf("TAT2 -> -t ->TITLE\n");
        printf("TYER -> -y ->YEAR\n");
        printf("TALB -> -a ->ALBUM\n");
        printf("TPE1 -> -A ->ARTIST\n");
        printf("TCON -> -g ->GENRE\n");
        printf("COMM -> -c ->COMMENT\n");
        printf("------------------------------------------\n");
        printf("\n");

        printf("------------------------------------------\n");
        printf("************ VIEW ************ \n");
        printf("------------------------------------------\n");
        printf("-v and file name to view\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("------------------------------------------\n");
        printf("************ EDIT ************ \n");
        printf("------------------------------------------\n");
        printf("1). -e and file name to edit and Select which tag to edit\n");
        printf("------------------------------------------\n");
        printf("\n");
    }
    else if (strcasecmp("-x", operation) == 0)
    {
        printf("exit\n");
    }
    else
    {
        printf("Invalid Operation Type\n");
        printf("Check in Help Info\n");
        printf("For Help Info Press -h\n");
    }
}
