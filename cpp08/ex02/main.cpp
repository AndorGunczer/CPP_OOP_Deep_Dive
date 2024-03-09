/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:06 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/06 13:17:29 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main()
{

    {
        std::cout << "Self Implemented Test 1:" << std::endl << std::endl;
        MutantStack<int> test;
        test.push(3);
        test.push(6);
        test.push(9);

        MutantStack<int>::iterator start = test.begin();
        MutantStack<int>::iterator end = test.end();

        for(; start < end; start++)
        {
            std::cout << *start << std::endl;
        }
    }
    
    {
        std::cout << "Provided Test with Stack:" << std::endl << std::endl;

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;

        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;--it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }

std::cout << "\n\n";

    {
        std::cout << "Provided Test with List:" << std::endl << std::endl;

        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;

        mstack.pop_back();
        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;--it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(mstack);

        std::cout << std::endl;
    }

    {
        std::cout << "Copy Constructor Test:" << std::endl << std::endl;

        MutantStack<double> ptr1;
        MutantStack<double> ptr2((const MutantStack<double> &)ptr1);

        std::cout << "Address 1: " << &ptr1 << std::endl;
        std::cout << "Address 2: " << &ptr2 << std::endl;

        std::cout << std::endl;
    }

    {
        std::cout << "Operator= Test:" << std::endl << std::endl;

        MutantStack<double> ptr1;
        MutantStack<double> ptr2 = ptr1;

        std::cout << "Address 1: " << &ptr1 << std::endl;
        std::cout << "Address 2: " << &ptr2 << std::endl;

        std::cout << std::endl;
    }
    
    return 0;
}