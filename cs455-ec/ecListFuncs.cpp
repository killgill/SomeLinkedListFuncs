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


    Node *curr = list;
    if (curr == NULL) {
        return NULL;
    }
    ListType reverse = new Node(curr->data, NULL);
    while (curr->next != NULL) {
        curr = curr->next;
        reverse = new Node(curr->data, reverse);
    }
    return reverse;

}



void removeMiddleElmt(ListType &list) {
    if (list != NULL) {
        int sum = 0;
        Node *curr = list;
        while (curr != NULL) {
            sum++;
            curr = curr->next;
        }
        curr = list;
        switch (sum)
        {
        case 0: {
            break;
        }
        case 1: {
            delete curr;
            list = NULL;
            break;
        }
        case 2: {
            list = curr->next;
            delete curr;
            break;
        }
        default: {
            int mid = sum / 2;
            int count = 0;
            curr = list->next;
            Node *prev = list;
            while (count < mid - 1) {
                prev = curr;
                curr = curr->next;
                count++;
            }
            prev->next = curr->next;
            delete curr;
            break;
        }
        }
        }
    }



    void splitOn(ListType &list, int splitVal, ListType &a, ListType &b) {

    }
