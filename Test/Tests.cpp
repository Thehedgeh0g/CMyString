//
// Created by flipd on 10.05.2024.
//

#include <gtest/gtest.h>
#include <sstream>
#include "../Class/CMyString.h"

TEST(CMyStringTest, TestSuccesfullCreateEmpty)
{
    CMyString string;
    EXPECT_TRUE(std::strcmp(string.GetStringData(), "") == 0);
    EXPECT_EQ(string.GetLength(), 0);
}

TEST(CMyStringTest, TestSuccesfullCreateWithPStr)
{
    const char *testStr = "Hello world";
    CMyString string(testStr);
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr) == 0);
    EXPECT_EQ(string.GetLength(), strlen(testStr));
}

TEST(CMyStringTest, TestSuccesfullCreateWithStlStr)
{
    std::string testStr = "Hello world";
    CMyString string(testStr);
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr.c_str()) == 0);
    EXPECT_EQ(string.GetLength(), testStr.length());
}

TEST(CMyStringTest, TestSuccesfullCreateWithMove)
{
    std::string testStr = "Hello world";
    CMyString tmpString(testStr);
    CMyString string(std::move(tmpString));
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr.c_str()) == 0);
    EXPECT_EQ(string.GetLength(), testStr.length());

    EXPECT_TRUE(std::strcmp(tmpString.GetStringData(), "") == 0);
    EXPECT_EQ(tmpString.GetLength(), 0);
}

TEST(CMyStringTest, TestSuccesfullCreateWithPtrStrWithStrLen)
{
    const char *testStr = "Hello world";
    CMyString string(testStr, 11);
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr) == 0);
    EXPECT_EQ(string.GetLength(), strlen(testStr));
}

TEST(CMyStringTest, TestSuccesfullCreateWithPtrStrWithNullSym)
{
    const char *testStr = "Hello \0world";
    CMyString string(testStr, 12);
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr) == 0);
    EXPECT_EQ(string.GetLength(), 12);
}

TEST(CMyStringTest, TestSuccesfullCopyCMyString)
{
    CMyString testStr = "Hello \0world";
    CMyString string = testStr;
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr.GetStringData()) == 0);
    EXPECT_EQ(string.GetLength(), testStr.GetLength());
}

TEST(CMyStringTest, TestSuccesfullCopyPtrString)
{
    const char *testStr = "Hello \0world";
    CMyString string = testStr;
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr) == 0);
    EXPECT_EQ(string.GetLength(), strlen(testStr));
}

TEST(CMyStringTest, TestSuccesfullCopyStlString)
{
    std::string testStr = "Hello world";
    CMyString string = testStr;
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr.c_str()) == 0);
    EXPECT_EQ(string.GetLength(), testStr.length());
}

TEST(CMyStringTest, TestSuccesfullCopyWithMoveMyCString)
{
    std::string testStr = "Hello world";
    CMyString tmpString = testStr;
    CMyString string(std::move(tmpString));
    EXPECT_TRUE(std::strcmp(string.GetStringData(), testStr.c_str()) == 0);
    EXPECT_EQ(string.GetLength(), testStr.length());

    EXPECT_TRUE(std::strcmp(tmpString.GetStringData(), "") == 0);
    EXPECT_EQ(tmpString.GetLength(), 0);
}

TEST(CMyStringTest, TestSuccesfullGetSubstr)
{
    std::string testStr = "Hello world";
    CMyString string(testStr);
    EXPECT_TRUE(std::strcmp(string.SubString(1, 4).GetStringData(), "ello") == 0);
}

TEST(CMyStringTest, TestSuccesfullClear)
{
    std::string testStr = "Hello world";
    CMyString string(testStr);
    string.Clear();
    EXPECT_TRUE(std::strcmp(string.GetStringData(), "") == 0);
    EXPECT_EQ(string.GetLength(), 0);
}

