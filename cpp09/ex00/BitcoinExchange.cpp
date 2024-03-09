/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:50:09 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/15 11:58:05 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Custom Comparator for Multimap /~ By agunczer ^^ */

bool BitcoinExchange::Comp::operator()(const tm& time1, const tm& time2) const {
    // Compare the 2 locations, return true if loc1 is less than loc2
    if (time1.tm_year > time2.tm_year) {
        return true;
    } else if (time1.tm_year < time2.tm_year){
        return false;
    } else {
        if (time1.tm_mon > time2.tm_mon)
            return true;
        else if (time1.tm_mon < time2.tm_mon)
            return false;
        else {
            if (time1.tm_mday > time2.tm_mday)
                return true;
            else
                return false;
        }
    }
}

int BitcoinExchange::_check_if_empty(std::string str) {
    if (str.length() == 0)
        return -1;
    else
        return 0;
}

int BitcoinExchange::_date_check(std::string str) {
    std::string::iterator it = str.begin();
    std::string::iterator ite = str.end();
    int year = 0, month = 0, day = 0;

    while(it < ite && year < 4) {
        if (!isdigit(*it)) {
            std::cout << *it << std::endl;
            return 1;
        }

        it++; year++;
    }

    if (it < ite && *it == '-')
        it++;
    else
        return 1;

    while(it < ite && month < 2) {
        if (!isdigit(*it)) {
            std::cout << *it << "month" << std::endl;
            return 1;
        }

        it++; month++;
    }

    if (it < ite && *it == '-')
        it++;
    else
        return 1;

    while(it < ite && day < 2) {
        if (!isdigit(*it)) {
            std::cout << *it << std::endl;
            return 1;
        }

        it++; day++;
    }

    return 0;
}

int BitcoinExchange::_value_check(std::string str) {
    std::string::iterator it = str.begin();
    std::string::iterator ite = str.end();
    int dotCount = 0;

    if (*it == '-')
        it++;

    while(it < ite) {
        if (!isdigit(*it) && *it != '.') {
            std::cout << *it << " not a number" << std::endl;
            return 1;
        } else if (*it == '.')
            dotCount++;

        it++;
    }

    if (dotCount > 1)
        return 1;

    return 0;
}

std::string BitcoinExchange::_trim(std::string str) {
    std::string::iterator it = str.begin();
    std::string::iterator ite = str.end();

    while(it < ite) {
        if (*it == ' ' || *it == '\n' || *it == '\t')
            str.erase(it);
        it++;
    }

    return str;
}

void BitcoinExchange::_print_map(std::multimap<std::string, std::string> mapToPrint) {
    std::multimap<std::string, std::string>::iterator it = mapToPrint.begin();
    std::multimap<std::string, std::string>::iterator ite = mapToPrint.end();

    for(; it != ite; it++)
        std::cout << it->first << ";" << it->second << ";" << std::endl;
}

void BitcoinExchange::_print_map(std::multimap<struct tm, float, struct BitcoinExchange::Comp> mapToPrint) {
    std::multimap<struct tm, float, BitcoinExchange::Comp>::iterator it = mapToPrint.begin();
    std::multimap<struct tm, float, BitcoinExchange::Comp>::iterator ite = mapToPrint.end();

    for(; it != ite; it++) {
        std::cout << "Date:\n"
        << "\tYear: " << it->first.tm_year << "\n"
        << "\tMonth " << it->first.tm_mon << "\n"
        << "\tDay: " << it->first.tm_mday << "\n"
        << "Value:\n"
        << "\t= " << it->second << "\n\n" << std::endl;
    }
}

std::multimap<std::string, std::string> BitcoinExchange::_parse(char *inputFileName, char delimiter) {
    std::ifstream myfile;
    std::multimap<std::string, std::string> stringStore;
    int i = 0;

    myfile.open(inputFileName);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            std::string str;
            std::getline(myfile, str, '\n');
            std::string first, second;

            if (i++ == 0)
                continue;

            str = _trim(str);
            if (_check_if_empty(str) == -1)
            {
                if (i == 1) {
                    std::multimap<std::string, std::string> emptyStore;
                    return emptyStore;
                } else {
                    break;
                }
            } 

            unsigned long delimiter_pos = str.find(delimiter);
            // std::cout << delimiter_pos << std::endl;

            if (_check_if_empty(str) == -1 || delimiter_pos == str.npos){
                std::multimap<std::string, std::string> emptyStore;
                return emptyStore;
            }

            first = str.substr(0, delimiter_pos);
            second = str.substr(delimiter_pos + 1);

            if (_date_check(first) != 0 || _value_check(second) != 0) {
                std::multimap<std::string, std::string> emptyStore;
                return emptyStore;
            }

            if (str.length() > delimiter_pos) {
                stringStore.insert(std::pair<std::string, std::string>(first, second));
            }
        }
        myfile.close();
    } else {
        throw std::invalid_argument("Error: File Cannot Be Opened");
    }

    return stringStore;
}

