#include "Base.h"

int	main()
{
	Base*	test = generate();
	identify(test);
	identify(*test);
	delete test;
}