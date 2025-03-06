#include "ATarget.hpp"

ATarget::ATarget(std::string _type) : type(_type){

}

ATarget & ATarget::operator=(ATarget const & src){
	type = src.type;
	return *this;
}

ATarget::ATarget(ATarget const & src){
	*this = src;
}


ATarget::~ATarget(){}

std::string ATarget::getType() const{
	return (type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}