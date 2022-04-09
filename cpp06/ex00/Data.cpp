#include "Data.hpp"

Data::Data() {}

Data::Data( std::string input ) : 
	_input(input),  typeSelector(new int), _charVal('\0'), _intVal(0), _floatVal(0.0f), _doubleVal(0.0),
	_charError(""), _intError(""), _floatError(""), _doubleError("") {
	return ;
}

Data::~Data() {}

Data::Data( const Data& obj ) {
	*this = obj;
}

// void	Data::operator=( const Data& obj ) {
// 	*this = obj;
// }

// const int&			Data::getCurrent() { return this->_current; }
const char&			Data::getChar() { return this->_charVal; }
const int&			Data::getInt() { return this->_intVal; }
const float&		Data::getFloat() { return this->_floatVal; }
const double&		Data::getDouble() { return this->_doubleVal; }

// void	Data::setCurrent( const int& input ) { this->_current = input; }
void	Data::setChar( const char& input ) { this->_charVal = input; }
void	Data::setInt( const int& input ) { this->_intVal = input; }
void	Data::setFloat( const float& input ) { this->_floatVal = input; }
void	Data::setDouble( const double& input ) { this->_doubleVal = input; }

void	Data::isChar() {
	if ( _input.size() == 1 && std::isdigit(_input[0]) == 0 ) {
		/* rangeCheck */
		if (_input[0] >= 0 && _input[0] < 128)
			*typeSelector = 1;
	}
}

void	Data::isInt() {
	int	inputSize = _input.size();
	bool isDigit = true;
	long long	rangeCheck;

	for (size_t i = 0; i < inputSize; i++) {
		if (std::isdigit(_input[i]) == 0)
			isDigit = false;
	}
	if (isDigit) {
		rangeCheck = stoll(_input);
		if (rangeCheck >= INT_MIN && rangeCheck <= INT_MAX)
			*typeSelector = 2;
	}
}
//-inff , +inff and nan
void	Data::isFloat() {
	int	inputSize = _input.size();
	bool isFloat = true;
	bool dot = false;

	// Special Type Handling

	if (_input.compare("-inff") == 0) {
		_floatError = "-inff";
		*typeSelector = 3;
		return ;
	}
	if (_input.compare("+inff") == 0) {
		_floatError = "+inff";
		*typeSelector = 3;
		return ;
	}
	if (_input.compare("nanf") == 0) {
		_floatError = "nanf";
		*typeSelector = 3;
		return ;
	}

	if (_input[0] == '.')
		return ;

	for (size_t i = 0; i < inputSize; i++) {
		if (std::isdigit(_input[i]) == 0 && i != (inputSize - 1)) {
			if (_input[i] == '.' && dot == false)
				dot = true;
			else if (_input[i] == '.' && dot == true)
				isFloat = false;
			else
				isFloat = false;
		}
	}
	if (_input[inputSize - 1] != 'f')
		isFloat = false;
	if (isFloat && dot)
		*typeSelector = 3;
}

//-inf, +inf and nan
void	Data::isDouble() {
	int	inputSize = _input.size();
	bool isDouble = true;
	bool dot = false;

	if (_input.compare("-inf") == 0) {
		_floatError = "-inf";
		*typeSelector = 4;
		return ;
	}
	if (_input.compare("+inf") == 0) {
		_floatError = "+inf";
		*typeSelector = 4;
		return ;
	}
	if (_input.compare("nan") == 0) {
		_floatError = "nan";
		*typeSelector = 4;
		return ;
	}

	if (_input[0] == '.')
		return ;

	for (size_t i = 0; i < inputSize; i++) {
		if (std::isdigit(_input[i]) == 0) {
			if (_input[i] == '.' && dot == false)
				dot = true;
			else if (_input[i] == '.' && dot == true)
				isDouble = false;
			else
				isDouble = false;
		}
	}
	if (isDouble && dot)
		*typeSelector = 4;
}


void	Data::convertToFloat() {
	if (*typeSelector == 3 && _floatError.compare("") == 0)
		_floatVal = stof(_input);
	else if (*typeSelector == 1)
		_floatVal = static_cast<float>(_charVal);
	else if (*typeSelector == 2)
		_floatVal = static_cast<float>(_intVal);
	else if (*typeSelector == 4) {
		_floatError = checkFloatingPointOrigin();
		if (_floatError.compare("") == 0)
			_floatVal = static_cast<float>(_doubleVal);
		else
			_floatError.push_back('f');
	}
}

