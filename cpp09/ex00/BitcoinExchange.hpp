/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:50:07 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/15 11:58:55 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <fstream>
#include <map>
#include <ctime>
#include <cstdlib>

class BitcoinExchange {
    private:
        struct Comp {
            bool operator()(const tm& time1, const tm& time2) const;
        };
        std::multimap<struct tm, float, struct BitcoinExchange::Comp> _inputStore;
        std::multimap<struct tm, float, struct BitcoinExchange::Comp> _db;

        /* PARSING FUNCTIONS */
        std::multimap<std::string, std::string> _parse(char *inputFileName, char delimiter);
        int _check_if_empty(std::string str);
        int _date_check(std::string str);
        int _value_check(std::string str);
        std::string _trim(std::string str);

        /* CONVERSION FUNCTIONS */
        std::multimap<struct tm, float, struct BitcoinExchange::Comp> _convertMap(std::multimap<std::string, std::string> mapToConvert);
        
        /* CALCULATION FUNCTIONS */
        std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator _findIndexToComp(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc);
        bool _my_map_find(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc, std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_itc);
        void _calculate(std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator input_itc, std::multimap<struct tm, float, struct BitcoinExchange::Comp>::iterator db_itc);

        /* ERROR CHECKS FOR CONVERTED VALUES */
        void _check_year_bounds(float year);
        void _check_month_bounds(float month);
        void _check_day_bounds(float year, float month, float day);
        void _check_value(float value);

        /* PRINT MAP CONTENT */
        void _print_map(std::multimap<std::string, std::string> mapToPrint);
        void _print_map(std::multimap<struct tm, float, struct BitcoinExchange::Comp> mapToPrint);

    public:
        BitcoinExchange();
        BitcoinExchange(char *inputFileName);
        BitcoinExchange(const BitcoinExchange &a);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &a);

        /* RUN PROGRAM */
        void run();

};