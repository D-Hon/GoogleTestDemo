
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
//自定义打印信息
//funtion(const char* expr_1, int nValue1)    EXPECT_PRED_FORMAT1(funtion, nValue1);
//funtion(const char* expr_1, int nValue1, const char* expr_2, int nValue2)    EXPECT_PRED_FORMAT2(funtion, nValue1, nValue2);
//EXPECT_PRED_FORMAT1,..EXPECT_PRED_FORMAT5
testing::AssertionResult OddF(const char* m_expr, int nValue)
{
	if (1 == (nValue % 2))
	{
		return testing::AssertionSuccess();
	}
	else
	{
		testing::Message msg;
		msg << "参数 " << m_expr << " = " << nValue << " 不是奇数";
		return testing::AssertionFailure(msg);
	}
}

TEST(GT, OddF)
{
	for (int i = 0; i < 10; i++)
	{
		EXPECT_PRED_FORMAT1(OddF, i);
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
	//把事件挂卡来，先挂起的包住后挂起的。
	//testing::AddGlobalTestEnvironment(new FooEnvironment_First);
	//testing::AddGlobalTestEnvironment(new FooEnvironment_Second);

	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
