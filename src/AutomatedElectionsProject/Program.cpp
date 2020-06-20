#define _CRT_SECURE_NO_WARNINGS
#define  MAX_CHAR_LENGTH 100

#include <iostream>
#include <vector>

#include "MenuOptions.h"
#include "Elections.h"
#include "BallotBox.h"
#include "Civilian.h"
#include "CoronaBallotBox.h"
#include "DataFile.h"
#include "Exception.h"
#include "MilitaryBallotox.h"
#include "MilitaryCoronaBallotBox.h"

using namespace std;

Party* CreateParty(const string& name, PoliticalStream politicalStream)
{
	return new Party(
		name,
		politicalStream,
		Date(1999));
}

Civilian* CreateCivilian(const string& name, int id, BallotBox* ballotBox, bool isQuarantined = false)
{
	Civilian* civilian = new Civilian(
		name,
		id,
		Date(1980));

	civilian->SetIsQuarantined(isQuarantined);
	civilian->SetBallotBox(*ballotBox);
	return civilian;
}

BallotBox* CreateBallotBox(const string& city, const string& street, int streetNumber, const Date& date)
{
	return new BallotBox(Address(city, street, streetNumber), date);
}

BallotBox* CreateCoronaBallotBox(const string& city, const string& street, int streetNumber, const Date& date)
{
	return new CoronaBallotBox(Address(city, street, streetNumber), date);
}

Elections* CreateElections(const Date& date)
{
	Elections* elections = new Elections(date);

	BallotBox* telAvivBallotBox = CreateBallotBox("Tel Aviv", "Shimon Hatarsi", 37, date);
	BallotBox* coronaBallotBox = CreateCoronaBallotBox("Or yeduda", "Hapirat Haadom", 12, date);
	BallotBox* herzliyaBallotBox = CreateBallotBox("Herzliya", "Haalumim", 3, date);
	Civilian* bibi = CreateCivilian("Binyamin Netaniyahu", 132158971, coronaBallotBox, true);
	Civilian* miriRegev = CreateCivilian("Miri Regev", 132158972, telAvivBallotBox);
	Civilian* gantz = CreateCivilian("Binyamin Gantz", 132158973, coronaBallotBox, true);
	Civilian* yairLapid = CreateCivilian("Yair Lapid", 132158974, herzliyaBallotBox);
	Civilian* noamKozer = CreateCivilian("Noam Kozer", 132158975, telAvivBallotBox);
	Civilian* ohadShemTov = CreateCivilian("Ohad Shem-Tov", 132158976, herzliyaBallotBox);

	elections->AddBallotBox(telAvivBallotBox);
	elections->AddBallotBox(coronaBallotBox);
	elections->AddBallotBox(herzliyaBallotBox);
	elections->AddCivilian(bibi);
	elections->AddCivilian(miriRegev);
	elections->AddCivilian(gantz);
	elections->AddCivilian(yairLapid);
	elections->AddCivilian(noamKozer);
	elections->AddCivilian(ohadShemTov);


	return elections;
}

void AddParties(Elections* elections)
{
	Party* blueAndWhite = CreateParty("Blue And White", Center);
	Party* likud = CreateParty("Likud", Right);
	Party* thePirates = CreateParty("The Pirates", Center);
	elections->AddParty(blueAndWhite);
	elections->AddParty(likud);
	elections->AddParty(thePirates);

	vector<Civilian*> civilians = elections->GetCivilians();

	if (civilians.size() < 6)
	{
		cout << "Unexpected civilian count. initializing without party candidates" << endl;
		return;
	}
	
	Candidate bibiCandidate((civilians[0]), likud, 1);
	Candidate miriRegevCandidate((civilians[1]), likud, 1);
	Candidate gantzCandidate((civilians[2]), blueAndWhite, 1);
	Candidate yairLapidCandidate((civilians[3]), blueAndWhite, 1);
	Candidate noamKozerCandidate((civilians[4]), thePirates, 1);
	Candidate ohadShemTovCandidate((civilians[5]), thePirates, 1);
	
	elections->AddCandidate(bibiCandidate, *likud);
	elections->AddCandidate(miriRegevCandidate, *likud);
	elections->AddCandidate(gantzCandidate, *blueAndWhite);
	elections->AddCandidate(yairLapidCandidate, *blueAndWhite);
	elections->AddCandidate(noamKozerCandidate, *thePirates);
	elections->AddCandidate(ohadShemTovCandidate, *thePirates);
}


