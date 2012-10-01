////////////////////////////////////////////////////////////////////////////////
// Filename:    TimePointStream.h
// Description: Declares a stream insertion operator to format a time_point
//				value which is useful for unit test Assert.AreEqual calls.
//
// Created:     2012-09-30 22:49:31
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <ostream>
#include <chrono>
#include <ctime>

inline std::ostream& operator<<(
	std::ostream& out,
	std::chrono::high_resolution_clock::time_point value)
{
	char buffer[100] = {0};
	std::time_t time = std::chrono::high_resolution_clock::to_time_t(value);
	std::strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", std::localtime(&time));
	return out << buffer;
}

inline std::ostream& operator<<(
	std::ostream& out,
	std::chrono::milliseconds value)
{
	return out << value.count() << "ms";
}

