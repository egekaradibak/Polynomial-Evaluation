//
// Created by Ege Karadibak on 2020-04-13.
// Main module for Polyapp
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "poly.h"

int main(int n, char * args[]){
    if (n < 2){ // If no arguments supplied print error message and quit
        printf("Please provide data file as an argument to the program");
        return 1;
    }
    FILE * fp = fopen(args[1], "r");
    if (fp == NULL) { // Error check for file not found
        printf("File not found.");
    }
    char * line = (char *) malloc(20 * sizeof(char));
    int i = 1;
    int * coef = (int*) malloc(sizeof(int));
    int * exp = (int*) malloc(sizeof(int));
    while(!feof(fp)){ // Loop reading lines for supplied file
        fgets(line, 20, fp);
        if (feof(fp)) break;
        int err = parse(line, coef, exp); // Parse Line
        if (err == -1){ // Checks if line could be parsed
            printf("Failed to read line number %d in supplied file.\n", i);
            return 1;
        }
        err = addToPoly(*coef, *exp); // Add term to polynomial
        if (err == -1){ // Checks if term could be added
            printf("Ran out of memory. Program terminating...");
            return 1;
        }
        i++;
    }
    // Return memory to OS
    free(coef);
    free(exp);
    free(li
    displayPolynomial(); // Display entered polynomial
    int x[5] = {-2,-1,0,1,2};
    for (int j = 0; j < 5; ++j) { // Evaluate polynomial and print results for each of the points in x
        int result = evaluatePolynomial(x[j]);
        printf("for x=%d, y=%d\n", x[j], result);
    }
    return 0;
}
