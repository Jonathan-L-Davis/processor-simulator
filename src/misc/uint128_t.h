#ifndef UINT128_T_H
#define UINT128_T_H

struct uint128_t{

    uint64_t raw_values[2] = {0,0};

    friend uint128_t operator + ( uint128_t A, uint128_t B){
        uint128_t retMe = {0,0};
        return retMe;
    }

    friend uint128_t operator << ( uint128_t A, uint32_t B){
        uint128_t retMe;
        if(B>127)
            return retMe;
        retMe.raw_values[0]  = (B<64)?(A.raw_values[0] << (B) ):0;
        retMe.raw_values[0] |= (B<64)?(A.raw_values[1] >> (64-B)):(A.raw_values[1] << (B&63));
        retMe.raw_values[1]  = (B<64)?(A.raw_values[1] << (B) ):0;
        return retMe;
    }

    friend uint128_t operator >> ( uint128_t A, uint32_t B){
        uint128_t retMe;
        if(B>127)
            return retMe;
        retMe.raw_values[0]  = (B<64)?(A.raw_values[1] >> (B) ):0;
        retMe.raw_values[1]  = (B<64)?(A.raw_values[1] >> (B) ):0;
        retMe.raw_values[1] |= (B<64)?(A.raw_values[0] << (64-B)):(A.raw_values[0] >> (B&63));
        return retMe;
    }

};

#endif//UINT128_T_H
