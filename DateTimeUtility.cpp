#include "DateTimeUtility.h"

namespace XCom
{

std::chrono::high_resolution_clock::time_point DateTimeUtility::GetNow() const
{
	return std::chrono::high_resolution_clock::now();
}

}
