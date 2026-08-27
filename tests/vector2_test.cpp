#include <gtest/gtest.h>
#include <cmath>

#include <jcml/vectors/vector2.h>


TEST(Vector2Test, DefaultConstructor)
{
    jcml::Vector2 v;

    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
}


TEST(Vector2Test, Constructor)
{
    jcml::Vector2 v{3.0, 4.0};

    EXPECT_DOUBLE_EQ(v.x, 3.0);
    EXPECT_DOUBLE_EQ(v.y, 4.0);
}


TEST(Vector2Test, Addition)
{
    jcml::Vector2 a{3.0, 4.0};
    jcml::Vector2 b{1.0, 2.0};

    auto result = a + b;

    EXPECT_DOUBLE_EQ(result.x, 4.0);
    EXPECT_DOUBLE_EQ(result.y, 6.0);
}


TEST(Vector2Test, ScalarAddition)
{
    jcml::Vector2 a{3.0, 4.0};

    auto result = a + 2.0;

    EXPECT_DOUBLE_EQ(result.x, 5.0);
    EXPECT_DOUBLE_EQ(result.y, 6.0);
}


TEST(Vector2Test, Subtraction)
{
    jcml::Vector2 a{3.0, 4.0};
    jcml::Vector2 b{1.0, 2.0};

    auto result = a - b;

    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
}


TEST(Vector2Test, ScalarSubtraction)
{
    jcml::Vector2 a{3.0, 4.0};

    auto result = a - 2.0;

    EXPECT_DOUBLE_EQ(result.x, 1.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
}


TEST(Vector2Test, Multiplication)
{
    jcml::Vector2 a{3.0, 4.0};

    auto result = a * 2.0;

    EXPECT_DOUBLE_EQ(result.x, 6.0);
    EXPECT_DOUBLE_EQ(result.y, 8.0);
}


TEST(Vector2Test, Division)
{
    jcml::Vector2 a{3.0, 4.0};

    auto result = a / 2.0;

    EXPECT_DOUBLE_EQ(result.x, 1.5);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
}

TEST(Vector2Test, Negation)
{
    jcml::Vector2 a{3.0, 4.0};

    auto result = -a;

    EXPECT_DOUBLE_EQ(result.x, -3.0);
    EXPECT_DOUBLE_EQ(result.y, -4.0);
}


TEST(Vector2Test, CompoundOperators)
{
    jcml::Vector2 v{3.0, 4.0};

    v += jcml::Vector2{1.0, 2.0};
    EXPECT_DOUBLE_EQ(v.x, 4.0);
    EXPECT_DOUBLE_EQ(v.y, 6.0);

    v -= jcml::Vector2{1.0, 2.0};
    EXPECT_DOUBLE_EQ(v.x, 3.0);
    EXPECT_DOUBLE_EQ(v.y, 4.0);

    v *= 2.0;
    EXPECT_DOUBLE_EQ(v.x, 6.0);
    EXPECT_DOUBLE_EQ(v.y, 8.0);

    v /= 2.0;
    EXPECT_DOUBLE_EQ(v.x, 3.0);
    EXPECT_DOUBLE_EQ(v.y, 4.0);
}


TEST(Vector2Test, Squared)
{
    jcml::Vector2 v{3.0, 4.0};

    auto result = v.squared();

    EXPECT_DOUBLE_EQ(result.x, 9.0);
    EXPECT_DOUBLE_EQ(result.y, 16.0);
}


TEST(Vector2Test, SqrtComponents)
{
    jcml::Vector2 v{9.0, 16.0};

    auto result = v.sqrtComponents();

    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
}


TEST(Vector2Test, MagnitudeSquared)
{
    jcml::Vector2 v{3.0, 4.0};

    EXPECT_DOUBLE_EQ(v.magSquared(), 25.0);
}


TEST(Vector2Test, Magnitude)
{
    jcml::Vector2 v{3.0, 4.0};

    EXPECT_NEAR(v.mag(), 5.0, 1e-9);
}


TEST(Vector2Test, Normalized)
{
    jcml::Vector2 v{3.0, 4.0};

    auto result = v.normalized();

    EXPECT_NEAR(result.x, 0.6, 1e-9);
    EXPECT_NEAR(result.y, 0.8, 1e-9);
}


TEST(Vector2Test, ZeroNormalization)
{
    jcml::Vector2 v{};

    auto result = v.normalized();

    EXPECT_DOUBLE_EQ(result.x, 0.0);
    EXPECT_DOUBLE_EQ(result.y, 0.0);
}


TEST(Vector2Test, DotProduct)
{
    jcml::Vector2 a{3.0, 4.0};
    jcml::Vector2 b{1.0, 2.0};

    EXPECT_DOUBLE_EQ(a.dot(b), 11.0);
}


TEST(Vector2Test, DistanceSquared)
{
    jcml::Vector2 a{3.0, 4.0};
    jcml::Vector2 b{1.0, 2.0};

    EXPECT_DOUBLE_EQ(jcml::distSquared(a, b), 8.0);
}


TEST(Vector2Test, Distance)
{
    jcml::Vector2 a{3.0, 4.0};
    jcml::Vector2 b{1.0, 2.0};

    EXPECT_NEAR(jcml::dist(a, b), std::sqrt(8.0), 1e-9);
}