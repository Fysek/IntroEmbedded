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
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes as an input a reference to char array and size of array.
 * It prints 
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
 * <Add Extended Description Here>
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
 * <Add Extended Description Here>
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
 * <Add Extended Description Here>
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
 * <Add Extended Description Here>
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
 * <Add Extended Description Here>
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
 * <Add Extended Description Here>
 *
 * @param An unsigned char pointer to an n-element data array
 * @param An unsigned integer as the size of the array
 *
 * @return void
 */
void sort_array(unsigned char tab[], unsigned int tabSize);



#endif /* __STATS_H__ */
