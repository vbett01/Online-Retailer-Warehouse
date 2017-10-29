//
//  main.cpp
//  Project1
//
//  Created by Vincent Bett on 10/5/16.
//

// Include all the header files
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Fetcher.h"
#include "incomingOrders.h"
#include "OrderQueue.h"
#include "Order.h"
#include "Parser.h"
#include "Packer.h"
#include "string2int.h"
using namespace std;

// Declare the helper functions to help calculate the life of an order.
void Add2PU(Packer PU[], int Num_PUs, Order toADD, string Method, int wchPU);
void printFunction(Order toPrint, int time);
void createPackagingunits(int NUM_PackagingUnits, Packer *PU);
bool PusAllEmpty(Packer PU[], int num);
void IfDonePcking(int time, Packer PU[], int NUM_PUs, int *tottime, 
				int *elapsedTime);
void FindShortestTime(Packer PU[], int num, Order toADD);
void FindFewestItems(Packer PU[], int num, Order toAdd);
void Round_robin(Packer PU[], int num);
int trackRBN(int num, int numPUs);
void finalStats(int packaged, int minTime, int maxTime, int tottime);
int findelapsedTime(int time);

/*
   main function that initializes all the classes and runs the clock.
   It also accepts user input and determines the method to use.
 */
int main(int argc, char * argv[]) {
	if(argc < 3)
	{
		cerr<<"too few arguments"<<endl;
		return 0;
	}
	Packer *PU = NULL;
	string Filename = argv[1]; // Save filename.
	int NoPU = string2int(argv[2]); // Get number of PUS
	string Method = argv[3]; // get the method.
	PU = new Packer[NoPU]; // Create the PUs
	Parser p(Filename); // Red in the file
	incomingOrders incoming; // instance of incomingOrders
	Fetcher retriever; // instance of fetcher.
	Order parcelIncoming;
	Order Outg;
	int time = 0;
	int fetchtimeRemaining = 0;
	int wchPU = 0;
	while( not p.is_done()) // read in the orders.
	{
		Order order = p.read_order();
		incoming.addorders(order);
	}
	Order PI = incoming.topOrder();
	int initialT = PI.fetch_duration + PI.pack_duration;
	int packaged = 0;
	int tottime = 0;
	int elapsedTime;
	int minTime = 0;
	int maxtime = 0;
	// start the clock
	while(not incoming.noOrders() or not retriever.isEmpty() or 
					not PusAllEmpty(PU, NoPU))
	{
		if(time != 0)  // Get the fetchtime remainig.
		{
			fetchtimeRemaining = retriever.FetchTimeRemaining(time);
		}
		/*
		   Check if the fetcher is empty.
		   If the fetcher is empty, give it a package to send.
		 */
		if(fetchtimeRemaining == 0)
		{
			if(not retriever.isEmpty())
			{
				Outg = retriever.FetchedOrder();
				retriever.removeOrder();
				// send the order to be packaged.
				Outg.pack_time_left = Outg.pack_duration;
				Add2PU(PU, NoPU, Outg, Method, wchPU);
				packaged ++;
				if(Method == "ROUND_ROBIN")
				{
					wchPU = trackRBN(wchPU, NoPU);
				}
			}
			if(not incoming.noOrders()) // check if incoming class
			{                           // is empty
				parcelIncoming = incoming.topOrder();
				incoming.removeOrder();
				retriever.fetchOdrer(parcelIncoming, time);
			}
		}
		// Check if the PUs have finished packing.
		IfDonePcking(time, PU, NoPU, &tottime, &elapsedTime);
		if(elapsedTime < initialT)
		{
			minTime = elapsedTime;
		}
		if(elapsedTime > maxtime)
		{
			maxtime = elapsedTime;
		}
		time ++;
	}
	finalStats(packaged, minTime, maxtime,tottime);// Print the final stats
	return 0;
}

/*
FUNCTION: Add2PU
PURPOSE: TO take an order and add it to a packaging class
INPUT: An array of PUs, an int number of PUs,
a struct order, a string method and int time, an int unit
OUTPUT: None
 */
void Add2PU(Packer PU[],int Num_PUs,Order toADD,string Method,int wchPU)
{

	if(Method == "FEWEST_ITEMS")
	{
		FindFewestItems(PU, Num_PUs, toADD);
	}
	else if(Method == "SHORTEST_TIME")
	{
		FindShortestTime(PU, Num_PUs, toADD);
	}
	else if(Method == "ROUND_ROBIN")
	{
		PU[wchPU].addOrderTopack(toADD);
	}

}


