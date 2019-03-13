#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

using namespace std;

int main()
{
    int opc;
    Node *root = nullptr;
    AVL avl;

    char name[40] = "AVL.bin";

    while (opc != -1)
    {
        AVL tree;
        cout << "\n-------Menu-------\n1. Insertar Nodo\n2. Eliminar Nodo\n3. Print Preorden\n4. Print Inorden\n5. Print Postorden\n6. Crear archivo binario.\n7. Read file" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch (opc)
        {

        case 1:
        {
            int key;
            cout << "Ingrese un valor para el nodo: ";
            cin >> key;

            root = tree.insert(root, key);
            avl.saveNodestoFile(name, key);

            break;
        }

        case 2:
        {
        }

        case 3:
        {
            tree.preOrder(root);
            break;
        }

        case 4:
        {
            tree.inOrder(root);
            break;
        }

        case 5:
        {
            tree.postOrder(root);
            break;
        }

        case 6:
        {
            tree.createFile(name);
            break;
        }

        case 7:
        {
            tree.readFile(name);
            break;
        }

        default:
        {
            break;
        }
        }
    }
    return 0;
}