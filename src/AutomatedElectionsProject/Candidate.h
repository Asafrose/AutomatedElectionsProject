#ifndef CANDIDATE_H
#define CANDIDATE_H

class Civilian;

class Candidate
{
private:
	Civilian* _civilian;
	int _rank;
public:
	void Initialize(Civilian* civilian, int rank);
	Civilian& GetCivilian() const;
	int& GetRank();
	void Free() const;
};


#endif // CANDIDATE_H
