#include <iostream>


#include "MenuOptions.h"
#include "Elections.h"
#include "BallotBox.h"

#define  MAX_CHAR_LENGTH 10

using namespace std;

void PrintMenu(Elections elections);

void RunMenu(Elections elections);


void MenuAddBallotBox(Elections elections);
/*
void MenuAddCitizen(Elections elections);
void MenuAddParty(Elections elections);
void MenuAddCandidate(Elections elections);
*/

void EndMenu(Elections elections);


int main()
{
	Date ElectionsDate;
	ElectionsDate.SetDate(1, 1, 2020);
	Elections newElections;
	newElections.Initialize(ElectionsDate);
	RunMenu(newElections);
	EndMenu(newElections);
}


void PrintMenu(Elections elections)
{
	if (!elections.IsElectionsOccured())
	{
		cout << "**** Elections  Will take place at ";
		elections.GetElectionsDate().ShowDate();
		cout << "****";
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
		elections.GetElectionsDate().ShowDate();
		cout << "*****\n";

		cout << "5 - Show All Ballot boxes \n";
		cout << "6 - Show All Citizens \n";
		cout << "7 - Show All Parties \n";

		cout << "9 - Show Elections Results \n";
		cout << "10 - Exit \n";
		cout << "****Please Note: Elections Completed, t \n ";
	}
}

void RunMenu(Elections elections)
{
	int UserInput;
	PrintMenu(elections);
	cin >> UserInput;
	system("CLS");
	while (UserInput != 10)
	{
		switch (UserInput)
		{
		case (AddBallotBox):
			{
				MenuAddBallotBox(elections);
				break;
			}
	/*	case (AddCitizen):
			{
				MenuAddCitizen(elections);
				break;
			}
		case (AddParty):
			{
				MenuAddParty(elections);
				break;
			}
		case (AddCandidate):
			{
				MenuAddCandidate(elections);
				break;
			}
		case (ShowAllBallotBoxes):
			{
				//elections.GetBallotBoxes()
				break;
			}
		case (ShowAllCitizens):
			{
				//	elections.GetBallotBoxes().
				break;
			}
		case (ShowAllParties):
			{
				//elections.GetParties()
				break;
			}
		case(RunElections):
			{
				//elections.Run
				break;
			}
		case (ShowElectionsResults):
			{
				elections.ShowResults();
				break;
		}*/	
		default:
			{
				cout << "Please Enter your Selection Again: ";
			}
		}
		cin >> UserInput;
	}
}

char* InputString()
{
	char* newString = new char[MAX_CHAR_LENGTH];
	cin >> newString;
	const int size = strlen(newString);
	if (size + 1 < MAX_CHAR_LENGTH)
	{
		delete (newString + size + 1);
	}

	return newString;
}

void MenuAddBallotBox(Elections elections)
{
	Address ballotAddress;
	BallotBox newBallotBox;
	unsigned int houseNum;
	char* street = InputString();
	char* city = InputString();
	int ballotBoxId = elections.GetBallotBoxes().GetCount() + 1;

	cout << " please enter Ballet Box city: \n";

	cout << " please enter Ballet Box street: \n";

	cout << " please enter Ballet Box street: \n";

	cin >> houseNum;

	ballotAddress.Initialize(city, street, houseNum);
	newBallotBox.Initialize(ballotBoxId, ballotAddress);
	elections.AddBallotBox(newBallotBox);
	
}

/*

void MenuAddCitizen(Elections elections);
void MenuAddParty(Elections elections);
void MenuAddCandidate(Elections elections);
*/

void EndMenu(Elections elections)
{
}


/*
 *  objects:
 *  Elections
 *  Date
 *      Day
 *      Month
 *      Year
 *      
 *  Civilian
 *      Name
 *      Id
 *      BirthYear
 *      BallotBox
 *      IsVoted
 *
 *  Candidate
 *      Civilian
 *      Place
 *      
 *  Civilians
 *      int Count;
 *      Civilian[] Civilians
 *  
 *  Candidates
 *      int Count
 *      Candidates[] Candidates
 *
 *  Party
 *      Id
 *      Name
 *      PoliticalStream
 *      DateCreated
 *      Candidates
 *
 *  PoliticalStream -> enum
 *
 *  Address
 *      City
 *      Street
 *      HouseNumber
 *          
 *  BallotBox
 *      Id
 *      Address
 *      Civilians
 *      Results
 *      VotingPercent => Calculated property
 *      
 *      
 *  Results
 *      int VotersCount
 *      int PartyCount
 *      PartyResults[]
 *      method:
 *          AddResults(Result results)
 *
 *  PartyResults
 *      PartyName
 *      Votes
 */
