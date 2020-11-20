#ifndef POINT_HPP
#define POINT_HPP

#define eps 1e-3

template<class T>
struct Point
{
    T x, y;
};

template<class T>
std::istream &operator>>(std::istream &in, Point<T> &pt)
{
    in >> pt.x >> pt.y;
    return in;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Point<T> &pt)
{
    out << "(" << std::fixed << pt.x << ", " << pt.y << ")";
    return out;
}

template<class T>
T DistanceSquared(Point<T> p, Point<T> q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

template<class T>
T Cross(Point<T> p, Point<T> q)
{
    return p.x * q.y - q.x * p.y;
}

#endif