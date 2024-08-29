#ifndef STRINGC_H
#define STRINGC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define String_Args "%s\n"

typedef struct {
    char* data;
    size_t length;
} StringC;

/** @brief Create a new String */ 
StringC CreateString(const char* initial) {
    StringC str;
    if (initial) {
        str.length = strlen(initial);
        str.data = malloc(str.length + 1);
        if (str.data) {
            strcpy(str.data, initial);
        } else {
            str.length = 0;
            str.data = malloc(1); // Allocate space for the null terminator
            if (str.data) {
                str.data[0] = '\0';
            }
        }
    }

    return str;
}

/** @brief Joins two string together */
void join(StringC* str, const char* additional) {
    if (additional) {
        size_t additional_length = strlen(additional);
        str->data = realloc(str->data, str->length + additional_length + 1);
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
        sub.data = malloc(sub.length + 1);
        if (sub.data) {
            strncpy(sub.data, str->data + start, sub.length);
            sub.data[sub.length] = '\0';
        }
    } else {
        sub.length = 0;
        sub.data = malloc(1); // empty string
        if (sub.data) {
            sub.data[0] = '\0';
        }
    }
    return sub;
}

/** @brief Prints the string */
bool ptrstr(const StringC* str) {
    if (!str) {
        fprintf(stderr, "[ERROR] Missing Pramiter\n");
        return false;
    } else {
        printf("%s\n", str->data);
        return true;
    }
}

/** @brief Get the size of the string */
size_t size(StringC* str) {
    return str->length;
}

/** @brief Free the string */
void freestr(StringC* str) {
    free(str->data);
    str->data = NULL;
    str->length = 0;
}

#endif // STRINGC_H
