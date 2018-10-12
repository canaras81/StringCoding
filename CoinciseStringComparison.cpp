int shstrcmp_v1(const char* s1, const char* s2) {
    while(*s1 && *s2){        
        if      (*s1 < *s2)     return -1;
        else if (*s1 > *s2)     return 1;
        else                    {s1++; s2++;}
    }
    if(!*s1 && !*s2) return 0;
    else if(!*s1)    return -1;
    else             return 1;
}

int shstrcmp_v2(const char* s1, const char* s2) {
    while (*s1 && *s1 == *s2)   ++s1, ++s2;
    return *s1 - *s2;
}
