// fms_lmm.cpp - This file contains the 'main' function. Program execution begins and ends there.
#include <cassert>
#include <algorithm>
#include <vector>
#include "fms_lmm.h"

using namespace fms;

void test_fms_lmm()
{
	std::vector<double> t{ 1, 2, 3 };
	std::vector<double> f{ .1, .2, .3 };
	std::vector<double> sigma{ .01, .02, .03 };

	std::vector<double> f0(f);
	lmm::to_futures(3, t.data(), f.data(), sigma.data());
	for (size_t i = 0; i < 3; ++i) {
		assert(f[i] > f0[i]);
	}
	lmm::to_forwards(3, t.data(), f.data(), sigma.data());
	for (size_t i = 0; i < 3; ++i) {
		assert(f[i] == f0[i]);
	}
}

int main()
{
	test_fms_lmm();

    return 0;
}

