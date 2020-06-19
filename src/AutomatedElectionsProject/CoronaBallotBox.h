#ifndef CORONABALLOTBOX
#define CORONABALLOTBOX

#include "BallotBox.h"

class CoronaBallotBox : public BallotBox
{
public:
	CoronaBallotBox(const Address& address,const Date& electionsDate);
	CoronaBallotBox(ifstream& file, const Date& electionsDate);
	bool CanAdd(Civilian& civilian) const override;
	
};




#endif
