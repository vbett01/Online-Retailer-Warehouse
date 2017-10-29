//
//  incomingOrders.cpp
//  Project1
//
//  Created by Vincent Bett on 10/10/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <stdio.h>
#include "incomingOrders.h"

/*
 FUNCTION:
 INPUT:
 OUTPUT:
 */
incomingOrders::incomingOrders()
{
    
}
/*
 FUNCTION:
 INPUT:
 OUTPUT:
*/
incomingOrders::~incomingOrders()
{
    
}

/*
 FUNCTION: addorders
 PURPOSE: to add theincoming orders to the queue
 INPUT: A struct order
 OUTPUT: None
*/
void incomingOrders::addorders(Order ToAdd)
{
    added.enqueue(ToAdd);
}

/*
 FUNCTION: removeOrder
 PURPOSE: TO remove the order at the front
 INPUT: None
 OUTPUT: None
*/
void incomingOrders::removeOrder()
{
    added.dequeue();
}

/*
 FUNCTION: topOrder
 PURPOSE: To return the order at the top of the queue
 INPUT: None
 OUTPUT: A struct order
*/
Order incomingOrders::topOrder()
{
    return added.frontOfQueue();
}

/*
 FUNCTION: topOrderFetchtime
 PURPOSE: to returnt the time it will take to fetch the front order
 INPUT: None
 OUTPUT: An int time
*/
int incomingOrders::topOrderFetchtime()
{
    return added.fetchTimeFront();
}

/*
 FUNCTION: topOrderarrivaltime
 PURPOSE: to return the time the front order arrived
 INPUT: None
 OUTPUT: an int time
*/
int incomingOrders::topOrderarrivaltime()
{
    return added.arrivaltime();
}


/*
 FUNCTION: noOrders
 PURPOSE: To check if the queue is empty
 INPUT: None
 OUTPUT: A bool
*/
bool incomingOrders::noOrders()
{
    return added.is_empty();
}
