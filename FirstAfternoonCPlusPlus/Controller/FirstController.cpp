//
//  FirstController.cpp
//  FirstAfternoonCPlusPlus
//
//  Created by Palesh, Mark on 1/23/17.
//  Copyright © 2017 Palesh, Mark. All rights reserved.
//

#include "FirstController.h"
#include <iostream>
#include "../Model/Node.hpp"
#include "../Model/Array.h"
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.hpp"
#include "../Model/DoubleList.h"
#include "../Model/Queue.h"
#include "../Model/Stack.h"
#include "../Model/BiDirectionalNode.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/Tree.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/BinarySearchTreeNode.h"
#include "../Model/CrimeData.hpp"
#include "../Controller/FileController.hpp"
#include "../Model/AVLTree.hpp"
#include "../Model/Graph.hpp"
#include "../Model/Hashtable.h"
#include <string>

using namespace std;

FirstController ::  FirstController()
{
    wordNode = Node<string>("derpy mcderpface");
    numberNode = Node<int>();
}

void FirstController :: testNodes()
{
    cout << "The contents of the Node<string>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void FirstController :: start()
{
    cout << "Starting the project" << endl;
    
    cout << "Going to test the Array Template" << endl;
    testAdvancedFeatures();
    cout << "Finished testing" << endl;
}

void FirstController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match:" << endl;
    cout << words.getFromIndex(0) << " should be the same as "
    << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
}

void FirstController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for (int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot  "<< index << endl;
    }
    
    cout << "Testing input" << endl;
    
    for(int index = 0; index < 3; index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < temp.getSize(); index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void FirstController :: testListIntro()
{
        List<int> sample;
        sample.addFront(2);
        sample.addEnd(3);
        sample.addFront(1);
        cout << "This should go 1, 2, 3" << endl;
        
        for(int index = 0; index < sample.getSize(); index++)
        {
            cout << sample.getFromIndex(index) << endl;
            cout << sample.remove(1) << endl;
        }
        
        cout << "Size should read 3 and is " << sample.getSize() << endl;
    }

void FirstController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    totalTimer.stopTimer();
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds."
    << endl;
    
    cout << "The average speed for the getFromIndexFast method was: " << averageFast <<
    "microseconds." << endl;
    
    cout << "A time savings?? of: " << averageSlow - averageFast << " mircoseconds." << endl;
    totalTimer.displayTimerInformation();
}

void FirstController :: testIntStack()
{
    Stack<int> numberStack;
    numberStack.add(2315);
    numberStack.push(32);
    int testValue = numberStack.pop();
    cout << "Test value is " << testValue << " and should be 32" << endl;
}

void FirstController :: testFoodQueue()
{
    Queue<FoodItem> tastyFood;
    FoodItem szechwan("spicy chinese dish");
    
    tastyFood.enqueue(szechwan);
    FoodItem boring;
    tastyFood.add(boring);
    
    FoodItem removed = tastyFood.dequeue();
    cout << "The item removed from the queue was: " << " and should be: " << endl;
}

void FirstController :: testBinarySearchTreeOperations()

{
    
    BinarySearchTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    
}

void FirstController :: testBinarySearchData()
{
    
    FirstController fileData;
    Timer treeTimer;
    treeTimer.startTimer();
    
    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/Mpal7487/Documents/crimes.csv");
    
    treeTimer.stopTimer();
    
    int count = crimeTree.getSize();
    int height = crimeTree.getHeight();
    bool complete = crimeTree.isComplete();
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
}
void FirstController :: testAVLTreeOperations()

{
    
    AVLTree<int> numbers;
    numbers.insert(9843);
    numbers.insert(10);
    numbers.insert(43);
    numbers.insert(-123);
    numbers.insert(23465);
    numbers.insert(10); // won't go in
    numbers.insert(43243);
    numbers.insert(-45677654);
    numbers.insert(92165);
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
}


void FirstController :: testAVLData()

{
    
    FirstController fileData;
    Timer treeTimer;
    treeTimer.startTimer();
    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    int height = crimeTree.getHeight();
    bool complete = crimeTree.isComplete();
    bool balanced = crimeTree.isBalanced();
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
    
}

BinarySearchTree<CrimeData> FirstController :: readCrimeDataToBinarySearchTree(string filename)

{
    
    BinarySearchTree<CrimeData> crimeData;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            
            //Exclude first row headers
            
            if (rowCount != 0)
            {
                CrimeData rowData(currentCSVLine);
                crimeData.insert(rowData);
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimeData;
    
}



AVLTree<CrimeData> FirstController :: readCrimeDataToAVLTree(string filename)
{
    AVLTree<CrimeData> crimeData;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            
            //Exclude first row headers
    
            if (rowCount != 0)
            {
                CrimeData rowData(currentCSVLine);
                crimeData.insert(rowData);
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimeData;
    
}

void FirstController :: testGraph()
{
    Graph<string> connectWords;
connectWords.addVertex ("Video Games");
connectWords.addVertex ("Halo CE");
connectWords.addVertex ("Call of Duty");
connectWords.addVertex ("The Legend of Zelda");
connectWords.addVertex ("Evolve");
connectWords.addVertex (" -> is the return indicator");
connectWords.addVertex (" * is the dereference");

connectWords.addEdge (0,1);
connectWords.addEdge (0,2);
connectWords.addEdge (0,3);
connectWords.addEdge (0,4);
connectWords.addEdgeUndirected (2,6);
connectWords.addEdgeUndirected (4,5);
}

