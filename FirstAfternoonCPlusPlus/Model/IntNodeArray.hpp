//
//  FirstMegaData.hpp
//  FirstAfternoonCPlusPlus
//
//  Created by Palesh, Mark on 2/6/17.
//  Copyright © 2017 Palesh, Mark. All rights reserved.
//

#ifndef IntNodeArray_hpp
#define IntNodeArray_hpp

#include "IntNode.hpp"

class IntNodeArray
{
private:
    IntNode * front;
    int size;
    
public:
    IntNodeArray(int size);
    void setAtIndex(int index, int value);
    int getFromIndex(int index);
    int getSize();
};


#endif /* IntArray_hpp */
