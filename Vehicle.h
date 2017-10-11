#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include "Driver.h"
using namespace std;

class Vehicle
{
protected:
    string licePltNum;
    string brand;
    string VIN;
    string year;
    string color;
    Driver *d_ptr;
    int numOfTickets;
    bool status;

public:
        Vehicle()
        {}

        virtual ~Vehicle()
        {}

        void displayInfo()
        {
            cout<<"==================================================================="<<endl;
            cout<<"Vehicle's type:\t\t\t\t"<<this->getType()<<endl;
            cout<<"Vehicle's brand:\t\t\t"<<brand<<endl;
            cout<<"Vehicle's year model:\t\t\t"<<year<<endl;
            if(!color.empty())
              cout<<"Vehicle's color:\t\t\t"<<color<<endl;
            cout<<"Vehicle's plate number:\t\t\t"<<licePltNum<<endl;
            cout<<"Vehicle's VIN:\t\t\t\t"<<VIN<<endl;
            cout<<"Vehicle's status:\t\t\t";
            if(status==true)
                  cout<<"In Use"<<endl;
            else
                  cout<<"Out of Use"<<endl;
            cout<<"Outstanding tickets on vehicle:\t\t"<<numOfTickets<<endl;
            cout<<"==================================================================="<<endl;
        }

         Driver* getDriver()
        {
          return d_ptr;
        }

         string getLicePltNum()
        {
          return licePltNum;
        }

         string getVIN()
        {
          return VIN;
        }

         string getBrand()
        {
          return brand;
        }

         string getYear()
        {
          return year;
        }

         bool getStatus()
        {
          return status;
        }

         int getNumOfTickets()
        {
          return numOfTickets;
        }

         string getColor()
        {
          return color;
        }

         void editDriver(Driver*d_ptr_par)
        {
          d_ptr=d_ptr_par;
        }

         void editVIN(string VIN_par)
        {
          VIN=VIN_par;
        }

         void editBrand(string brand_par)
        {
          brand=brand_par;
        }

         void editYear(string year_par)
        {
          year=year_par;
        }

         void editStatus(bool choice)
        {
          status=choice;
        }

        virtual void editColor(string color_par)
        {}

        virtual string getType()=0;

         void operator ++()
        {
            numOfTickets++;
        }

         void operator --()
        {
            numOfTickets--;
        }

};


class Private:public Vehicle
{
public:
        Private(Driver *d_ptr_par,string licePltNum_par,string year_par,string VIN_par,string brand_par,string color_par,bool status_par=true,int numOfTickets_par=0)
        {
          d_ptr=d_ptr_par;
          licePltNum=licePltNum_par;
          year=year_par;
          VIN=VIN_par;
          brand=brand_par;
          color=color_par;
          numOfTickets=numOfTickets_par;
          status=status_par;
        }

        virtual ~Private()
        {}

    string getType()
    {
        return "PRIVATE";
    }

    void editColor(string color_par)
    {
      color=color_par;
    }
};



class Governmental:public Vehicle
{
    public:

  Governmental(Driver *d_ptr_par,string licePltNum_par,string year_par,string VIN_par,string brand_par,bool status_par=true,int numOfTickets_par=0)
  {
    d_ptr=d_ptr_par;
    licePltNum=licePltNum_par;
    year=year_par;
    VIN=VIN_par;
    brand=brand_par;
    numOfTickets=numOfTickets_par;
    status=status_par;
  }

  virtual~Governmental()
     {}

    string getType()
    {
        return "GOVERNMENTAL";
    }
};


class Public:public Vehicle
{
public:

  Public(Driver *d_ptr_par,string licePltNum_par,string year_par,string VIN_par,string brand_par,bool status_par=true,int numOfTickets_par=0)
  {
    d_ptr=d_ptr_par;
    licePltNum=licePltNum_par;
    year=year_par;
    VIN=VIN_par;
    brand=brand_par;
    numOfTickets=numOfTickets_par;
    status=status_par;
  }

  virtual~Public()
  {}

  string getType()
    {
        return "PUBLIC";
    }
};


#endif // VEHICLE_H
