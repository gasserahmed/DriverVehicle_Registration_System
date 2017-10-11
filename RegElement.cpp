#include "Global.h"

void RegDriver()
{
    string name;
    string ID;
    string liceNum;
    cout<<"Please enter the Driver's name: ";
    cin>>name;
    name=capitalizer(name);
    cout<<"Please enter the Driver's ID [14 numerics long]: ";
    cin>>ID;
    while(ID.length()!=14 || checkifused(ID))
      {
        cout<<"Invalid length or ID used before, please re-enter: ";
        cin>>ID;
      }

    liceNum=RandomGenerator(1,0);

    Driver*d_ptr=new Driver(name,ID,liceNum);

    driver_vec.push_back(d_ptr);

    d_ptr->displayInfo();

    d_ptr=NULL;

    cout<<"New driver has been succesfully registered!"<<endl;
}

void RegVehicle()
{
  if(driver_vec.empty())
    {
      cout<<"Please register atleast one driver first, returning to main menu...."<<endl;
      return;
    }

Vehicle*v_ptr=NULL;
Driver *d_ptr=NULL;
string licePltNum;
string VIN;
string color;
string year;
string brand;

d_ptr=SearchDriver();

while(d_ptr==NULL)
{
    cout<<"Search again or return to main menu?"<<endl;
    cout<<"-Search\t1"<<endl;
    cout<<"-Return\t2"<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Your Choice: ";
    cin>>cmd;
    cout<<"==================================================================="<<endl;
    while(cmd!=1 && cmd!=2)
    {
     cout<<"Invalid command, please re-enter[1-2]: ";
     cin>>cmd;
     cout<<"==================================================================="<<endl;
    }
    if(cmd==2)
        return;
    d_ptr=SearchDriver();
}
cout<<"==================================================================="<<endl;
cout<<"Please choose the type of vehicle"<<endl;
cout<<"-Public Vehicle\t\t1"<<endl;
cout<<"-Governmental Vehicle\t2"<<endl;
cout<<"-Private Vehicle\t3"<<endl;
cout<<"==================================================================="<<endl;
cout<<"Your Choice: ";
cin>>cmd;
cout<<"==================================================================="<<endl;

while(cmd<1 || cmd>3)
{
 cout<<"Invalid command, please re-enter[1-3]: ";
 cin>>cmd;
 cout<<"==================================================================="<<endl;
}

cout<<"Please Enter the VIN [17 alphanumerics long]: ";
cin>>VIN;
while(VIN.length()!=17 || checkifused(VIN))
  {
    cout<<"Invalid length or VIN used before, please re-enter: ";
    cin>>VIN;
  }
VIN=capitalizer(VIN);
cout<<"==================================================================="<<endl;
cout<<"Please enter the vehicle's brand: ";
cin>>brand;
brand=capitalizer(brand);
cout<<"Please Enter the vehicle's year model [4 numerics long]: ";
cin>>year;
while(year.length()!=4)
  {
    cout<<"Invalid length, please re-enter: ";
    cin>>year;
  }

if(cmd==3)
{
    cout<<"Please enter the vehicle's color: ";
    cin>>color;
    color=capitalizer(color);
}

licePltNum=RandomGenerator(2,cmd);

switch(cmd)
{
case 1:
    v_ptr=new Public(d_ptr,licePltNum,year,VIN,brand);
    break;
case 2:
    v_ptr=new Governmental(d_ptr,licePltNum,year,VIN,brand);
    break;
case 3:
    v_ptr=new Private(d_ptr,licePltNum,year,VIN,brand,color);
    break;
}

vehicle_vec.push_back(v_ptr);

++(*d_ptr);

d_ptr->displayInfo();
v_ptr->displayInfo();

d_ptr=NULL;
v_ptr=NULL;

cout<<"Vehicle has been successfully registered!"<<endl;

return;
}

void AddTicket()
{
  if(vehicle_vec.empty())
    {
      cout<<"Please register atleast one vehicle first, returning to main menu...."<<endl;
      return;
    }

Vehicle*v_ptr=NULL;
Ticket*t_ptr=NULL;
string serialNumber;
char buffer[8];
time_t rawtime;
struct tm * timeinfo;

time (&rawtime);
timeinfo = localtime (&rawtime);

strftime(buffer,9,"%d/%m/%y",timeinfo);
string dateOfIssue(buffer);

v_ptr=SearchVehicle();

while(v_ptr==NULL)
{
    cout<<"==================================================================="<<endl;
    cout<<"Search again or return to main menu?"<<endl;
    cout<<"-Search\t1"<<endl;
    cout<<"-Return\t2"<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Your Choice: ";
    cin>>cmd;
    cout<<"==================================================================="<<endl;
    while(cmd!=1 && cmd!=2)
    {
     cout<<"Invalid command, please re-enter[1-2]"<<endl;
     cin>>cmd;
    }
    if(cmd==2)
          return;
    v_ptr=SearchVehicle();
}
cout<<"==================================================================="<<endl;
cout<<"Please choose type of ticket"<<endl;
cout<<"-Illegal Parking Ticket\t\t1"<<endl;
cout<<"-Speeding Ticket\t\t2"<<endl;
cout<<"-Cutting Traffic Ticket\t\t3"<<endl;
cout<<"==================================================================="<<endl;
cout<<"Your Choice: ";
cin>>cmd;
cout<<"==================================================================="<<endl;

while(cmd<1 || cmd>3)
{
 cout<<"Invalid command, please re-enter[1-3]: ";
 cin>>cmd;
}

serialNumber=RandomGenerator(3,cmd);

switch(cmd)
{
case 1:
    t_ptr=new IllegalParkingTicket(dateOfIssue,v_ptr,serialNumber);
    break;
case 2:
    t_ptr=new SpeedingTicket(dateOfIssue,v_ptr,serialNumber);
    break;
case 3:
    t_ptr=new CuttingTrafficTicket(dateOfIssue,v_ptr,serialNumber);
    break;
}

ticket_vec.push_back(t_ptr);

++(*v_ptr);

v_ptr->displayInfo();
t_ptr->displayInfo();

v_ptr=NULL;
t_ptr=NULL;

cout<<"Ticket has been successfully added to vehicle!"<<endl;

return;
}
