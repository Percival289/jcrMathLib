#include <gtest/gtest.h>
#include <jcml/constants.h>

TEST(ConstantsTest, BasicConstants)
{
    EXPECT_NEAR(jcml::constants::pi, 3.141592653589793, 1e-15);
    EXPECT_NEAR(jcml::constants::tau, 6.283185307179586, 1e-15);
    EXPECT_NEAR(jcml::constants::deg_to_rad, 0.0174532925199433, 1e-15);
    EXPECT_DOUBLE_EQ(jcml::constants::g, 9.80665);
}