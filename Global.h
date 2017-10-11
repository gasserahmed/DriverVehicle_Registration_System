#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include "Driver.h"
#include "Vehicle.h"
#include "Ticket.h"

using namespace std;

//Helper Global Variables//
extern int cmd;

//Main Data Structures//
extern vector<Driver*> driver_vec;
extern vector<Vehicle*> vehicle_vec;
extern vector<Ticket*> ticket_vec;
extern set<string> used_num;

//Main Functions//
void RegDriver();
void EditDriver();
void RegVehicle();
void EditVehicle();
void AddTicket();
void EditTicket();
void DisplayDriver();
void DisplayVehicle();
void DisplayTicket();
void ResetSystem();

//Helper Functions//
Ticket * SearchTicket();
Driver * SearchDriver();
Vehicle * SearchVehicle();
void LoadDatabase();
void SaveDatabase();
void ClearMemory();

void*SearchVehicle(Driver *input);
void*SearchTicket(Vehicle *input);
void ClearMemory();

string RandomGenerator(int mode, int type);
bool checkifused(string input);
string capitalizer(string input);
void MENU();

#endif // GLOBAL_H
