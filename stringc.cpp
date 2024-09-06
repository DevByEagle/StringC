#include "stringc.h"

StringC::StringC(const char* initial)
{
	
	if (initial) {
		length = strlen(initial);
		data = (char*)malloc(length + 1);
		if (data) {
			strcpy(data, initial);
			isEmpty = false;
		} else {
			length = 0;
			isEmpty = true;
			data = (char*)malloc(1); // Allocate space for the null terminator
			if (data) {
				data[0] = '\0';
			}
		}
	}
}

void StringC::join(const char* additional) 
{
	if (additional) {
		size_t additional_length = strlen(additional);
		data = (char*)realloc(data, length + additional_length + 1);
		if (data) {
			strcat(data, additional);
			length += additional_length;
		}
	}
}

int StringC::cmpstr(const StringC* str) const
{
	return strcmp(data, str->data);
}

bool StringC::empty() const
{
	return isEmpty;
}

bool StringC::ptrstr() 
{
	if (isEmpty == true || !data) {
		return false;
	} else {
		printf("%s\n", data);
		return true;
	}
}

size_t StringC::size()
{
	return length;
}

void StringC::strfree()
{
	free(data);
	data = nullptr;
	length = 0;
}

