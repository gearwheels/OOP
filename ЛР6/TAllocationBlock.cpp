#include "TAllocationBlock.h"

TAllocationBlock::TAllocationBlock(int32_t size, int32_t count){
    _used_blocks = (Byte *)malloc(size * count);

    for(int32_t i = 0; i < count; ++i) {
        void *ptr = (void *)malloc(sizeof(void *));
        ptr = _used_blocks + i * size;
        _free_blocks.push_back(ptr);
    }
}

void *TAllocationBlock::Allocate(){
    if(!_free_blocks.empty()) {
        return _free_blocks.front();
        
    } else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::Deallocate(void *ptr){
    _free_blocks.push_back(ptr);   
}

bool TAllocationBlock::Empty(){
    return _free_blocks.empty();   
}

int32_t TAllocationBlock::Size(){
    return _free_blocks.size();   
}

TAllocationBlock::~TAllocationBlock(){
    while(!_free_blocks.empty()){  
        _free_blocks.pop_front();   
    }
    free(_used_blocks);
}