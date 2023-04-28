#ifndef UINT128_T_H
#define UINT128_T_H

#include <iostream>

struct uint128_t{

    uint64_t raw_values[2] = {0,0};


    friend void operator += ( uint128_t& A, const uint128_t& B){
        A = A + B;
    }

    friend uint128_t operator + ( uint128_t A, uint128_t B){
        uint128_t retMe = {0,0};

        uint64_t A_h = A.raw_values[0];
        uint64_t A_l = A.raw_values[1];
        uint64_t B_h = B.raw_values[0];
        uint64_t B_l = B.raw_values[1];

        retMe.raw_values[0] = A_h+B_h;
        retMe.raw_values[1] = A_l+B_l;
        //if overflow occured
        if( retMe.raw_values[1] < A_l ){
            retMe.raw_values[0]++;
        }
        return retMe;
    }

    friend uint128_t operator << ( uint128_t A, uint32_t B){
        uint128_t retMe{0,0};
        if(B>127)
            return retMe;
        if(B==0)
            return A;
        retMe.raw_values[0]  = (B<64)?(A.raw_values[0] << (B) ):0;
        retMe.raw_values[0] |= (B<64)?(A.raw_values[1] >> (64-B)):(A.raw_values[1] << (B&63));
        retMe.raw_values[1]  = (B<64)?(A.raw_values[1] << (B) ):0;
        return retMe;
    }

    friend uint128_t operator >> ( uint128_t A, uint32_t B){
        uint128_t retMe;
        if(B>127)
            return retMe;
        if(B==0)
            return A;
        retMe.raw_values[0]  = (B<64)?(A.raw_values[1] >> (B) ):0;
        retMe.raw_values[1]  = (B<64)?(A.raw_values[1] >> (B) ):0;
        retMe.raw_values[1] |= (B<64)?(A.raw_values[0] << (64-B)):(A.raw_values[0] >> (B&63));
        return retMe;
    }

};

#endif//UINT128_T_H
