//
//  Packer.h
//  Project1
//
//  Created by Vincent Bett on 10/6/16.
/*
   Header file for the packer class.
   Will be responsible for receiving an order and 
   removin it from the queue
   once the packing time has elapsed.
 */

#include "Order.h"
# include "OrderQueue.h"
#ifndef Packer_h
#define Packer_h
class Packer{
	public:

		// Constructor
		Packer();
		// Destructor
		~Packer();
/*
Function: addOrderTopack
Purpose: To add an order to the packing list
Input: an order to be packed
Output: None
*/
		void addOrderTopack(Order ToPack);

/*
Function: removePackagedOrder
Purpose: To remove an order from the list once we have 
finished packing it
Input: None
Output: None
*/
		void removePackagedOrder();

		bool finishedPacking(); // turns true if an 
					// item has finished 
					// packing so we
		                        // can remove it
/*
Function: timeToPackFront
Purpose: To get the time it takes to pack the front order
Input: None
Output: An int time
*/
		int timeToPackFront();

/*
Function: itemsinQueue
Purpose: To return the items waiting to be packed
Input: None
Output: an integer number of items in queue
*/
		int itemsinQueue();

/*
Function: timetopackall
Purpose: To return the amount of 
time it will take to pack all the items in queue
Input: None
Output: An int
*/
		int timeleftToPackAll();

/*
FUNCTION: isempty
PURPOSE: To check if the packer is empty
INPUT: none
OUTPUT: a boolead
*/
		bool isempty();

/*
FUNCTION: packtimeremainingFront
PURPOSE: To returnt the time remaining for the 
front order to be packed
INPUT: None
OUTPUT: An int time.
*/

		int packTimeremainingFront();

/*
FUNCTION: time added
INPUT: none.
OUTPUT:none
*/

		int timeAdded();

/*
FUNCTION: frontOrder
PURPOSE: returns the order at the front
INPUT: None
OUTPUT: A struct order
*/

		Order frontOrder();
/*
FUNCTION: decrementPacktime
PURPOSE: To reduce the time left for the 
front order to be packed
INPUT: None
OUTPUT: None
*/

		void decrementPacktime();

	private:



		int packtime; // time to pack.
			      // will increase 
			     //as orders are  added
	

		OrderQueue OrdertoPack;

};

#endif /* Packer_h */
