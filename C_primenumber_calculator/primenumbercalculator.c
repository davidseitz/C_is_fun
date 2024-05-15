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
    fwrite(buffer,sizeof(uint64_t),BUFFERSIZE,fp);
    fclose(fp);
    return SUCCESS;
}

int main(int argc, char** argv) {

    uint64_t buffer[BUFFERSIZE];
    uint64_t number = 1;
    uint64_t primenumcounter = 0;
    for (uint64_t i = 1; i<UPPER_PRIME_BOUND; i++) {
        uint64_t n = squarerootapproximation(&i, &number);
        if (primenum(i, number) != NOT_A_PRIME)
        {
            buffer[primenumcounter++] = i;

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
