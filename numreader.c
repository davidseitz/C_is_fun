#include <stdio.h>
#include <stdint.h>
int main(const int argc,const char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./numreader filename\n");
        return 2;
    }
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("File %s clouldn't be opened",argv[1]);
        return 1;
    } else {
        uint64_t num= 0;
	uint64_t prevnum = -1;
        while( fread(&num,sizeof(uint64_t),1,fp) != -1 && num != prevnum)
        {
            printf("Number = %li\n", num);
	    num = prevnum;

        }
        fclose(fp);
        return 0;
    }
}
