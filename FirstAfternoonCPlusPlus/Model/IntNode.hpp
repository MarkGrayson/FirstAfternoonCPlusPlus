//
//  IntNode.hpp
//  FirstAfternoonCPlusPlus
//
//  Created by Palesh, Mark on 2/6/17.
//  Copyright © 2017 Palesh, Mark. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nodePointer;
public:
    //Constructor
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specified value and next pointer.
     */
    IntNode(int value, IntNode * nextNode);
    
    //Methods
    int getNodeData();
    IntNode * getNextPointer();
    
    
    void setNodeData(int value);
    void setNodePointer(IntNode * next);
    
};

#endif /* IntNode_hpp */
