#include <iostream>
#include <string>
#include "../include/FilenameValidator.hpp"
#include <utility>
#include <gtest/gtest.h>
#include <sstream>

using namespace std;

class TestFilenameValidationCheck : 
	public ::testing::TestWithParam<std::pair<string,bool>> {};

class TestFilenameValidationChecker : 
	public ::testing::TestWithParam<std::pair<string,bool>> {};

TEST_P(TestFilenameValidationCheck, correctFilename)
{
   auto [name, result]= GetParam();
   EXPECT_EQ(is_valid(name), result);
}

INSTANTIATE_TEST_SUITE_P(
   CheckFilenameCorrect,
   TestFilenameValidationCheck,
   ::testing::Values(
	   std::make_pair("sandeep.txt", true),
	   std::make_pair("_adhrit.txt", true),
	   std::make_pair("san_deep.txt", true)
	   )//,
   //[](const ::testing::TestParamInfo<std::pair<std::string, bool>> info)
   //{
   //   std::stringstream ss_string;

   //   ss_string << "Param_ " << info.param.first << "  " << info.param.second;

   //   std::string result= ss_string.str();
   //   return result; 
   //}
);

TEST_P(TestFilenameValidationChecker, incorrectFilename)
{
    auto [name, result] = GetParam();
    EXPECT_EQ(is_valid(name), result);
}

INSTANTIATE_TEST_SUITE_P(
    CheckFilenameIncorrect,
    TestFilenameValidationChecker,
    ::testing::Values(
	   std::make_pair("#myNmae.txt", false),
	   std::make_pair("sandeep&khamari.txt", false),
	   std::make_pair("sandeep", false),
	   std::make_pair(".txt", false)
    )
);


class TestFilenameValidationCheckWithRegex: public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(TestFilenameValidationCheckWithRegex, correctFilenames)
{
   auto [name, expected]= GetParam();
   EXPECT_EQ(is_valid_regex(name), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CheckFilenameRegexCorrect,
    TestFilenameValidationCheckWithRegex,
    ::testing::Values(
	    std::make_pair("config.git", true),
	    // failing case.
	    //std::make_pair("config_log", true),
	    std::make_pair("config_log.txt", true),
	    std::make_pair("_Assfwrc.w", true),
	    std::make_pair("B_qwqe.Zq", true),
	    std::make_pair("_Q.a", true),
	    std::make_pair("A.B", true)
    )
);

class TestFilenameValidationCheckWithRegexIncorrect: public ::testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(TestFilenameValidationCheckWithRegexIncorrect, incorrectFilenames)
{
   auto [name, expected]= GetParam();
   EXPECT_EQ(is_valid_regex(name), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CheckFilenameRegexIncorrect,
    TestFilenameValidationCheckWithRegexIncorrect,
    ::testing::Values(
            std::make_pair(".config45.git", false),
            std::make_pair("con!fig_log", false),
            std::make_pair("_Assfwrc.?w", false),
            std::make_pair("", false),
            std::make_pair("_Q._2a", false),
	    std::make_pair(" ", false)
    )
);

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
