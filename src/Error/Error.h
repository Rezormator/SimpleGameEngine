#pragma once

#include "../Application/Application.h"

class Error {
private:
    static constexpr GLboolean DEFAULT_SHUT = true;
public:
    static GLvoid logMassage(const char *target, const char *description, GLboolean shut = DEFAULT_SHUT);
};
