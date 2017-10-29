//
//  incomingOrders.h
//  Project1
//
//  Created by Vincent Bett on 10/6/16.

/*
 Header file for incoming orders.
 This class will hold a queue that stores all the orders that have been placed.
 It will also be responsible for removing an order from the queue and sending it to
 the fetcher class. Will do that by being called from main.
*/

# include "Order.h"
# include "OrderQueue.h"
#ifndef incomingOrders_h
#define incomingOrders_h

class incomingOrders{
public:
    incomingOrders();
    ~incomingOrders();
    
    /*
     Function: addorders.
     Purpose: To take orders from input and store them in our queue implementation
     Input: A struct
     Output: None
    */
    void addorders(Order Toadd);
    
    /*
     Function: removeOrder.
     Purpose: To remove an order that has been "fetched" by fetcher.
     Input: None
     Output: None
     */
    void removeOrder();
    
    /*
     Function: topOrder
     Purpose: to return the item at the top of the queue. i.e the one that
              arrived first.
     Input: None
     Output: None
     */
    Order topOrder();
    
    /*
     Function: noOrders
     Purpose: to check if the queue is empty or not
     Input: None
     Output: A boolean
     */

    bool noOrders();
    
    /*
     Function: topOrderarrivaltime
     Purpose: To return the time the top order came in.
     Input:
     Output:
     */
    int topOrderarrivaltime();
    
    /*
     Function: topOrderFetchtime
     Purpose: To return the number of minutes it will take to fetch the top order
     Input: None
     Output: None
     */
    int topOrderFetchtime();

private:
    
    // Our queue to store orders
   // OrderQueue order;
    
   
       OrderQueue added;
    
    
};


#endif /* incomingOrders_h */
