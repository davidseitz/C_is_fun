#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Give at least 1 argument\n");
        return 1;
    } else {
        printf("The files you'd like to add: %s\n", argv[1]);
        printf("Your comment: %s\n",argv[2]);
        printf("Does this look right to you (Y,n)\n");
        for (int i = 3; i>=0; --i) {
            char option = fgetc(stdin);
            if (option == 'Y') {
                printf("Executing commands\n");
            } else if (option == 'n') {
                return 0;
            } else {
                printf("Unkown Option: %c\n",option);
            }
            if(i!=0)
            {
                printf("You got %i more tries left before the Programm auto-terminates\n",i);
            }
        }
    }
    return 0;
}
