#include <iostream>

using namespace std;



int main()
{
        cout << "Hello World!\n";
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
