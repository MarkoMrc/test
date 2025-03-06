#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell & ASpell::operator=(ASpell const & rhs)
{
	_name = rhs.getName();
	_effects = rhs.getEffects();
	return *this;
}

ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
	return (_name);
}

std::string ASpell::getEffects() const
{
	return (_effects);
}

void ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}


#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell 
{
	protected :
		std::string _name;
		std::string _effects;
	
	public :
		ASpell(std::string name, std::string effects);
		ASpell & operator=(ASpell const & rhs);
		ASpell(ASpell const & obj);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target) const;
};

#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{

}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	_type = rhs.getType();
	return *this;
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return (_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}


#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
	protected :
		std::string _type;
	
	public :
		ATarget(std::string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		std::string getType() const;
		virtual ATarget* clone() const = 0;
};

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::~BrickWall()
{}

ATarget* BrickWall::clone() const
{
	return (new BrickWall());
}

#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public :
		BrickWall();
		~BrickWall();
		ATarget* clone() const;
};

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{}

ATarget* Dummy::clone() const
{
	return (new Dummy());
}

#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public :
		Dummy();
		~Dummy();
		ATarget* clone() const;
};

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball()
{}

ASpell* Fireball::clone() const
{
	return (new Fireball());
}

#pragma once
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public :
		Fireball();
		~Fireball();
		ASpell* clone() const;
};

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::~Fwoosh()
{}

ASpell* Fwoosh::clone() const
{
	return (new Fwoosh());
}

#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public :
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"


int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph()
{}

ASpell* Polymorph::clone() const
{
	return (new Polymorph());
}

#pragma once
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public :
		Polymorph();
		~Polymorph();
		ASpell* clone() const;
};

#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	_SpellBook = src._SpellBook;
	return (*this);
}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & SpellName)
{
	std::map<std::string, ASpell*>::iterator it = _SpellBook.find(SpellName);
	if (it != _SpellBook.end())
	{
		delete it->second;
		_SpellBook.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	ASpell* tmp = NULL;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		tmp = _SpellBook[SpellName];
	return (tmp);
}

#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private :
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::map < std::string, ASpell*> _SpellBook;
	public :
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & src)
{
	*this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src)
{
	_target = src._target;
	return (*this);
}


TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		_target[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
	if (_target.find(target) != _target.end())
		_target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	ATarget* tmp = NULL;
	if (_target.find(target) != _target.end())
		tmp = _target[target];
	return (tmp);
}

#pragma once
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private :
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator & operator=(TargetGenerator const & src);
		std::map < std::string, ATarget*> _target;
	public :
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const
{
	return (_name);
}

std::string const & Warlock::getTitle() const
{
	return (_title);
}

void	Warlock::setTitle(std::string const & str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string SpellName)
{
	_SpellBook.forgetSpell(SpellName);
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
}

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {

	private :
		std::string _name;
		std::string _title;
		SpellBook _SpellBook;
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();

	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & str);
		void	introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget const & target);
};