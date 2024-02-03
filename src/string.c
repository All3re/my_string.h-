#include "string.h"

void* s21_memchr(const void* str, int c, s21_size_t n){
    void* de = s21_NULL;
    unsigned char* ds = (unsigned char*)str;
    for(s21_size_t i = 0; i < n && !de; i++){
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
    return dest;
}

char* s21_strchr(const char *str, int c){
    const char* de = s21_NULL;
    if(c == '\0') de = "";
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
    char *res = dest;
    for(; n > 0; n--){
        if(*src) *dest++ = *src++;
        else *dest++ = '\0';
    }
    return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t res = 0;
    for (; *str1; str1++){
        s21_size_t flag = 0;
        for(char* de = (char*)str2; *de; de++){
            if(*str1 == *de){
                flag = 1;
                break;
            }
        }
        if(flag) break;
        else res++;
    }
    return res;
}

char* s21_strpbrk(const char *str1, const char *str2){
    char* ds = s21_NULL;
    int flag = 0;
    if ((str1 == s21_NULL) || (str2 == s21_NULL)) flag = 1;
    for(;flag != 1 && *str1;) {
        if (!s21_strchr(str2, *str1)) {
            str1++;
        } else {
            flag = 1;
            ds = (char*)str1;
        }
    }
    return ds;
}

char* s21_strrchr(const char *str, int c){
    const char* de = s21_NULL;
    if(c == '\0') de = "";
    for(;*str;){
        if(*str == c) {
            de = str;
        }
        str++;
    }
    return (char*)de;
}

char* s21_strstr(const char *haystack, const char *needle){
    const char* res = s21_NULL;
    if (*needle == '\0') {
        res = haystack;
    }
    for(;*haystack && res == s21_NULL;){
        if(*haystack == *needle) {
            char* de = (char*) haystack;
            char* ds = (char*) needle;
            for(;*de == *ds && *ds != '\0';){
                de++;
                ds++;
            }
            if(*ds == '\0'){
                res = haystack;
            }
        }
        haystack++;
    }
    return (char*)res;
}

char* s21_strtok(char *str, const char *delim){
    int i = 0;
    static char *last;
    char *ref;
    s21_size_t func_work = 1;
    if ((ref = str) == s21_NULL && (ref = last) == s21_NULL) func_work = 0;
    for (i = 0; func_work && *ref && delim[i]; i++) {
        if (*ref == delim[i]) {
        ref++;
        i = -1;
        }
    }
    if (func_work && *ref == '\0') {
        ref = s21_NULL;
        last = s21_NULL;
        func_work = 0;
    }
    str = ref;
    while (func_work && *ref) {
        for (s21_size_t i = 0; delim[i]; i++) {
            if (*ref == delim[i]) {
                func_work = 0;
                *ref = '\0';
                ref++;
                if (*ref == '\0') ref = s21_NULL;
                last = ref;
                break;
            }
        }
        if (func_work) {
            ref++;
            if (*ref == '\0') {
                last = s21_NULL;
            }
        }
    }
    return str;
}

void s21_f_to_buf(char* str, elements param, char format, va_list *arguments) {
    long double num = 0;
    int i = 0;
    num = va_arg(*arguments, double);
    s21_size_t size = size_double(&param, num);
}

s21_size_t size_double(elements *p, long double num){
    s21_size_t res = 0;
    long double in = 0;
    long double frac = modfl(num, &in);
    int prec = p->precision;
    if(frac + 0.000000000000001 >= 1) {
        frac = 0;
        in += 1;
    }
    for(int i = 0; i < 15; i++){
        frac *= 10;
        if((long)frac != 0) break;
    }
}