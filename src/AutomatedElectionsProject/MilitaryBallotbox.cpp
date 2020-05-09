#include "MilitaryBallotox.h"


MilitaryBallotbox::MilitaryBallotbox(const Address& address, const Date& electionsDate):BallotBox(address,electionsDate)
{

}


bool MilitaryBallotbox::CanAdd(Civilian* civilian) 
{
	return civilian->IsInArmy(_electionsDate) && !civilian->GetIsQuarantined();
}


