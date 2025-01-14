#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

#ifndef BSTsort_H
#define BSTsort_H

class BST
{
public:
    BST() : root(nullptr) {}

    // Insert a new new_human into the BST
    void insert(string new_human)
    {
        root = insertRec(root, new Human(new_human, root));
    }

    // Search for a name in the BST
    bool search(string name)
    {
        return searchRec(root, name);
    }

    // In-order traversal of the BST
    void inorder()
    {
        inorderRec(root);
        std::cout << std::endl;
    }

private:
    Human *root;

    // Recursive function to insert a name
    Human *insertRec(Human *root, Human *new_human)
    {
        if (root == nullptr)
        {
            return new_human;
        }
        if (new_human->name < root->name)
        {
            root->dad = insertRec(root->dad, new_human);
        }
        else if (new_human->name > root->name)
        {
            root->mom = insertRec(root->mom, new_human);
        }
        return root;
    }

    // Recursive function to search for a name
    bool searchRec(Human *root, string name)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->name == name)
        {
            return true;
        }
        return name < root->name ? searchRec(root->dad, name) : searchRec(root->mom, name);
    }

    // Recursive function for in-order traversal
    void inorderRec(Human *root)
    {
        if (root != nullptr)
        {
            inorderRec(root->dad);
            std::cout << root->name << " ";
            inorderRec(root->mom);
        }
    }
};

#endif