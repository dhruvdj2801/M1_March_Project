/**
 * @file gray.h
 * @author Dhruv Jindal
 * @brief Header file for gray coding method
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Structures for storing the input & output stream
 * 
 */
typedef struct Output_Gray_struct
{
    int gray[50];
    int length;
} Output_Gray_struct;
typedef struct Input_Gray_struct
{
    int number;
} Input_Gray_struct;
Output_Gray_struct transformGray(Input_Gray_struct input);

/**
 * @brief Convert a decimal number to Gray coding system
 * 
 * @param input 
 * @return Output_Gray_struct 
 */
Output_Gray_struct transformGray(Input_Gray_struct input)
{
    int number = input.number;
    int arr[50];
    int counter = 0;
    Output_Gray_struct output;

    // check if output is zero
    if (number == 0)
    {
        *(output.gray) = 0;
        counter = 1;
        return output;
    }

    // conversion if input is not zero
    while (number != 0)
    {
        arr[counter++] = number % 2;
        number = number / 2;
    }
    *(output.gray + counter - 1) = *(arr + counter - 1);
    for (int i = counter - 2; i >= 0; i--)
    {
        *(output.gray + i) = *(arr + i) ^ *(arr + i + 1);
    }
    
    output.length = counter;
    return output;
}
