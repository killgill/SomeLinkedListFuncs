/*  Name:
*  USC NetID:
*  CS 455 Fall 2017
*
*  See ecListFuncs.h for specification of each function.
*/

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int numRuns(ListType list) {

    int sum = 0;
    int yes = 0;
    Node *curr = list;
    Node *prev = list;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        if (curr->data == prev->data) {
            switch (yes)
            {
            case 0: {
                yes = 1;
                sum++;
                break;
            }
            default:
                break;
            }
        }
        else {
            yes = 0;
        }
    }
    return sum;
}



ListType reverseCopy(ListType list) {

    return NULL;  // stub code to get it to compile

}



void removeMiddleElmt(ListType &list) {

}



void splitOn(ListType &list, int splitVal, ListType &a, ListType &b) {

}
