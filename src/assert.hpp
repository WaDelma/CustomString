#ifndef ASSERT_HPP
#define ASSERT_HPP
#ifdef NDEBUG
    #define assert(x)
#else
    #include <iostream>
	#include <stdexcept> 
	#define assert(x) ((void)((x)?(void)0:doAssert(#x, __func__, __FILE__, __LINE__)))
    extern inline void doAssert(const char *x, const char *func, const char *file, int line) {
		std::cerr << "Test " << func << " in " << file << " line " << line << " failed: " << std::endl;
		throw std::logic_error(x);
	} 
#endif
#endif
