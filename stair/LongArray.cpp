#include "LongArray.h"

LongArray::LongArray(int arraySize){
    _arraySize = arraySize;
    _array[arraySize] = {0};
    _index = 0;
}

void LongArray::add(long value) {
    if(_index > _arraySize) {
        _index = 0;
        _array[_index] = value;
    } else {
        _array[_index] = value;
        _index += 1;
    }

    return _array;
}

long LongArray::avg() {
    long total = 0;
    for (int i = 0; i < _arraySize; i++)
    {
        total += _array[i];
        Serial.println(_array[i]);
    }

    return total / _arraySize;
}
