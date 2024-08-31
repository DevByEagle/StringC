#ifndef STRINGC_H
#define STRINGC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define String_Args "%s\n"

/** @brief StringC is a fast, lightweight C/C++ library for efficient string manipulation, offering core functions like concatenation, formatting, and searching, designed for cross-platform use. */
typedef struct _stringc {
    char* data;
    size_t length;
} StringC;

/** @brief strinit initializes and returns a new string, allocating memory and setting the content to a specified value. */
StringC strinit(const char* initial) {
    StringC str;
    if (initial) {
        str.length = strlen(initial);
        str.data = (char*)malloc(str.length + 1);
        if (str.data) {
            strcpy(str.data, initial);
        } else {
            str.length = 0;
            str.data = (char*)malloc(1); // Allocate space for the null terminator
            if (str.data) {
                str.data[0] = '\0';
            }
        }
    }

    return str;
}

/** @brief `join` concatenates an array of strings into a single string, separated by a specified delimiter. Ideal for combining multiple text elements efficiently. */
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
/** @brief cmpstr compares two strings lexicographically. Returns 0 if they are equal, a negative value if the first string is less than the second, or a positive value if it is greater. */
int cmpstr(const StringC* str1, const StringC* str2) {
    return strcmp(str1->data, str2->data);
}

/** @brief substring extracts a portion of a string based on specified start and end indices. It efficiently handles string slicing for both C and C++ applications. */
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
    } else {
        sub.length = 0;
        sub.data = (char*)malloc(1); // empty string
        if (sub.data) {
            sub.data[0] = '\0';
        }
    }
    return sub;
}

/** @brief `ptrstr`: Prints the string pointed to by a given pointer. Efficiently handles null-terminated strings, ensuring proper output and formatting. */
bool ptrstr(const StringC* str) {
    if (!str) {
        fprintf(stderr, "[ERROR] Missing Perimeter\n");
        return false;
    } else {
        printf(String_Args, str->data);
        return true;
    }
}

/** @brief `size`: Returns the length of the string, excluding the null terminator. */
size_t size(StringC* str) {
    return str->length;
}

/** @brief `freestr`: Frees the memory allocated for a string created with StringLib, ensuring proper resource management and preventing memory leaks. */
void freestr(StringC* str) {
    free(str->data);
    str->data = NULL;
    str->length = 0;
}

#endif // STRINGC_H
