#define _CRT_SECURE_NO_WARNINGS
#define  MAX_CHAR_LENGTH 100

#include <iostream>
#include "MenuOptions.h"
#include "Elections.h"
#include "BallotBox.h"

using namespace std;

void PrintMenu(Elections& elections);

void RunMenu(Elections& elections);


Civilian* AddNewCivilian(Elections& elections);

void MenuAddBallotBox(Elections& elections);
/*

void MenuAddParty(Elections elections);
void MenuAddCandidate(Elections elections);
*/



void EndMenu(Elections& elections);


int main()
{
	Date ElectionsDate;
	ElectionsDate.SetDate(1, 1, 2020);
	Elections newElections;
	newElections.Initialize(ElectionsDate);
	RunMenu(newElections);
	EndMenu(newElections);
}


void PrintMenu(Elections& elections)
{
	if (!elections.IsElectionsOccured())
	{
		cout << "**** Elections  Will take place at ";
		elections.GetElectionsDate().Show();
		cout << "**** \n";
		cout << "Please enter a number to select from the menu: \n";
		cout << "1 - Add New Ballot Box \n";
		cout << "2 - Add New Citizen \n";
		cout << "3 - Add New Party \n";
		cout << "4 - Add New Candidate \n";
		cout << "5 - Show All Ballot boxes \n";
		cout << "6 - Show All Citizens \n";
		cout << "7 - Show All Parties \n";
		cout << "8 - Elections - Perform Elections  \n";
		cout << "9 - Show Elections Results \n";
		cout << "10 - Exit \n";
		cout << "****Please Note: After Choosing to run Elections you can only - Add votes  or Show final results \n ";
	}
	else
	{
		cout << "****Elections Completed at: ";
		elections.GetElectionsDate().Show();
		cout << "*****\n";

		cout << "5 - Show All Ballot boxes \n";
		cout << "6 - Show All Citizens \n";
		cout << "7 - Show All Parties \n";

		cout << "9 - Show Elections Results \n";
		cout << "10 - Exit \n";
		cout << "****Please Note: Elections Completed, t \n ";
	}
}

void RunMenu(Elections& elections)
{
	int UserInput;


	while (true)
	{
		
		PrintMenu(elections);
		cin >> UserInput;
		getchar();
		system("CLS");
		switch (UserInput)
		{
		case (AddBallotBox):
			{
				MenuAddBallotBox(elections);
				break;
			}
				case (AddCitizen):
					{
					elections.AddCivilian(AddNewCivilian(elections));
						break;
					}
					/*	case (AddParty):
					{
						MenuAddParty(elections);
						break;
					}
				case (AddCandidate):
					{
						MenuAddCandidate(elections);
						break;
					}
					*/
		case (ShowAllBallotBoxes):
			{
			elections.ShowAllBallotBoxes();
				break;
			}
		case (ShowAllCivilians):
			{
				elections.ShowAllCivilians();
				break;
			}
		case (ShowAllParties):
			{
				elections.ShowAllParties();
				break;
			}
			/*case(RunElections):
				{
					//elections.Run
					break;
				}
			case (ShowElectionsResults):
				{
					elections.ShowResults();
					break;
			}*/
		case (Exit):
			{
				return;
			}
		default:
			{
				cout << "Please Enter your Selection Again: ";
			}
		}
		
	}
}


char* GetString()
{
	char string[MAX_CHAR_LENGTH];
	cin.getline(string, sizeof string);

	char* newString = new char[strlen(string) + 1];
	strcpy(newString, string);

	return newString;
}

void MenuAddBallotBox(Elections& elections)
{
	cout << "*** New Ballot Box *** \n";
	Address ballotAddress;
	BallotBox* newBallotBox = new BallotBox;
	unsigned int houseNum;

	const int ballotBoxId = elections.GetBallotBoxes().GetCount() + 1;

	cout << "please enter Ballet Box city: \n";
	char* city = GetString();
	cout << "please enter Ballet Box street: \n";
	char* street = GetString();
	cout << "please enter Ballet Box House Number: \n";

	cin >> houseNum;

	ballotAddress.Initialize(city, street, houseNum);
	newBallotBox->Initialize(ballotBoxId, ballotAddress);
	elections.AddBallotBox(newBallotBox);
}


BallotBox * SelectBallotBox (Elections& elections)
{
	int ballotId;
	BallotBox* selectedBallotBox; 
	cout << "Available Ballot Boxes: "<< endl;
	elections.ShowAllBallotBoxes();
	cout << "Please select Ballot Box by entering the Ballot box ID:";
	cin >> ballotId;
	selectedBallotBox = &(elections.GetBallotBoxes().Get(ballotId -= 1));
	return selectedBallotBox;
}

Civilian* AddNewCivilian(Elections& elections)
{
	Civilian* newCivilian = new Civilian;
	char* civilianName;
	int id;
	unsigned int year;
	Date Birthdate;
	
	cout << "*** Enter New Civilian ****"<< endl;
	cout << "Enter name: ";
	civilianName = GetString();
	cout << "Enter Civilian ID: ";
	cin >> id;
	cout << "Enter Civilian Birth Year: ";
	cin >> year;
	
	
	Birthdate.SetDate(year);
	newCivilian->Initialize(civilianName, id, Birthdate, SelectBallotBox(elections));
	
	return newCivilian;
	
}



void EndMenu(Elections& elections)
{
}
