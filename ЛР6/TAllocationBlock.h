#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <iostream>
#include <list>
#include <cstdlib>
typedef unsigned char Byte;

class TAllocationBlock{
private:
    Byte *_used_blocks;
    std::list <void *>_free_blocks;
public:
    TAllocationBlock(int32_t size, int32_t count);
    void *Allocate();
    void Deallocate(void *ptr);
    bool Empty();
    int32_t Size();
    virtual ~TAllocationBlock();
};
#endif /* TALLOCATIONBLOCK_H */
