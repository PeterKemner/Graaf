#include "node.hpp"


/**
 * @brief Comparable voor Node klasse
 * 
 */
struct NodeComparable{
    bool operator()(const Node* lhs, const Node* rhs) const{
        return *lhs > *rhs;
    }
};



/**
 * @brief Generieke implementatie voor studenten die stap (en subklassen van stap) willen comparen.
 * 
 * @tparam T 
 */
template<typename T>
struct Comparable{
    bool operator()(const T* lhs, const T* rhs) const{
        return *lhs > *rhs;
    }
};