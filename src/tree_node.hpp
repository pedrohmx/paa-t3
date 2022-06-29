#ifndef TREE_NODE_INCLUDED_HPP
#define TREE_NODE_INCLUDED_HPP

#include <memory>

namespace paa {
namespace t3 {

template<typename T>
struct b_tree_node_t : std::enable_shared_from_this<b_tree_node_t<T>>
{
    b_tree_node_t(const T value) : data(value){};
    std::shared_ptr<b_tree_node_t<T>> get_ptr(){return this->shared_from_this();}
    
    T data;
    std::shared_ptr<b_tree_node_t<T>> parent;
    std::shared_ptr<b_tree_node_t<T>> lnode, rnode;
    
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
    std::shared_ptr<b_tree_node_t<T>> rotate_right(){
        auto X = this->shared_from_this();
        auto Y = X->lnode;
        // right rotation
        X->lnode = Y->rnode;
        Y->rnode = X;
        // return new node at startind spot
        return Y;
    };
    std::shared_ptr<b_tree_node_t<T>> rotate_left(){
        auto X = this->shared_from_this();
        auto Y = X->rnode;
        // left rotation
        X->rnode = Y->lnode;
        Y->lnode = X;
        // return new node at startind spot
        return Y;
    };

};

}} // namespace paa::t3


#endif