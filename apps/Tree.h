//
//  Tree.h
//  tree
//
//  Created by Tucker King on 10/22/21.
//

#ifndef Tree_h
#define Tree_h
#pragma once

#include <memory>
#include <fucntional>
#include <cassert>

using namespace std;

template<class T>
class Tree
{
    struct Node
    {
        Node(shared_ptr<const Node> const & lft
             , T val
             , std::shared_ptr<const Node> const & rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}

        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
    };

    //
    // And this private constructor defines how we keep track of the root of the
    // tree while not exposing that information to clients of this class.
    //
    explicit Tree(std::shared_ptr<const Node> const & node)
      : _root(node) {}

public:
    //
    // The first two public constructors provide the protocol for creating a
    // Tree per the mathematical definition of the Tree ADT.
    //
    Tree() {}

    Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || val < rgt.root());
    }

    //
    // We add an additional constructor that we use to construct a Tree from
    // an initializer list.
    //
    Tree(std::initializer_list<T> init) {
        Tree t;
        for (T v: init) {
            t = t.insert(v);
        }
        _root = t._root;
    }

    //
    // The next portion of the protocol allows the client to query the state
    // of the Tree.   Again, note how we avoid exposing the state to the client.
    //
    bool isEmpty() const { return !_root; }

    T root() const {
        assert(!isEmpty());
        return _root->_val;
    }


    Tree left() const {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }

    Tree right() const {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }

    //
    // Now we manipulate the tree.
    // Note insert operates... we don't try to "fix" an existing treee.
    // Rather we build a new tree, inserting the new value at the correct point.
    //
    // Note also the implicit assumption about the template class... it must
    // support the comparison operator, or mathematically, must be partially
    // ordered.
    //
    Tree insert(T x) const {
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this; // no duplicates
    }

    bool member(T x) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    //
    // For each of traversal functions, we assume that the parameter is a
    // function pointer, object, or lambda expression that returns void and is
    // passed an object of type T.
    //
    void preorder(std::function<void(T)> visit) const {
        if (isEmpty())
            return;
        T contents = root();
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().inorder(visit);
        T contents = root();
        visit(contents);
        right().inorder(visit);
    }

    void postorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().postorder(visit);
        right().postorder(visit);
        T contents = root();
        visit(contents);
    }

private:
    std::shared_ptr<const Node> _root;)
    }
}


#endif /* Tree_h */
