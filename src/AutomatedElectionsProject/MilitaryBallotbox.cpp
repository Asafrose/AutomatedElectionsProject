#include "MilitaryBallotox.h"


MilitaryBallotbox::MilitaryBallotbox(const Address& address, const Date& electionsDate):BallotBox(address,electionsDate)
{

}


bool MilitaryBallotbox::CanAdd(Civilian& civilian) const
{
	return civilian.IsInArmy(_electionsDate) && !civilian.GetIsQuarantined();
}


