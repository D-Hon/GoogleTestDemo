
#include "GTest.h"


//////////////////////////////////////////////////////////////////////////
//����У��
bool Odd(int nValue)
{
	return (1 == (nValue % 2)) ? true : false;
}

//ż��У��
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
			EXPECT_EQ(true, Odd(i)) << i << " ��Ϊ����";
		}
	}
}
TEST(GT, Even)
{
	for (int i = 0; i < 4; i++)
	{
		//if (0 == (i % 2))
		{
			EXPECT_EQ(true, Even(i)) << i << " ��Ϊż��";
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//�Զ����ӡ��Ϣ
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
		msg << "���� " << m_expr << " = " << nValue << " ��������";
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
//������
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
	//���¼��ҿ������ȹ���İ�ס�����ġ�
	//testing::AddGlobalTestEnvironment(new FooEnvironment_First);
	//testing::AddGlobalTestEnvironment(new FooEnvironment_Second);

	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
