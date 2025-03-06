#include "SpellBook.hpp"



SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	spellbook = src.spellbook;
	return (*this);
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook(){
	// for (std::map<std::string, ASpell*>::iterator it = spellbook.begin(); it != spellbook.end(); ++it)
	// 	delete it->second;
	// spellbook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		spellbook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & _target)
{
	std::map<std::string, ASpell*>::iterator it = spellbook.find(_target);
	if (it != spellbook.end())
	{
		// delete it->second;
		spellbook.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string  const &_target)
{
	ASpell* tmp = NULL;
	if (spellbook.find(_target) != spellbook.end())
		tmp = spellbook[_target];
	return (tmp);
}