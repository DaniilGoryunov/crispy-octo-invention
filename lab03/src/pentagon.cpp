#include "pentagon.hpp"
#include <cmath>

const double EPS = 1e-7;

static bool is_eq(double x, double y) noexcept {
    return std::fabs(x - y) < EPS;
}

double s_Geron(Coord x1, Coord x2, Coord x3){
    return 0.5 * ((x1.first - x3.first) * (x2.second - x3.second) - (x2.first - x3.first) * (x1.second - x3.second));
}

std::ostream& operator<<(std::ostream& os, const Pentagon & h) {
    for (Coord elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon & h) {
    std::vector<Coord> v(h._num_of_vertices);
    for (Coord & elem : v) {
        is >> elem;
    }
    return is;
}

Pentagon::Pentagon() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

Pentagon::Pentagon(const std::vector<Coord> & t) : _vertices(t) {}

Pentagon::Pentagon(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

Pentagon::Pentagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
}

Pentagon::Pentagon(const Pentagon & h) {
    _vertices = h._vertices;
}

Pentagon::Pentagon(Pentagon&& h) noexcept {
    _vertices = std::move(h._vertices);
}

Pentagon::~Pentagon() {}

Coord Pentagon::get_center() const noexcept {
    double a = sqrt((_vertices[0].first - _vertices[3].first) * (_vertices[0].first - _vertices[3].first) + (_vertices[0].second - _vertices[3].second) *  (_vertices[0].second - _vertices[3].second));
    double R = a / (2 * sin(M_PI / 5));
    return Coord{_vertices[0].first, (_vertices[0].second - R)};
}

Pentagon::operator double() const noexcept {
    return 5 * s_Geron(_vertices[1], _vertices[0], _vertices[2]);
}

bool Pentagon::operator==(const Pentagon & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

bool Pentagon::operator!=(const Pentagon & rhs) const noexcept {
    return !(*this == rhs);
}

bool Pentagon::operator>(const Pentagon & rhs) const noexcept {
    return (double) *this > (double) rhs;
}

bool Pentagon::operator>=(const Pentagon & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Pentagon::operator<=(const Pentagon & rhs) const noexcept {
    return !(*this > rhs);
}

bool Pentagon::operator<(const Pentagon & rhs) const noexcept {
    return !(*this >= rhs);
}

Pentagon& Pentagon::operator=(const Pentagon & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
