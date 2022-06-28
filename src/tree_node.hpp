#ifndef TREE_NODE_INCLUDED_HPP
#define TREE_NODE_INCLUDED_HPP

#include <memory>

namespace paa {
namespace t3 {

template<typename T>
struct b_tree_node_t
{
    b_tree_node_t(const T value) : data(value){};
    long height() const {
        long lh = (!lnode) ? 0 : lnode->height();
        long rh = (!rnode) ? 0 : rnode->height();
        return (lh > rh) ? lh + 1 : rh + 1;
    };
    long balance() const {
        long lh = (!lnode) ? 0 : lnode->height();
        long rh = (!rnode) ? 0 : rnode->height();
        return rh - lh;
    };
    T data;
    std::shared_ptr<b_tree_node_t<T>> parent;
    std::shared_ptr<b_tree_node_t<T>> lnode, rnode;
};

}} // namespace paa::t3


#endif