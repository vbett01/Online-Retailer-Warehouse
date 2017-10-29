//
//  Fetcher.cpp
//  Project1
//
//  Created by Vincent Bett on 10/10/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <stdio.h>
#include "Fetcher.h"

/*
FUNCTION:
INPUT:
OUTPUT:
 */
Fetcher::Fetcher()
{

}

/*
FUNCTION:
INPUT:
OUTPUT:
 */
Fetcher::~Fetcher()
{

}

/*
FUNCTION: Fetchorder
PURPOSE: TO enque the fetcher with an order to be fetched and 
to save the time it was added to the fetcher
INPUT: None
OUTPUT: None
 */
void Fetcher::fetchOdrer(Order Tofetch, int time)
{

	Tofetch.TimeInfetch = Tofetch.fetch_duration + time;

	orders.enqueue(Tofetch);
}

/*
FUNCTION: removeOrder
PURPOSE: TO remove a fetched order
INPUT: None
OUTPUT: None
 */
void Fetcher::removeOrder()
{
	orders.dequeue();
}

/*
FUNCTION: FetchTimeRemaining
PURPOSE: to calculate the time left for front ordeer to be fetched.
INPUT: An int time
OUTPUT: None
 */
int Fetcher::FetchTimeRemaining(int time)
{
	if(isEmpty())
	{
		return 0;
	}
	Order p;
	p = orders.frontOfQueue();
	return p.TimeInfetch - time;
}

/*
FUNCTION: isempty
PURPOSE: To check if the fetcher is empty.
INPUT: None
OUTPUT: A bool
 */
bool Fetcher::isEmpty()
{
	return orders.is_empty();
}

/*
FUNCTION: FetchedOrder
PURPOSE: To return the odere at the fronf of the queue
INPUT: None
OUTPUT: A struct order
 */
Order Fetcher::FetchedOrder()
{
	return orders.frontOfQueue();
}
