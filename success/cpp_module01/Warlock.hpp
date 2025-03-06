#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock &operator=(Warlock const & src);
		Warlock(Warlock const & src); 
		std::map<std::string, ASpell*> Spellbook;

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string const getName() const;
		std::string const getTitle() const;
		void setTitle(std::string const & title);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellname);
		void launchSpell(std::string spellname, ATarget const & target);

};

#endif