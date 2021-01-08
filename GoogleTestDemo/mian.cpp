
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

//////////////////////////////////////////////////////////////////////////
//参数化
TEST_P(CGT_T, CT)
{
	EXPECT_TRUE(CShow());
}
int aValues[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//const char* aValues[] = { "how", "are", "you" };
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Values(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Values("how", "are", "you"));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::ValuesIn(aValues));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::ValuesIn(aValues + 1, aValues + 2));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Range(0, 9));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Range(0, 9, 2));
// INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Bool());
INSTANTIATE_TEST_SUITE_P(CT, CGT_T, testing::Combine(testing::Range(0, 2), testing::Bool(), testing::Values("how", "are", "you")));

int main(int argc, char* argv[])
{
	testing::GTEST_FLAG(output) = "xml:";  //测试结果以xml格式保存到运行路径下，且不会覆盖，每份测试结果均被保存

	//把事件挂卡来，先挂起的包住后挂起的。
	//testing::AddGlobalTestEnvironment(new FooEnvironment_First);
	//testing::AddGlobalTestEnvironment(new FooEnvironment_Second);

	/*命令行形式传测试指令

	--gtest_output=xml:             //测试结果以xml格式保存到运行路径下
	--gtest_output=xml:d:\          //测试结果以xml格式保存到 D盘
	--gtest_output=xml:d:\foo.xml   //测试结果以foo.xml文件保存到 D盘

	./foo_test                                      运行所有案例
	./foo_test --gtest_filter=*                     运行所有案例
	./foo_test --gtest_filter=FooTest.*             运行所有“测试案例名称(testcase_name)”为FooTest的案例
	./foo_test --gtest_filter=*Null*:*Constructor*  运行所有“测试案例名称(testcase_name)”或“测试名称(test_name)”包含Null或Constructor的案例。
	./foo_test --gtest_filter=FooTest.*-FooTest.Bar 运行所有“测试案例名称(testcase_name)”为FooTest的案例，但是除了FooTest.Bar这个案例

	--gtest_repeat=1000    重复执行1000次，即使中途出现错误。
	--gtest_repeat=-1      无限次数执行
	--gtest_repeat=1000 --gtest_break_on_failure    重复执行1000次，并且在第一个错误发生时立即停止。这个功能对调试非常有用。
	--gtest_repeat=1000 --gtest_filter=FooBar       重复执行1000次测试案例名称为FooBar的案例。


	--gtest_break_on_failure	调试模式下，当案例失败时停止，方便调试
	*/
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
