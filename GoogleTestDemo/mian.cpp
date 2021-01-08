
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
	testing::GTEST_FLAG(output) = "xml:";  //���Խ����xml��ʽ���浽����·���£��Ҳ��Ḳ�ǣ�ÿ�ݲ��Խ����������

	//���¼��ҿ������ȹ���İ�ס�����ġ�
	//testing::AddGlobalTestEnvironment(new FooEnvironment_First);
	//testing::AddGlobalTestEnvironment(new FooEnvironment_Second);

	/*��������ʽ������ָ��

	--gtest_output=xml:             //���Խ����xml��ʽ���浽����·����
	--gtest_output=xml:d:\          //���Խ����xml��ʽ���浽 D��
	--gtest_output=xml:d:\foo.xml   //���Խ����foo.xml�ļ����浽 D��

	./foo_test                                      �������а���
	./foo_test --gtest_filter=*                     �������а���
	./foo_test --gtest_filter=FooTest.*             �������С����԰�������(testcase_name)��ΪFooTest�İ���
	./foo_test --gtest_filter=*Null*:*Constructor*  �������С����԰�������(testcase_name)���򡰲�������(test_name)������Null��Constructor�İ�����
	./foo_test --gtest_filter=FooTest.*-FooTest.Bar �������С����԰�������(testcase_name)��ΪFooTest�İ��������ǳ���FooTest.Bar�������

	--gtest_repeat=1000    �ظ�ִ��1000�Σ���ʹ��;���ִ���
	--gtest_repeat=-1      ���޴���ִ��
	--gtest_repeat=1000 --gtest_break_on_failure    �ظ�ִ��1000�Σ������ڵ�һ��������ʱ����ֹͣ��������ܶԵ��Էǳ����á�
	--gtest_repeat=1000 --gtest_filter=FooBar       �ظ�ִ��1000�β��԰�������ΪFooBar�İ�����


	--gtest_break_on_failure	����ģʽ�£�������ʧ��ʱֹͣ���������
	*/
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
