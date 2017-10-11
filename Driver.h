#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Driver
{
private:
    string name;
    string ID;
    string liceNum;
    int numOfVehicles;
    bool status;

public:
    Driver(string name_par,string ID_par,string liceNum_par,bool status_par=true,int numOfVehicles_par=0)
    {
      name=name_par;
      ID=ID_par;
      liceNum=liceNum_par;
      status=status_par;
      numOfVehicles=numOfVehicles_par;
    }

    virtual ~Driver()
    {}

    void displayInfo()
    {
        cout<<"==================================================================="<<endl;
        cout<<"Driver's name:\t\t\t\t"<<name<<endl;
        cout<<"Driver's ID number:\t\t\t"<<ID<<endl;
        cout<<"Driver's license number:\t\t"<<liceNum<<endl;
        cout<<"Number of Vehicles owned by driver:\t"<<numOfVehicles<<endl;
        cout<<"Driver's status:\t\t\t";
        if(status==true)
              cout<<"ACTIVE"<<endl;
        else
              cout<<"INACTIVE"<<endl;
        cout<<"==================================================================="<<endl;
    }

    void editName(string name_par)
    {
      name=name_par;
    }

    void editID(string ID_par)
    {
      ID=ID_par;
    }

    void editStatus(bool choice)
    {
      status=choice;
    }

    string getName()
    {
      return name;
    }

    string getID()
    {
      return ID;
    }

    string getLiceNum()
    {
      return liceNum;
    }

    int getNumOfVehicles()
    {
      return numOfVehicles;
    }

    bool getStatus()
    {
      return status;
    }

    void operator ++()
    {
        numOfVehicles++;
    }

    void operator --()
    {
        numOfVehicles--;
    }

};

#endif // DRIVER_H
