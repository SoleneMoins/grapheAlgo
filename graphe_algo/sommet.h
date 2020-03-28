#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>
#include <fstream>


class sommet
{
    public:

    ///Default constructor: point (0,0)
      sommet();

      /**
      Constructor with cartesian coordinates
      @param x x-coordinate
      @param y y-coordinate
    */
      sommet(int x, int y,int d_numero);


      int getX()  const;

      int getY()  const;

      int getNumero()  const;

      bool estVide();




    /**
      Distance between two points
      @param p point to which the distance is computed
      @return the distance between the point and p
    */
      double distance(const sommet& p) const;


    /**
      Change the coordinates of the point
      @param x the new x-coordinate
      @param y the new y-coordinate
    */
      void moveTo(double x, double y);


    /**
      Move the point with a translation
      @param dx the deplacement along the x-axis
      @param dx the deplacement along the x-axis
    */
      void move(double dx, double dy);


    /**
      Operator *=: the coordinates of the point are multiplicated by the real
      @param val the value by which the coordinates will be multiplicated
      @return the point itself
    */
      sommet& operator*=(double val);


    /**
      Operator /=: the coordinates of the point are divided by the real
      @param val the value by which the coordinates will be divided
      @return the point itself
    */
      sommet& operator/=(double val);


    /**
      Operator /: the coordinates of the result point are the coordinates of the
                  point divided by the real
      @param val the value by which the coordinates will be divided
      @return a point whose coordinates are the coordinates of the point
              divided by the real
    */
      sommet  operator/(double val) const;


    /**
      Operator +=: add the (coordinates of the) point to the current point
      @param p the added point
      @return the point itself
    */
      sommet& operator+=(const sommet& p);
    /**
      Operator +: the coordinates of the result point are the sum of the
                  coordinates of the two points
      @param p one of the two added points
      @return a point whose coordinates are the sum of the coordinates
                of the two points
    */
      sommet  operator+(const sommet& p) const;


    /**
      Operator ==: two points are equal if their coordinates are equal
      @param p the compared point
      @return true if the x- and y-coordinates are equal
    */
      bool operator==(const sommet& p)   const;


    /**
      Operator !=: two points are different if one of their coordinates are different
      @param p the compared point
      @return true if either the x- or y-coordinates are different
    */
      bool operator!=(const sommet& p)   const;

      void save(std::ostream&ost);

      void open(std::istream&ist);



    private:

      int d_x,d_y;//Cartesian coordinates
      int d_numero;


};

std::ostream& operator<<(std::ostream&ost,sommet&s);
std::istream& operator>>(std::istream&ist,sommet&s);


#endif // SOMMET_H
