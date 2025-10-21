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
	   std::make_pair("sandeep", false)
	   )
);

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
