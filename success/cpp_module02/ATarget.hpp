#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
	protected:
		std::string type;
	
	public:
		ATarget(std::string type);
		ATarget & operator=(ATarget const & src);
		ATarget(ATarget const & src);
		virtual ~ATarget();
		std::string getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell const & spell) const;

};

#endif