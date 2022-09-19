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
	std::srand(std::time(NULL));
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
	else
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	identify(&p);
}