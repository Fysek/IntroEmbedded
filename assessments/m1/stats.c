/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Source file with statistic function definitions
 *
 * This file contains definitions of different statistic functions for given char array.
 * File stats.h is required to ensure correct working for functions.
 *
 * @author Mateusz Dyrdó³
 * @date 14.08.2019
 *
 */


#include <stdio.h>
#include "stats.h"
#define SIZE (40)


void print_statistics(unsigned char tab[], unsigned int tabSize){
    printf("median %d\n", find_median(tab, tabSize));
    printf("mean %d\n", find_mean(tab, tabSize));
    printf("minimum %d\n", find_minimum(tab, tabSize));
    printf("maximum %d\n", find_maximum(tab, tabSize));
}

void print_array(unsigned char tab[], unsigned int tabSize){
    for(int i=0; i<tabSize; i++)
        printf("tab[%d] = %d\n", i, tab[i]);
}

unsigned char find_median(unsigned char tab[], unsigned int tabSize){
    sort_array(tab, tabSize);
    if(tabSize%2==0) {
        return((tab[tabSize/2] + tab[tabSize/2 - 1]) / 2);
    } else {
        return tab[tabSize/2];
    }
}

unsigned char find_mean(unsigned char tab[], unsigned int tabSize){
    char sum=0;
    for(int i=0; i<tabSize; i++)
        sum+=tab[i];
    return(sum/tabSize);
}

unsigned char find_maximum(unsigned char tab[], unsigned int tabSize){
    unsigned char max=tab[0];
    for(int i=1;i<tabSize;i++){
        if(tab[i]>max)
            max=tab[i];
    }
    return max;
}

unsigned char find_minimum(unsigned char tab[], unsigned int tabSize){
    unsigned char min=tab[0];
    for(int i=1;i<tabSize;i++){
        if(tab[i]<min)
            min=tab[i];
    }
    return min;
}

void sort_array(unsigned char tab[], unsigned int tabSize){
    char temp;
    for(int i=0;i<tabSize;i++){
		for(int j=1;j<tabSize-i;j++){
            if(tab[j-1]<tab[j]){
                temp = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = temp;
            }
		}
    }
}


void main() {
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
									7,  87, 250, 230,  99,   3, 100,  90};


	print_array(test, SIZE);
	print_statistics(test, SIZE);
	sort_array(test, SIZE);
	print_array(test, SIZE);
}


