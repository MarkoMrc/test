#ifndef FWOOSH_CPP
#define FWOOSH_CPP

#include "ASpell.hpp"

class Fwoosh : public ASpell {
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};

#endif