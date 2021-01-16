#pragma once
#include <iostream>
#include <functional>

template<class key>
struct hash{};

template<>
struct hash<int>
{
    size_t operator()(int x) const {return x;}
};


template<>
struct hash<double>
{
    size_t operator()(double x) const {return x;}
};
