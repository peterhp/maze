#ifndef _CPP_HEADER_ALGORITHM_H_
#define _CPP_HEADER_ALGORITHM_H_

#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>

template<typename _InputIterator, typename _UnaryOperation>
std::string join(_InputIterator first, _InputIterator last,
        _UnaryOperation unary_op, const std::string &deli = std::string()) {
    std::vector<std::string> strs;
    std::transform(first, last, std::back_inserter(strs), unary_op);

    std::ostringstream oss;
    std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(oss, deli.c_str()));

    std::string str= oss.str();
    return str.empty() ? str : str.substr(0, str.length() - deli.length());
}

#endif // algo.h
