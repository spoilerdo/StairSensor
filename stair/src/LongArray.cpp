#include "LongArray.h"

LongArray::LongArray(int arraySize) {
    _arraySize = arraySize;
    _array[arraySize] = {0};
    _index = 0;
}

void LongArray::add(long value) {
    if (_index >= _arraySize) {
        _index = 0;
        _array[_index] = value;
    }
    else {
        _array[_index] = value;
        delay(1); // Needed to correctly fill the array... just... its dark magic don't question it
        _index += 1;
    }
}

long LongArray::avg() {
    long total = 0;
    for (int i = 0; i < _arraySize; i++) {
        total += _array[i];
    }

    return total / _arraySize;
}
