#include <gtest/gtest.h>
#include "src/three.hpp"

TEST(eq, test01) {
    Three num1("0"), num2("0");
    ASSERT_TRUE(num1 == num2);
}

TEST(eq, test02) {
    Three num1("100"), num2("21");
    ASSERT_FALSE(num1 == num2);
}


TEST(not_eq, test01) {
    Three num1("21"), num2("21");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_eq, test02) {
    Three num1("21"), num2("1");
    ASSERT_TRUE(num1 != num2);
}



TEST (greater, test01) {
    Three num1("21"), num2("1");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Three num1("102");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Three num1("10100"), num2("10010");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Three num1("10"), num2("1220");
    ASSERT_FALSE(num1 > num2);
}



TEST(greater_or_eq, test01) {
    Three num1("12"), num2("1");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test02) {
    Three num1("112");
    ASSERT_TRUE(num1 >= num1);
}

TEST(greater_or_eq, test03) {
    Three num1("22"), num2("12");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test04) {
    Three num1("10"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}



TEST(less, test01) {
    Three num1("21"), num2("1");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Three num1("222");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Three num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Three num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}



TEST(less_or_eq, test01) {
    Three num1("21"), num2("1");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test02) {
    Three num1("111");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_eq, test03) {
    Three num1("22"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test04) {
    Three num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}



TEST(add, test01) {
    Three num1("0"), num2("12");
    ASSERT_TRUE(num1 + num2 == Three("12"));
}

TEST(add, test02) {
    Three num1("11"), num2("0");
    ASSERT_TRUE(num1 + num2 == Three("11"));
}

TEST(add, test03) {
    Three num1("20"), num2("1");
    ASSERT_TRUE(num1 + num2 == Three("21"));
}

TEST(add, test04) {
    Three num1("2"), num2("10");
    ASSERT_TRUE(num1 + num2 == Three("12"));
}

TEST(add, test05) {
    Three num1("2"), num2("1");
    ASSERT_TRUE(num1 + num2 == Three("10"));
}

TEST(add, test06) {
    Three num1("20"), num2("12");
    ASSERT_TRUE(num1 + num2 == Three("102"));
}


TEST(sub, test01) {
    Three num1("12"), num2("10");
    ASSERT_TRUE(num1 - num2 == Three("2"));
}

TEST(sub, test02) {
    Three num1("2"), num2("1");
    ASSERT_TRUE(num1 - num2 == Three("1"));
}

TEST(sub, test03) {
    Three num1("10"), num2("2");
    ASSERT_TRUE(num1 - num2 == Three("1"));
}

TEST(sub, test04) {
    Three num1("21212"), num2("21212");
    ASSERT_TRUE(num1 - num2 == Three("0"));
}

TEST(sub, test05) {
    Three num1("2"), num2("12");
    ASSERT_ANY_THROW(num1 - num2);
}


TEST(sub, test07) {
    Three num1("10100"), num2("10010");
    ASSERT_TRUE(num1 - num2 == Three("20"));
}


TEST(assignment, test01) {
    Three num1, num2("21");
    num1 = num2;
    ASSERT_TRUE(num1 == Three("21"));
}

TEST(assignment, test02) {
    Three num1("12"), num2("1");
    num1 = num2;
    ASSERT_TRUE(num1 == num2);
}

TEST(assignment, test03) {
    Three num1, num2;
    num1 = num2;
    ASSERT_TRUE(num1 == num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}