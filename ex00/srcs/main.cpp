#include "Conversion.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	Conversion	conversion(argv[1]);
	conversion.convert();
	std::cout << conversion << std::endl;
	return 0;
}