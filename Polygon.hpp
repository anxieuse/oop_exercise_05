#ifndef Polygon_HPP
#define Polygon_HPP

#define pi 3.1415926535897

std::vector<std::string> nameByType =
    {"", "Point", "Line", "Triangle", "Square", "Pentagon", "Hexagon", "Heptagon", "Octagon", "Nonagon"};

template <class T>
struct Polygon
{
    int n;
    Point<T> center;
    T side;

    T radius;
    std::vector<Point<T>> points;
    T area;

    Polygon() = default;

    Polygon(int _n, Point<T> _center, T _side) : n(_n), center(_center), side(_side)
    {
        radius = side / (2 * sin((180 / n) * pi / 180));
        points.resize(n);
        for (int i = 0; i < n; ++i)
        {
            points[i].x = radius * cos(2 * pi * i / n) + center.x;
            points[i].y = radius * sin(2 * pi * i / n) + center.y;
        }
        area = 0.5 * radius * radius * n * sin((360 / n) * pi / 180);
    }
};

template <class U>
std::istream &operator>>(std::istream &in, Polygon<U> &pg)
{
    std::cout << "Enter <number_of_vertices>, <center.x, center.y>, <side>\n";
    in >> pg.n >> pg.center >> pg.side;
    pg = Polygon<U>(pg.n, pg.center, pg.side);
    return in;
}

template <class U>
std::ostream &operator<<(std::ostream &out, const Polygon<U> &pg)
{
    for (int i = 0; i < 28; ++i) out << "-";
    out << '\n';

    out << "Type: " << nameByType[pg.n] << '\n';
    out << "Side: " << pg.side << '\n';
    out << "Area: " << pg.area << '\n';
    out << "Points: ";
    for (int i = 0; i < pg.n; ++i)
    {
        out << pg.points[i] << " ";
    }
    out << '\n';
    return out;
}

#endif
