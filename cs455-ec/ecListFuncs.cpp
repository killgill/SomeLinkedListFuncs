/*  Name: Karan Singh Gill 
*  USC NetID: karansig
*  CS 455 Fall 2017
*
*  See ecListFuncs.h for specification of each function.
*/

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int numRuns(ListType list) {

    if (list == NULL) {
        return 0;
    }
    int sum = 0;
    int yes = 0;
    Node *curr = list;
    Node *prev = list;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        //if the previous data is the same as the current, we're in a run
        if (curr->data == prev->data) {
            switch (yes) //use this switch so that a run longer than 2 elements isn't an issue
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
    //simple loop builds the new list from the front
    ListType reverse = new Node(curr->data, NULL);
    while (curr->next != NULL) {
        curr = curr->next;
        reverse = new Node(curr->data, reverse);
    }
    return reverse;

}



void removeMiddleElmt(ListType &list) {
    if (list != NULL) { //ensures list isn't null
        int sum = 0;
        Node *curr = list;
        //finds number of elements
        while (curr != NULL) {
            sum++;
            curr = curr->next;
        }
        curr = list;
        //different cases are needed for 0, 1, or 2 elements
        switch (sum){
            case 0: { //not strictly needed, but better to have it
                break;
            }
            case 1: {//deletes the element
                delete curr;
                list = NULL;
                break;
            }
            case 2: {//deletes the first element and fixes pointers
                list = curr->next;
                delete curr;
                break;
            }
            default: { //for all other cases
                int mid = sum / 2;
                int count = 0;
                curr = list->next;
                Node *prev = list;
                //counts to the middle
                while (count < mid - 2) {
                    prev = curr;
                    curr = curr->next;
                    count++;
                }
                //links element before middle to element after middle
                prev->next = curr->next;
                //delete the middle node
                delete curr;
                break;
            }
        }
    }
}



void splitOn(ListType &list, int splitVal, ListType &a, ListType &b) {
    Node *curr = list;
    if (curr != NULL){//make sure list isn't empty
        if (curr->data != splitVal) { //make sure the first element is splitVal
            a = curr; //sets first element of a to first element of list
            Node *foo = a;
            //progresses until either the end of the list or splitVal
            while (curr->next != NULL && curr->next->data != splitVal) {
                foo->next = curr->next;
                curr = curr->next;
                foo = foo->next;
            }
            //assuming we reached splitVal rather than the end of the list
            if (foo->next != NULL) {
                Node *del = curr->next;
                curr = curr->next->next;//skips past the node to be deleted
                foo->next = NULL;//makes the last element of a point to NULL
                delete del; //deletes superfluous element
                b = curr; //starts b at the element after Splitval
                foo = b;
                //same as before
                while (curr != NULL) {
                    foo->next = curr->next;
                    curr = curr->next;
                    foo = foo->next;
                }
            }
        }
        else { //if first element is splitval, we just put the rest of the list into b
            curr = curr->next;
            b = curr;
            Node *foo = b;
            while (curr != NULL) {
                foo->next = curr->next;
                curr = curr->next;
                foo = foo->next;
            }
        }
        list = NULL; //stops the list from pointing to it's previous elements        
    }
}
