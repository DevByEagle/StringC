#include "stringc.h"

StringC strinit(const char* initial) {
    StringC str = { 0 };
    if (initial) {
        str.length = strlen(initial);
        str.data = (char*)malloc(str.length + 1);
        if (str.data) {
            strcpy(str.data, initial);
        }
        else {
            str.length = 0;
            str.data = (char*)malloc(1); // Allocate space for the null terminator
            if (str.data) {
                str.data[0] = '\0';
            }
        }
    }

    return str;
}

void join(StringC* str, const char* additional) {
    if (additional) {
        size_t additional_length = strlen(additional);
        str->data = (char*)realloc(str->data, str->length + additional_length + 1);
        if (str->data) {
            strcat(str->data, additional);
            str->length += additional_length;
        }
    }
}

int cmpstr(const StringC* str1, const StringC* str2) {
    return strcmp(str1->data, str2->data);
}

StringC substring(const StringC* str, size_t start, size_t length) {
    StringC sub;
    if (start < str->length) {
        sub.length = length;
        if (start + length > str->length) {
            sub.length = str->length - start;
        }
        sub.data = (char*)malloc(sub.length + 1);
        if (sub.data) {
            strncpy(sub.data, str->data + start, sub.length);
            sub.data[sub.length] = '\0';
        }
    }
    else {
        sub.length = 0;
        sub.data = (char*)malloc(1); // empty string
        if (sub.data) {
            sub.data[0] = '\0';
        }
    }
    return sub;
}

bool ptrstr(const StringC* str) {
    if (!str) {
        fprintf(stderr, "[ERROR] No data provided");
        return false;
    }
    else {
        printf(String_Print, str->data);
        return true;
    }
}

size_t size(StringC* str) {
    return str->length;
}

void strfree(StringC* str) {
    free(str->data);
    str->data = NULL;
    str->length = false;
}
