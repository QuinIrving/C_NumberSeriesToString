/*
Quin Irving <irvingq@sheridancollege.ca>
----------------------------------------------------------------------
 /

/
 * File:   main.c
 * Author: Quin Irving <irving@sheridancollege.ca>
 *
 * Created on February 06, 2022, 12:16 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 200

#define FLUSH freopen(NULL, "r", stdin)

unsigned long Fn(unsigned int n);

void removeCharacters(char*);

void removeDuplicates(char*);

int main() {
    int N;
    char charN[201];
    char str[MAX_INPUT + 1];
    do {
        printf("How many numbers to print (1-200)? ");

        fgets(charN, MAX_INPUT, stdin);
        FLUSH;
        //48-57 is: 0-9
        //65-90 is: A-Z
        //97-122 is: a-z
        N = strtol(charN, NULL, 10);
        int p = 5;

    } while(N < 1 || N > 200);

    printf("Series: ");
    int index = 0;

    for (int i = 0; i < N; i++) {

        int digit = Fn(i); // digit equals the final value from the recursion function
        printf("%d ", digit);

        if(digit > 47 && digit < 58) {
            //charN is a number 0-9
            str[index] = digit;
            index++; //increase index of the char array
        } else if(digit > 64 && digit < 91) {
            //charN is a character A-Z
            str[index] = digit;
            index++; //increase index of the char array
        } else if(digit > 96 && digit < 123) {
            //charN is a character a-z
            str[index] = digit;
            index++; //increase index of the char array
        }

    }

    printf("\nString: %s", str);

    removeCharacters(str);
    printf("\nUpper-case String: %s", str);

    removeDuplicates(str);
    printf("\nUnique String: %s", str);
    getchar();
    return 0;
}

unsigned long Fn(unsigned int n) {
    // if the number is 0,1,2 then the value in the series is 10 (ends the recursive function by not calling itself)
    // return the equation and call the function on itself
    return (n < 3) ? 10 : 2 * n + 1 + Fn(n - 1) % 50;
}

void removeCharacters(char* s) {
    size_t i = 0, j = 0;
    //keep checking array until we meet the end of the string (terminating null character)
    while (s[j]) {
        //keeping characters of range A-Z
        if (s[j] > 64 && s[j] < 91) {
            //if the character being matched isn't at the same index as the character we would replace
            if (i != j) {
                s[i] = s[j]; //replace character from string to the uppercase character we found
            }
            i++; //increase our replacement index as we have found an uppercase character
        }
        j++; //increase our newest character to check index as we are checking the next character in the string
    }
    s[i] = 0; // We must end the string with a new line character!
}

// I got most of this code from exercise 5_9 as well, with more edits compared to removeCharacters function
void removeDuplicates(char* s) {
    size_t i = 0, j = 0, k, unique;
    //keep checking array until we meet the end of the string (terminating null character)
    while (s[j]) {
        k = 0;
        unique = 1; //set up the variables for checking for duplicates
        while (k < i) {
            //if character matches a character already in our unique string
            if (s[j] == s[k]) {
                unique = 0; //is a duplicate
                break;
            }
            k++;// no duplicates found at this index, move to next position (or end the while loop and add unique char)
        }
        //if it is a duplicate
        if(!unique) {
            j++; //go to check next character
            continue;
        }
        //if the character being matched isn't at the same index as the character we would replace
        if (i != j) {
            s[i] = s[j]; //replace character from string to the unique character we found
        }
        i++; //increase our replacement index as we have found a unique character
        j++; //increase our newest character to check index as we are checking the next character in the string
    }

    s[i] = 0; // We must end the string with a new line character!
}