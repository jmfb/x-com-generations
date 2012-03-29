#include "../../Graphics/ColorScheme.h"
#include "../../UnitTest/UnitTest.h"
#include <set>

namespace XCom
{

TEST_CLASS(ColorSchemeTest)
{
public:
	ColorSchemeTest()
	{
	}

#if 0
	static void InitializeTests()
	{
		const Color color(1, 2, 3);
		UnitTest::Mock<IPalette> mockPalette;
		UnitTest::Mock<IGraphicsBuffer> mockGraphics;
		mockPalette.Setup(&IPalette::operator[], UnitTest::Any::Match)
			.Expects(41).Returns(color);
		
		
		//TODO: Need ReturnValue to support returning references to abstract classes somehow.
		mockGraphics.Setup(&IGraphicsBuffer::GetPalette, UnitTest::Any::Match)
			.Expects(8).Returns(*mockPalette.GetObject());
		
		
		ColorScheme::Get(mockGraphics.GetObject(), SCHEME_WHITE);
		mockGraphics.Verify();
		mockPalette.Verify();
	}
#endif
	
	TEST_METHOD(DefaultConstructor)
	{
		ColorScheme scheme;
		Color black;
		Assert.AreEqual(black, scheme[COLOR_LIGHTER], "COLOR_LIGHTER");
		Assert.AreEqual(black, scheme[COLOR_LIGHT], "COLOR_LIGHT");
		Assert.AreEqual(black, scheme[COLOR_BASE], "COLOR_BACK");
		Assert.AreEqual(black, scheme[COLOR_LIGHTDARK], "COLOR_LIGHTDARK");
		Assert.AreEqual(black, scheme[COLOR_DARK], "COLOR_DARK");
		Assert.AreEqual(black, scheme[COLOR_DARKER], "COLOR_DARKER");
	}
	
	TEST_METHOD(PaletteConstructorFive)
	{
		const unsigned long index = 1;
		const Color colorLighter(1, 1, 1);
		const Color colorLight(2, 2, 2);
		const Color colorBack(3, 3, 3);
		const Color colorDark(4, 4, 4);
		const Color colorDarker(5, 5, 5);
		UnitTest::Mock<IPalette> mockPalette;
		mockPalette.Setup(&IPalette::operator[], index).Returns(colorLighter);
		mockPalette.Setup(&IPalette::operator[], index + 1).Returns(colorLight);
		mockPalette.Setup(&IPalette::operator[], index + 2).Returns(colorBack);
		mockPalette.Setup(&IPalette::operator[], index + 3).Returns(colorDark);
		mockPalette.Setup(&IPalette::operator[], index + 4).Returns(colorDarker);
		ColorScheme scheme(*mockPalette.GetObject(), index, 5);
		Assert.AreEqual(colorLighter, scheme[COLOR_LIGHTER], "COLOR_LIGHTER");
		Assert.AreEqual(colorLight, scheme[COLOR_LIGHT], "COLOR_LIGHT");
		Assert.AreEqual(colorBack, scheme[COLOR_BASE], "COLOR_BACK");
		Assert.AreEqual(colorBack, scheme[COLOR_LIGHTDARK], "COLOR_LIGHTDARK");
		Assert.AreEqual(colorDark, scheme[COLOR_DARK], "COLOR_DARK");
		Assert.AreEqual(colorDarker, scheme[COLOR_DARKER], "COLOR_DARKER");
		mockPalette.Verify();
	}
	
	TEST_METHOD(PaletteConstructorSix)
	{
		const unsigned long index = 1;
		const Color colorLighter(1, 1, 1);
		const Color colorLight(2, 2, 2);
		const Color colorBack(3, 3, 3);
		const Color colorLightDark(4, 4, 4);
		const Color colorDark(5, 5, 5);
		const Color colorDarker(6, 6, 6);
		UnitTest::Mock<IPalette> mockPalette;
		mockPalette.Setup(&IPalette::operator[], index).Returns(colorLighter);
		mockPalette.Setup(&IPalette::operator[], index + 1).Returns(colorLight);
		mockPalette.Setup(&IPalette::operator[], index + 2).Returns(colorBack);
		mockPalette.Setup(&IPalette::operator[], index + 3).Returns(colorLightDark);
		mockPalette.Setup(&IPalette::operator[], index + 4).Returns(colorDark);
		mockPalette.Setup(&IPalette::operator[], index + 5).Returns(colorDarker);
		ColorScheme scheme(*mockPalette.GetObject(), index, 6);
		Assert.AreEqual(colorLighter, scheme[COLOR_LIGHTER], "COLOR_LIGHTER");
		Assert.AreEqual(colorLight, scheme[COLOR_LIGHT], "COLOR_LIGHT");
		Assert.AreEqual(colorBack, scheme[COLOR_BASE], "COLOR_BACK");
		Assert.AreEqual(colorLightDark, scheme[COLOR_LIGHTDARK], "COLOR_LIGHTDARK");
		Assert.AreEqual(colorDark, scheme[COLOR_DARK], "COLOR_DARK");
		Assert.AreEqual(colorDarker, scheme[COLOR_DARKER], "COLOR_DARKER");
		mockPalette.Verify();
	}
	
	TEST_METHOD(PaletteConstructorInvalid)
	{
		UnitTest::Mock<IPalette> mockPalette;
		Assert.Throws([&]{ ColorScheme scheme(*mockPalette.GetObject(), 1, 0); },
			"Palette size must be 5 or 6.");
		mockPalette.Verify();
	}
	
	TEST_METHOD(IndexInvalid)
	{
		const std::string& expectedMessage = "Index out of range.";
		ColorScheme scheme;
		Assert.Throws([&]{ scheme[0]; }, expectedMessage, "When zero.");
		Assert.Throws([&]{ scheme[COLOR_SCHEME_SIZE + 1]; }, expectedMessage, "When greater.");
		const ColorScheme& constScheme = scheme;
		Assert.Throws([&]{ constScheme[0]; }, expectedMessage, "Const when zero.");
		Assert.Throws([&]{ constScheme[COLOR_SCHEME_SIZE + 1]; }, expectedMessage, "Const when greater.");
	}
	
	TEST_METHOD(IndexValid)
	{
		const Color color(1, 2, 3);
		ColorScheme scheme;
		scheme[COLOR_BASE] = color;
		Assert.AreEqual(color, scheme[COLOR_BASE], "Get non-const equal.");
		Assert.AreNotEqual(color, scheme[COLOR_LIGHT], "Get non-const not equal.");
		const ColorScheme& constScheme = scheme;
		Assert.AreEqual(color, constScheme[COLOR_BASE], "Get const equal.");
		Assert.AreNotEqual(color, constScheme[COLOR_LIGHT], "Get const not equal.");
	}
	
	TEST_METHOD(GetInverse)
	{
		Color colors[COLOR_SCHEME_SIZE];
		ColorScheme scheme;
		for (unsigned long index = 0; index < COLOR_SCHEME_SIZE; ++index)
			scheme[index + 1] = colors[index] = Color(index, index, index);
		ColorScheme inverse = scheme.GetInverse();
		Assert.AreEqual(colors[5], inverse[COLOR_LIGHTER], "COLOR_LIGHTER");
		Assert.AreEqual(colors[4], inverse[COLOR_LIGHT], "COLOR_LIGHT");
		Assert.AreEqual(colors[3], inverse[COLOR_BASE], "COLOR_BACK");
		Assert.AreEqual(colors[2], inverse[COLOR_LIGHTDARK], "COLOR_LIGHTDARK");
		Assert.AreEqual(colors[1], inverse[COLOR_DARK], "COLOR_DARK");
		Assert.AreEqual(colors[0], inverse[COLOR_DARKER], "COLOR_DARKER");
	}

#if 0	
	TEST_METHOD(GetValid)
	{
		UnitTest::Mock<IGraphicsBuffer> mockGraphics;
		std::set<const ColorScheme*> schemes;
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_WHITE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_AQUA));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_GREEN));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_BLUE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_DARK_YELLOW));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_PURPLE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_YELLOW));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_LIGHT_MAGENTA));
		Assert.AreEqual(8ul, schemes.size(), "Distinct color schemes.");
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_WHITE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_AQUA));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_GREEN));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_BLUE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_DARK_YELLOW));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_PURPLE));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_YELLOW));
		schemes.insert(&ColorScheme::Get(mockGraphics.GetObject(), SCHEME_LIGHT_MAGENTA));
		Assert.AreEqual(8ul, schemes.size(), "Same instances returned between calls.");
		mockGraphics.Verify();
	}
	
	TEST_METHOD(GetInvalid)
	{
		UnitTest::Mock<IGraphicsBuffer> mockGraphics;
		Assert.Throws([&]{ ColorScheme::Get(mockGraphics.GetObject(), static_cast<ColorSchemeType>(8)); },
			"Bad color scheme index.");
		mockGraphics.Verify();
	}
#endif
};

}
