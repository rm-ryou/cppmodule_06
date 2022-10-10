#include "Conversion.h"

Conversion::Conversion(): str_("none")//, i_(0), c_(0), f_(0), d_(0), arguType_(OTHER)
{}

Conversion::Conversion(const std::string value): str_(value)//, i_(0), c_(0), f_(0), d_(0), arguType_(OTHER)
{
	this->c_ = 0;
	this->i_ = 0;
	this->f_ = 0;
	this->d_ = 0;
	this->other_c_ = "";
	this->other_i_ = "";
	this->other_f_ = "";
	this->other_d_ = "";
	this->isNeg_ = false;
}

Conversion::Conversion(const Conversion& other)
{
	*this = other;
}

Conversion&	Conversion::operator=(const Conversion& other)
{
	if (this != &other) {
		const_cast<std::string&>(this->str_) = other.str_;
		this->i_ = other.i_;
		this->c_ = other.c_;
		this->f_ = other.f_;
		this->d_ = other.d_;
	}
	return *this;
}

Conversion::~Conversion()
{}

const std::string	Conversion::getCharStr() const { return this->other_c_; }
const std::string	Conversion::getIntStr() const { return this->other_i_; }
const std::string	Conversion::getFloatStr() const { return this->other_f_; }
const std::string	Conversion::getDoubleStr() const { return this->other_d_; }

bool	Conversion::isChar()
{
	size_t	str_size = this->str_.size();
	if (str_size == 1) {
		this->c_ = this->str_[0];
		if ((this->c_ >= 0 && this->c_ < 48) || this->c_ > 57)
			return true;
	} else if (str_size == 3) {
		this->c_ = this->str_[1];
		if (this->str_[0] != '\'' && this->str_[2] != '\'')
			return false;
		if (this->str_[0] >= 0)
			return true;
	}
	return false;
}

e_argu_type	Conversion::isInt() // 数字のみ確定
{
	const char	*str = this->str_.c_str();
	char		*end;
	errno = 0;

	long	num = std::strtol(str, &end, 10);
	if (errno != 0 || end == str || num > INT_MAX || num < INT_MIN) {
		this->other_i_ = "impossible";
		return isFloat();
	}
	this->i_ = static_cast<int>(num);
	return INT;
}

e_argu_type	Conversion::isFloat()
{
	const char	*p = this->str_.c_str();
	char		*end;
	errno = 0;

	this->f_ = std::strtod(p, &end);
	if (errno == ERANGE || end == p)
		this->other_f_ = "nanf";
	else if (this->f_ > FLT_MAX)
		this->other_f_ = "+inff";
	else if (this->f_ < -FLT_MAX)
		this->other_f_ = "-inff";
	else
		return FLOAT;
	return isDouble();
}

e_argu_type	Conversion::isDouble()
{// 桁数でオーバーフロー対策
	const char	*p = this->str_.c_str();
	char		*end;
	errno = 0;

	this->d_ = std::strtold(p, &end);
	if (errno == ERANGE || end == p)
		this->other_f_ = "nan";
	if (this->d_ == HUGE_VAL)
		this->other_d_ = "+inf";
	else if (this->d_ == -HUGE_VAL)
		this->other_d_ = "-inf";
	return DOUBLE;
}

e_argu_type	Conversion::getArguType()
{
	std::string	str = this->str_;
	size_t	num_dot = 0;
	size_t	num_f = 0;

	if (isChar())
		return CHAR;
	size_t	i = 0;
	if (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			this->isNeg_ = true;
		i++;
	}
	for (; str[i] != '\0'; i++) {
		if (str[i] == 'f')
			num_f += i;
		else if (str[i] == '.')
			num_dot++;
		else if (!std::isdigit(str[i]))
			return OTHER;
	}
	if (num_dot > 1 || (num_f + 1 != i && num_f))
		return OTHER;
	else if (!num_dot && !num_f)
		return isInt();
	else if (num_dot <= 1 && num_f)
		return isFloat();
	return isDouble();
}

void	Conversion::setStr2Char()
{
	// this->i_ = (this->c_);
	// std::cout << this->c_ << std::endl;
	// std::cout << this->i_ << std::endl;
	// setStr2Int();

	this->i_ = static_cast<int>(this->c_);
	this->f_ = static_cast<float>(this->c_);
	this->d_ = static_cast<double>(this->c_);
}

void	Conversion::setStr2Int()
{
	// std::ostringstream oss;

	// if ((this->i_ >= 0 && this->i_ <= 31) || this->i_ == 127)
	// 	this->other_c_ = "Non displayable";
	// else if (std::isprint(this->i_)) {
	// 	this->c_ = static_cast<char>(this->i_);
	// 	oss << this->c_;
	// 	this->other_c_ = "'" + oss.str() + "'";
	// 	oss.str("");
	// 	oss.clear();
	// } else
	// 	this->other_c_ = "impossible";
	// oss << this->i_;
	// if (this->other_i_ == "")
	// 	this->other_i_ = oss.str();
	// if (this->other_f_ == "")
	// 	this->other_f_ = oss.str() + ".0f";
	// if (this->other_d_ == "")
	// 	this->other_d_ = oss.str() + ".0";

	this->c_ = static_cast<char>(this->i_);
	this->f_ = static_cast<float>(this->i_);
	this->d_ = static_cast<double>(this->i_);
}

