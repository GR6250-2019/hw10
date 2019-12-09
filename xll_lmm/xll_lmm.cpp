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
//Return the bumped forwards past u. See skip example below.
//Make sure the function is volatile.
AddIn xai_lmm_advance(
	Function(XLL_FP, L"?xll_lmm_advance", L"XLL.LMM.ADVANCE")
	.Arg(XLL_DOUBLE, L"u", L"is the time to advance to. ")
	.Arg(XLL_FP, L"t", L"is an array of times. ")
	.Arg(XLL_FP, L"f", L"is an array of forwards. ")
	.Arg(XLL_FP, L"sigma", L"is an array of volatilities. ")
	.Arg(XLL_DOUBLE, L"alpha", L"is a correlation parameter. ")
	.Volatile()
	.Category(CATEGORY)
	.FunctionHelp(L"Generate random forward curve at time u. ")
	.Documentation(L"Implement the LIBOR Market Model. ")
);
_FP12* WINAPI xll_lmm_advance(double u, _FP12* pt, _FP12* pf, _FP12* ps, double alpha)
{
#pragma XLLEXPORT
	static xll::FP12 result;

	try {
		auto n = size(*pt);

		ensure(n == size(*pf));
		ensure(n == size(*ps));

		double* t = &pt->array[0];
		double* f = &pf->array[0];
		double* s = &ps->array[0];

		n = fms::lmm::advance(u, n, t, f, s, alpha);
		result.resize(n, 1);
		std::copy(f, f + n, result.begin());
	}
	catch (const std::exception & ex) {
		XLL_ERROR(ex.what());

		return 0;
	}

	return result.get();
}

AddIn xai_lmm_to_futures(
	Function(XLL_FP, L"?xll_lmm_to_futures", L"XLL.LMM.TO_FUTURES")
	.Arg(XLL_FP, L"t", L"is an array of times. ")
	.Arg(XLL_FP, L"f", L"is an array of forwards. ")
	.Arg(XLL_FP, L"sigma", L"is an array of volatilities. ")
	.Volatile()
	.Category(CATEGORY)
	.FunctionHelp(L"Convert array of forwards to futures. ")
	.Documentation(L"Add convexity. ")
);
_FP12* WINAPI xll_lmm_to_futures(const _FP12* pt, _FP12* pf, const _FP12* ps)
{
#pragma XLLEXPORT
	fms::lmm::to_futures(size(*pt), pt->array, pf->array, ps->array);

	return pf;
}

AddIn xai_lmm_to_forward(
	Function(XLL_FP, L"?xll_lmm_to_forwards", L"XLL.LMM.TO_FORWARDS")
	.Arg(XLL_FP, L"t", L"is an array of times. ")
	.Arg(XLL_FP, L"f", L"is an array of futures. ")
	.Arg(XLL_FP, L"sigma", L"is an array of volatilities. ")
	.Volatile()
	.Category(CATEGORY)
	.FunctionHelp(L"Convert array of futures to forwards. ")
	.Documentation(L"Subtract convexity. ")
);
_FP12* WINAPI xll_lmm_to_forwards(const _FP12* pt, _FP12* pf, const _FP12* ps)
{
#pragma XLLEXPORT
	fms::lmm::to_forwards(size(*pt), pt->array, pf->array, ps->array);

	return pf;
}
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
	auto n = skip(u, size(*pt), t);
	result.resize(n, 1);
	std::copy(t, t + n, result.array());

	return result.get();
}

#endif
