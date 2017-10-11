#include"Global.h"


void ClearMemory()
{
    Ticket*p1;
     for (std::vector<Ticket *>::iterator i = ticket_vec.begin(); i != ticket_vec.end(); ++i)
    {
        p1=(*i);
        delete p1;
    }
    ticket_vec.clear();

    Vehicle*p2;
     for (std::vector<Vehicle *>::iterator i = vehicle_vec.begin(); i != vehicle_vec.end(); ++i)
    {
        p2=(*i);
        delete p2;
    }
    vehicle_vec.clear();

    Driver*p3;
     for (std::vector<Driver *>::iterator i = driver_vec.begin(); i != driver_vec.end(); ++i)
    {
        p3=(*i);
        delete p3;
    }
    driver_vec.clear();

    used_num.clear();
    return;
}

void ResetSystem()
{
  cout<<"Resetting system will erase current database, are you sure you want to reset?"<<endl;
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

  ClearMemory();
  SaveDatabase();
  cout<<"==================================================================="<<endl;
  cout<<"System has been successfully reset!"<<endl;
}

string capitalizer(string input)
{
    for (int i=0; i<input.length(); i++)
        input[i]=toupper(input[i]);

    return input;
}


bool checkifused(string input)
{
  if(used_num.find(input)==used_num.end())
    {
      used_num.insert(input);
      return false; //not found
    }
  else
    return true; //found
}
