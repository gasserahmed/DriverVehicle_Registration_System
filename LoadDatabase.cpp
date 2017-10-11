#include "Global.h"

void LoadDatabase()
{
vector<Driver*>::iterator it_d;
vector<Vehicle*>::iterator it_v;
set<string>::iterator it_u;

Driver*d_ptr=NULL;
Vehicle*v_ptr=NULL;
Ticket*t_ptr=NULL;

ifstream FILE_D("Driver.txt");
ifstream FILE_V("Vehicle.txt");
ifstream FILE_T("Ticket.txt");
ifstream FILE_U("Used.txt");

string name,ID,liceNum,statusStr;
string licePltNum,brand,VIN,year,type,color;
string serialNum,dateOfIssue;
string numOfVehiclesStr,numOfTicketsStr;
string used;
int numOfVehicles,numOfTickets;
bool status;

stringstream convert;

char c;



while(true)
  {
    c=FILE_D.get();
    if(c==EOF)
      {
        FILE_D.unget();
        break;
      }
    else
      FILE_D.unget();

    getline(FILE_D,name,';');
    getline(FILE_D,ID,';');
    getline(FILE_D,liceNum,';');
    getline(FILE_D,statusStr,';');
    if(statusStr=="true")
      status=true;
    else
      status=false;
    getline(FILE_D,numOfVehiclesStr,'\n');

    convert<<numOfVehiclesStr;
    convert>>numOfVehicles;
    convert.clear();

    d_ptr=new Driver(name,ID,liceNum,status,numOfVehicles);
    driver_vec.push_back(d_ptr);
    d_ptr=NULL;

  }


while(true)
  {
    c=FILE_V.get();
    if(c==EOF)
      {
        FILE_V.unget();
        break;
      }
    else
      FILE_V.unget();

    getline(FILE_V,licePltNum,';');
    getline(FILE_V,brand,';');
    getline(FILE_V,VIN,';');
    getline(FILE_V,year,';');
    getline(FILE_V,type,';');
    getline(FILE_V,color,';');
    getline(FILE_V,statusStr,';');
    if(statusStr=="true")
      status=true;
    else
      status=false;

    getline(FILE_V,numOfTicketsStr,';');
    convert<<numOfTicketsStr;
    convert>>numOfTickets;
    convert.clear();
    getline(FILE_V,liceNum,'\n');

    for (it_d = driver_vec.begin(); it_d != driver_vec.end(); ++it_d)
    {
    if((*it_d)->getLiceNum()==liceNum)
      d_ptr=(*it_d);
    }

    if(type=="PUBLIC")
      {
        v_ptr=new Public(d_ptr,licePltNum,year,VIN,brand,status,numOfTickets);
      }
    else if(type=="GOVERNMENTAL")
      {
        v_ptr=new Governmental(d_ptr,licePltNum,year,VIN,brand,status,numOfTickets);
      }
    else if(type=="PRIVATE")
      {
        v_ptr=new Private(d_ptr,licePltNum,year,VIN,brand,color,status,numOfTickets);
      }

    vehicle_vec.push_back(v_ptr);
    d_ptr=NULL;
    v_ptr=NULL;

}


while(true)
  {
    c=FILE_T.get();
    if(c==EOF)
      {
        FILE_T.unget();
        break;
      }
    else
      FILE_T.unget();

    getline(FILE_T,serialNum,';');
    getline(FILE_T,dateOfIssue,';');
    getline(FILE_T,type,';');
    getline(FILE_T,color,';');
    getline(FILE_T,statusStr,';');
    if(statusStr=="true")
      status=true;
    else
      status=false;
    getline(FILE_T,licePltNum,'\n');

    for (it_v = vehicle_vec.begin(); it_v != vehicle_vec.end(); ++it_v)
    {
    if((*it_v)->getLicePltNum()==licePltNum)
      v_ptr=(*it_v);
    }

    if(type=="ILLEGAL PARKING")
      {
        t_ptr=new IllegalParkingTicket(dateOfIssue,v_ptr,serialNum);
      }
    else if(type=="SPEEDING")
      {
        t_ptr=new SpeedingTicket(dateOfIssue,v_ptr,serialNum);
      }
    else if(type=="CUTTING TRAFFIC")
      {
        t_ptr=new CuttingTrafficTicket(dateOfIssue,v_ptr,serialNum);
      }

    ticket_vec.push_back(t_ptr);
    v_ptr=NULL;
    t_ptr=NULL;

}

while(true)
  {
    c=FILE_U.get();
    if(c==EOF)
      {
        FILE_U.unget();
        break;
      }
    else
      FILE_U.unget();

    getline(FILE_U,used,'\n');
    used_num.insert(used);
  }

FILE_D.close();
FILE_V.close();
FILE_T.close();
FILE_U.close();

return;
}

