// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "art/math.hpp"

#define EPSILON 0.000000000000001

using art::pi;

TEST(art_degtorad_tests, degtorad_unit_circle)
{
  EXPECT_DOUBLE_EQ(2 * -pi, art::degtorad(-360));
  EXPECT_DOUBLE_EQ(1.5 * -pi, art::degtorad(-270));
  EXPECT_DOUBLE_EQ(-pi, art::degtorad(-180));
  EXPECT_DOUBLE_EQ(0.5 * -pi, art::degtorad(-90));
  EXPECT_DOUBLE_EQ(0, art::degtorad(0));
  EXPECT_DOUBLE_EQ(0.5 * pi, art::degtorad(90));
  EXPECT_DOUBLE_EQ(pi, art::degtorad(180));
  EXPECT_DOUBLE_EQ(1.5 * pi, art::degtorad(270));
  EXPECT_DOUBLE_EQ(2 * pi, art::degtorad(360));
}

TEST(art_radtodeg_tests, radtodeg_unit_circle)
{
  EXPECT_DOUBLE_EQ(-360, art::radtodeg(2 * -pi));
  EXPECT_DOUBLE_EQ(-270, art::radtodeg(1.5 * -pi));
  EXPECT_DOUBLE_EQ(-180, art::radtodeg(-pi));
  EXPECT_DOUBLE_EQ(-90, art::radtodeg(0.5 * -pi));
  EXPECT_DOUBLE_EQ(0, art::radtodeg(0));
  EXPECT_DOUBLE_EQ(90, art::radtodeg(0.5 * pi));
  EXPECT_DOUBLE_EQ(180, art::radtodeg(pi));
  EXPECT_DOUBLE_EQ(270, art::radtodeg(1.5 * pi));
  EXPECT_DOUBLE_EQ(360, art::radtodeg(2 * pi));
}

TEST(lengthdir_x_tests, lengthdir_x_direction)
{
  ASSERT_NEAR(0, art::lengthdir_x(1, -270), EPSILON);
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, -225));
  EXPECT_DOUBLE_EQ(-1, art::lengthdir_x(1, -180));
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, -135));
  ASSERT_NEAR(0, art::lengthdir_x(1, -90), EPSILON);
  EXPECT_DOUBLE_EQ(std::sqrt(2) / 2, art::lengthdir_x(1, -45));
  EXPECT_DOUBLE_EQ(1, art::lengthdir_x(1, 0));
  EXPECT_DOUBLE_EQ(std::sqrt(2) / 2, art::lengthdir_x(1, 45));
  ASSERT_NEAR(0, art::lengthdir_x(1, 90), EPSILON);
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, 135));
  EXPECT_DOUBLE_EQ(-1, art::lengthdir_x(1, 180));
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, 225));
  ASSERT_NEAR(0, art::lengthdir_x(1, 270), EPSILON);
}

TEST(art_floor_tests, floor_whole)
{
  EXPECT_DOUBLE_EQ(0, art::floor(0));
  EXPECT_DOUBLE_EQ(10, art::floor(10));
  EXPECT_DOUBLE_EQ(100, art::floor(100));
}

TEST(art_floor_tests, floor_decimal)
{
  EXPECT_DOUBLE_EQ(3, art::floor(3.3));
  EXPECT_DOUBLE_EQ(4, art::floor(4.5));
  EXPECT_DOUBLE_EQ(5, art::floor(5.7));
}

TEST(art_floor_tests, floor_negative)
{
  EXPECT_DOUBLE_EQ(0, art::floor(-0));
  EXPECT_DOUBLE_EQ(-1, art::floor(-1));
  EXPECT_DOUBLE_EQ(-2, art::floor(-1.3));
  EXPECT_DOUBLE_EQ(-3, art::floor(-2.5));
  EXPECT_DOUBLE_EQ(-4, art::floor(-3.7));
}
