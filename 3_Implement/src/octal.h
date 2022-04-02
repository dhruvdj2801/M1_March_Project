/**
 * @file octal.h
 * @author Dhruv Jindal
 * @brief Header file for octal (base-8) method
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
typedef struct Output_Octal_struct
{
    int octal[50];
    int length;
} Output_Octal_struct;

typedef struct Input_Octal_struct
{
    long int number;
    int base;
} Input_Octal_struct;

Output_Octal_struct transformOct(Input_Octal_struct input);

/**
 * @brief Convert a decimal number to octal number
 * 
 * @param input 
 * @return Output_Octal_struct
 */
Output_Octal_struct transformOct(Input_Octal_struct input)
{
    int number = input.number;
    int base = input.base;
    int counter = 0;
    Output_Octal_struct output;

    if (number == 0)
    {
        *(output.octal) = 0;
        output.length = 1;
        return output;
    }

    while (number != 0)
    {
        *(output.octal + counter) = number % base; // store modulo of the number by the base
        number /= base;
        counter++;
    }
    output.length = counter;
    
    return output;
}
