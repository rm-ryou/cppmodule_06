#include "Serialization.h"

int	main()
{
	{
		Data	data;
		data.str = "hoge";
		uintptr_t	Serialize = serialize(&data);
		Data*		Deserialize = deserialize(Serialize);
		std::cout << Serialize << std::endl;
		std::cout << Deserialize->str << std::endl;
	}
	{
		Data	data;
		data.num = 42;
		uintptr_t	Serialize = serialize(&data);
		Data*		Deserialize = deserialize(Serialize);
		std::cout << Serialize << std::endl;
		std::cout << Deserialize->num << std::endl;
	}
	{
		uintptr_t	uintptr = 123456789;
		Data*	data = new Data;
		std::cout << uintptr << std::endl;
		data->num = 100;
		std::cout << data->num << std::endl;
		uintptr = serialize(data);
		std::cout << uintptr << std::endl;
		delete data;
	}
	return 0;
}