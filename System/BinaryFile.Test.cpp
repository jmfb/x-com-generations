#include "BinaryFile.h"
#include <UnitTest/UnitTest.h>
#include "../WindowsInclude.h"
using UnitTest::Assert;

namespace XCom
{

TEST_CLASS(BinaryFileTest)
{
public:
	BinaryFileTest()
	{
	}

	class TempFile
	{
	public:
		TempFile(const std::string& filename, const char* data, unsigned long size)
			: mFileName(filename)
		{
			std::ofstream out(filename.c_str(), std::ios::binary);
			out.write(data, size);
		}
		~TempFile()
		{
			::DeleteFile(mFileName.c_str());
		}

	private:
		std::string mFileName;
	};

	TEST_METHOD(OpenExists)
	{
		const std::string filename = ".\\BinaryFileTestOpenExists.bin";
		char buffer[] = "TEST";
		TempFile temp(filename, buffer, 4);

		BinaryFile file;
		file.Open(filename);
	}

	TEST_METHOD(OpenDoesNotExist)
	{
		BinaryFile file;
		Assert.Throws([&]{ file.Open(".\\BinaryFileTestOpenDoesNotExist.bin"); },
			"Could not open file.");
	}

	TEST_METHOD(ReadNotOpen)
	{
		BinaryFile file;
		char buffer[1] = {0};
		Assert.Throws([&]{ file.Read(buffer, 1); },
			"Must call Open before Read.");
	}

	TEST_METHOD(ReadInvalidArguments)
	{
		const std::string filename = ".\\BinaryFileTestReadInvalidArguments.bin";
		char buffer[] = "TEST";
		TempFile temp(filename, buffer, 4);

		BinaryFile file;
		file.Open(filename);
		Assert.Throws([&]{ file.Read(nullptr, 1); },
			"Data pointer must be non-null.");
		Assert.Throws([&]{ file.Read(buffer, 0); },
			"Size value must be non-zero.");
		Assert.Throws([&]{ file.Read(buffer, (1 << (10 + 10 + 2)) + 1); },
			"Size value sanity check (4MB).");
	}

	TEST_METHOD(ReadValid)
	{
		const std::string filename = ".\\BinaryFileTestReadValid.bin";
		char buffer[] = "TEST";
		TempFile temp(filename, buffer, 4);

		char input[] = "    ";
		BinaryFile file;
		file.Open(filename);
		file.Read(input, 4);
		Assert.AreEqual(std::string(buffer), std::string(input));
	}

	TEST_METHOD(ReadLongNotOpen)
	{
		BinaryFile file;
		unsigned long data = 0;
		Assert.Throws([&]{ file.ReadLong(data); },
			"Must call Open before Read.");
	}

	TEST_METHOD(ReadLongValid)
	{
		const std::string filename = ".\\BinaryFileTestReadUnsignedLongValid.bin";
		char buffer[4] = { 4, 3, 2, 1 };
		const unsigned long value = 0x01020304;
		TempFile temp(filename, buffer, 4);
		BinaryFile file;
		file.Open(filename);
		unsigned long data = 0;
		file.ReadLong(data);
		Assert.AreEqual(value, data);
	}
};

}
