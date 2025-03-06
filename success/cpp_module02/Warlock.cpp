#include "Warlock.hpp"

Warlock::Warlock(std::string const  &_name, std::string const &_title) : name(_name), title(_title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & src)
{
	name = src.name;
	title = src.title;
	return *this;
}

Warlock::Warlock(Warlock const & src)
{
	*this = src;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const{
	return name;
}

std::string const & Warlock::getTitle() const{
	return title;
}

void Warlock::setTitle(std::string const & _title)
{
	title = _title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell* spell)
{
	spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellname)
{
	spellbook.forgetSpell(spellname);
}

void Warlock::launchSpell(std::string spellname, ATarget const & target)
{
	if(spellbook.createSpell(spellname))
		spellbook.createSpell(spellname)->launch(target);
}