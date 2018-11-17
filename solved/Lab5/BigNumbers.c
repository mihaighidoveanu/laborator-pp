#include "Utils.h"

unsigned unsigned_sum(int* x, unsigned x_size, int* y, unsigned y_size, int* result){
    unsigned rsize = (y_size > x_size ? y_size : x_size);
    int xIndex = x_size - 1;
    int yIndex = y_size - 1;
    int rIndex = 0;
    int carry = 0;
    while(xIndex >= 0 && yIndex >= 0){
        int sum = x[xIndex] + y[yIndex] + carry;
        result[rIndex] = sum % 10; //xIndex and yIndex are the same at this point, always
        carry = sum / 10;
        --xIndex;
        --yIndex;
        ++rIndex;
    }
    while(xIndex >= 0){
        int sum = x[xIndex] + carry;
        result[rIndex] = sum % 10;
        carry = sum / 10;
        --xIndex;
        ++rIndex;
    }
    while(yIndex >= 0){
        int sum = y[yIndex] + carry;
        result[rIndex] = sum % 10;
        carry = sum / 10;
        --yIndex;
        ++rIndex;
    }
    if (carry){
        result[rIndex] = carry;
        ++rsize;
    }
    reverse_arr(result,rsize);
    return rsize;
}

int cmp(int* x, unsigned x_size, int* y, unsigned y_size){
    if(x_size == y_size){
        int i = 0;
        for(;i< x_size; ++i){
            if(x[i] == y[i]){
                continue;
            }
            return x[i] - y[i];
        }
    }
    return x_size - y_size;
}

unsigned diff(int* x, unsigned x_size, int* y, unsigned y_size, int* result){
    unsigned rsize = (y_size > x_size ? y_size : x_size);
    int xIndex = x_size - 1;
    int yIndex = y_size - 1;
    int rIndex = 0;
    int borrow = 0;
    while(xIndex >= 0 && yIndex >= 0){
        int diff = x[xIndex] - y[yIndex] - borrow ;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        result[rIndex] = diff;
        --xIndex;
        --yIndex;
        ++rIndex;
    }
    while(xIndex >= 0){
        int diff = x[xIndex] - borrow;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        result[rIndex] = diff;
        --xIndex;
        ++rIndex;
    }
    while(yIndex >= 0){
        int diff = y[yIndex] - borrow;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        result[rIndex] = diff;
        --yIndex;
        ++rIndex;
    }
    reverse_arr(result,rsize);
    return rsize;
}

unsigned sum(int* x, unsigned x_size, int* y, unsigned y_size, int* result) {
    if(x[0] > 0 && y[0] > 0){
        return unsigned_sum(x,x_size,y,y_size,result);
    }
    int xNegative = 0;
    if(x[0] < 0){
        x[0] = -x[0];
        xNegative = 1;
    }
    int yNegative = 0;
    if(y[0] < 0){
        y[0] = -y[0];
        yNegative = 1;
    }
    int xBigger = 1;
    unsigned rsize = 0;
    if (cmp(x,x_size,y,y_size) < 0){ //if x is smaller, swap the two of them
        xBigger = 0; // so y is bigger
        rsize = diff(y,y_size,x,x_size,result);
    }
    else{
        xBigger = 1;
        rsize = diff(x,x_size,y,y_size,result);
    }
    if((xBigger && xNegative) || (!xBigger && yNegative)){    // !xBigger means yBigger
        int i = 0;
        while(i < rsize && result[i] == 0){
            ++i;
        }
        result[i] = -result[i];
    }
    return rsize;
}




