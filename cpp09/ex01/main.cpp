/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:51:55 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/12 14:21:40 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <cstdlib>
#include <sstream>

bool isNumber(const char *str) {
    int i = 0;
    int dotCount = 0;
    
    if (str[i] == '-' && str[i + 1])
        i++;

    while(str && str[i] != '\0') {
        if (!isdigit(str[i]) && str[i] != '.') {
            // std::cout << str[i] << " not a number" << std::endl;
            return 0;
        } else if (str[i] == '.')
            dotCount++;

        i++;
    }

    if (dotCount > 1)
        return 0;

    return 1;
}

bool isOperand(const char *str) {
    if ((str[0] == '-' || str[0] == '+' || str[0] == '*' || str[0] == '/') && !str[1])
        return true;
    else
        return false;
}

int main(int argc, char **argv) {
    std::stack<int> rpnStack;
    int i = 1;

    if (argc != 2)
        return -1;

    std::string s = argv[1], str;
    std::stringstream ss(s);

    while (std::getline(ss, str, ' ')) {

        // std::cout << str << std::endl;
        
        try {
            if (isNumber(str.c_str())) {
                int number = atoi(str.c_str());
                if (number > 9 || number < 0)
                    throw std::invalid_argument("Error: Number not smaller than 10");
                else
                    rpnStack.push(atoi(str.c_str())); 
            } else if (isOperand(str.c_str())) {
                if (rpnStack.empty())
                    throw std::invalid_argument("Error: Stack is Empty -> Wrong Format");
                int operand2 = rpnStack.top(); rpnStack.pop();
                if (rpnStack.empty())
                    throw std::invalid_argument("Error: Stack is Empty -> Wrong Format");
                int operand1 = rpnStack.top(); rpnStack.pop();
                
                switch(str.c_str()[0]) {
                    case '+': rpnStack.push(operand1 + operand2);
                        break;
                    case '-': rpnStack.push(operand1 - operand2); 
                        break;
                    case '*': rpnStack.push(operand1 * operand2); 
                        break;
                    case '/': rpnStack.push(operand1 / operand2); 
                        break;
                }
            } else {
                throw std::invalid_argument("Error");
            }
        } catch(std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            return -1;
        }

        i++;
        // std::cout << rpnStack.top() << std::endl;
    }

    std::cout << rpnStack.top() << std::endl;
}