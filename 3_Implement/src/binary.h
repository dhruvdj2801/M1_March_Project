/**
 * @file binary.h
 * @author Dhruv Jindal
 * @brief Header file for binary (base-2) method
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdi

/**
 * @brief Structures for storing the input & output stream
 * 
 */
typedef struct Output_Binary_struct
{
    int binary[50];
    int length;
} Output_Binary_struct;


typedef struct Input_Binary_struct
{
    long int number;
    int base;
} Input_Binary_struct;


Output_Binary_struct transformBinary(Input_Binary_struct input);


/**
 * @brief Convert a decimal number to binary number
 * 
 * @param input
 * @return Bianry_Output_struct 
 */
Output_Binary_struct transformBinary(Input_Binary_struct input)
{
    int number = input.number;
    int base = input.base;
    int counter = 0;
    Output_Binary_struct output;

    // check if the number zero
    if (number == 0)
    {
        *(output.binary) = 0;
        output.length = 1;
        return output;
    }

    //convert to binary
    while (number != 0)
    {
        *(output.binary + counter ) = number % base; // store the remainder
        number /= base; // divide the number by the base
        counter++; // increment the counter
    }
    output.length = counter;
    
    return output;
}
