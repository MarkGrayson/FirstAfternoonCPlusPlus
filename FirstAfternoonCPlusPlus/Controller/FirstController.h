//
//  FirstController.h
//  FirstAfternoonCPlusPlus
//
//  Created by Palesh, Mark on 1/23/17.
//  Copyright © 2017 Palesh, Mark. All rights reserved.
//

#ifndef FirstController_h
#define FirstController_h

#include "../Model/Node.hpp"
#include "../Model/Array.h"
#include "../Model/List.hpp"
#include "../Model/Stack.h"
#include "../Model/Queue.h"
#include "../Model/FoodItem.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/Timer.hpp"
#include "../Model/DoubleList.h"
#include "../Model/BiDirectionalNode.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/BinarySearchTreeNode.h"
#include "../Model/Tree.h"
#include "../Model/AVLTree.hpp"
#include "../Model/Graph.hpp"
#include "../Model/CrimeData.hpp"
#include "../Model/HashNode.h"
#include "../Model/HashTable.h"
#include <fstream>
#include <string>

using namespace std;

class FirstController
{
private:
    void testGraph();
    void testAVLTreeOperations();
    void testBinarySearchData();
    void testAVLData();
    void testBinarySearchTreeOperations();
    void testIntArray();
    void testNodes();
    void testAdvancedFeatures();
    void testDestructor();
    void testListIntro();
    void testDoubleList();
    void testListTiming();
    void testIntStack();
    void testFoodQueue();
    Node<int> numberNode;
    Node<string> wordNode;
public:
    FirstController();
    BinarySearchTree<CrimeData> readCrimeDataToBinarySearchTree(string filename);
    AVLTree<CrimeData> readCrimeDataToAVLTree(string filename);
    void start();
    
};

#endif // FirstController_h
