/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:36 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/05 11:33:36 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T> class MutantStack: public std::stack<T> {

    public:
        typedef typename std::deque<T>::iterator    iterator;
        
        MutantStack() {

        }
        
        ~MutantStack() {

        }

        MutantStack<T>(const MutantStack<T> & toCopy) {
            *this = toCopy;
        }

        MutantStack<T> &operator=(const MutantStack<T>& toCopy) {
            std::stack<T>::operator=(toCopy);
            return *this;
        };

        iterator begin() {
            return this->c.begin();
        };

        iterator end() {
            return this->c.end();
        };
};