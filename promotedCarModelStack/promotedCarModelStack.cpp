
#include "promotedCarModelStack.h"
#include <stdlib.h>
#include <iostream>

/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1)
   * @param model
   * @param price
   */
void PromotedCarModelStack::push(string model, int price) {

    //create new nodes in order to hold value for possible shifts of change
    nodePtr newHead = new Node;
    nodePtr newMaxandMin = new Node;



    //assign each new node with the values from the param
    newHead->data = price;
    newHead->name = model;
    newHead->next = NULL;

    newMaxandMin->maxValue = price;
    newMaxandMin->minValue = price;
    newMaxandMin->maxName = model;
    newMaxandMin->minName = model;
    newMaxandMin->next = NULL;






//if this is the first value of node then the linked list head,maxValue,and minValue are determined
    if(head == NULL){
        head = newHead;
        holdMaxandMin = newMaxandMin;


//if head is not null a new head will be assigned and the old one with be assign to the next node of the new head
    }else{
        newHead->next = head;
        head = newHead;


        //check if the new data is bigger than the old and if so itll be added to another linked list as the head known as the largest value of the list so far
        if(price > holdMaxandMin->maxValue){
            newMaxandMin->maxValue = price;
            newMaxandMin->maxName = model;

        }

            //if the new data isnt larger then the previous large one will be assign to top
        else{
            newMaxandMin->maxValue =  holdMaxandMin->maxValue;
            newMaxandMin->maxName =  holdMaxandMin->maxName;
        }

        //check if the new data is smaller than the old and if so itll be added to another linked list as the head known as the smallest value of the list so far
        if(price <  holdMaxandMin->minValue){
            newMaxandMin->minValue = price;
            newMaxandMin->minName = model;

        }
            //if the new data isnt smaller then the previous smallest one will be assign to top
        else{
            newMaxandMin->minValue =  holdMaxandMin->minValue;
            newMaxandMin->minName =  holdMaxandMin->minName;
        }


//assign the new head for the node holding the max and min value of head
        newMaxandMin->next = holdMaxandMin;
        holdMaxandMin = newMaxandMin;

    }
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
//if head is null throw Promoted car model stack is empty

    if(head == NULL) {
        throw ("Promoted car model stack is empty");

    }

        //if head isnt null pop the list of maxList,minList, and head while also returning the values that are popped
    else{

        //declare and initializes values of the soon to be popped head
        string poppedModel = head-> name;
        int poppedData = head-> data;
//pop head of linkedList
        head = head->next;


//pop head of max and minn linkedList
        holdMaxandMin = holdMaxandMin->next;




        //return the popped values
        return  PromotedModel( poppedModel,poppedData);
    }









//return NULL
    return PromotedModel();
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
    //if head is null throw exception
    if(head == NULL) {
        throw ("Promoted car model stack is empty");

    }//returns the values of head
    else{
        return PromotedModel(head->name ,head->data );
    }
    //return null
    return PromotedModel();
}

/**
   * @brief getHighestPricedPromotedModel,
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
//if head is null throw exception
    if(head == NULL) {
        throw ("Promoted car model stack is empty");
    }
    else{
        //return the value with the largest value of the current head list


        return PromotedModel(holdMaxandMin->maxName ,holdMaxandMin->maxValue);
    }




//return NULL
    return PromotedModel();
}


/**
   * @brief getLowestPricedPromotedModel,
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {

//if head is null throw exception
    if(head == NULL) {
        throw ("Promoted car model stack is empty");
    }
    else{
        //return the value with the smallest value of the current head list
        return PromotedModel(holdMaxandMin->minName ,holdMaxandMin->minValue);
    }
//return NULL
    return PromotedModel();
}