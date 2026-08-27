#include <gtest/gtest.h>
#include <cmath>

#include <jcml/vectors/vector3.h>


TEST(Vector3Test, DefaultConstructor)
{
    jcml::Vector3 v;

    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}


TEST(Vector3Test, Constructor)
{
    jcml::Vector3 v{1.0, 2.0, 3.0};

    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
    EXPECT_DOUBLE_EQ(v.z, 3.0);
}


TEST(Vector3Test, Addition)
{
    jcml::Vector3 a{1.0, 2.0, 3.0};
    jcml::Vector3 b{4.0, 5.0, 6.0};

    auto result = a + b;

    EXPECT_DOUBLE_EQ(result.x, 5.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
    EXPECT_DOUBLE_EQ(result.z, 9.0);
}


TEST(Vector3Test, Subtraction)
{
    jcml::Vector3 a{4.0, 5.0, 6.0};
    jcml::Vector3 b{1.0, 2.0, 3.0};

    auto result = a - b;

    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 3.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}


TEST(Vector3Test, Multiplication)
{
    jcml::Vector3 v{1.0, 2.0, 3.0};

    auto result = v * 2.0;

    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 6.0);
}


TEST(Vector3Test, Division)
{
    jcml::Vector3 v{2.0, 4.0, 6.0};

    auto result = v / 2.0;

    EXPECT_DOUBLE_EQ(result.x, 1.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}


TEST(Vector3Test, Magnitude)
{
    jcml::Vector3 v{2.0, 3.0, 6.0};

    EXPECT_NEAR(v.mag(), 7.0, 1e-9);
}


TEST(Vector3Test, Normalized)
{
    jcml::Vector3 v{2.0, 3.0, 6.0};

    auto result = v.normalized();

    EXPECT_NEAR(result.x, 2.0 / 7.0, 1e-9);
    EXPECT_NEAR(result.y, 3.0 / 7.0, 1e-9);
    EXPECT_NEAR(result.z, 6.0 / 7.0, 1e-9);
}


TEST(Vector3Test, Dot)
{
    jcml::Vector3 a{1.0, 2.0, 3.0};
    jcml::Vector3 b{4.0, 5.0, 6.0};

    EXPECT_DOUBLE_EQ(a.dot(b), 32.0);
}


TEST(Vector3Test, Cross)
{
    jcml::Vector3 a{1.0, 0.0, 0.0};
    jcml::Vector3 b{0.0, 1.0, 0.0};

    auto result = a.cross(b);

    EXPECT_DOUBLE_EQ(result.x, 0.0);
    EXPECT_DOUBLE_EQ(result.y, 0.0);
    EXPECT_DOUBLE_EQ(result.z, 1.0);
}


TEST(Vector3Test, Distance)
{
    jcml::Vector3 a{1.0, 2.0, 3.0};
    jcml::Vector3 b{4.0, 6.0, 3.0};

    EXPECT_NEAR(jcml::dist(a, b), 5.0, 1e-9);
}


TEST(Vector3Test, Negation)
{
    jcml::Vector3 v{1.0, -2.0, 3.0};

    auto result = -v;

    EXPECT_DOUBLE_EQ(result.x, -1.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
    EXPECT_DOUBLE_EQ(result.z, -3.0);
}