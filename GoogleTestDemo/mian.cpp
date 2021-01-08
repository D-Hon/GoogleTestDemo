
#include <gtest/gtest.h>
#ifdef _DEBUG
#pragma comment(lib,"gtestd.lib")
#pragma comment(lib,"gtest_maind.lib")
#else
#pragma comment(lib,"gtest.lib")
#pragma comment(lib,"gtest_main.lib")
#endif


//////////////////////////////////////////////////////////////////////////
//奇数校验
bool Odd(int nValue)
{
	return (1 == (nValue % 2)) ? true : false;
}

//偶数校验
bool Even(int nValue)
{
	return (0 == (nValue % 2)) ? true : false;
}

//////////////////////////////////////////////////////////////////////////
TEST(GT, Odd)
{
	for (int i = 0; i < 4; i++)
	{
		EXPECT_EQ(true, Odd(i));
	}
}
TEST(GT, Even)
{
	for (int i = 0; i < 4; i++)
	{
		EXPECT_EQ(true, Even(i));
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
