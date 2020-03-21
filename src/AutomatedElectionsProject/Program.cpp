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


void MenuAddParty(Elections& elections);
void MenuAddCandidate(Elections& elections);


void EndMenu(Elections& elections);

Date CreateDate(int day, int month, int year)
{
	Date date;
	date.SetDate(day, month, year);
	return date;
}

Party* CreateParty(int id, const char* name, PoliticalStream politicalStream)
{
	Party* party = new Party;
	party->Initialize(
		id,
		name,
		politicalStream,
		CreateDate(1, 1, 1999));
	return party;
}

Civilian* CreateCivilian(const char* name, int id, BallotBox* ballotBox)
{
	Civilian* civilian = new Civilian;
	civilian->Initialize(
		name,
		id,
		CreateDate(1, 1, 1999),
		ballotBox);
	return civilian;
}

BallotBox* CreateBallotBox(int id, const char* city, const char* street, int streetNumber)
{
	BallotBox* ballotBox = new BallotBox;
	Address address;
	address.Initialize(city, street, streetNumber);
	ballotBox->Initialize(id, address);
	return ballotBox;
}

Candidate* CreateCandidate(Civilian* civilian, int rank)
{
	Candidate* candidate = new Candidate;
	candidate->Initialize(civilian, rank);
	return candidate;
}

Elections CreateElections(const Date& date)
{
	Elections elections;
	elections.Initialize(date);

	BallotBox* telAvivBallotBox = CreateBallotBox(1, "Tel Aviv", "Shimon Hatarsi", 37);
	BallotBox* herzliyaBallotBox = CreateBallotBox(2, "Herzliya", "Haalumim", 3);
	Civilian* bibi = CreateCivilian("Binyamin Netaniyahu", 1, telAvivBallotBox);
	Civilian* miriRegev = CreateCivilian("Miri Regev", 2, telAvivBallotBox);
	Civilian* gantz = CreateCivilian("Binyamin Gantz", 3, herzliyaBallotBox);
	Civilian* yairLapid = CreateCivilian("Yair Lapid", 4, herzliyaBallotBox);
	Civilian* noamKozer = CreateCivilian("Noam Kozer", 5, telAvivBallotBox);
	Civilian* ohadShemTov = CreateCivilian("Ohad Shem-Tov", 6, herzliyaBallotBox);
	Party* blueAndWhite = CreateParty(1, "Blue And White", Center);
	Party* likud = CreateParty(2, "Likud", Right);
	Party* thePirates = CreateParty(3, "The Pirates", Center);
	elections.AddBallotBox(telAvivBallotBox);
	elections.AddBallotBox(herzliyaBallotBox);
	elections.AddCivilian(bibi);
	elections.AddCivilian(miriRegev);
	elections.AddCivilian(gantz);
	elections.AddCivilian(yairLapid);
	elections.AddCivilian(noamKozer);
	elections.AddCivilian(ohadShemTov);
	elections.AddParty(blueAndWhite);
	elections.AddParty(likud);
	elections.AddParty(thePirates);
	elections.AddCandidate(CreateCandidate(bibi, 1), *likud);
	elections.AddCandidate(CreateCandidate(miriRegev, 1), *likud);
	elections.AddCandidate(CreateCandidate(gantz, 1), *blueAndWhite);
	elections.AddCandidate(CreateCandidate(yairLapid, 1), *blueAndWhite);
	elections.AddCandidate(CreateCandidate(noamKozer, 1), *thePirates);
	elections.AddCandidate(CreateCandidate(ohadShemTov, 1), *thePirates);

	return elections;
}


int main()
{
	Elections elections = CreateElections(CreateDate(1, 1, 2020));
	RunMenu(elections);
	EndMenu(elections);
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
		case (AddParty):
			{
				MenuAddParty(elections);
				break;
			}
		case (AddCandidate):
			{
				//		MenuAddCandidate(elections);
				break;
			}

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


BallotBox* SelectBallotBox(Elections& elections)
{
	int ballotId;
	const unsigned int maxBallotId = elections.GetBallotBoxes().GetCount();
	cout << "Available Ballot Boxes: " << endl;
	elections.ShowAllBallotBoxes();
	cout << "Please select Ballot Box by entering the Ballot box ID:";
	cin >> ballotId;
	while (ballotId <= 0 || (ballotId > maxBallotId))
	{
		cout << "Ballot not found, Please select Ballot Box by entering the Ballot box ID:";
		cin >> ballotId;
	}

	return &elections.GetBallotBoxes().Get(ballotId - 1);
}

Civilian* AddNewCivilian(Elections& elections)
{
	Civilian* newCivilian = new Civilian;
	int id;
	unsigned int year;
	Date birthdate;

	cout << "*** Enter New Civilian ***" << endl;
	cout << "Enter name: ";
	char* civilianName = GetString();
	cout << "Enter Id: ";
	cin >> id;
	cout << "Enter Civilian Birth Year: ";
	cin >> year;


	birthdate.SetDate(year);
	newCivilian->Initialize(
		civilianName,
		id,
		birthdate,
		SelectBallotBox(elections));

	return newCivilian;
}

PoliticalStream GetPoliticalStream()
{
	int value;
	cout << "Please choose Political stream: 0 - Left   1 - Middle   2- Right:";
	cin >> value;
	return (PoliticalStream)value;
}

Date GetDate()
{
	Date date;
	unsigned int day, month, year;
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter Month: ";
	cin >> month;
	cout << "Enter Year: ";
	cin >> year;
	while (!date.SetDate(day, month, year))
	{
		cout << "Enter day:";
		cin >> day;
		cout << "Enter Month:";
		cin >> month;
		cout << "Enter Year";
		cin >> year;
	}
	return date;
}

void MenuAddParty(Elections& elections)
{
	cout << "*** New Party ****" << endl;
	Party* newParty = new Party;
	cout << "Please Enter Party name: ";
	char* name = GetString();
	cout << "Please Enter Party Establish date" << endl;
	newParty->Initialize(elections.GetParties().GetCount() + 1, name, GetPoliticalStream(), GetDate());
	elections.AddParty(newParty);
}


void EndMenu(Elections& elections)
{
}
