//
//  Bounds.h
//  emptyExample
//
//  Created by David Stolarsky on 3/6/13.
//
//

#ifndef __emptyExample__Bounds__
#define __emptyExample__Bounds__

#include <ofMain.h>

template <class T>
class Bounds {
public:
    T left;
    T right;
    T top;
    T bottom;
    
    Bounds()
    {
        left = right = top = bottom = 0;
    };
    
    Bounds(ofImage img)
    {
        left = bottom = 0.0;
        right = img.width;
        top = img.height;
    };
    
    Bounds(T left, T right, T top, T bottom)
    {
        this->left = left;
        this->right = right;
        this->top = top;
        this->bottom = bottom;
    };
    
    T width() { return right - left; }
    T height() { return top - bottom; }
    
    std::string toString()
    {
        stringstream ss;
        ss << "bounds(" << left << ", " << right << ", " << top << ", " << bottom << ")";
        return ss.str();
    }
};

#endif /* defined(__emptyExample__Bounds__) */