#ifndef CORONABALLOTBOX
#define CORONABALLOTBOX

#include "BallotBox.h"

class CoronaBallotbox : public BallotBox
{
public:
	CoronaBallotbox(const Address& address,const Date& electionsDate);
	bool CanAdd(Civilian* civilian) override;
	
};




#endif
