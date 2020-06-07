﻿#include "MilitaryCoronaBallotBox.h"

MilitaryCoronaBallotBox::MilitaryCoronaBallotBox(const Address& address, const Date& electionsDate) :BallotBox(address, electionsDate)
{
}

bool MilitaryCoronaBallotBox::CanAdd(Civilian& civilian) const
{
	return civilian.IsInArmy(_electionsDate) && civilian.GetIsQuarantined();
}
