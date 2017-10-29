//
//  Fetcher.h
//  Project1
//
//  Created by Vincent Bett on 10/6/16.

/*
   Header file for the fetcher class
   This class will be responsible for taking an order 
   from the incoming orders and 
   taking it to be packaged. it will only have one
   item in it's queue unitll the order's fetch time
   elapses. 
   It will then remove that order form the queue and fetch a new one.
 */
#include "Order.h"
#include "OrderQueue.h"
#ifndef Fetcher_h
#define Fetcher_h

class Fetcher{
	public:
		// Constructor.
		Fetcher();
		// Destructor.
		~Fetcher();
		/*
Function: fetchOrder.
Purpose: to add an item to our one item queue.
Input: an order struct
Output: None
		 */
		void fetchOdrer( Order Tofetch, int time);

		/*
Function: removeOrder
Purpose: To remove an order onnce it's fetch time has elapsed.
Input: None
Output: None
		 */
		void removeOrder();

		/*
Function: fetchTimeRemaining.
Purpose: To return the fetch time remaining.
Input: None
Output: an int time left
		 */
		int FetchTimeRemaining(int time);

		bool isEmpty();
		/*
		 */
		Order FetchedOrder();
	private:

		OrderQueue orders; // Our queue to store one order.
		/*
Function: stillFetching.
Purpose: Returns true if the fetcher is still fetching an order
Input: None
Output: None
		 */
		bool stillFetchin();


};

#endif /* Fetcher_h */
