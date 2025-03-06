#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
	protected:
		std::string type;
	
	public:
		ATarget(std::string name);
		ATarget(ATarget const & src);
		virtual ATarget* clone() const = 0;
		virtual ~ATarget();
		ATarget & operator=(ATarget const & src);
		void getHitBySpell(ASpell const & spell) const;
		std::string getType() const;

};

#endif