std::multimap<struct tm, float, struct BitcoinExchange::Comp> BitcoinExchange::_convertMap(std::multimap<std::string, std::string> mapToConvert) {
    std::multimap<std::string, std::string>::iterator it = mapToConvert.begin();
    std::multimap<std::string, std::string>::iterator ite = mapToConvert.end();
    std::multimap<struct tm, float, struct BitcoinExchange::Comp> returnMap;

    for (; it != ite; it++) {
        struct tm dbDate;
        dbDate.tm_year = atoi(it->first.substr(0, 4).c_str());
        dbDate.tm_mon = atoi(it->first.substr(5, 2).c_str());
        dbDate.tm_mday = atoi(it->first.substr(8, 2).c_str());
        float number = atof(it->second.c_str());

        returnMap.insert(std::pair<struct tm, float>(dbDate, number));
    }
    
    return returnMap;
}

/* PROGRAM EXECUTION */

void BitcoinExchange::_check_year_bounds(float year) {
    /* LOWER BOUND 2009-01-02 UPPER BOUND:  2022-03-29 */

    if (year > 2022)
        throw std::invalid_argument("Invalid Year: Too High");
    if (year < 2009)
        throw std::invalid_argument("Invalid Year: Too Low");
}

void BitcoinExchange::_check_month_bounds(float month) {
    if (month < 1)
        throw std::invalid_argument("Invalid Month: Too Low");
    if (month > 12)
        throw std::invalid_argument("Invalid Month: Too High");
}

void BitcoinExchange::_check_day_bounds(float year, float month, float day) {
    if (month == 2) {
        if (((int)year) % 4 == 0 && (day < 1 || day > 29))
            throw std::invalid_argument("Invalid Day");
        else if (day < 1 || day > 28)
            throw std::invalid_argument("Invalid Day");
    } else if (((int)month) % 2 == 0) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
            month == 10 || month == 12) {
                if (day < 1 || day > 31)
                    throw std::invalid_argument("Invalid Day");
            }
    } else if (month == 2 || month == 4 || month == 6 || month == 9 ||
        month == 11) {
            if (day < 1 || day > 30)
                throw std::invalid_argument("Invalid Day");
        }
}

void BitcoinExchange::_check_value(float value) {
    if (value < 0)
        throw std::invalid_argument("Error: not a positive number");
    if (value > 1000)
        throw std::invalid_argument("Error: number too high");
}

bool BitcoinExchange::_my_map_find(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc, std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_itc) {
    if (input_itc->first.tm_year < db_itc->first.tm_year)
        return false;
    if (input_itc->first.tm_mon < db_itc->first.tm_mon)
        return false;
    if (input_itc->first.tm_mday < db_itc->first.tm_mday)
        return false;

    return true;
}

std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator BitcoinExchange::_findIndexToComp(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc) {
    std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_it = _db.begin();
    std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_ite = _db.end();

    while (db_it != db_ite) {
        // std::cout << db_it->first.tm_year << "-" << db_it->first.tm_mon << "-" << db_it->first.tm_mday << std::endl;
        if (_my_map_find(input_itc, db_it) == true)
            break;
        db_it++;
    }

    // std::cout << input_itc->first.tm_year << "-" << input_itc->first.tm_mon << "-" << input_itc->first.tm_mday << std::endl;
    // std::cout << db_it->first.tm_year << "-" << db_it->first.tm_mon << "-" << db_it->first.tm_mday << std::endl << std::endl;
    return db_it;
}

void BitcoinExchange::_calculate(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc, std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_itc) {
    float value = db_itc->second * input_itc->second;

    std::cout << input_itc->first.tm_year << "-" << input_itc->first.tm_mon << "-" << input_itc->first.tm_mday << " => " << input_itc->second << " = " << value << std::endl;
}

void BitcoinExchange::run() {
    std::multimap<struct tm, float, BitcoinExchange::Comp>::iterator it = this->_inputStore.begin();
    std::multimap<struct tm, float, BitcoinExchange::Comp>::iterator ite = this->_inputStore.end();

    while (it != ite) {
        try {
            _check_year_bounds(it->first.tm_year);
            _check_month_bounds(it->first.tm_mon);
            _check_day_bounds(it->first.tm_year, it->first.tm_mon, it->first.tm_mday);
            _check_value(it->second);
        } catch(std::invalid_argument &e) {
            throw std::invalid_argument(e.what());
        }

        try {
            _calculate(it, _findIndexToComp(it));
        } catch(std::invalid_argument &e) {
            throw std::invalid_argument(e.what());
        }


        // std::cout << << std::endl;
        it++;
    }
}

/* END */

BitcoinExchange::BitcoinExchange(char *inputFileName) {
    char csv[] = "data.csv";
    std::multimap<std::string, std::string> stringStore;
    std::multimap<std::string, std::string> dbStore;

    try {
        stringStore = _parse(inputFileName, '|');
        dbStore = _parse(csv, ',');
    } catch(std::invalid_argument &e) {
        throw std::invalid_argument(e.what());
    }

    _inputStore = _convertMap(stringStore);
    if (_inputStore.empty())
        throw std::invalid_argument("Input File is Invalid");
    _db = _convertMap(dbStore);
    if (_db.empty())
        throw std::invalid_argument("Database us Invalid");
    
    // _print_map(_inputStore);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a) {
    *this = a;
}

BitcoinExchange::~BitcoinExchange() {
    
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &a) {
    this->_inputStore = a._inputStore;
    this->_db = a._db;
    return *this;
}

