/**
 * @file hexadecimal.h
 * @author Dhruv Jindal
 * @brief Header file for hexadecimal (base-16) method
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
typedef struct Output_Hexadecimal_struct
{
    char hexadecimal[50];
    int length;
} Output_Hexadecimal_struct;
typedef struct Input_Hexadecimal_struct
{
    long int number;
    int base;
} Input_Hexadecimal_struct;
Output_Hexadecimal_struct transformHexadecimal(Input_Hexadecimal_struct input);

/**
 * @brief Convert a decimal number to hexadecimal number
 * 
 * @param input
 * @return Output_Hexadecimal_struct 
 */
Output_Hexadecimal_struct transformHexadecimal(Input_Hexadecimal_struct input)
{
    int number = input.number;
    int base = input.base;
    int counter = 0;
    Output_Hexadecimal_struct output;

    if (number == 0)
    {
        *(output.hexadecimal) = 48;
        output.length = 1;
        return output;
    }

    while (number != 0)
    {
        if (number % base < 10)
        {
            *(output.hexadecimal + counter) = 48 + number % base;
            counter++;
        }
        else
        {
            *(output.hexadecimal + counter) = 55 + number % base;
            counter++;
        }
        number = number / base;
    }
    output.length = counter;

    return output;
}