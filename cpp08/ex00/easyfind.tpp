/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:34:08 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/05 11:34:08 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <class T> typename T::iterator easyFind(T *sourceArray, int toFind) {
    typename T::iterator start = sourceArray->begin();
    typename T::iterator end = sourceArray->end();

    typename T::iterator found = std::find(start, end, toFind);
    if (*found == toFind)
        return found;
    else
        return found;
}