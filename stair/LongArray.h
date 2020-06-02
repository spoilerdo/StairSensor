#ifndef LongArray_h
#define LongArray_h

#include <Arduino.h>

class LongArray {
    public:
        LongArray(int arraySize);
        void add(long value);
        long avg();

    protected:
        int _arraySize;
        int _index;
        long  _array[];
};

#endif