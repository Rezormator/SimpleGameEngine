#include "Error.h"
#include <iostream>

GLvoid Error::logMassage(const char *target, const char *description, const GLboolean shut) {
    std::cerr << "ERROR::" << target << "::" << description << std::endl;
    if (shut) {
        Application::shut();
    }
}
