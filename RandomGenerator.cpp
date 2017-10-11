#include"Global.h"

string RandomGenerator(int mode, int type)
{
  char numerics[]="0123456789";
  char alphas[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char alphanumerics[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string target;


  srand(time(NULL));

  switch(mode)
  {
      case 1:
      do
      for(int i=0;i<10;i++)
        {
          target.append(1,numerics[rand()%10]);
        }
      while(checkifused(target));
      break;

      case 2:
      if(type==1)
        target="PUB";
      if(type==2)
        target="GOV";
      if(type==3)
        target="PVT";
      do
        {
      for(int i=3;i<6;i++)
        {
          target.append(1,numerics[(rand()%10)]);
        }
      for(int i=6;i<9;i++)
        {
          target.append(1,alphas[(rand()%26)]);
        }
        }
      while(checkifused(target));
      break;

      case 3:
      if(type==1)
        target="I-";
      if(type==2)
        target="S-";
      if(type==3)
        target="C-";
      do
      for(int i=2;i<8;i++)
        {
          target.append(1,alphanumerics[(rand()%36)]);
        }
      while(checkifused(target));
      break;
    }
  return target;
}

