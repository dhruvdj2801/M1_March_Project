/**
 * @file bcd.h
 * @author Dhruv Jindal
 * @brief Header file for Binary Coded Decimal (BCD) method
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>


/**
 * @brief Structures for storing the input & output stream
 * 
 */
typedef struct Output_Bcd_struct
{
    int bcd[50];
    int length;
} Output_Bcd_struct;

typedef struct Input_Bcd_struct
{
    int number;
} Input_Bcd_struct;


Output_Bcd_struct transformBcd(Input_Bcd_struct input);

/**
 * @brief Convert a decimal number to BCD system
 * 
 * @param input 
 * @return Output_Bcd_struct 
 */
Output_Bcd_struct transformBcd(Input_Bcd_struct input)
{
    int number = input.number;
    int i = 0;
    int arr[5];
    Output_Bcd_struct output;

    if (number == 0)
    {
        int k = 4;
        output.length = k;
        while (k--)
        {
            *(output.bcd + k) = 0;
        }
        return output;
    }

    while (number != 0)
    {
        arr[i++] = number % 10;
        number = number / 10;
    }
    int c = 0;
    for (int j = 0; j < i; j++)
    {
        int k = 4;
        while (*(arr + j) != 0)
        {
            k--;
            *(output.bcd+c) = *(arr + j) % 2;
            *(arr + j) = *(arr + j) / 2;
            c++;
        }
        while (k--)
        {
            *(output.bcd+c) = 0;
            c++;
        }
    }
    output.length = c;
    
    return output;
}