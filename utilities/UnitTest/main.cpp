#include <iostream>
#include "../../UnitTest/UnitTest.h"

int main(int argc, char** argv)
{
	UnitTest::TestRunWriter writer(std::cout);
	UnitTest::TestRunner::RunTests(writer);
	return 0;
}
