#define _CRT_SECURE_NO_WARNINGS
#define  MAX_CHAR_LENGTH 100

#include <iostream>
#include "MenuOptions.h"
#include "Elections.h"
#include "BallotBox.h"

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


	while (true)
	{
		PrintMenu(elections);
		cin >> UserInput;
		getchar();
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
					*/
		case (ShowAllBallotBoxes):
			{
				elections.GetBallotBoxes();
				break;
			}
			/*
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
		case (Exit):
			{
				return;
			}
		default:
			{
				cout << "Please Enter your Selection Again: ";
			}
		}
		system("CLS");
	}
}


char* GetString()
{
	char string[MAX_CHAR_LENGTH];
	char ch;
	cin.getline(string, sizeof string);
	char* newString = new char[strlen(string) + 1];
	strcpy(newString, string);
	return newString;
}

void MenuAddBallotBox(Elections elections)
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
