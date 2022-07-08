#ifndef TREE_NODE_INCLUDED_HPP
#define TREE_NODE_INCLUDED_HPP

#include <memory>

namespace paa {
namespace t3 {

struct node_t {
    node_t(const int value) : data(value){};
    ~node_t() {
        if (lnode) delete lnode;
        if (rnode) delete rnode;
    };
    
    int data, height = 1;
    node_t *lnode = nullptr, *rnode = nullptr;

    int get_height()  const { return height; };
    int get_balance() const {
        int lh = (!lnode) ? 0 : lnode->height;
        int rh = (!rnode) ? 0 : rnode->height;
        return lh - rh;
    };
};

node_t * rotate_right(node_t * X) {
    //     X           Y
    //    / \         / \ 
    //   Y   C  ->   A   X
    //  / \             / \ 
    // A   B           B   C
    auto Y = X->lnode;
    // right rotation
    X->lnode = Y->rnode;
    Y->rnode = X;
    // update heights
    int lh, rh;
    lh = !(X->lnode) ? 0 : X->lnode->height;
    rh = !(X->rnode) ? 0 : X->rnode->height;
    X->height = 1 + ((lh > rh) ? lh : rh);
    lh = !(Y->lnode) ? 0 : Y->lnode->height;
    rh = !(Y->rnode) ? 0 : Y->rnode->height;
    Y->height = 1 + ((lh > rh) ? lh : rh);
    // return new node at starting spot
    return Y;
};

node_t * rotate_left(node_t * Y){
    //     Y           X
    //    / \         / \ 
    //   A   X  ->   Y   C
    //      / \     / \ 
    //     B   C   A   B
    auto X = Y->rnode;
    // left rotation
    Y->rnode = X->lnode;
    X->lnode = Y;
    //update heights
    int lh, rh;
    lh = !(Y->lnode) ? 0 : Y->lnode->height;
    rh = !(Y->rnode) ? 0 : Y->rnode->height;
    Y->height = 1 + ((lh > rh) ? lh : rh);
    lh = !(X->lnode) ? 0 : X->lnode->height;
    rh = !(X->rnode) ? 0 : X->rnode->height;
    X->height = 1 + ((lh > rh) ? lh : rh);
    // return new node at starting spot
    return X;
};

}} // namespace paa::t3


#endif