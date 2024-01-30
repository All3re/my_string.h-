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
        if(ds[i] > de[i]){
            res = ds[i] - de[i];
            break;
        }
        if(ds[i] < de[i]){
            res = ds[i] - de[i];
            break;
        }
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

s21_size_t s21_strlen(const char *str)
{
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len;
} 


char* s21_strncat(char *dest, const char *src, size_t n){
    for(;*dest;){
        dest++;
    }
    for(; n > 0; n--){
        *dest++ = *src++;
    }
    //*dest = '\0';
    return dest;
}

char* s21_strchr(const char *str, int c){
    const char* de = s21_NULL;
    for(;*str;){
        if(*str == c) {
            de = str;
            break;
        }
        str++;
    }
    return (char*)de;
}


int s21_strncmp(const char *str1, const char *str2, size_t n){
    int res = 0;
    for(s21_size_t i = 0; i < n; i++){
        if(str1[i] > str2[i]){ 
            res = str1[i] - str2[i];
            break;
        }
        if(str1[i] < str2[i]){
            res = str1[i] - str2[i];
            break;
        }
        if(str1[1] == '\0') break;
    }
    return res;
}

char* s21_strncpy(char *dest, const char *src, size_t n){
    for(; n > 0; n--){
        if(*src) *dest++ = *src++;
        else *dest++ = '\0';
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t res = 0;
    s21_size_t ds = 0;
    s21_size_t i = 0;
    s21_size_t j = 0;
    for(; i < s21_strlen(str1) - 1; i++){
        if(str1[i] == str2[j]) {
            res = i;
            break;
        } 
        for(; j < s21_strlen(str2) - 1; j++);
    }
    ds = i;
    if(res == 0) res = ds;
    return res;
}

