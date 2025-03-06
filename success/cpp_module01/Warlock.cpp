#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::~Warlock(){
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock & Warlock::operator=(Warlock const & src)
{
	name = src.name;
	title = src.title;
	return *this;
}

Warlock::Warlock(Warlock const & src){
	*this = src;
}

Warlock::Warlock(std::string _name, std::string _title) : name(_name), title(_title){
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

void Warlock::setTitle(std::string const & _title){
	title = _title;
}

std::string const Warlock::getName() const{
	return name;
}

std::string const Warlock::getTitle() const{
	return title;
}

void Warlock::introduce() const{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell){
	if (spell)
	{
		if (Spellbook.find(spell->getName()) == Spellbook.end())
			Spellbook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellname){
	if (Spellbook.find(spellname) != Spellbook.end())
	{
		delete Spellbook[spellname];
		Spellbook.erase(Spellbook.find(spellname));
	}
}

void Warlock::launchSpell(std::string spellname, ATarget const & target){
	if (Spellbook.find(spellname) != Spellbook.end())
		Spellbook[spellname]->launch(target);
}