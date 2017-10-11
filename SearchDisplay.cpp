#include "Global.h"

Ticket*SearchTicket()
{
    Ticket*p1;
    string input;
    cout<<"Please Enter the ticket's serial number: ";
    cin>>input;
    input=capitalizer(input);
    for (std::vector<Ticket *>::iterator i = ticket_vec.begin(); i != ticket_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getSerialNum()==input)
        return p1;
    }
    cout<<"==================================================================="<<endl;
   cout<<"Search returned no results!"<<endl;
   return NULL;
}

Vehicle*SearchVehicle()
{
    Vehicle*p1;
    string input;
    int mode;
    cout<<"-Search by vehicle's license plate number \t1"<<endl;
    cout<<"-Search by VIN \t\t\t\t\t2"<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Your Choice: ";
    cin>>mode;
    cout<<"==================================================================="<<endl;
    while(mode!=1 && mode!=2)
    {
        cout<<"Invalid command, please re-enter[1-2]: ";
        cin>>mode;
    }


     if(mode==1)
    {
         cout<<"Please enter vehicle's license plate number: ";
         cin>>input;
         input=capitalizer(input);

      for (std::vector<Vehicle *>::iterator i = vehicle_vec.begin(); i != vehicle_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getLicePltNum()==input)
        return p1;
    }
      cout<<"==================================================================="<<endl;
      cout<<"Search returned no results!"<<endl;
   return NULL;
    }

  if(mode==2)
    {
      cout<<"Please enter VIN: ";
      cin>>input;
      input=capitalizer(input);
      for (std::vector<Vehicle *>::iterator i = vehicle_vec.begin(); i != vehicle_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getVIN()==input)
        return p1;
    }
      cout<<"==================================================================="<<endl;
      cout<<"Search returned no results!"<<endl;
   return NULL;
    }

}

Driver*SearchDriver()
{
    Driver *p1;
    int mode;
    string input;
    cout<<"-Search by driver's license number\t\t1"<<endl;
    cout<<"-Search by driver's ID number\t\t\t2"<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"Your Choice: ";
    cin>>mode;
    cout<<"==================================================================="<<endl;
    while(mode!=1 && mode!=2)
    {
        cout<<"Invalid command, please re-enter[1-2]"<<endl;
        cin>>mode;
    }

    if(mode==1)
    {
        cout<<"Please enter the driver's license number: ";
        cin>>input;
        input=capitalizer(input);
        for (std::vector<Driver *>::iterator i = driver_vec.begin(); i != driver_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getLiceNum()==input)
        return p1;
    }
        cout<<"==================================================================="<<endl;
        cout<<"Search returned no results!"<<endl;
    return NULL;
    }

    if(mode==2)
    {
        cout<<"Please enter the driver's ID: ";
        cin>>input;
        input=capitalizer(input);
        for (std::vector<Driver *>::iterator i = driver_vec.begin(); i != driver_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getID()==input)
        return p1;
    }
        cout<<"==================================================================="<<endl;
        cout<<"Search returned no results!"<<endl;
   return NULL;
    }
}

void DisplayTicket()
{
  if(ticket_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }

    Ticket *p1;
    p1=SearchTicket();

    while(p1==NULL)
    {
        cout<<"==================================================================="<<endl;
        cout<<"Search returned no results!"<<endl;
        cout<<"==================================================================="<<endl;
        cout<<"Search again or return to previous edit menu?"<<endl;
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
        p1=SearchTicket();
      }
    p1->displayInfo();
   (p1->getVehicle())->displayInfo();
   ((p1->getVehicle())->getDriver())->displayInfo();
}

void DisplayDriver()
{
  if(driver_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }

    Driver *p1=SearchDriver();

    while(p1==NULL)
    {
        cout<<"==================================================================="<<endl;
        cout<<"Search returned no results!"<<endl;
        cout<<"==================================================================="<<endl;
        cout<<"Search again or return to previous edit menu?"<<endl;
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
        p1=SearchDriver();
      }
    p1->displayInfo();
    SearchVehicle(p1);
}

void DisplayVehicle()
{
  if(vehicle_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }

    Vehicle *p1=SearchVehicle();

    while(p1==NULL)
    {
        cout<<"==================================================================="<<endl;
        cout<<"Search returned no results!"<<endl;
        cout<<"==================================================================="<<endl;
        cout<<"Search again or return to previous edit menu?"<<endl;
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
        p1=SearchVehicle();
      }
    p1->displayInfo();
    SearchTicket(p1);
}


void*SearchVehicle(Driver *input)
{
    Vehicle*p1;
    int flag=0;

    for (std::vector<Vehicle *>::iterator i = vehicle_vec.begin(); i != vehicle_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getDriver()==input)
        {
            flag++;
            p1->displayInfo();
            SearchTicket(p1);
        }
    }
    if(flag==0)
    {
        cout<<"==================================================================="<<endl;
        cout<<"Driver doesn't own any vehicles"<<endl;
    }
   p1=NULL;
}


void*SearchTicket(Vehicle *input)
{
    Ticket*p1;
    int flag=0;

    for (std::vector<Ticket *>::iterator i = ticket_vec.begin(); i != ticket_vec.end(); ++i)
    {
        p1=(*i);
        if(p1->getVehicle()==input)
        {
            flag++;
            p1->displayInfo();
        }
    }
    if(flag==0)
        {
   cout<<"==================================================================="<<endl;
   cout<<"Vehicle has no tickets"<<endl;
   }
}