string GetString(const string& prompt)
{
	cout << prompt << ": ";
	char* temp = new char[MAX_CHAR_LENGTH];
	cin.getline(temp, MAX_CHAR_LENGTH);

	string result(temp);

	delete[] temp;

	return result;
}

int GetInt(const string& prompt)
{
	cout << prompt << ": ";
	int result;
	cin >> result;
	return result;
}

BallotBox* GetBallotBox(Elections& elections, Civilian& civilian)
{
	cout << "Available Ballot Boxes: " << endl;
	elections.ShowAllValidBallotBoxes(civilian);
	return elections.GetBallotBoxes()[(GetInt("Please select BallotBox Id") - 1)];
}

void MenuAddBallotBox(Elections& elections) noexcept(false)
{
	cout << "*** MenuAddBallotBox Started *** \n";

	string city = GetString("Please enter Ballet Box city");
	string street = GetString("Please enter Ballet Box street");
	int houseNumber = GetInt("Please enter Ballet Box House Number");

	const Address address(city, street, houseNumber);

	BallotBox* ballotBox;
	switch (GetInt("Please Choose BalletBox type \n\t1) normal\n\t2) corona\n\t3) military\n\t4) military corona"))
	{
	case 1:
		ballotBox = new BallotBox(address, elections.GetElectionsDate());
		break;
	case 2:
		ballotBox = new CoronaBallotBox(address, elections.GetElectionsDate());
		break;
	case 3:
		ballotBox = new MilitaryBallotbox(address, elections.GetElectionsDate());
		break;
	case 4:
		ballotBox = new MilitaryCoronaBallotBox(address, elections.GetElectionsDate());
		break;
	default:
		throw Exception("invalid option selected");
		exit(1);
	}

	elections.AddBallotBox(ballotBox);


	cout << "*** MenuAddBallotBox Finished *** \n";
}


void AddNewCivilian(Elections& elections)
{
	cout << "*** AddNewCivilian Started ***" << endl;


	string name = GetString("Please enter civilian name");
	int id = GetInt("Please enter civilian id");

	Date birthDate(GetInt("Please enter civilian birth year"));

	Civilian* newCivilian = new Civilian(
		name,
		id,
		birthDate);

	newCivilian->SetBallotBox(*GetBallotBox(elections, *newCivilian));

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

	string name = GetString("Please enter party name");
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
		if (!civilian.GetIsQuarantined() || GetInt(
			"You are in quarantine! did you bring a protective mask? Press '1' for yes '0' for no"))
		{
			elections.ShowAllParties();
			int voteId = GetInt("Please select the id of your chosen party");
			civilian.Vote(*elections.GetParties()[voteId - 1]);
			cout << "Vote received successfully :)" << endl;
		}
		else
		{
			cout << "Since You are in quarantine, You cannot vote without a mask!" << endl;
		}
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
	cout << "*** Starting elections process ***" << endl;
	elections.StartElections();


	for (int i = 0; i < elections.GetCivilians().size(); i++)
	{
		cout << "*** Welcome to " << elections.GetElectionsDate() << " elections ***" << endl;

		PersonalElection(*elections.GetCivilians()[i], elections);
	}
	cout << "*** Elections process ended ***" << endl;
}

void MenuAddCandidate(Elections& elections)
{
	cout << "*** MenuAddCandidate started ***" << endl;

	for (int i = 0; i < elections.GetCivilians().size(); ++i)
	{
		cout << i << " ==> " << *elections.GetCivilians()[i] << endl;
	}

	Civilian* civilian = elections.GetCivilians()[GetInt(
		"Please select the number of the civilian that you want to run as candidate")];

	elections.ShowAllParties();
	Party* party = elections.GetParties()[GetInt("Please select the party id") - 1];

	Candidate candidate = Candidate(civilian, party, GetInt("Please enter rank in party"));
	elections.AddCandidate(candidate, *party);

	cout << "*** MenuAddCandidate finished ***" << endl;
}


