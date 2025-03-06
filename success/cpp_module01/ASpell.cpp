#include "ASpell.hpp"

ASpell::ASpell(std::string _name, std::string _effects) : name(_name), effects(_effects) {}

ASpell::ASpell(ASpell const & src){
	*this = src;
}

ASpell & ASpell::operator=(ASpell const & src){
	name = src.name;
	effects = src.effects;
	return *this;
}

ASpell::~ASpell(){}

std::string ASpell::getEffects() const{
	return ( effects);
}

std::string ASpell::getName() const{
	return ( name);
}

void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell(*this);
}