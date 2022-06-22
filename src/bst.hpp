#ifndef BST_INCLUDED_HPP
#define BST_INCLUDED_HPP

#include <memory>
#include <iostream>

#include "tree_node.hpp"

namespace paa {
namespace t3 {

template<typename T>
class BST {
public:
    auto insert(const T &&value, int &count) {
        return _insert(this->root, value, count);
    };
    auto insert(const T  &value, int &count) {
        return _insert(this->root, value, count);
    };
    auto search(T value, int &count) {};
    void in_place() {
        _in_place(this->root);
        std::cout << std::endl;
    };
private:
    using node_t = b_tree_node_t<T>;

    std::shared_ptr<node_t> root;

    auto _insert(std::shared_ptr<node_t> &node, const T &value, int &count) {
        // if node is null
        if (!node) {
            node = std::make_shared<node_t>(node_t{value});
            return node;
        }
        // if it needs to travel deeper in the tree
        if (value < node->data) {
            // Insert into left sub tree
            return _insert(node->lnode, value, count);
        } else if (value > node->data) {
            // Insert into rigth sub tree
            return _insert(node->rnode, value, count);
        }
        // if element is already in the tree
        // return its node
        return node;
    }
    void _in_place(const std::shared_ptr<node_t> &node) {
        if (node) {
            _in_place(node->lnode);
            std::cout << node->data << " ";
            _in_place(node->rnode);
        }
    };
};

}} // namespace paa::t3


#endif