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
    auto insert(const T &&value, long &count) {
        return _insert(this->root, value, count);
    };
    auto insert(const T  &value, long &count) {
        return _insert(this->root, value, count);
    };
    auto search(const T  &value, long &count) {
        return _search(this->root, value, count);
    };
    void in_place() {
        _in_place(this->root);
        std::cout << std::endl;
    };
private:
    using node_t = b_tree_node_t<T>;

    std::shared_ptr<node_t> root;

    auto _insert(std::shared_ptr<node_t> &node, const T &value, long &count) {
        // if node is null
        if (!node) {
            node = std::make_shared<node_t>(node_t{value});
            return node;
        }
        // if it needs to travel deeper in the tree
        count++;
        if (value < node->data) {
            // Insert into left sub tree
            return _insert(node->lnode, value, count);
        }
        count++;
        if (value > node->data) {
            // Insert into rigth sub tree
            return _insert(node->rnode, value, count);
        }
        // if element is already in the tree
        // return its node
        return node;
    }
    auto _search(const std::shared_ptr<node_t> &node, const T &value, long &count) {
        // if node is null, return null ptr
        if (!node) return node;

        // if its the node we are looking for
        count++;
        if ( node->data == value) {
            return node;
        }

        count++;
        if ( value < node->data ) {
            // if its less than
            return _search(node->lnode, value, count);
        } else {
            // if its greater than
            return _search(node->rnode, value, count);
        }

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