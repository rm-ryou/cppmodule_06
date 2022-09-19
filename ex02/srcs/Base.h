#ifndef BASE_H
#define BASE_H

#include <cstdlib>
#include <iostream>
#include <ctime>

class Base {
public:
	Base();
	virtual	~Base();
};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif // !BASE_H