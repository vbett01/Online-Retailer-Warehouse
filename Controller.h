//
//  Controller.hpp
//  Project1
//
//  Created by Vincent Bett on 10/7/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include <stdio.h>

#include <stdlib.h>
#include <iostream>
#include "Fetcher.h"
#include "incomingOrders.h"
#include "OrderQueue.h"
#include "Order.h"
#include "Parser.h"
#include "Packer.h"
#include "string2int.h"
using namespace std;


class controller
{
public:
    controller();
    controller(string File, string Num, string Met);
    ~controller();
    
    
    
    void printFunction(Order toPrint, int time);
    void createPackagingunits(int NUM_PackagingUnits, Packer *PU);
    bool PusAllEmpty(int num);
    void checkIfDonePacking(int time);
    void FindShortestTime( int time, Order toADD);
    void FindFewestItems( Order toAdd);
    void Round_robin( int num);
   
    void FromRetrieverToPacker( int time, int UnitTopack );
    
    void fromINcomingToretriever( int time );
    
    void addtoPackaging( Order toADD, int timeadded, int unitToPack);
    int keep_trackRoundrobin(int num);
    
    void masterClock();
    void readOrders();

private:
    Packer *PU;
    string Filename;
    int NumPackagingUNits;
    string Method;
    incomingOrders incoming; // instance of incomingOrders
    Fetcher retriever; // instance of fetcher.
    Order parcelIncoming;
    Order parcelOutg;
    int time;
    int fetchtimeRemaining;
    int UnitTopack;
    Parser p;
    
    
};

#endif /* Controller_hpp */
