
#include "GTest.h"


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
		//if (1 == (i % 2))
		{
			EXPECT_EQ(true, Odd(i)) << i << " 不为奇数";
		}
	}
}
TEST(GT, Even)
{
	for (int i = 0; i < 4; i++)
	{
		//if (0 == (i % 2))
		{
			EXPECT_EQ(true, Even(i)) << i << " 不为偶数";
		}
	}
}

//////////////////////////////////////////////////////////////////////////
TEST_F(CGT, COdd)
{
	for (int i = 0; i < 4; i++)
	{
		if (1 == (i % 2))
		{
			EXPECT_EQ(true, COdd(i));
		}
	}
}
TEST_F(CGT, CEven)
{
	for (int i = 0; i < 4; i++)
	{
		if (0 == (i % 2))
		{
			EXPECT_EQ(true, CEven(i));
		}
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
