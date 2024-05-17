#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

enum {
    NOT_A_PRIME = 0,
    SUCCESS = 0,
    FAILURE = 1,
    BUFFERSIZE = 10000,
    UPPER_PRIME_BOUND = 10000

};

uint64_t squarerootapproximation(const uint64_t *number, uint64_t *end)
{
//Number has to be bigger than 0
    if((*end)*(*end)>=*number) {
        return *end;
    } else {
        return ++(*end);
    }

}
uint64_t primenum(const uint64_t number, uint64_t end)
{
    uint64_t i = 2;
    while( i <= end)
    {
        if( number % i==0) {
            return NOT_A_PRIME;
        }
        ++i;
    }
    return number;
}
/**
 * @brief achieve persistance
 */
int persistance(uint64_t *buffer) {
    FILE *fp;
    printf("1");
    fp = fopen("primenums.bin", "wb");
    if (fp == NULL) {
        //Couldn't open file
        return FAILURE;
    }
    //Ignore return of fwrite for now
    (void)fwrite(buffer,sizeof(uint64_t),BUFFERSIZE,fp);
    fclose(fp);
    return SUCCESS;
}
/**
 * @brief put the buffer to disk if it is full
 * @TODO fseek return value check, is this function semantically correct? 
 * @return 0 on Success, 1 on failure
 */

int buffer_to_disk(uint64_t *buffer, uint64_t primenumcounter, FILE *fp)
{
    //Makros for fseek(FILE *fp, long int offset, int whence)
    //SEEK_SET, SEEK_CUR, SEEK_END respectiley for start, current, end
    if(fseek(fp,primenumcounter*8,SEEK_END) ==0) {
        (void)fwrite(buffer,sizeof(uint64_t),BUFFERSIZE, fp);
        return SUCCESS;
    } else {
        return FAILURE;
    }

}
/**
 * @brief Write to buffer from disk
 * @TODO fread return value check
 * @return 0 on SUCCESS, 1 on FAILURE
 */
int buffer_from_disk(uint64_t *buffer, uint64_t counter, FILE *fp)
{
    if (fseek(fp, counter*8,SEEK_SET) == 0) {
        (void)fread(buffer,sizeof(uint64_t),BUFFERSIZE,fp);
        return SUCCESS;
    }
    return FAILURE;
}
int main(int argc, char** argv) {
	FILE *primenums;
	primenums = fopen("primenums.bin", "wb");
	if (primenums == NULL){
		return FAILURE;
	}
    uint64_t primebuffer[BUFFERSIZE];
    uint64_t buffer[BUFFERSIZE];
    uint64_t number = 1;
    uint64_t primenumcounter = 0;
    for (uint64_t i = 1; i<UPPER_PRIME_BOUND; i++) {
        uint64_t n = squarerootapproximation(&i, &number);
        if (primenum(i, number) != NOT_A_PRIME)
        {

            buffer[primenumcounter++] = i;
		if(primenumcounter > BUFFERSIZE && !buffer_to_disk(buffer, primenumcounter,primenums)){
			return FAILURE;
		}
            // Print the primenums
            //printf("Primenum: %li, Squareroot: %li\n",i,number);
        }
    }
    /*
     * Test if numbers get put into buffer right
    for (uint64_t i = 0; i< 100; i++){
        printf("Primenum %li in buffer is %li\n",i,buffer[i]);
    }
    */
    int temp = persistance(buffer);
    if (temp == FAILURE ) {
        return FAILURE;
    }
    //printf("Num: %li Aprrox: %li\n", i, n);

    return SUCCESS;
}
