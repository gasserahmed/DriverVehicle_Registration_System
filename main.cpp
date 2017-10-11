#include "Global.h"

//Helper Global Variables//
int cmd;

//Main Data Structures//
vector<Driver*> driver_vec;
vector<Vehicle*> vehicle_vec;
vector<Ticket*> ticket_vec;
set<string> used_num;

int main()
{
  cout <<"\n\t\t     Driver and Vehicle Registration System" << endl;
  driver_vec.clear();
  vehicle_vec.clear();
  ticket_vec.clear();
  LoadDatabase();
  MENU();
  SaveDatabase();
  ClearMemory();

  return 0;
}

void MENU()
{
  cout<<"--------------------------------------------------------------------------------\n"<<endl;
  cout<<"\t\t\t\t  MAIN MENU\n\n"<<endl;
  cout<<"\t\t  Please choose a command:[1-11]"<<endl;
  cout<<"\t\t  =========================================="<<endl;
  cout<<"\t\t  -Register a new driver\t\t1"<<endl;
  cout<<"\t\t  -Edit an existing driver\t\t2"<<endl;
  cout<<"\t\t  -Register a new vehicle\t\t3"<<endl;
  cout<<"\t\t  -Edit an existing vehicle\t\t4"<<endl;
  cout<<"\t\t  -Add ticket to vehicle\t\t5"<<endl;
  cout<<"\t\t  -Clear ticket on vehicle\t\t6"<<endl;
  cout<<"\t\t  -Display a driver's information\t7"<<endl;
  cout<<"\t\t  -Display a vehicle's information\t8"<<endl;
  cout<<"\t\t  -Display a ticket's information\t9"<<endl;
  cout<<"\t\t  -Reset system\t\t\t\t10"<<endl;
  cout<<"\t\t  -Quit system\t\t\t\t11"<<endl;
  cout<<"\t\t  =========================================="<<endl;
  cout<<"\t\t  Your Choice: ";
  cin>>cmd;
  cout<<"================================================================================"<<endl;

  while(cmd<1 || cmd>11)
  {
      cout<<"Invalid command, please re-enter[1-10]"<<endl;
      cin>>cmd;
  }

  switch(cmd)
  {
  case 1:
      RegDriver();
      break;
  case 2:
      EditDriver();
      break;
  case 3:
      RegVehicle();
      break;
  case 4:
      EditVehicle();
      break;
  case 5:
      AddTicket();
      break;
  case 6:
      EditTicket();
      break;
  case 7:
      DisplayDriver();
      break;
  case 8:
      DisplayVehicle();
      break;
  case 9:
      DisplayTicket();
      break;
  case 10:
      ResetSystem();
      break;
  case 11:
        cout<<"\t\t\tThe Program has been closed"<<endl;
        cout<<"================================================================================"<<endl;
        return;
  }
  return MENU();
}
