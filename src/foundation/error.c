#include "../../include/foundation/error.h"

char* getErrorMessage(tError error)
{
    switch(error)
    {
        case OK:                        return "Everything Ok.";
        case ERROR_INVALID_ARGUMENT:    return "Error: Invalid argument.";
        case ERROR_MEMORY_ALLOCATION:   return "Error: No memory.";
        case ERROR_FILE_NOT_FOUND:      return "Error: Couldn't open file.";
        case ERROR_DUPLICATED_ENTRY:    return "Error: Duplicated.";
        case ERROR_NOT_FOUND:           return "Error: Not found.";
        case ERROR_UNKNOWN:             return "Error: We don't know what happened here.";
    }
}

    