/*
FUNCTION: printFunction
PURPOSE: to print the completed order
INPUT: an Order toPrint, an int time
OUTPUT: None
 */
void printFunction(Order toPrint, int time)
{
	cout<<"<Order(" <<toPrint.id<<") arrival_timestamp = ";
        cout <<toPrint.arrival_timestamp;
  	cout << " fetch_duration = "<< toPrint.fetch_duration;
        cout <<" pack_duration = ";
	cout<<toPrint.pack_duration<<" total_time = ";
	cout<<(time + 1) - toPrint.arrival_timestamp<<">"<<endl;
}


/*
FUNCTION: PUsallempty
PURPOSE: to check if the units are empty
INPUT: An array of PUs and int NUm
OUTPUT: A boolean.
 */
bool PusAllEmpty(Packer PU[], int num)
{
	int count = 0;
	for( int i = 0; i<num; i++ )
	{
		if( PU[i].isempty())
		{
			count++;
		}
	}
	if(count == num)
	{
		return true;
	} else
	{
		return false;
	}
}

/*
FUNCTION: IfDonePcking
PURPOSE: to check if a package ha been packed.
INPUT: an int time, an array PU, an int NUm_PUs a pointer to an int
OUTPUT: None
 */
void IfDonePcking(int time, Packer PU[], int NUM_PUs, int *tottime, 
                                                int *elapsedTime)
{
	int minimumTime;


	for (int i = 0; i< NUM_PUs; i++)
	{

		if(not PU[i].isempty())
		{
			// Decrement pack time front.
			PU[i].decrementPacktime();
			if( PU[i].packTimeremainingFront() == 0)
			{
				Order finished = PU[i].frontOrder();
				PU[i].removePackagedOrder();
				*tottime += time - finished.arrival_timestamp;
				minimumTime = time - finished.arrival_timestamp;
				*elapsedTime = minimumTime;
				printFunction(finished, time);

			}
		}


	}
}


/*
FUNCTION: Find shortest time
PURPOSE: to calculate the packaging unit with the shortest time
INPUT: an array PU, an int num, an int time, an order toADD
OUTPUT: None
 */
void FindShortestTime(Packer PU[], int num,  Order toADD)
{
	int *SumPerPU;
	int shortestTime;
	int PU_With_leastTime = 0;
	SumPerPU = new int[num];
	for (int i = 0; i<num; i++)
	{
		SumPerPU[i] = PU[i].timeleftToPackAll();

	}
	shortestTime = SumPerPU[0];
	for (int j = 0; j< num; j++)
	{
		if(SumPerPU[j] <= shortestTime)
		{
			PU_With_leastTime = j;
		}
	}
	PU[PU_With_leastTime].addOrderTopack(toADD);

}


/*
FUNCTION: FindFewest Items
PURPOSE: to find the PU with the fewest items
INPUT: an array of PUs and int num, an order toADD
OUTPUT:
 */
void FindFewestItems(Packer PU[], int num, Order toAdd)
{
	int *itemsPerPu; // create a pointer to an int
	int fewestItems;
	int PU_With_Fewestitems = 0;
	itemsPerPu = new int[num]; // make an array
	for (int i = 0; i<num; i++)
	{
		itemsPerPu[i] = PU[i].itemsinQueue();

	}
	fewestItems = itemsPerPu[0];
	for (int j = 0; j<= num; j++) // chack which has the fewest items
	{
		if(itemsPerPu[j] < fewestItems)
		{
			PU_With_Fewestitems = j;
		}
	}
	PU[PU_With_Fewestitems].addOrderTopack(toAdd);
}


/*
FUNCTION: trackRBN
PURPOSE: to loop through the arrays while adding an order
INPUT: an int num, an int number of PUs
OUTPUT:
 */
int trackRBN(int num, int numPUs)
{
	if(num == numPUs - 1)
		num = 0;
	else
		num ++;
	return num;

}

/*
FUNCTION: final stats
PURPOSE: toprint the mean, max and min values
INPUTS: an int packaged, an int mintime, an int max tim an int tottime
OUTPUTS: none
 */
void finalStats(int packaged, int minTime, int maxTime, int tottime)
{
	cout<< "min elapsed time "<<minTime<<" minutes"<<endl;
	cout<< "max elapsed time "<< maxTime<<" minutes"<<endl;
	cout <<"mean elased time "<< tottime/packaged<<" minutes"<<endl;
        cout<<packaged<<" orders processed"<<endl;
}



