#ifndef FIREBALL_CPP
#define FIREBALL_CPP

#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball();
		~Fireball();
		ASpell* clone() const;
};

#endif