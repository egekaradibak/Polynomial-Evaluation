//
// Created by Ege Karadibak on 2020-04-13.
// File that handles the polynomial Linked List.
// Linked List always sorted by ascending order of exponent.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct PolyTerm Term; // Creating a shorthand for PolyTerm

struct PolyTerm{
    int coef;
    int exp;
    Term * next;
};

Term * head;
// Helper returning term with exponent = exp or NULL if doesn't exist
Term * getTerm(int exp){
    Term * cur = head;
    while (cur != NULL){
        if (cur->exp == exp) return cur;
        cur = cur->next;
    }
    return NULL;
}

// Inserts new term into polynomial in its appropriate position.
int addToPoly(int coef, int exp){
    Term * new = (Term *) malloc(sizeof(Term));
    if (new == NULL) return -1;
    if (head == NULL){ // If the polynomial is empty initialize term as the head
        new->coef = coef;
        new->exp = exp;
        new->next = NULL;
        head = new;
        return 0;
    }
    else if(head->next == NULL && head->exp < exp){ // If the polynomial has only one element
        new->coef = coef;
        new->exp = exp;
        new->next = NULL;
        head->next = new;
        return 0;
    }
    else if(head->exp > exp){ // If the term has to be inserted at the head of the linked list.
        //Term * new = (Term *) malloc(sizeof(Term));
        //if (new == NULL) return -1;
        new->coef = coef;
        new->exp = exp;
        new->next = head;
        head = new;
        return 0;
    }
    else{
        Term * cur = getTerm(exp);
        if (cur != NULL){ // Handling the case in which the terms have to be merged
            cur->coef += coef;
            free(new); // Returns memory to OS since it wasn't used
            return 0;
        }
        cur = head;
        //Term * new = (Term *) malloc(sizeof(Term));
        //if (new == NULL) return -1;
        while (cur->next != NULL){
            if (cur->exp < exp && cur->next->exp > exp){ // Adding the polynomial between terms
                new->coef = coef;
                new->exp = exp;
                new->next = cur->next;
                cur->next = new;
                return 0;
            }
            cur = cur->next;
        }
        if (cur->exp < exp){  // Adding polynomial to tail
            new->coef = coef;
            new->exp = exp;
            cur->next = new;
            new->next = NULL;
            return 0;
        }

    }
    return -1;
}
// Prints the polynomial to the console
void displayPolynomial(){
    if (head == NULL) printf("Empty Polynomial");
    Term * cur = head;
    char * display = (char *) malloc(60 * sizeof(char));
    char * term = (char *) malloc(10 * sizeof(char));
    while (cur != NULL){
        if (cur->coef == 0){ // Skips the term with 0 coefficient
            cur = cur->next;
            continue;
        }
        if (cur->coef > 0 && strcmp(display, "")!= 0){ // Add + sign if coef is +ve and display string is not empty
            display = strcat(display, "+");
        }
        sprintf(term, "%dx%d", cur->coef, cur->exp); // Format term
        display = strcat(display, term);
        cur = cur->next;
    }
    printf("%s\n", display);
    // Return resources
    free(display);
    free(term);
}
// Returns the result of evaluating the polynomial at x
int evaluatePolynomial(int x){
    int result = 0;
    Term * cur = head;
    if (cur == NULL) return result; // Safety check for empty polynomial return 0 if so

    while (cur != NULL){ // Cycle polynomial
        if (cur->coef == 0){
            cur = cur->next;
            continue;
        }
        result += cur->coef * powi(x, cur->exp);
        cur = cur->next;
    }
    return result;
}
