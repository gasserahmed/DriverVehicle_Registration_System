#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Ticket
{
protected:
    string serialNum;
    string dateOfIssue;
    bool status;
    Vehicle* v_ptr;

public:
    Ticket()
    {}

    virtual ~Ticket()
    {}

    void displayInfo()
    {
        cout<<"==================================================================="<<endl;
        cout<<"Ticket's type:\t\t\t\t"<<this->getType()<<endl;
        cout<<"Ticket's date of issue:\t\t\t"<<dateOfIssue<<endl;
        cout<<"Ticket's serial number:\t\t\t"<<serialNum<<endl;
        cout<<"Ticket's status:\t\t\t";
        if(status==true)
              cout<<"OUTSTANDING"<<endl;
        else
              cout<<"PAID"<<endl;
        cout<<"==================================================================="<<endl;
    }

     string getSerialNum()
    {
      return serialNum;
    }

     string getDateOfIssue()
    {
      return dateOfIssue;
    }

     Vehicle* getVehicle()
    {
      return v_ptr;
    }

     bool getStatus()
    {
      return status;
    }

     void editStatus()
    {
      status=false;
    }

    virtual string getType()=0;
};

class IllegalParkingTicket: public Ticket
{
public:
    IllegalParkingTicket(string dateOfIssue_par, Vehicle* v_ptr_par, string serialNum_par)
    {
        status=true;
        dateOfIssue=dateOfIssue_par;
        v_ptr=v_ptr_par;
        serialNum= serialNum_par;
    }

    virtual ~IllegalParkingTicket()
    {}

    string getType()
    {
        return "ILLEGAL PARKING";
    }
};


class SpeedingTicket: public Ticket
{
public:

    SpeedingTicket(string dateOfIssue_par, Vehicle* v_ptr_par, string serialNum_par)
    {
        status=true;
        dateOfIssue=dateOfIssue_par;
        v_ptr=v_ptr_par;
        serialNum= serialNum_par;
    }

    virtual ~SpeedingTicket()
    {}

    string getType()
    {
        return "SPEEDING";
    }
};

class CuttingTrafficTicket: public Ticket
{
public:

    CuttingTrafficTicket(string dateOfIssue_par, Vehicle* v_ptr_par, string serialNum_par)
    {
        status=true;
        dateOfIssue=dateOfIssue_par;
        v_ptr=v_ptr_par;
        serialNum= serialNum_par;
    }

    virtual ~CuttingTrafficTicket()
    {}

    string getType()
    {
        return "CUTTING TRAFFIC";
    }
};

#endif // TICKET_H
