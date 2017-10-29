//
//  OrderQueue.cpp
//  Project1
//
//  Created by Vincent Bett on 10/5/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <stdio.h>
#include "OrderQueue.h"

/*
Function: Constructor.
Purpose: To initialize the class
Input: None
Output: None

 */
OrderQueue::OrderQueue()
{
	front = NULL;
	back = NULL;
	numElements = 0;
	sumPackTime = 0;
}

// Overloaded constructor.
OrderQueue::OrderQueue(Order add)
{
	numElements = 0;
	node *temp = new node;
	temp->arrived = add;
	temp->next = NULL;
	front = temp;
	back = temp;
	increase();
	sumPackTime+=back->arrived.pack_duration;
}


// Destructor.
OrderQueue::~OrderQueue()
{
	node *temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

}


/*
Function: enqueue
Purpose: Tadd items into the queue
Input: a struct
Output: None
 */
void OrderQueue::enqueue( Order add)
{
	node *temp = new node;
	temp->arrived = add;
	temp->next = NULL;

	if(front == NULL)
	{
		front = temp;
		back = temp;

	}else
	{
		back->next = temp;
	}
	back = temp;
	increase();
	sumPackTime+=back->arrived.pack_duration;
}

/*
Function: dequeue
Purpose: To remove an item fron the front of the queue
Input: NONE
Output: NONE

 */
void OrderQueue::dequeue()
{
	node *temp;
	temp = front;
	sumPackTime -= front->arrived.pack_duration;
	if(front == NULL)
		throw "Queue is empty";
	if(front == back)
	{
		front = back =NULL;
	}
	else
	{
		front = front->next;
	}

	delete temp;
	decrease();
}

/*
Function:   size
Purpose: to retun the number of items in the queue
Input: None
Output: None

 */
int OrderQueue::size()
{
	return numElements;
}


/*
Function: decrease
Purpose: To count down the number of items in the 
queue whenever an item is removed
Input: None
Output: None

 */
void OrderQueue::decrease()
{
	numElements --;
}

/*
Function: increase.
Purpose: To count up the number of items
in the queue whenever the enque function is called
Input: None
Output: None

 */
void OrderQueue::increase()
{
	numElements ++;
}

/*
Function: FrontOfQueue
Purpose: To return the object at the front 
of the queue before it is deleted by dequeue
Input: None
Output: A struct

 */
Order OrderQueue::frontOfQueue()
{
	if(front == NULL)
	{
		throw "Empty queue";
	}
	return front->arrived;
}

/*
Function: backOfqueue
Purpose: To return the item at the back of the queue
Input: None
Output: a struct order.
 */
Order OrderQueue::BackOfQueue()
{
	return back->arrived;
}

/*
Function: is_empty
Purpose: To checkif the queue is empty or not
Input: None
Output: a boolean

 */
bool OrderQueue::is_empty()
{
	if(numElements == 0)
		return true;
	else
		return false;   
}

/*
Function: totalPackTime
Purpose: adds up all the pack time of elements in the queue
and returns the sum
Input: None
Output: An int

 */
int OrderQueue::totalPacktime()
{
	return sumPackTime;
}

/*
Function: fetchTimeFront
Purpose: To return the number of minutes it will take for 
the retriever to fetch the
item in front of the queue.
Input: None
Output: An int time

 */
int OrderQueue::fetchTimeFront()
{
	return front->arrived.fetch_duration;
}

/*
Function: PackTimeFront
Purpose: To check the number of minutes it will take to pack the
front item.
Input: None
Output: An int time

 */
int OrderQueue::packTimeFront()
{
	return front->arrived.pack_duration;
}

/*
function: arrival time
Purpose: to get the arrival time of the front order
Input: None
Output: An int time
 */
int OrderQueue::arrivaltime()
{
	return front->arrived.arrival_timestamp;
}

/*
FUNCTION: timeaddedToPacking
PURPOSE: to return the time front order was added to packing
INPUT: None
OUTPUT: None
 */
int OrderQueue::timeAddedToPacking()
{
	return front->arrived.time_Added;
}
/*
FUNCTION: decrementFrontPAcktime
PURPOSE: To reduce the pack time left of the front order by one
INPUT: None
OUTPUT: None
 */
void OrderQueue::decrementFrontPacktime()
{
	front->arrived.pack_time_left --;
}
