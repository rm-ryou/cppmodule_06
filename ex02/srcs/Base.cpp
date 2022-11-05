#include "A.h"
#include "B.h"
#include "C.h"
#include "Base.h"

Base::Base()
{
	std::cout << "Base constructor called." << std::endl;
}

Base::~Base()
{
	std::cout << "Base destructor called." << std::endl;
}

Base*	generate()
{
	int	num = rand() % 3;
	switch (num) {
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		return NULL;
		break;
	}
	
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch(std::exception &e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}