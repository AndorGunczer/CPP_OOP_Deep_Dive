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

void	Data::isChar( int *typeSelector ) {
	if ( _input.size() == 1 && std::isdigit(_input[0]) == 0 )
		*typeSelector = 1;
}

void	Data::isInt( int *typeSelector ) {
	int	inputSize = _input.size();
	bool isDigit = true;

	for (size_t i = 0; i < inputSize; i++) {
		if (std::isdigit(_input[i]) == 0)
			isDigit = false;
	}
	if (isDigit)
		*typeSelector = 2;
}
//-inff , +inff and nan
void	Data::isFloat( int *typeSelector ) {
	int	inputSize = _input.size();
	bool isFloat = true;
	bool dot = false;

	// Special Type Handling

	// if (std::strcmp(_input, "-inff"))

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
void	Data::isDouble( int *typeSelector ) {
	int	inputSize = _input.size();
	bool isDouble = true;
	bool dot = false;

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


void	Data::convertToFloat( int *typeSelector ) {
	if (*typeSelector == 3)
		_floatVal = stof(_input);
	else if (*typeSelector == 1)
		_floatVal = static_cast<float>(_charVal);
	else if (*typeSelector == 2)
		_floatVal = static_cast<float>(_intVal);
	else if (*typeSelector == 4)
		_floatVal = static_cast<float>(_doubleVal);
}

void	Data::convertToDouble( int *typeSelector ) {
	if (*typeSelector == 4)
		_doubleVal = stod(_input);
	else if (*typeSelector == 1)
		_doubleVal = static_cast<double>(_charVal);
	else if (*typeSelector == 2)
		_doubleVal = static_cast<double>(_intVal);
	else if (*typeSelector == 3)
		_doubleVal = static_cast<double>(_floatVal);
}

void	Data::convertToInt( int *typeSelector ) {
	if (*typeSelector == 2)
		_intVal = stoi(_input);
	else if (*typeSelector == 1)
		_intVal = static_cast<int>(_charVal);
	else if (*typeSelector == 3)
		_intVal = static_cast<int>(_floatVal);
	else if (*typeSelector == 4)
		_intVal = static_cast<int>(_doubleVal);
}

void	Data::convertToChar( int *typeSelector ) {
	if (*typeSelector == 1)
		_charVal = _input[0];
	else if (*typeSelector == 2)
		_charVal = static_cast<char>(_intVal);
	else if (*typeSelector == 3)
		_charVal = static_cast<char>(_floatVal);
	else if (*typeSelector == 4)
		_charVal = static_cast<char>(_doubleVal);
}

void	Data::converter() {
	// int *typeSelector = new int;
	void (Data::*ptr[4])(int*) = { &Data::convertToChar, &Data::convertToInt, &Data::convertToFloat, &Data::convertToDouble };

	*typeSelector = 0;
	isChar( typeSelector );
	isInt( typeSelector );
	isFloat( typeSelector );
	isDouble( typeSelector );

	switch (*typeSelector) {
		case 1: convertToChar( typeSelector ); break;
		case 2: convertToInt( typeSelector ); break;
		case 3: convertToFloat( typeSelector ); break;
		case 4: convertToDouble( typeSelector ); break;
		// default: nonSense();
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (i + 1 != *typeSelector)
			(this->*ptr[i])(typeSelector);
	}
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
	std::cout << _charVal << std::endl;
	std::cout << _intVal << std::endl;
	std::cout << _floatVal << std::endl;
	std::cout << _doubleVal << std::endl;
}

