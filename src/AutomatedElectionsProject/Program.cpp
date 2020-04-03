#define _CRT_SECURE_NO_WARNINGS
#define  MAX_CHAR_LENGTH 100

#include <iostream>
#include "MenuOptions.h"
#include "Elections.h"
#include "BallotBox.h"

using namespace std;

Party* CreateParty(const char* name, PoliticalStream politicalStream)
{
	return new Party(
		name,
		politicalStream,
		Date(1999));
}

Civilian* CreateCivilian(const char* name, int id, BallotBox* ballotBox)
{
	return new Civilian(
		name,
		id,
		Date(1999),
		ballotBox);
}

BallotBox* CreateBallotBox(const char* city, const char* street, int streetNumber)
{
	return new BallotBox(Address(city, street, streetNumber));
}

Elections CreateElections(const Date& date)
{
	Elections elections(date);

	BallotBox* telAvivBallotBox = CreateBallotBox("Tel Aviv", "Shimon Hatarsi", 37);
	BallotBox* herzliyaBallotBox = CreateBallotBox("Herzliya", "Haalumim", 3);
	Civilian* bibi = CreateCivilian("Binyamin Netaniyahu", 1, telAvivBallotBox);
	Civilian* miriRegev = CreateCivilian("Miri Regev", 2, telAvivBallotBox);
	Civilian* gantz = CreateCivilian("Binyamin Gantz", 3, herzliyaBallotBox);
	Civilian* yairLapid = CreateCivilian("Yair Lapid", 4, herzliyaBallotBox);
	Civilian* noamKozer = CreateCivilian("Noam Kozer", 5, telAvivBallotBox);
	Civilian* ohadShemTov = CreateCivilian("Ohad Shem-Tov", 6, herzliyaBallotBox);
	Party* blueAndWhite = CreateParty("Blue And White", Center);
	Party* likud = CreateParty("Likud", Right);
	Party* thePirates = CreateParty("The Pirates", Center);
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
	elections.AddCandidate(new Candidate(bibi, 1), *likud);
	elections.AddCandidate(new Candidate(miriRegev, 1), *likud);
	elections.AddCandidate(new Candidate(gantz, 1), *blueAndWhite);
	elections.AddCandidate(new Candidate(yairLapid, 1), *blueAndWhite);
	elections.AddCandidate(new Candidate(noamKozer, 1), *thePirates);
	elections.AddCandidate(new Candidate(ohadShemTov, 1), *thePirates);

	return elections;
}


char* GetString(const char* prompt)
{
	cout << prompt << ": ";
	char string[MAX_CHAR_LENGTH];
	cin.getline(string, sizeof string);

	char* newString = new char[strlen(string) + 1];
	strcpy(newString, string);

	return newString;
}

int GetInt(const char* prompt)
{
	cout << prompt << ": ";
	int result;
	cin >> result;
	return result;
}

BallotBox* GetBallotBox(Elections& elections)
{
	cout << "Available Ballot Boxes: " << endl;
	elections.ShowAllBallotBoxes();
	return &elections.GetBallotBoxes().Get(GetInt("Please select BallotBox Id") - 1);
}

void MenuAddBallotBox(Elections& elections)
{
	cout << "*** MenuAddBallotBox Started *** \n";

	char* city = GetString("Please enter Ballet Box city");
	char* street = GetString("Please enter Ballet Box street");
	int houseNumber = GetInt("Please enter Ballet Box House Number");

	elections.AddBallotBox(new BallotBox(Address(city, street, houseNumber)));

	cout << "*** MenuAddBallotBox Finished *** \n";
}


void AddNewCivilian(Elections& elections)
{
	cout << "*** AddNewCivilian Started ***" << endl;
	

	char* name = GetString("Please enter civilian name");
	int id = GetInt("Please enter civilian id");

	Date birthDate(GetInt("Please enter civilian birth year"));
	

	BallotBox* balletBox = GetBallotBox(elections);

	Civilian* newCivilian = new Civilian(
		name,
		id,
		birthDate,
		balletBox);

	elections.AddCivilian(newCivilian);
	cout << "*** AddNewCivilian Finished ***" << endl;
}

PoliticalStream GetPoliticalStream()
{
	return (PoliticalStream)GetInt("Please choose Political stream: 0-Left   1-Middle   2-Right");
}

