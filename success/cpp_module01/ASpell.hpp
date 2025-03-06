#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
	protected:
		std::string name;
		std::string effects;
	
	public:
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const & src);
		virtual ASpell* clone() const = 0;
		virtual ~ASpell();
		ASpell & operator=(ASpell const & src);
		void launch(ATarget const & target) const;
		std::string getName() const;
		std::string getEffects() const;

};

#endif