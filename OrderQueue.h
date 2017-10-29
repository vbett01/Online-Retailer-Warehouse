//
//  OrderQueue.h
//  Project1
//
//  Created by Vincent Bett on 10/5/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

# include "Order.h"
# include <iostream>
#ifndef OrderQueue_h
#define OrderQueue_h


struct node{
	Order arrived;
	node *next;
};

class OrderQueue
{
	public:

		// Constructor.
		OrderQueue();
		// Overloaded constructor.
		OrderQueue(Order add);
		// Destructor
		~OrderQueue();
		/*
		   Function to add a item to the back of the list.
		 */
		void enqueue(Order add);
		/*
		   Function to remove the first item from 
		   the front of the list;
		 */
		void dequeue();
		/*
		   Function to get the number of items in the queue.
		 */
		int size();

		/*
		   Function to get the item at the front of the list.
		 */
		Order frontOfQueue();

		/*
		   Function to get the back of the list.
		 */
		Order BackOfQueue();

		/*
		   Function to get the total pack time of all the
		   orders in the list.
		 */
		int totalPacktime();
		/*
		   Function to return the fetch time of the front item
		 */
		int fetchTimeFront();

		/*
		   Function to return the pack time of the front item.
		 */
		int packTimeFront();
		/*
		   Function that checks if the queue is empty.
		 */
		bool is_empty();

		/*
		 */
		int arrivaltime();

		/*
		 */
		int timeAddedToPacking();
		//
		void decrementFrontPacktime();


	private:

		node *front;

		node *back;
		// Number of orders in the queue
		int numElements;
		// Total pack time of all the elements.
		int sumPackTime;
		// Decrease the count of number of elements
		void decrease();
		// increase the count of number of elements.
		void increase();




};
#endif /* OrderQueue_h */
