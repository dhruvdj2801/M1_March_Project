/**
 * @file xs.h
 * @author Dhruv Jindal
 * @brief Header file for excess-3 (XS-2) method
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
typedef struct Output_Xs_struct
{
    int xs[50];
    int length;
} Output_Xs_struct;


typedef struct Input_Xs_struct
{
    int number;
} Input_Xs_struct;


Output_Xs_struct transformXS(Input_Xs_struct input);

/**
 * @brief Convert a decimal number to XS-3 coding system
 * 
 * @param input 
 * @return Output_Xs_struct 
 */
Output_Xs_struct transformXS(Input_Xs_struct input)
{
    int number = input.number;
    int i = 0;
    int arr[5];
    Output_Xs_struct output;

    if (number == 0)
    {
        int k = 4;
        output.length = k;
        *(output.xs) = 1;
        *(output.xs + 1) = 1;
        *(output.xs + 2) = 0;
        *(output.xs + 3) = 0;
        return output;
    }

    while (number != 0)
    {
        arr[i++] = (number % 10) + 3;
        number = number / 10;
    }
    int c = 0;
    for (int j = 0; j < i; j++)
    {
        int k = 4;
        while (*(arr + j) != 0)
        {
            k--;
            *(output.xs + c) = *(arr + j) % 2;
            *(arr + j) = *(arr + j) / 2;
            c++;
        }

        while (k--)
        {
            *(output.xs + c) = 0;
            c++;
        }
    }
    output.length = c;
    
    return output;
}