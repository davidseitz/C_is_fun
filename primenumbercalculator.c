#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
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
            return 0;
        }
        ++i;
    }
    return number;
}
int main(int argc, char** argv) {


    uint64_t number = 1;
    for (uint64_t i = 1; i<10000; i++) {
        uint64_t n = squarerootapproximation(&i, &number);
        if (primenum(i, number) !=0)
        {
            printf("Primenum: %li, Squareroot: %li\n",i,number);
        }

        //printf("Num: %li Aprrox: %li\n", i, n);
    }
    return 0;
}