Date GetDate(const char* prompt)
{
	cout << prompt << ":\n";
	int day = GetInt("Please enter day");
	int month = GetInt("Please enter month");
	int year = GetInt("Please enter year");

	return Date(day, month, year);
}

void MenuAddParty(Elections& elections)
{
	cout << "*** MenuAddParty Started ***" << endl;

	char* name = GetString("Please enter party name");
	PoliticalStream politicalStream = GetPoliticalStream();
	Date date = GetDate("Please Enter Party Establish date");
	Party* newParty = new Party(
		name,
		politicalStream,
		date);
	elections.AddParty(newParty);
}


void PersonalElection(Civilian& civilian, Elections& elections)
{
	cout << "Welcome " << civilian.GetName() << endl;
	if (GetInt("Would you like to vote? Press '1' to continue '0' to exit"))
	{
		elections.ShowAllParties();
		int voteId = GetInt("Please select the id of your chosen party");
		civilian.Vote(elections.GetParties().Get(voteId - 1));
		cout << "Vote received successfully :)" << endl;
	}
	else
	{
		cout << " Your Vote has ended without voting :( thank you" << endl;
	}
	cout << " Press any key to move to next civilian: ";
	getchar();
	system("CLS");
}

void MenuRunElections(Elections& elections)
{
	elections.StartElections();
	cout << "*** Welcome to ";
	elections.GetElectionsDate().Show();
	cout << " elections ***" << endl;
	cout << "*** Starting elections process ***" << endl;
	const Civilians civilians = elections.GetCivilians();
	for (int i = 0; i < civilians.GetCount(); i++)
	{
		PersonalElection(civilians.Get(i), elections);
	}
	cout << "*** Elections process ended ***" << endl;
}

void MenuAddCandidate(Elections& elections)
{
	cout << "*** MenuAddCandidate started ***" << endl;

	for (int i = 0; i < elections.GetCivilians().GetCount(); ++i)
	{
		cout << i << " ==> ";
		elections.GetCivilians().Get(i).Show();
		cout << endl;
	}

	Civilian* civilian =
		&elections.
		 GetCivilians().
		 Get(GetInt("Please select the number of the civilian that you want to run as candidate"));

	elections.ShowAllParties();
	Party* party = &elections.GetParties().Get(GetInt("Please select the party id") - 1);

	Candidate* candidate = new Candidate(civilian, GetInt("Please enter rank in party"));
	elections.AddCandidate(candidate, *party);

	cout << "*** MenuAddCandidate finished ***" << endl;
}

void PrintMenu(Elections& elections)
{
	cout << endl;
	if (!elections.IsElectionsOccured())
	{
		cout << "**** Elections  Will take place at ";
		elections.GetElectionsDate().Show();
		cout << "**** \n";
		cout << "Available actions: \n";
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
		cout << endl;
		cout << "****Elections Completed at: ";
		elections.GetElectionsDate().Show();
		cout << "*****\n";
		cout << "Available actions: \n";
		cout << "5 - Show All Ballot boxes \n";
		cout << "6 - Show All Citizens \n";
		cout << "7 - Show All Parties \n";
		cout << "9 - Show Elections Results \n";
		cout << "10 - Exit \n";
		cout << "****Please Note: Elections Completed,  \n ";
	}
}

void RunMenu(Elections& elections)
{
	while (true)
	{
		PrintMenu(elections);
		const int userInput = GetInt("Please choose action number");
		getchar();
		system("CLS");
		switch (userInput)
		{
		case AddBallotBox:
			{
				MenuAddBallotBox(elections);
				break;
			}
		case AddCitizen:
			{
				AddNewCivilian(elections);
				break;
			}
		case AddParty:
			{
				MenuAddParty(elections);
				break;
			}
		case AddCandidate:
			{
				MenuAddCandidate(elections);
				break;
			}
		case ShowAllBallotBoxes:
			{
				elections.ShowAllBallotBoxes();
				break;
			}
		case ShowAllCivilians:
			{
				elections.ShowAllCivilians();
				break;
			}
		case ShowAllParties:
			{
				elections.ShowAllParties();
				break;
			}
		case RunElections:
			{
				MenuRunElections(elections);
				break;
			}
		case ShowElectionsResults:
			{
				elections.ShowResults();
				break;
			}
		case Exit:
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

int main()
{
	Elections elections = CreateElections(GetDate("Please enter elections date"));
	RunMenu(elections);
	return 0;
}
