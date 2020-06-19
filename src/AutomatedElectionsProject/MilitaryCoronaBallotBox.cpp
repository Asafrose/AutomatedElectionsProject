#include "MilitaryCoronaBallotBox.h"

MilitaryCoronaBallotBox::MilitaryCoronaBallotBox(const Address& address, const Date& electionsDate) :BallotBox(address, electionsDate)
{
}

MilitaryCoronaBallotBox::MilitaryCoronaBallotBox(ifstream& file, const Date& electionsDate): BallotBox(file,electionsDate)
{
}

bool MilitaryCoronaBallotBox::CanAdd(Civilian& civilian) const
{
	return civilian.IsInArmy(_electionsDate) && civilian.GetIsQuarantined();
}
