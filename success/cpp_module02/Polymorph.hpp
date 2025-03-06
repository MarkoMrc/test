#ifndef POLYMORPH_CPP
#define POLYMORPH_CPP

#include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph();
		~Polymorph();
		ASpell* clone() const;
};

#endif