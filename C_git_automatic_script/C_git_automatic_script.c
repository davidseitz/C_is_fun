#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Only give one argument\n");
        return 1;
    } else {
        printf("Your argument: %s\n", argv[1]);
    }
    return 0;
}
