#include "string.h"

void* s21_memchr(const void* str, int c, s21_size_t n){
    void* de = s21_NULL;
    unsigned char* ds = (unsigned char*)str;
    for(s21_size_t i = 0; i < n; i++){
        if(ds[i] == c) de = (void*)&ds[i]; 
    }
    return de;
}

int s21_memcmp(const void *str1, const void *str2, size_t n){
    int res = 0;
    unsigned char* ds = (unsigned char*)str1;
    unsigned char* de = (unsigned char*)str2;
    for(s21_size_t i = 0; i < n; i++){
        if(ds[i] > de[i]) res = 1;
        if(ds[i] < de[i]) res = -1;
    }
    return res;
}

void* s21_memcpy(void *dest, const void *src, size_t n){
    unsigned char* ds = (unsigned char*)src;
    unsigned char* de = (unsigned char*)dest;
    for(; n > 0; n--){
        *de++ = *ds++;
    }
    return dest;
}

void* s21_memset(void *str, int c, size_t n){
    unsigned char* ds = (unsigned char*)str;
    for(; n > 0; n--){
        *ds++ = c;
    }
    return str;
}

char* s21_strncat(char *dest, const char *src, size_t n){}