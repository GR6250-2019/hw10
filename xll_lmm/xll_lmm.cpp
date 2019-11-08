// xll_lmm.cpp - LIBOR Market Model
#include "../fms_lmm/fms_lmm.h"
#include "xll_lmm.h"

using namespace fms;
using namespace xll;

AddIn xai_project(
    Document(L"xll_lmm")
    .Documentation(
        L"This will generate a Sandcastle Helpfile Builder project file. "
        L"Start Excel with the add-in loaded and run (Alt-F8) the macro MAKE.SHFB. "
    )
);

AddIn xai_xllproject(
    Document(CATEGORY)
    .Documentation(
        L"Documentation for the " CATEGORY L" category. "
    )
);

//!!! Implement
//AddIn xai_lmm_advance