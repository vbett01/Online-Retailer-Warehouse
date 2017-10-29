//
//  Packer.cpp
//  Project1
//
//  Created by Vincent Bett on 10/10/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <stdio.h>
#include "Packer.h"

/*
FUNCTION: Constructor
PURPOSE:
INPUT: None
OUTPUT: None
 */
Packer::Packer()
{

}

/*
FUNCTION: Destructor.
PURPOSE: to destroy the class
INPUT: None
OUTPUT: None
 */
Packer::~Packer()
{

}

/*
FUNCTION: addorderTopack
PURPOSE: To enque a queue with a struct.
INPUT: A struct order.
OUTPUT: None.
 */
void Packer::addOrderTopack(Order Topack)
{
	OrdertoPack.enqueue(Topack);
}

/*
FUNCTION: removepackaged order.
PURPOSE: To dequeue when the item has already been packed
INPUT: None
OUTPUT: None
 */
void Packer::removePackagedOrder()
{
	OrdertoPack.dequeue();
}

/*
FUNCTION: timeToPackFront
PURPOSE: to return the time it takes to pack the front order.
INPUT: None
OUTPUT: An int time
 */
int Packer::timeToPackFront()
{
	return OrdertoPack.packTimeFront();
}

/*
FUNCTION: itemsinQueue
PURPOSE: To return the number of items in a queue
INPUT: None
OUTPUT: An int number of elements
 */
int Packer::itemsinQueue()
{
	return OrdertoPack.size();
}

/*
FUNCTION: timeleftToPackAll
PURPOSE: to return the time it takes to pack everything 
in a queue
INPUT: None
OUTPUT: an int time.
 */
int Packer::timeleftToPackAll()
{
	if(isempty())
	{
		return 0;
	}
	else
	{
	return OrdertoPack.totalPacktime() - packTimeremainingFront();
	}
}


/*
FUNCTION: packtimeremainingFront
PURPOSE: To returnt the time remaining for the front order to be packed
INPUT: None
OUTPUT: An int time.
 */
int Packer::packTimeremainingFront()
{
	Order item = OrdertoPack.frontOfQueue();

	return item.pack_time_left ;
}

/*
FUNCTION: time added
INPUT: none.
OUTPUT:none
 */
int Packer::timeAdded()
{
	return  OrdertoPack.timeAddedToPacking();
}

/*
FUNCTION: frontOrder
PURPOSE: returns the order at the front
INPUT: None
OUTPUT: A struct order
 */
Order Packer::frontOrder()
{
	return OrdertoPack.frontOfQueue();
}

/*
FUNCTION: isempty
PURPOSE: TO check if the packer is empty or not
INPUT: None
OUTPUT: a boolean 
 */
bool Packer::isempty()
{
	return OrdertoPack.is_empty();
}

/*
FUNCTION: decrementPacktime
PURPOSE: To reduce the time left for the front order to be packed
INPUT: None
OUTPUT: None
 */
void Packer::decrementPacktime()
{
	OrdertoPack.decrementFrontPacktime();
}
