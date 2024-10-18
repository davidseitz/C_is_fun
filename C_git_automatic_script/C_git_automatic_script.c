#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int execute_arguments(char* files, char* comment)
{
	int len = strlen("git commit -m\"\"") + strlen(files) + strlen(comment);
	char* buffer = (char*) calloc(1000,0);
	//char buffer[1000];

	if (!buffer || len > 999){
		return 1;
	}
	char* strptr = &buffer[0];
	strptr = strcat(files, strptr);
	strptr = strcat(comment, strptr);	
	printf("Buffer: %s\n", strptr);
	free(buffer);
	return 0;
}
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
            char option[10];
	    const char* yes = "Y";
	    const char* no  = "n";
	    (void)fgets(option, 10,stdin);
            if (strncmp(option, yes, 1) == 0) {
                printf("Executing commands\n");
		break;
            } else if (strncmp(option, no, 1) == 0) {
                return 0;
            } else {
                printf("Unkown Option: %s\n",option);
            }
            if(i!=0)
            {
                printf("You got %i more tries left before the Programm auto-terminates\n",i);
            }
        }
	(void)execute_arguments(argv[1], argv[2]);
    }
    return 0;
}
