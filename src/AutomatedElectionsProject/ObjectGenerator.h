#pragma once
#include <fstream>

#include "Civilian.h"
#include "FileHelper.h"
#include "BallotBox.h"
#include "CoronaBallotBox.h"
#include "MilitaryBallotox.h"
#include "MilitaryCoronaBallotBox.h"

using namespace std;

class ObjectGenerator
{
public:
	template <class TItem, class TAdditionalData>
	static TItem* CreateObject(ifstream& file, const TAdditionalData& additionalData)
	{
		if (typeid(TItem) == typeid(Civilian))
		{
			return (TItem*)new Civilian(file, (vector<BallotBox*>&)additionalData);
		}

		string ballotBoxClassName;
		FileHelper::ReadString(ballotBoxClassName, file);

		if (ballotBoxClassName == typeid(BallotBox).name())
		{
			return (TItem*)new BallotBox(file, (Date&)additionalData);
		}

		if (ballotBoxClassName == typeid(CoronaBallotBox).name())
		{
			return (TItem*)new CoronaBallotBox(file, (Date&)additionalData);
		}

		if (ballotBoxClassName == typeid(MilitaryBallotbox).name())
		{
			return (TItem*)new MilitaryBallotbox(file, (Date&)additionalData);
		}

		if (ballotBoxClassName == typeid(MilitaryCoronaBallotBox).name())
		{
			return (TItem*)new MilitaryCoronaBallotBox(file, (Date&)additionalData);
		}

		return nullptr;
	}
};
