/**
 * @file test_project.c
 * @author your name (you@domain.com)
 * @brief Unity testing for Number System Converter
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string.h>
#include <stdio.h>
#include "../src/binary.h"
#include "../src/octal.h"
#include "../src/hexadecimal.h"
#include "../src/bcd.h"
#include "../src/xs.h"
#include "../src/gray.h"
#include "../unity/unity.h"
/**
 * @brief Set the Up object
 * 
 */
void setUp()
{
}
/**
 * @brief Required by the unity test framework 
 * 
 */
void tearDown()
{
}
/**
 * @brief Required by the unity test framework 
 * 
 */
void test_binary(void)
{
    Input_Binary_struct bin;
    Output_Binary_struct obin;
    bin.number = 0;
    bin.base = 2;
    obin = transformBinary(bin);
    TEST_ASSERT_EQUAL(0, *(obin.binary));

    bin.number = 83;
    bin.base = 2;
    obin = transformBinary(bin);
    TEST_ASSERT_EQUAL(1, *(obin.binary));
    TEST_ASSERT_EQUAL(1, *(obin.binary + 1));
    TEST_ASSERT_EQUAL(0, *(obin.binary + 2));
    TEST_ASSERT_EQUAL(0, *(obin.binary + 3));
    TEST_ASSERT_EQUAL(1, *(obin.binary + 4));
    TEST_ASSERT_EQUAL(0, *(obin.binary + 5));
    TEST_ASSERT_EQUAL(1, *(obin.binary + 6));
}
void test_octal(void)
{
    Input_Octal_struct oct;
    Output_Octal_struct ooct;
    oct.number = 0;
    oct.base = 8;
    ooct = transformOct(oct);
    TEST_ASSERT_EQUAL(0, *(ooct.octal));
    oct.number = 83;
    oct.base = 8;
    ooct = transformOct(oct);
    TEST_ASSERT_EQUAL(3, *(ooct.octal));
    TEST_ASSERT_EQUAL(2, *(ooct.octal + 1));
    TEST_ASSERT_EQUAL(1, *(ooct.octal + 2));
    oct.number = 8;
    oct.base = 8;
    ooct = transformOct(oct);
    TEST_ASSERT_EQUAL(0, *(ooct.octal));
    TEST_ASSERT_EQUAL(1, *(ooct.octal + 1));
}

void test_hexadecimal(void)
{
    Input_Hexadecimal_struct hexa;
    Output_Hexadecimal_struct ohexa;
    hexa.number = 0;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(48, *(ohexa.hexadecimal));
    hexa.number = 83;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(51, *(ohexa.hexadecimal));
    TEST_ASSERT_EQUAL(53, *(ohexa.hexadecimal + 1));
    hexa.number = 10;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(65, *(ohexa.hexadecimal));
    hexa.number = 16;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(48, *(ohexa.hexadecimal));
    TEST_ASSERT_EQUAL(49, *(ohexa.hexadecimal + 1));
    hexa.number = 123;
    hexa.base = 16;
    ohexa = transformHexadecimal(hexa);
    TEST_ASSERT_EQUAL(66, *(ohexa.hexadecimal));
    TEST_ASSERT_EQUAL(55, *(ohexa.hexadecimal + 1));
}

void test_bcd(void)
{
    Input_Bcd_struct bcd;
    Output_Bcd_struct obcd;
    bcd.number = 0;
    obcd = transformBcd(bcd);
    int x = obcd.length;
    for (int i = x - 1; i >= 0; i--)
    {
        TEST_ASSERT_EQUAL(0, *(obcd.bcd + i));
    }
    bcd.number = 83;
    obcd = transformBcd(bcd);
    TEST_ASSERT_EQUAL(1, *(obcd.bcd));
    TEST_ASSERT_EQUAL(1, *(obcd.bcd + 1));
    TEST_ASSERT_EQUAL(0, *(obcd.bcd + 2));
    TEST_ASSERT_EQUAL(0, *(obcd.bcd + 3));
    TEST_ASSERT_EQUAL(0, *(obcd.bcd + 4));
    TEST_ASSERT_EQUAL(0, *(obcd.bcd + 5));
    TEST_ASSERT_EQUAL(0, *(obcd.bcd + 6));
    TEST_ASSERT_EQUAL(1, *(obcd.bcd + 7));
}

void test_xs(void)
{
    Input_Xs_struct xs;
    Output_Xs_struct oxs;
    xs.number = 0;
    oxs = transformXS(xs);
    int y = oxs.length;
    for (int i = y - 1; i >= 2; i--)
    {
        TEST_ASSERT_EQUAL(0, *(oxs.xs + i));
    }
    for (int i = 1; i >= 0; i--)
    {
        TEST_ASSERT_EQUAL(1, *(oxs.xs + i));
    }
    xs.number = 83;
    oxs = transformXS(xs);
    TEST_ASSERT_EQUAL(0, *(oxs.xs));
    TEST_ASSERT_EQUAL(1, *(oxs.xs + 1));
    TEST_ASSERT_EQUAL(1, *(oxs.xs + 2));
    TEST_ASSERT_EQUAL(0, *(oxs.xs + 3));
    TEST_ASSERT_EQUAL(1, *(oxs.xs + 4));
    TEST_ASSERT_EQUAL(1, *(oxs.xs + 5));
    TEST_ASSERT_EQUAL(0, *(oxs.xs + 6));
    TEST_ASSERT_EQUAL(1, *(oxs.xs + 7));
}
void test_gray(void)
{
    Input_Gray_struct gray;
    Output_Gray_struct ogray;
    gray.number = 0;
    ogray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(ogray.gray));
    gray.number = 83;
    ogray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(ogray.gray));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 1));
    TEST_ASSERT_EQUAL(0, *(ogray.gray + 2));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 3));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 4));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 5));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 6));
    gray.number = 8;
    ogray = transformGray(gray);
    TEST_ASSERT_EQUAL(0, *(ogray.gray));
    TEST_ASSERT_EQUAL(0, *(ogray.gray + 1));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 2));
    TEST_ASSERT_EQUAL(1, *(ogray.gray + 3));
}
int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_binary);
    RUN_TEST(test_octal);
    RUN_TEST(test_hexadecimal);
    RUN_TEST(test_bcd);
    RUN_TEST(test_xs);
    RUN_TEST(test_gray);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
