//
// Created by Ege Karadibak on 2020-04-12.
// Module containing utility functions for use by poly and polyapp

#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
// parse line into coefficient and exponent
int parse(char * line, int * coef, int * exp){
    int errcode = sscanf(line, "%d %d\n", coef, exp); // Reads the line and parses it to integers
    if (errcode != 2) { // Check if there was an error with parsing
        return -1;
    }
    return 0;

}
int powi(int x, int pow){
    // Series of checks to see if we can skip computation and return known result
    if (pow==0) return 1;
    if (pow==1) return x;
    if (x==0) return 0;
    int temp = x;
    for (int i = 0; i < (pow-1); ++i) { // Loop does the actual exponentiation
        temp = temp * x;
    }
    return temp;
}