#ifndef AVL_INCLUDED_HPP
#define AVL_INCLUDED_HPP

#include <memory>
#include <iostream>

#include "tree_node.hpp"

namespace paa {
namespace t3 {

template<typename T>
class AVL {
public:
    long get_insertion_cmp_count() const { return insert_cmp_count;}
    long get_search_cmp_count() const { return search_cmp_count;}
    void reset_search_cmp_count() { search_cmp_count = 0;}
    auto insert(const T &&value) {
        if (!root){
            root = std::make_shared<node_t>(node_t{value});
            return root;
        }
        auto res = _insert(this->root, value);
        this->balance();
        return res;
    };
    auto insert(const T  &value) {
        if (!root){
            root = std::make_shared<node_t>(node_t{value});
            return root;
        }
        auto res = _insert(this->root, value);
        this->balance();
        return res;    };
    auto search(const T  &value) {
        return _search(this->root, value);
    };
    void in_place() {
        _in_place(this->root);
        std::cout << std::endl;
    };
private:
    using node_t = b_tree_node_t<T>;

    std::shared_ptr<node_t> root;
    long insert_cmp_count = 0;
    long search_cmp_count = 0;

    auto _insert(std::shared_ptr<node_t> &node, const T &value) {
        // if node is null
        if (!node) {
            node = std::make_shared<node_t>(node_t{value});
            return node;
        }
        // if it needs to travel deeper in the tree
        insert_cmp_count++;
        if (value < node->data) {
            // Insert into left sub tree
            return _insert(node->lnode, value);
        }
        insert_cmp_count++;
        if (value > node->data) {
            // Insert into rigth sub tree
            return _insert(node->rnode, value);
        }
        // if element is already in the tree
        // return its node
        return node;
    }
    auto _search(const std::shared_ptr<node_t> &node, const T &value) {
        // if node is null, return null ptr
        if (!node) return node;

        // if its the node we are looking for
        search_cmp_count++;
        if ( node->data == value) {
            return node;
        }

        search_cmp_count++;
        if ( value < node->data ) {
            // if its less than
            return _search(node->lnode, value);
        } else {
            // if its greater than
            return _search(node->rnode, value);
        }

    }
    void _in_place(const std::shared_ptr<node_t> &node) {
        if (node) {
            _in_place(node->lnode);
            std::cout << node->data << " ";
            _in_place(node->rnode);
        }
    };
    void balance(){/*FIXME: missing implementation*/};
};

}} // namespace paa::t3


#endif