void PrintMenu(Elections& elections)
{
	cout << endl;
	if (!elections.IsElectionsOccured())
	{
		cout << "**** Elections  Will take place in " << (elections.GetDate() - Date::Now()).Days() << " days **** \n";
		cout << "Available actions: \n";
		cout << "1 - Add New Ballot Box \n";
		cout << "2 - Add New Citizen \n";
		cout << "3 - Add New Party \n";
		cout << "4 - Add New Candidate \n";
		cout << "5 - Update Quarantine status \n";
		cout << "6 - Show All Ballot boxes \n";
		cout << "7 - Show All Citizens \n";
		cout << "8 - Show All Parties \n";
		cout << "9 - Elections - Perform Elections  \n";
		cout << "11 - Exit \n";
		cout << "****Please Note: After Choosing to run Elections you can only - Add votes  or Show final results \n ";
	}
	else
	{
		cout << endl;
		cout << "****Elections Completed at: " << elections.GetElectionsDate() << "*****\n";
		cout << "Available actions: \n";
		cout << "6 - Show All Ballot boxes \n";
		cout << "7 - Show All Citizens \n";
		cout << "8 - Show All Parties \n";
		cout << "10 - Show Elections Results \n";
		cout << "11 - Exit \n";
		cout << "****Please Note: Elections Completed,  \n ";
	}
}

void UpdateQuarantineStatus(Elections& elections)
{
	cout << "**** Update Quarantine Status for Civilian **** \n";

	for (int i = 0; i < elections.GetCivilians().size(); ++i)
	{
		cout << i << " ==> " << *elections.GetCivilians()[i] << endl;
	}

	Civilian* civilian =
		elections.
		GetCivilians()[GetInt("Please select the number of the civilian that you want to update his Quarantine status ")
		];
	bool isQuarantined = GetInt("Enter 0 for \"no Quarantine\" or 1 for \"apply Quarantine\"");

	if (civilian->GetIsQuarantined() == isQuarantined)
	{
		return;
	}

	vector<Civilian*>& civilians = civilian->GetBallotBox()->GetCivilians();
	for (vector<Civilian*>::iterator it = civilians.begin(); it != civilians.end(); ++it)
	{
		if ((*it)->GetId() == civilian->GetId())
		{
			civilians.erase(it);
			break;
		}
	}

	civilian->SetIsQuarantined(isQuarantined);
	BallotBox* ballotBox = GetBallotBox(elections, *civilian);
	civilian->SetBallotBox(*ballotBox);
	ballotBox->AddCivilian(civilian);
}

void RunMenu(Elections& elections)
{
	while (true)
	{
		try
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

			case SetNewQuarantineStatus:
				{
					UpdateQuarantineStatus(elections);
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
		catch (const Exception& exception)
		{
			system("CLS");
			cout << exception.GetMessage() << endl;
		}
	}
}

int main()
{
	Elections* elections = nullptr;
	try
	{
		Date date = GetDate("Please enter elections date");
		auto ballotBoxes = DataFile<BallotBox>::Load(date);
		if (ballotBoxes.empty())
		{
			elections = CreateElections(date);
		}
		else
		{
			elections = new Elections(date);
			elections->SetBallotBoxes(ballotBoxes);
			elections->SetCivilians(DataFile<Civilian>::Load(ballotBoxes));
		}

		AddParties(elections);
		RunMenu(*elections);
		
		DataFile<BallotBox>::Save(elections->GetBallotBoxes());
		DataFile<Civilian>::Save(elections->GetCivilians());

		delete elections;
		return 0;
	}
	catch (const Exception& exception)
	{
		cout << exception.GetMessage() << endl;
		delete elections;

		exit(1);
	}
}
