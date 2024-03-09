/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:53:34 by agunczer          #+#    #+#             */
/*   Updated: 2024/02/15 12:02:54 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>

template <class container_store, class container_type> class PmergeMe {
    private:
        char **input;
        
        std::pair<bool, int> _yi;
        container_store _pairs;
        container_type _finalVector;

        /* VECTOR FUNCTIONS */

        container_store _createContainerTypes(char **argv) {
            container_store _pairs;
             int i = 1;
             int x = 0;

                while (argv && argv[i]) {
                    container_type current_container_type;
                    while (argv && argv[i] && x / 2 != 1) {
                        int currentArgv = atoi(argv[i]);
                        if (currentArgv < 0)
                            throw std::invalid_argument("Error");
                        current_container_type.push_back(currentArgv);
                        i++;
                        x++;
                    }
                    x = 0;
                    _pairs.push_back(current_container_type);
                }
            
                return _pairs;
        };

        std::pair<bool, int> _popLast(container_store &_pairs) {
            bool isSolo = false;
            int yi;

            if (_pairs.back().size() == 1) {
                isSolo = true;
                yi = _pairs.back().front();
                _pairs.pop_back();
            }

            return std::pair<bool, int>(isSolo, yi);
        };

        void _sortPairs(container_store &_pairs) {
            typename container_store::iterator it = _pairs.begin();
            typename container_store::iterator ite = _pairs.end();

            while (it < ite) {
                std::sort(it->begin(), it->end());
                std::reverse(it->begin(), it->end());
                it++;
            }
        };

        container_store _mergeVectors(container_store vector1, container_store vector2) {
            container_store _finalVector;

            typename container_store::iterator it1 = vector1.begin();
            typename container_store::iterator ite1 = vector1.end();
            typename container_store::iterator it2 = vector2.begin();
            typename container_store::iterator ite2 = vector2.end();

            while(!vector1.empty() && !vector2.empty()) {
                int vector1Number = vector1.front().front();
                int vector2Number = vector2.front().front();
                int min = std::min(vector1Number, vector2Number);
        
                if (min == vector1Number) {
                    _finalVector.push_back(vector1.front());
                    vector1.erase(std::find(it1, ite1, vector1.front()));
                    it1 = vector1.begin();
                } else {
                    _finalVector.push_back(vector2.front());
                    vector2.erase(std::find(it2, ite2, vector2.front()));
                    it2 = vector2.begin();
                }
            }

            if (vector1.empty()) {
                while(!vector2.empty()) {
                // int vector2Number = vector2.front().front();

                    _finalVector.push_back(vector2.front());
                    vector2.erase(std::find(it2, ite2, vector2.front()));
                    it2 = vector2.begin();            
                }
            } else if (vector2.empty()) {
                while(!vector1.empty()) {
                    // int vector1Number = vector1.front().front();

                    _finalVector.push_back(vector1.front());
                    vector1.erase(std::find(it1, ite1, vector1.front()));
                    it1 = vector1.begin();            
                }        
            }

            return _finalVector;
        };

        container_store _mergeSort(container_store _pairs) {
            size_t size = _pairs.size();

            if (size == 0) {
                return _pairs;
            }
            if (size == 1)
                return _pairs;

            typename container_store::iterator low = _pairs.begin();
            typename container_store::iterator high = _pairs.end() - (size/2);

            container_store first(low, high);
            container_store second(high, _pairs.end());

            return _mergeVectors(_mergeSort(first), _mergeSort(second));
        };

        void _insertFirstofFirst(container_store &_pairs) {
            if (_pairs.front().size() <= 1)
                return;

            container_type toAdd;
            toAdd.push_back(_pairs.front().back());
            _pairs.front().pop_back();
            _pairs.insert(_pairs.begin(), toAdd); 
        };
        
        container_store _groupY(container_store _pairs) {
            container_type ungroupedY;
            container_store groupedY;

            {
                typename container_store::iterator it = _pairs.begin();
                typename container_store::iterator ite = _pairs.end();

                while (it != ite) {
                    if (it->size() > 1) {
                        ungroupedY.push_back(it->back());
                    }
                    it++;
                }
            }
            // printVector(ungroupedY);

            typename container_type::iterator it = ungroupedY.begin();
            typename container_type::iterator ite = ungroupedY.end();
            int position = 1;
            int size;

            while (it != ite) {
                size = _sequenceSolver(position);
                int i = 0;
                container_type currentBatch;
                while (it != ite && i < size) {
                    currentBatch.push_back(*it);
                    i++;
                    it++;
                }
                std::reverse(currentBatch.begin(), currentBatch.end());
                groupedY.push_back(currentBatch);
                position++;
            }

            return groupedY;
        };

        container_type _yXMerge(container_store _pairs, std::pair<bool, int> _yi) {
            container_type _finalVector;
            container_store groupedY = _groupY(_pairs);

            typename container_store::iterator it = _pairs.begin();
            typename container_store::iterator ite = _pairs.end();

            while (it != ite) {
                _finalVector.push_back(it->front());
                it++;
            }
    
            typename container_store::iterator groupedYit = groupedY.begin();
            typename container_store::iterator groupedYite = groupedY.end();

            while (groupedYit != groupedYite) {
                typename container_type::iterator firstOfGroupedYit = groupedYit->begin();
                typename container_type::iterator lastOfGroupedYit = groupedYit->end();

                while (firstOfGroupedYit != lastOfGroupedYit) {
                    typename container_type::iterator finalit = _finalVector.begin();
                    typename container_type::iterator finalite = _finalVector.end();
                    typename container_type::iterator toInsert = std::lower_bound(finalit, finalite, *firstOfGroupedYit);
            
                    _finalVector.insert(toInsert, *firstOfGroupedYit);
                    firstOfGroupedYit++;
                }
                groupedYit++;
            }
    
            if (_yi.first == true) {
                typename container_type::iterator finalit = _finalVector.begin();
                typename container_type::iterator finalite = _finalVector.end();
                typename container_type::iterator toInsert = std::lower_bound(finalit, finalite, _yi.second);

                _finalVector.insert(toInsert, _yi.second);
            }
    
            return _finalVector;
        };

        int _sequenceSolver(int position) {
            if (position == 1 || position == 2)
                return 2;
        
            return _sequenceSolver(position - 2) * 2 + _sequenceSolver(position - 1);
        };

    public:
        PmergeMe() {};
        PmergeMe(char **input) {
            this->input = input;
        };
        ~PmergeMe() {};
        PmergeMe(const PmergeMe &a) {
            *this = a;
        };
        const PmergeMe& operator=(const PmergeMe &a) {
            this->input = a.input;
            this->_yi = a._yi;
            this->_pairs = a._pairs;
            this->_finalVector = a._finalVector;
            return *this;
        };
        void run() {
            try {
                _pairs = _createContainerTypes(input);
            } catch (std::invalid_argument &e) {
                throw std::invalid_argument(e.what());
            }
            _yi = _popLast(_pairs);
            _sortPairs(_pairs);
            _pairs = _mergeSort(_pairs);
            _insertFirstofFirst(_pairs);
            _finalVector = _yXMerge(_pairs, _yi);
        };

        void printVector(std::vector<int> numberStore);
        
        void getPairs() {
            typename container_store::iterator it = _pairs.begin();
            typename container_store::iterator ite = _pairs.end();

            while (it != ite) {
                typename container_type::iterator itS = it->begin();
                typename container_type::iterator iteS = it->end();

                while(itS != iteS) {
                    std::cout << *itS << " ";

                    itS++;
                }
                std::cout << std::endl;
                it++;
            }
        };

        void getFinalVector() {
            typename container_type::iterator it = _finalVector.begin();
            typename container_type::iterator ite = _finalVector.end();

            while (it < ite) {
                std::cout << *it << " ";
                it++;
            }

            std::cout << std::endl;
        };

        void exercisePrint() {
            int i = 1;
            std::cout << "Before: ";
            while (input && input[i]) {
                std::cout << input[i] << " ";
                i++;
            }
            std::cout << std::endl;
            std::cout << "After: "; getFinalVector();
        };
};