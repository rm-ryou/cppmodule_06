#ifndef CONVERSION_H
#define CONVERSION_H

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER,
}	e_argu_type;

class Conversion {
private:
	const std::string	str_;
	bool	isNeg_;
	int		i_;
	char	c_;
	float	f_;
	double	d_;
	std::string	other_i_;
	std::string	other_c_;
	std::string	other_f_;
	std::string	other_d_;
	e_argu_type	arguType_;
public:
	Conversion();
	Conversion(const std::string value);
	Conversion(const Conversion& other);
	Conversion&	operator=(const Conversion& other);
	~Conversion();

	e_argu_type	getArguType();

	bool	isChar();
	e_argu_type	isInt();
	e_argu_type	isFloat();
	e_argu_type	isDouble();

	void	setStr2Char();
	void	setStr2Int();
	void	setStr2Float();
	void	setStr2Double();
	void	setImpossible();
	void	setNan();

	void	setOutChar();
	void	setOutInt();
	void	setOutFloat();
	void	setOutDouble();
	void	setOutStr();

	const std::string	getCharStr() const;
	const std::string	getIntStr() const;
	const std::string	getFloatStr() const;
	const std::string	getDoubleStr() const;

	void	convert();

};

std::ostream&	operator<<(std::ostream& os, const Conversion& conversion);

#endif // !CONVERSION_H