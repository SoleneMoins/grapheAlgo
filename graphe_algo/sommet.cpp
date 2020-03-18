#include "sommet.h"
#include <cmath>

sommet::sommet() : sommet {0.0,0.0}
{}

sommet::sommet(double x, double y) : d_x{x}, d_y{y}
{}

double sommet::x() const
{
  return d_x;
}

double sommet::y() const
{
  return d_y;
}

double sommet::distance(const sommet& p) const
{
  double dx = p.d_x-d_x, dy = p.d_y-d_y;
  return sqrt(dx*dx + dy*dy);
}


void sommet::moveTo(double x, double y)
{
  d_x = x; d_y = y;
}

void sommet::move(double dx, double dy)
{
  d_x += dx; d_y += dy;
}

sommet& sommet::operator*=(double val)
{
  d_x *= val; d_y *= val;
  return *this;
}

sommet operator*(double val, const sommet& p)
{
  sommet res{p};
  res *= val;
  return res;
}

sommet& sommet::operator/=(double val)
{
  d_x /= val; d_y /= val;
  return *this;
}

sommet sommet::operator/(double val) const
{
  sommet res{*this};
  res /= val;
  return res;
}

sommet& sommet::operator+=(const sommet& p)
{
  d_x += p.d_x; d_y += p.d_y;
  return *this;
}

sommet sommet::operator+(const sommet& p) const
{
  sommet res{*this};
  res += p;
  return res;
}

bool sommet::operator==(const sommet& p) const
{
  return (d_x == p.d_x) && (d_y == p.d_y);
}

bool sommet::operator!=(const sommet& p) const
{
  return (d_x != p.d_x) || (d_y != p.d_y);
}

