#include "romb.hpp"
#include <cmath>

const double EPS = 1e-7;

static bool is_eq(double x, double y) noexcept {
    return std::fabs(x - y) < EPS;
}

std::ostream& operator<<(std::ostream& os, const Romb & h) {
    for (Coord elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Romb & h) {
    std::vector<Coord> v(h._num_of_vertices);
    for (Coord & elem : v) {
        is >> elem;
    }
    return is;
}

Romb::Romb() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

Romb::Romb(const std::vector<Coord> & t) : _vertices(t) {}

Romb::Romb(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

Romb::Romb(Coord first, Coord second, Coord third, Coord fourth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
}

Romb::Romb(const Romb & h) {
    _vertices = h._vertices;
}

Romb::Romb(Romb&& h) noexcept {
    _vertices = std::move(h._vertices);
}

Romb::~Romb() {}

Coord Romb::get_center() const noexcept {
    Coord c;
    c.first = (_vertices[0].first + _vertices[3].first + _vertices[2].first + _vertices[1].first) / 4;
    c.second = (_vertices[0].second + _vertices[3].second + _vertices[2].second + _vertices[1].second) / 4;
    return c;
}

Romb::operator double() const noexcept {
    double d1 = _vertices[0].second - _vertices[2].second;
    double d2 = _vertices[1].first - _vertices[3].first;
    return 0.5 * d1 * d2;
}

bool Romb::operator==(const Romb & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

bool Romb::operator!=(const Romb & rhs) const noexcept {
    return !(*this == rhs);
}

bool Romb::operator>(const Romb & rhs) const noexcept {
    return (double) *this > (double) rhs; 
}

bool Romb::operator>=(const Romb & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Romb::operator<=(const Romb & rhs) const noexcept {
    return !(*this > rhs);
}

bool Romb::operator<(const Romb & rhs) const noexcept {
    return !(*this >= rhs);
}

Romb& Romb::operator=(const Romb & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

Romb& Romb::operator=(Romb&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
