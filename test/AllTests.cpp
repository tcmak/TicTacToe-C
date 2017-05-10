/*
 * AllTests.cpp
 *
 *  Created on: 6 May 2017
 *      Author: stevenmak
 */

#include "../include/CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

