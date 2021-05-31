#include<cstdint>
#include<sys/mman.h>
#include<string.h>

struct Arena{
    char* memory;
    size_t lenght;

    Arena size_t lenght;
    ~Arena();

    void* allocate(size_t len);
};

Arena::Arena(size_t){
    lenght = l;
    memory = mmap(nullptr, lenght, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

Arena::~Arena(){
    munmap(memory,lenght);
}

enum arena_flags{
    touched = 0x00010000,
    allocate = 0x00020000,
    deallocate = 0x00040000,
};

void* Arena::allocate(size_t len){
    uint32_t flag;
    uint16_t flag_size = len | arena_flags::touched | arena_flags::allocate;
    char* ptr = memory;

    while(ptr < (memory+lenght)){
        uint32_t block_flag = 0;
        memcpy(&block_flag, ptr, sizeof(block_flag));
        if(block_flag & arena_flags::touched){
            if(block_flag & arena_flags::allocate){
                uint16_t block_size = block_flag;
                ptr += block_size;
                ptr += sizeof(flag);
                continue;
            }else if(block_size>=len){
                flag = block_size | arena_flags::touched | arena_flags::allocate;
                memcpy(ptr, &flag, sizeof(flag));
                return sizeof(flag)+ptr;
            }
        }else {
            auto size = (memory + lenght) - ptr;
            if(size >= (len+sizeof(flag))){
                memcpy(ptr, &flag, sizeof(flag));
                return sizeof(flag)+ptr;
            }else{
                return nullptr;
            }
        }
    }
}

auto main() -> int{
    return 0;
}