void	Conversion::setStr2Float()
{
	// std::ostringstream	os;

	// os << this->f_;
	// this->other_f_ = os.str() + "f";
	// this->other_d_ = os.str();
	// if (this->f_ >= INT_MIN && this->f_ <= INT_MAX) {
	// 	this->i_ = static_cast<int>(this->f_);
	// 	setStr2Int();
	// } else
	// 	this->other_i_ = "impossible";// この時点でint, char は考えなくていい

	this->c_ = static_cast<char>(this->f_);
	this->i_ = static_cast<int>(this->f_);
	this->d_ = static_cast<double>(this->f_);
}

void	Conversion::setStr2Double()
{
	// std::ostringstream	os;

	// os << this->d_;
	// if (this->other_f_ == "")
	// 	this->other_f_ = os.str() + "f";
	// this->other_d_ = os.str();
	// if (this->d_ >= INT_MIN && this->d_ <= INT_MAX) {
	// 	this->i_ = static_cast<int>(this->d_);
	// 	setStr2Int();
	// } else
	// 	this->other_i_ = "impossible";
	this->c_ = static_cast<char>(this->d_);
	this->i_ = static_cast<int>(this->d_);
	this->f_ = static_cast<float>(this->d_);
}

void	Conversion::setImpossible()
{
	this->other_c_ = "impossible";
	this->other_i_ = "impossible";
	this->other_f_ = "nanf";
	this->other_d_ = "nan";
}

void	Conversion::setOutChar()
{
	std::ostringstream	os;

	os << this->c_;
	this->other_c_ = "'" + os.str() + "'";
	os.str("");
	os.clear();
	os << this->i_;
	this->other_i_ = os.str();
	this->other_f_ = os.str() + ".0f";
	this->other_d_ = os.str() + ".0";
}

void	Conversion::setOutInt()
{ // INT_MIN <= N <= INT_MAXは確定
	std::ostringstream oss;

	if ((this->i_ >= 0 && this->i_ <= 31) || this->i_ == 127)
		this->other_c_ = "Non displayable";
	else if (this->i_ >= 32 && this->i_ <= 126) {
		oss << this->c_;
		this->other_c_ = "'" + oss.str() + "'";
		oss.str("");
		oss.clear();
	} else
		this->other_c_ = "impossible";
	oss << this->i_;
	if (this->other_i_ == "")
		this->other_i_ = oss.str();
	if (this->other_f_ == "")
		this->other_f_ = oss.str() + ".0f";
	if (this->other_d_ == "")
		this->other_d_ = oss.str() + ".0";
}

void	Conversion::setOutFloat()
{
	std::ostringstream	os;

	os << this->f_;
	if (this->i_ == this->f_) {
		this->other_f_ = os.str() + ".0f";
		this->other_d_ = os.str() + ".0";
	} else {
		this->other_f_ = os.str() + "f";
		this->other_d_ = os.str();
	}
	if (this->f_ >= INT_MIN && this->f_ <= INT_MAX)
		setOutInt();
	else {
		this->other_c_ = "impossible";
		this->other_i_ = "impossible";// この時点でint, char は考えなくていい
	}
}

void	Conversion::setOutDouble()
{
	std::ostringstream	os;

	os << this->d_;
	if (this->i_ == this->d_) {
		if (this->other_f_ == "")
			this->other_f_ = os.str() + ".0f";
		this->other_d_ = os.str() + ".0";
	} else {
		if (this->other_f_ == "")
			this->other_f_ = os.str();
		this->other_d_ = os.str();
	}
	if (this->d_ >= INT_MIN && this->d_ <= INT_MAX)
		setOutInt();
	else {
		this->other_c_ = "impossible";
		this->other_i_ = "impossible";
	}
}

void	Conversion::convert()
{
	this->arguType_ = getArguType();
	switch (this->arguType_)
	{
	case CHAR:
		setStr2Char();
		setOutChar();
		break;
	case INT:
		setStr2Int();
		setOutInt();
		break;
	case FLOAT:
		setStr2Float();
		setOutFloat();
		break;
	case DOUBLE:
		setStr2Double();
		setOutDouble();
		break;
	case OTHER:
		setImpossible();
		break;
	default:
		break;
	}
	// setOutStr();
}

std::ostream&	operator<<(std::ostream& os, const Conversion& conversion)
{
	os << "char: " << conversion.getCharStr() << "\n" << \
		  "int: " << conversion.getIntStr() << "\n" << \
		  "float: " << conversion.getFloatStr() << "\n" << \
		  "double: " << conversion.getDoubleStr();
	return os;
}