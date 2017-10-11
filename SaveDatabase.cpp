#include "Global.h"

void SaveDatabase()
{
vector<Driver*>::iterator it_d;
vector<Vehicle*>::iterator it_v;
vector<Ticket*>::iterator it_t;
set<string>::iterator it_u;

ofstream FILE_D("Driver.txt");
ofstream FILE_V("Vehicle.txt");
ofstream FILE_T("Ticket.txt");
ofstream FILE_U("Used.txt");


for(it_t = ticket_vec.begin(); it_t != ticket_vec.end(); ++it_t)
{
  FILE_T<<(*it_t)->getSerialNum()<<";";
  FILE_T<<(*it_t)->getDateOfIssue()<<";";
  FILE_T<<(*it_t)->getType()<<";";
    if((*it_t)->getStatus())
    FILE_T<<"true"<<";";
  else
    FILE_T<<"false"<<";";
    FILE_T<<((*it_t)->getVehicle())->getLicePltNum()<<endl;
}

for(it_v = vehicle_vec.begin(); it_v != vehicle_vec.end(); ++it_v)
{
  FILE_V<<(*it_v)->getLicePltNum()<<";";
  FILE_V<<(*it_v)->getBrand()<<";";
  FILE_V<<(*it_v)->getVIN()<<";";
  FILE_V<<(*it_v)->getYear()<<";";
  FILE_V<<(*it_v)->getType()<<";";
  if((*it_v)->getColor().empty())
    FILE_V<<"EMPTY"<<";";
  else
    FILE_V<<(*it_v)->getColor()<<";";
  if((*it_v)->getStatus())
    FILE_V<<"true"<<";";
  else
    FILE_V<<"false"<<";";
  FILE_V<<(*it_v)->getNumOfTickets()<<";";
  FILE_V<<((*it_v)->getDriver())->getLiceNum()<<endl;
}

for(it_d = driver_vec.begin(); it_d != driver_vec.end(); ++it_d)
{
  FILE_D<<(*it_d)->getName()<<";";
  FILE_D<<(*it_d)->getID()<<";";
  FILE_D<<(*it_d)->getLiceNum()<<";";
  if((*it_d)->getStatus())
    FILE_D<<"true"<<";";
  else
    FILE_D<<"false"<<";";
  FILE_D<<(*it_d)->getNumOfVehicles()<<endl;
}

for(it_u = used_num.begin(); it_u != used_num.end(); ++it_u)
  {
    FILE_U<<(*it_u)<<endl;
  }

FILE_T.close();
FILE_V.close();
FILE_D.close();
FILE_U.close();
return;
}
