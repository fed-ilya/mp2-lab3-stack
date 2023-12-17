#include "../mp2-lab3-stack/TCalculator.h"


#include "gtest.h"

TEST(TCalculator, can_create_calculator)
{
    ASSERT_NO_THROW(TCalculator calc);
}

TEST(TCalculator, can_create_calculator_with_positive_size_of_str)
{
    std::string a = "1+1";
    ASSERT_NO_THROW(TCalculator calc(a));
}
TEST(TCalculator, can_get_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(b = calc.get_infix());
    EXPECT_EQ(a, b);
}
TEST(TCalculator, can_set_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(calc.set_infix(b));
    EXPECT_EQ(calc.get_infix(), b);
}

TEST(TCalculator, can_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_correct)
{/////
    std::string a = "2+(3*5)";
    std::string b = "235*+";
    std::string c;
    TCalculator calc(a);
    ASSERT_NO_THROW(c = calc.get_postfix());
    EXPECT_EQ(c, b);
}
TEST(TCalculator, cant_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    std::string b = "235*+";
    std::string c;
    TCalculator calc(a);
    EXPECT_NE(calc.get_postfix(), b);
}

TEST(TCalculator, check_expression_return_true_when_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";


    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check = calc.proverka_skob(calc.get_infix()));
    EXPECT_EQ(true, check);
}


TEST(TCalculator, check_expression_return_false_when_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";


    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check = calc.proverka_skob(calc.get_infix()));
    EXPECT_EQ(false, check);
}

TEST(TCalculator, can_calculate_if_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";


    TCalculator calc(a);
    double check;
    ASSERT_NO_THROW(check = calc.CalcPostfix());
    EXPECT_EQ(17, check);
}

TEST(TCalculator, cant_calculate_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";


    TCalculator calc(a);
    double check;
    ASSERT_ANY_THROW(check = calc.CalcPostfix());
    EXPECT_NE(17, check);
}