void	Data::convertToDouble() {
	if (*typeSelector == 4 && _doubleError.compare("") == 0)
		_doubleVal = stod(_input);
	else if (*typeSelector == 1)
		_doubleVal = static_cast<double>(_charVal);
	else if (*typeSelector == 2)
		_doubleVal = static_cast<double>(_intVal);
	else if (*typeSelector == 3) {
		_doubleError = checkFloatingPointOrigin();
		if (_doubleError.compare("") == 0)
			_doubleVal = static_cast<double>(_floatVal);
		else
			_doubleError.pop_back();
	}
}

void	Data::convertToInt() {
	if (*typeSelector == 2)
		_intVal = stoi(_input);
	else if (*typeSelector == 1)
		_intVal = static_cast<int>(_charVal);
	else if (*typeSelector == 3) {
		if (checkFloatingPointOrigin().compare("") != 0 || !(_floatVal >= INT_MIN && _floatVal <= INT_MAX))
			_intError = "impossible";
		else
			_intVal = static_cast<int>(_floatVal);
	}
	else if (*typeSelector == 4) {
		if (checkFloatingPointOrigin().compare("") != 0 || !(_doubleVal >= INT_MIN && _doubleVal <= INT_MAX))
			_intError = "impossible";
		else
			_intVal = static_cast<int>(_doubleVal);
	}
}

void	Data::convertToChar() {
	if (*typeSelector == 1)
		_charVal = _input[0];
	else if (*typeSelector == 2) {
		if (!(_intVal >= 0 && _intVal <= 127))
			_charError = "impossible";
		else
			_charVal = static_cast<char>(_intVal);
	}
	else if (*typeSelector == 3) {
		if (checkFloatingPointOrigin().compare("") != 0 || !(_floatVal >= 0 && _floatVal <= 127))
			_charError = "impossible";
		else
			_charVal = static_cast<char>(_floatVal);
	}
	else if (*typeSelector == 4) {
		if (checkFloatingPointOrigin().compare("") != 0 || !(_doubleVal >= 0 && _doubleVal <= 127))
			_charError = "impossible";
		else
			_charVal = static_cast<char>(_doubleVal);
	}
}

void	Data::nonsense() {
	_charError = "impossible";
	_intError = "impossible";
	_floatError = "impossible";
	_doubleError = "impossible";
}

void	Data::converter() {
	void (Data::*ptr[4])() = { &Data::convertToChar, &Data::convertToInt, &Data::convertToFloat, &Data::convertToDouble };

	*typeSelector = 0;
	isChar();
	isInt();
	isFloat();
	isDouble();

	if (*typeSelector == 0) {
		nonsense();
		return ;
	}

	switch (*typeSelector) {
		case 1: convertToChar(); break;
		case 2: convertToInt(); break;
		case 3: convertToFloat(); break;
		case 4: convertToDouble(); break;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (i + 1 != *typeSelector)
			(this->*ptr[i])();
	}
}

std::string	Data::checkFloatingPointOrigin() {
	const char * c = _input.c_str();

	if (*typeSelector == 3) {
		if (std::strcmp(c, "nanf") == 0)
			return "nanf";
		else if (std::strcmp(c, "-inff") == 0)
			return "-inff";
		else if (std::strcmp(c, "+inff") == 0)
			return "+inff";
	}
	else if (*typeSelector == 4) {
		if (std::strcmp(c, "nan") == 0)
			return "nan";
		else if (std::strcmp(c, "-inf") == 0)
			return "-inf";
		else if (std::strcmp(c, "+inf") == 0)
			return "+inf";
	}
	return "";
}

void	Data::printCurrent() {
	switch (*typeSelector) {
		case 1: std::cout << _charVal << std::endl; break;
		case 2: std::cout << _intVal << std::endl; break;
		case 3: std::cout << _floatVal << std::endl; break;
		case 4: std::cout << _doubleVal << std::endl; break;
	}

	// switch (_current) {
	// 	case 1: std::cout << 1 << std::endl; break;
	// 	case 2: std::cout << 2 << std::endl; break;
	// 	case 3: std::cout << 3 << std::endl; break;
	// 	case 4: std::cout << 4 << std::endl; break;
	// }
}

void	Data::printAll() {
	if (_charError.compare("") == 0)
		std::cout << "char: " << _charVal << std::endl;
	else
		std::cout << "char: " << _charError << std::endl;
	if (_intError.compare("") == 0)
		std::cout << "int: " << _intVal << std::endl;
	else
		std::cout << "int: " << _intError << std::endl;
	if (_floatError.compare("") == 0)
		std::cout << "float: " << _floatVal << "f" << std::endl;
	else
		std::cout << "float: " << _floatError << std::endl;
	if (_doubleError.compare("") == 0)
		std::cout << "double: " << _doubleVal << std::endl;
	else
		std::cout << "double: " << _doubleError << std::endl;
}

