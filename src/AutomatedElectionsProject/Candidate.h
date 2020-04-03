#ifndef CANDIDATE_H
#define CANDIDATE_H

class Civilian;

class Candidate
{
private:
	Civilian* _civilian;
	int _rank;
public:
	Candidate(Civilian* civilian, int rank);
	~Candidate();
	
	Civilian& GetCivilian() const;
	int& GetRank();
};


#endif // CANDIDATE_H
