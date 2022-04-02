/**
 * @file main.c
 * @author Dhruv Jindal
 * @brief 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include "src/binary.h"
#include "src/octal.h"
#include "src/hexadecimal.h"
#include "src/bcd.h"
#include "src/xs.h"
#include "src/gray.h"

/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    /**
     * @brief Binary conversion code
     * 
     */
    int temp;
    printf("Enter the input number which has to be converted: \n");
    scanf("%d", &temp);
    printf("\nOUTPUTS:\n\n");
    Input_Binary_struct bin;
    Output_Binary_struct obin;
    bin.number=temp;
    bin.base = 2;
    obin = transformBinary(bin);
    int u = obin.length;
    printf("Binary form: ");
    for (int i = u - 1; i >= 0; i--)
    {
        printf("%d", *(obin.binary + i));
    }

    /**
     * @brief Octal conversion code
     * 
     */
    Input_Octal_struct oct;
    Output_Octal_struct ooct;
    oct.number = temp;
    oct.base = 8;
    ooct = transformOct(oct);
    int v = ooct.length;
    printf("\nOctal form: ");
    for (int i = v - 1; i >= 0; i--)
    {
        printf("%d", *(ooct.octal + i));
    }
    
    /**
     * @brief Hexadecimal conversion code
     * 
     */
    Input_Hexadecimal_struct hexa;
    Output_Hexadecimal_struct ohexa;
    hexa.number = temp;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    int w = ohexa.length;
    printf("\nHexadecimal form: ");
    for (int i = w - 1; i >= 0; i--)
    {
        printf("%c", *(ohexa.hexadecimal + i));
    }

    /**
     * @brief BCD conversion code
     * 
     */
    Input_Bcd_struct bcd;
    Output_Bcd_struct obcd;
    bcd.number = temp;
    obcd = transformBcd(bcd);
    int x = obcd.length;
    printf("\nBinary Coded Decimal (BCD) form: ");
    for (int i = x - 1; i >= 0; i--)
    {
        printf("%d", *(obcd.bcd + i));
    }

    /**
     * @brief XS-3 conversion code
     * 
     */
    Input_Xs_struct xs;
    Output_Xs_struct oxs;
    xs.number = temp;
    oxs = transformXS(xs);
    int y = oxs.length;
    printf("\nExcess-3 (XS-3) form: ");
    for (int i = y - 1; i >= 0; i--)
    {
        printf("%d", *(oxs.xs + i));
    }

    /**
     * @brief Gray conversion code
     * 
     */
    Input_Gray_struct gray;
    Output_Gray_struct ogray;
    gray.number = temp;
    ogray = transformGray(gray);
    int z = ogray.length;
    printf("\nGray form: ");
    for (int i = z - 1; i >= 0; i--)
    {
        printf("%d", *(ogray.gray + i));
    }
}
