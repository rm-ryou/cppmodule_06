#include "Base.h"

int	main()
{
	{
		std::srand(std::time(NULL));
		Base*	test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
	{
		identify(NULL);
		identify(NULL);
	}
}