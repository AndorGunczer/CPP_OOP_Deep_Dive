#include "Data.hpp"

Data::Data() {}

Data::Data( std::string input ) : 
	_input(input),  _current(0), _charVal('\0'), _intVal(0), _floatVal(0.0f), _doubleVal(0.0),
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

const int&			Data::getCurrent() { return this->_current; }
const char&			Data::getChar() { return this->_charVal; }
const int&			Data::getInt() { return this->_intVal; }
const float&		Data::getFloat() { return this->_floatVal; }
const double&		Data::getDouble() { return this->_doubleVal; }

void	Data::setCurrent( const int& input ) { this->_current = input; }
void	Data::setChar( const char& input ) { this->_charVal = input; }
void	Data::setInt( const int& input ) { this->_intVal = input; }
void	Data::setFloat( const float& input ) { this->_floatVal = input; }
void	Data::setDouble( const double& input ) { this->_doubleVal = input; }

void	Data::isChar( int *typeSelector ) {
	std::cout << "isChar ran" << std::endl;
}

void	Data::isInt( int *typeSelector ) {
	std::cout << "isInt ran" << std::endl;
}

void	Data::isFloat( int *typeSelector ) {
	std::cout << "isFloat ran" << std::endl;
}

void	Data::isDouble( int *typeSelector ) {
	std::cout << "isDouble ran" << std::endl;
}


void	Data::convertToFloat( int *typeSelector ) {
	std::cout << "convertToFloat ran" << std::endl;
}

void	Data::convertToDouble( int *typeSelector ) {
	std::cout << "ConvertToDouble ran" << std::endl;
}

void	Data::convertToInt( int *typeSelector ) {
	std::cout << "convertToInt ran" << std::endl;
}

void	Data::convertToChar( int *typeSelector ) {
	std::cout << "convertToChar ran" << std::endl;	
}

void	Data::detectLiteral() {
	int *typeSelector = new int;
	// void (*ptr[4])(int *) = { &(this->convertToChar), &(this->convertToInt), &(this->convertToFloat), &(this->convertToDouble) };
	void (Data::*ptr[4])(int*) = { &Data::convertToChar, &Data::convertToInt, &Data::convertToFloat, &Data::convertToDouble };
	// method_function method_pointer[4] = {&Method::add, &Method::subtract,  &Method::multiply, &Method::divide};

	// ptr[0] = &Data::convertToChar;
	// ptr[1] = &Data::convertToInt;
	// ptr[2] = &Data::convertToFloat;
	// ptr[3] = &Data::convertToDouble;
	*typeSelector = 0;
	isChar( typeSelector );
	isInt( typeSelector );
	isFloat( typeSelector );
	isDouble( typeSelector );

	(this->*ptr[0])(typeSelector);

	switch (*typeSelector) {
		case 1: convertToChar( typeSelector ); break;
		case 2: convertToInt( typeSelector ); break;
		case 3: convertToFloat( typeSelector ); break;
		case 4: convertToDouble( typeSelector ); break;
		// default: nonSense();
	}

	// for (size_t i = 0; i < 4; i++)
	// {
	// 	if (i != *typeSelector)
	// 		ptr[i](typeSelector);
	// }
	

}

void	Data::printCurrent() {
	// switch (_current) {
	// 	case 1: std::cout << _charVal << std::endl; break;
	// 	case 2: std::cout << _intVal << std::endl; break;
	// 	case 3: std::cout << _floatVal << std::endl; break;
	// 	case 4: std::cout << _doubleVal << std::endl; break;
	// } 

	switch (_current) {
		case 1: std::cout << 1 << std::endl; break;
		case 2: std::cout << 2 << std::endl; break;
		case 3: std::cout << 3 << std::endl; break;
		case 4: std::cout << 4 << std::endl; break;
	}
}

