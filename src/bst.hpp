#ifndef BST_INCLUDED_HPP
#define BST_INCLUDED_HPP

#include <memory>
#include <iostream>

#include "tree_node.hpp"

namespace paa {
namespace t3 {

class BST {
public:
    long get_insertion_cmp_count() const { return insert_cmp_count;}
    long get_search_cmp_count() const { return search_cmp_count;}
    void reset_search_cmp_count() { search_cmp_count = 0;}
    auto insert(const int &&value) {
        this->root = _insert(this->root, value);
    };
    auto insert(const int  &value) {
        this->root = _insert(this->root, value);
    };
    auto search(const int  &value) {
        return _search(this->root, value);
    };
    void in_place() {
        _in_place(this->root);
        std::cout << std::endl;
    };
    void pre_tree_view() {
        std::cout << '@' << this->root->data  << '\n';
        _pre_tree_view(this->root->lnode, 'l',1);
        _pre_tree_view(this->root->rnode, 'r',1);
        std::cout << std::endl;
    }
private:
    node_t * root = nullptr;
    long insert_cmp_count = 0;
    long search_cmp_count = 0;

    node_t * _insert(node_t * node, const int &value) {
        // if node is null
        if (!node) {
            return new node_t(value);
        }
        // if it needs to travel deeper in the tree
        insert_cmp_count++;
        if (value < node->data) {
            // Insert into left sub tree
            node->lnode = _insert(node->lnode, value);
        } else if (value > node->data) {
            // Insert into rigth sub tree
            node -> rnode = _insert(node->rnode, value);
        } 
        // if element is already in the tree
        // return its node
        return node;
    }
    node_t * _search(node_t * node, const int &value) {
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
    void _in_place(const node_t * node) {
        if (node) {
            _in_place(node->lnode);
            std::cout << node->data << " ";
            _in_place(node->rnode);
        }
    };
    void _pre_tree_view(const node_t * node, char prefix, int depth) {
        if (node) {
            for (int i = 0; i < depth; i++) std::cout << '\t';
            std::cout << prefix << node->data << '\n';
            _pre_tree_view(node->lnode, 'l', depth+1);
            _pre_tree_view(node->rnode, 'r', depth+1);
        }
    }
};

}} // namespace paa::t3


#endif