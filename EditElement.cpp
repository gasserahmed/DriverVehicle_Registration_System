#include "Global.h"
void EditDriver()
{
  if(driver_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }

    string str;

    Driver *d_ptr=NULL;

    do
    {
        d_ptr=SearchDriver();
        if(d_ptr==NULL)
        {
            cout<<"Search again or return to main menu?"<<endl;
            cout<<"Search\t1"<<endl;
            cout<<"Return\t2"<<endl;
            cin>>cmd;
                 while(cmd!=1 && cmd!=2)
                 {
                     cout<<"Invalid command, please re-enter[1-2]"<<endl;
                     cin>>cmd;
                 }
            if(cmd==2)
                return;
        }
    }
    while(d_ptr==NULL);

    d_ptr->displayInfo();

    do
        {
         cout<<"==================================================================="<<endl;
         cout<<"-Edit driver's Name\t1"<<endl;
         cout<<"-Edit driver's ID\t2"<<endl;
         cout<<"-Edit driver's status\t3"<<endl;
         cout<<"-Return to main menu\t4"<<endl;
         cout<<"==================================================================="<<endl;
            do
            {
                cout<<"Your choice: ";
                cin>>cmd;
                cout<<"==================================================================="<<endl;
                if(cmd==1)
                {
                    cout<<"\nDriver's current name: "<<d_ptr->getName()<<endl;
                    cout<<"\nPlease enter driver's new name: ";
                    cin>>str;
                    str=capitalizer(str);
                    d_ptr->editName(str);
                    cout<<"==================================================================="<<endl;
                }
                else if(cmd==2)
                {
                    cout<<"\nDriver's current ID: "<<d_ptr->getID()<<endl;
                    cout<<"\nPlease enter driver's new ID [14 numerics long]: ";
                    cin>>str;
                    while(str.length()!=14 || checkifused(str))
                      {
                        cout<<"Invalid length or ID used before, please re-enter: ";
                        cin>>str;
                        cout<<"==================================================================="<<endl;
                      }
                    d_ptr->editID(str);
                }
                else if(cmd==3)
                {
                 if(d_ptr->getStatus())
                    {
                     cout<<"Driver's current status: Active"<<endl;
                     cout<<"Mark Driver as inactive?"<<endl;
                     cout<<"-Yes\t1"<<endl;
                     cout<<"-No\t2"<<endl;
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
                          if(cmd==1)
                            {
                            d_ptr->editStatus(false);
                            cout<<"Driver has been succesfully marked as inactive!"<<endl;
                            }
                    }
                   else
                    {
                     cout<<"Driver's current status: Inactive"<<endl;
                     cout<<"Mark Driver as active?"<<endl;
                     cout<<"-Yes\t1"<<endl;
                     cout<<"-No\t2"<<endl;
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
                          if(cmd==1)
                            {
                            d_ptr->editStatus(true);
                            cout<<"Driver has been succesfully marked as active!"<<endl;
                            }
                    }

                }
                else if(cmd==4)
                  {
                    cout<<"==================================================================="<<endl;
                    cout<<"Returning to main menu..."<<endl;
                  return;
                  }
                else
                {
                  cout<<"Invalid command, please re-enter[1-3]: ";
                }
            }
            while(cmd<1 || cmd>4);
        }
        while(true);

}





