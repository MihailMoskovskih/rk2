#include <gtest/gtest.h>
#include "adaper.cpp"

TEST(PlayerTest, ForwardsAttack) {
    Forwards f("John");
    testing::internal::CaptureStdout();
    f.attack();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Forward attack John\n", output);
}

TEST(PlayerTest, CenterDefense) {
    Center c("Jane");
    testing::internal::CaptureStdout();
    c.defense();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Center defense Jane\n", output);
}

TEST(PlayerTest, TranslatorAttackAndDefense) {
    Translator t("YaoMing");
    testing::internal::CaptureStdout();
    t.attack();
    t.defense();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Foreign Center attack YaoMing\nForeign Center defense YaoMing\n", output);
}


