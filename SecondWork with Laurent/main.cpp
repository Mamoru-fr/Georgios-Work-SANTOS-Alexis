#include <iostream>
#include <string>
#include "Node.hpp"
#include "BST.hpp"

using namespace std;

int main()
{
    BST bst;

    // Insert some values into the BST
    bst.insert("Jean");
    bst.insert("Kevin");
    bst.insert("Bob");
    bst.insert("Broceliande-Nausicaa");
    bst.insert("Honore");
    bst.insert("Dylan");
    bst.insert("Maurice");

    // Perform in-order traversal
    std::cout << "In-order traversal of the BST: ";
    bst.inorder();

    // Search for some values in the BST
    string keysToSearch[] = {"Jean", "Bon", "Broceliande-Nausicaa", "Eric", "Laurent", "Bob"};
    for (string key : keysToSearch)
    {
        if (bst.search(key))
        {
            std::cout << key << " is present in the BST." << std::endl;
        }
        else
        {
            std::cout << key << " is not present in the BST." << std::endl;
        }
    }

    bst.view();

    cout << "coucou 1" << endl;

    bst.deleteHuman("Maurice");

    cout << "coucou 2" << endl;

    bst.view();

    for (string key : keysToSearch)
    {
        if (bst.search(key))
        {
            std::cout << key << " is present in the BST." << std::endl;
        }
        else
        {
            std::cout << key << " is not present in the BST." << std::endl;
        }
    }

    return 0;
}