void EditVehicle()
{
  if(vehicle_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }


    Vehicle*v_ptr=NULL;
    Driver *d_ptr=NULL;
    Driver *d_temp=NULL;
    string VIN;
    string brand;
    string year;
    string color;


  v_ptr=SearchVehicle();

  while(v_ptr==NULL)
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
      v_ptr=SearchVehicle();
  }
  v_ptr->displayInfo();

  while(true)
  {
      cout<<"==================================================================="<<endl;
      cout<<"-Edit VIN\t\t\t1"<<endl;
      cout<<"-Edit vehicle's owner\t\t2"<<endl;
      cout<<"-Edit vehicle's brand\t\t3"<<endl;
      cout<<"-Edit vehicle's year model\t4"<<endl;
      cout<<"-Edit vehicle's status\t\t5"<<endl;
      cout<<"-Edit vehicle's color\t\t6"<<endl;
      cout<<"-Return to main menu\t\t7"<<endl;
      cout<<"==================================================================="<<endl;
      cout<<"Your Choice: ";
      cin>>cmd;
      cout<<"==================================================================="<<endl;
      while(cmd<1 || cmd>7)
      {
          cout<<"Invalid command, please re-enter[1-2]: ";
          cin>>cmd;
          cout<<"==================================================================="<<endl;
      }

      switch(cmd)
      {
          case 1:
          cout<<"Vehicle's current VIN: "<<v_ptr->getVIN()<<endl;
          cout<<"Enter vehicle's new VIN [17 alphanumerics long]: ";
          cin>>VIN;
          cout<<"==================================================================="<<endl;
          while(VIN.length()!=17 || checkifused(VIN))
            {
              cout<<"Invalid length or VIN used before, please re-enter: ";
              cin>>VIN;
            }
          VIN=capitalizer(VIN);
          v_ptr->editVIN(VIN);
          cout<<"==================================================================="<<endl;
          cout<<"Vehicle's VIN has been successfully changed!"<<endl;
          break;

          case 2:
          d_ptr=v_ptr->getDriver();
          cout<<"Vehicle's current owner's information: "<<endl;
          d_ptr->displayInfo();
          d_temp=d_ptr;
          d_ptr=SearchDriver();
          while(d_ptr==NULL)
          {
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
                    break;
              d_ptr=SearchDriver();
          }
          --(*d_temp);
          ++(*d_ptr);
          v_ptr->editDriver(d_ptr);

          d_ptr->displayInfo();
          cout<<"Vehicle ownership has been successfully changed!";
          break;

          case 3:
          cout<<"==================================================================="<<endl;
          cout<<"Vehicle's current brand: "<<v_ptr->getBrand()<<endl;
          cout<<"Enter vehicle's new brand: ";
          cin>>brand;
          brand=capitalizer(brand);
          v_ptr->editBrand(brand);
          cout<<"==================================================================="<<endl;
          cout<<"Vehicle's brand has been successfully changed!";
          break;

          case 4:
          cout<<"Vehicle's current year model: "<<v_ptr->getYear()<<endl;
          cout<<"Enter Vehicle's new year model [4 numerics long]: ";
          cin>>year;
          while(year.length()!=4)
            {
              cout<<"Invalid length, please re-enter: ";
              cin>>year;
            }
          v_ptr->editYear(year);
          cout<<"==================================================================="<<endl;
          cout<<"Vehicle's year model has been successfully changed!";
          break;

          case 5:
          cout<<"Vehicle's current status= "<<v_ptr->getStatus()<<endl;
          if(v_ptr->getStatus())
            {
              cout<<"Mark vehicle as out of use?"<<endl;
              cout<<"-Yes\t1"<<endl;
              cout<<"-No\t2"<<endl;
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
                   if(cmd==1)
                     {
                     v_ptr->editStatus(false);
                     cout<<"==================================================================="<<endl;
                     cout<<"Vehicle has been succesfully marked as out of use!"<<endl;
                     }
                   else
                     break;
            }
          else
            {
              cout<<"Mark vehicle as in use?"<<endl;
              cout<<"-Yes\t1"<<endl;
              cout<<"-No\t2"<<endl;
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
                   if(cmd==1)
                     {
                     v_ptr->editStatus(true);
                     cout<<"==================================================================="<<endl;
                     cout<<"Vehicle has been succesfully marked as out of use!"<<endl;
                     }
                   else
                     break;
            }
          break;


          case 6:
          cout<<"Vehicle's current color: ";
          if((v_ptr->getColor()).empty())
          {
              cout<<"==================================================================="<<endl;
              cout<<"Default"<<endl;
              cout<<"Sorry, this vehicle's color can't be edited"<<endl;
              break;
          }
          else
          {
              cout<<v_ptr->getColor()<<endl;
              cout<<"Enter vehicle's new color: ";
              cin>>color;
              color=capitalizer(color);
              v_ptr->editColor(color);
              cout<<"==================================================================="<<endl;
              cout<<"Vehicle's color has been successfully changed!"<<endl;
          }
          break;

          case 7:
          cout<<"Returning to main menu..."<<endl;
          return;
        }
  }
  return;
}








void EditTicket()
{
  if(ticket_vec.empty())
    {
      cout<<"Database is empty! Returning to main menu..."<<endl;
      return;
    }

  Ticket*t_ptr=NULL;
  Vehicle*v_ptr=NULL;

  t_ptr=SearchTicket();
  while(t_ptr==NULL)
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
      t_ptr=SearchTicket();
  }

  t_ptr->displayInfo();
  v_ptr=t_ptr->getVehicle();

  if(t_ptr->getStatus())
    {
    cout<<"Current Ticket is still outstanding, mark as paid?"<<endl;
    cout<<"-Yes\t1"<<endl;
    cout<<"-No\t2"<<endl;
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
    if(cmd==1)
      {
      t_ptr->editStatus();
      --(*v_ptr);
      cout<<"Ticket has been successfully mark as paid!"<<endl;
      }
    }
  else
    cout<<"Ticket already paid!"<<endl;

  return;
}




