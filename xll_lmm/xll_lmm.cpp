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
// AddIn xai_lmm_advance
// Return the bumped forwards past u. See skip example below.
// Make sure the function is volatile.

#ifdef _DEBUG

// Skip to t[i-1] <= i < u
inline size_t skip(double u, size_t n, double*& t)
{
	while (n > 0 && *t <= u) {
		++t;
		--n;
	}

	return n;
}

AddIn xai_xll(
	Document(L"XLL")
	.Documentation(L"Documentation for the XLL category")
);

AddIn xai_skip(
	Function(XLL_FP, L"?xll_skip", L"XLL.SKIP")
	.Arg(XLL_DOUBLE, L"u", L"is the time to skip to. ")
	.Arg(XLL_FP, L"t", L"is an array of increasing times. ")
	.Category(L"XLL")
	.FunctionHelp(L"Return the elements of the array of times past u. ")
	.Documentation(L"Doc")
);
_FP12* WINAPI xll_skip(double u, _FP12* pt)
{
#pragma XLLEXPORT
	static xll::FP12 result;

	double* t = &pt->array[0]; // a pointer to modify
	size_t n = skip(u, size(*pt), t);
	result.resize((RW)n, 1);
	std::copy(t, t + n, result.array());

	return result.get();
}

#endif