TEST(CMyStringTest, TestSuccesfullSelfConcatCMyString)
{
    std::string testStr = "Hello world";
    CMyString string1 = testStr;
    CMyString string2(testStr);
    string1 += string2;
    EXPECT_TRUE(std::strcmp(string1.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(string1.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullSelfConcatPtrString)
{
    CMyString string1 = "Hello world";
    string1 += "Hello world";
    EXPECT_TRUE(std::strcmp(string1.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(string1.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullSelfConcatstlString)
{
    std::string testStr = "Hello world";
    CMyString string1 = "Hello world";
    string1 += testStr;
    EXPECT_TRUE(std::strcmp(string1.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(string1.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullConcatCMyString)
{
    std::string testStr = "Hello world";
    CMyString string1 = testStr;
    CMyString string2(testStr);
    CMyString res = (string1 + testStr);
    EXPECT_TRUE(std::strcmp(res.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(res.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullConcatPtrString)
{
    CMyString string1 = "Hello world";
    CMyString res = (string1 + "Hello world");
    EXPECT_TRUE(std::strcmp(res.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(res.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullConcatstlString)
{
    std::string testStr = "Hello world";
    CMyString string1 = "Hello world";
    CMyString res = (string1 + testStr);
    EXPECT_TRUE(std::strcmp(res.GetStringData(), "Hello worldHello world") == 0);
    EXPECT_EQ(res.GetLength(), 22);
}

TEST(CMyStringTest, TestSuccesfullGetCharByIndex)
{
    CMyString string1 = "Hello world";
    EXPECT_EQ(string1[0], 'H');
}

TEST(CMyStringTest, TestSuccesfullGetCharWithInvalidIndex)
{
    CMyString string1 = "Hello world";
    EXPECT_THROW(
        {
            string1[50];
        },
        std::invalid_argument
    );
}

TEST(CMyStringTest, TestSuccesfullEditCharByIndex)
{
    CMyString string1 = "Hello world";
    string1[0] = 'W';
    EXPECT_TRUE(std::strcmp(string1.GetStringData(), "Wello world") == 0);
}

TEST(CMyStringTest, TestSuccesfullEditCharWithInvalidIndex)
{
    CMyString string1 = "Hello world";
    EXPECT_THROW(
        {
            string1[50] = 'W';
        },
        std::invalid_argument
    );
}

TEST(CMyStringTest, TestSuccesfullCompareEqualStrings)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello world";
    EXPECT_TRUE(string1 == string2);
}

TEST(CMyStringTest, TestSuccesfullCompareNotEqualStrings)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello worl";
    EXPECT_FALSE(string1 == string2);
}

TEST(CMyStringTest, TestSuccesfullUnCompareEqualStrings)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello world";
    EXPECT_FALSE(string1 != string2);
}

TEST(CMyStringTest, TestSuccesfullUnCompareNotEqualStrings)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello worl";
    EXPECT_TRUE(string1 != string2);
}

TEST(CMyStringTest, TestSuccesfullcompareBiggerString)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello worlz";
    EXPECT_TRUE(string1 < string2);
    EXPECT_TRUE(string2 > string1);
    EXPECT_FALSE(string1 > string2);
    EXPECT_FALSE(string2 < string1);
}

TEST(CMyStringTest, TestSuccesfullcompareBiggerStringByLength)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello worl";
    EXPECT_FALSE(string1 < string2);
    EXPECT_TRUE(string2 > string1);
}

TEST(CMyStringTest, TestSuccesfullBiggerEqualStrings)
{
    CMyString string1 = "Hello world";
    CMyString string2 = "Hello worl";
    CMyString string3 = "Hello world";
    EXPECT_FALSE(string1 <= string2);
    EXPECT_TRUE(string2 >= string1);
    EXPECT_TRUE(string3 <= string1);
    EXPECT_TRUE(string3 >= string2);
}



TEST(CMyStringTest, TestSuccesfullCoutAndCin)
{
    CMyString string1 = "Hello";
    CMyString string2;
    std::stringstream ss;
    ss << string1;
    ss >> string2;
    std::string res = string2.GetStringData();
    EXPECT_EQ(string1, string2);
}

TEST(CMyStringIteratorTest, TestSuccesfullCreatebeginIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    EXPECT_EQ(string1[0], *it);
}

TEST(CMyStringIteratorTest, TestSuccesfullCreateEndIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.end();
    EXPECT_EQ(string1[string1.GetLength()], *it);
}

TEST(CMyStringIteratorTest, TestSuccesfullIncrementIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    EXPECT_EQ(string1[0], *it++);
    EXPECT_EQ(string1[1], *it);
    EXPECT_EQ(string1[2], *++it);
}

TEST(CMyStringIteratorTest, TestSuccesfullDecrementIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    it++;
    it++;
    EXPECT_EQ(string1[2], *it--);
    EXPECT_EQ(string1[1], *it);
    EXPECT_EQ(string1[0], *--it);
}

TEST(CMyStringIteratorTest, TestSuccesfullJumpIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    EXPECT_EQ(string1[2], it[2]);
}

TEST(CMyStringIteratorTest, TestSuccesfullCompareIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it1 = string1.begin();
    CMyStringIterator it2 = string1.begin();
    EXPECT_TRUE(it1 == it2);
    EXPECT_TRUE(it1 <= it2);
    EXPECT_TRUE(it1 >= it2);
    it1++;
}

TEST(CMyStringIteratorTest, TestSuccesfullCreateEndRIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.rend();
    EXPECT_EQ(string1[0], *it);
}

TEST(CMyStringIteratorTest, TestSuccesfullCreateBeginRIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.rbegin();
    EXPECT_EQ(string1[string1.GetLength()], *it);
}

TEST(CMyStringIteratorTest, TestSuccesfullDecrementRIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.rend();
    EXPECT_EQ(string1[0], *it--);
    EXPECT_EQ(string1[1], *it);
    EXPECT_EQ(string1[2], *--it);
}

TEST(CMyStringIteratorTest, TestSuccesfullInecrementRIt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.rbegin();
    EXPECT_EQ(string1[5], *it++);
    EXPECT_EQ(string1[4], *it);
    EXPECT_EQ(string1[3], *++it);
}


TEST(CMyStringIteratorTest, TestSuccesfullInecrementItWithInt)
{
    CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    it+2;
    EXPECT_EQ(string1[2], *it);
    it-2;
    EXPECT_EQ(string1[0], *it);
    2+it;
    EXPECT_EQ(string1[2], *it);
    2-it;
    EXPECT_EQ(string1[0], *it);
}

TEST(CMyStringIteratorTest, TestSuccesfullRangeBased)
{
    CMyString string1 = "Hello";
    std::stringstream ss;
    for (char ch : string1)
    {
        ss << ch;
    }
    ss >> string1;
    EXPECT_TRUE(std::strcmp(string1.GetStringData(), "Hello") == 0);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
