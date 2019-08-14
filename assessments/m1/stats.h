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
 * @file stats.h
 * @brief Header file with statistic function declaration
 *
 * This file contains declarations of different statistic functions for given char array.
 *
 * @author Mateusz Dyrdół
 * @date 14.08.2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes as an input a reference to char array and size of array.
 * It prints median, mean, minimum, maximum of array
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return void
 */
 void print_statistics(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * This function takes as an input a reference to char array and size of array.
 * It prints elements in the array
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return void
 */
void print_array(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, returns the median value
 *
 * This function takes as an input a reference to char array and size of array.
 * It finds median of the array and returns it.
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned char result from the function
 */
unsigned char find_median(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, returns the mean
 *
 * This function takes as an input a reference to char array and size of array.
 * It finds mean of the array and returns it.
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned char result from the function
 */
unsigned char find_mean(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, returns the maximum,
 *
 * This function takes as an input a reference to char array and size of array.
 * It finds maximum of the array and returns it.
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned char result from the function
 */
unsigned char find_maximum(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, returns the minimum
 *
 * This function takes as an input a reference to char array and size of array.
 * It finds minimum of the array and returns it.
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return An unsigned char result from the function
 */
unsigned char find_minimum(unsigned char tab[], unsigned int tabSize);


 /**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * This function takes as an input a reference to char array and size of array.
 * It sorts the array with bubblesort algorithm from largest to smallest.
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return void
 */
void sort_array(unsigned char tab[], unsigned int tabSize);



#endif /* __STATS_H__ */
