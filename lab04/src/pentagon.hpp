#pragma once
#include "figure.hpp"
#include <vector>

const double EPS = 1e-7;

template <class T>
class Pentagon;

template <class T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T> & h);

template <class T>
std::istream& operator>>(std::istream& is, Pentagon<T> & h);

template <class T>
class Pentagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Pentagon<T> & h);
    friend std::istream& operator>>(std::istream& is, Pentagon<T> & h);
public:
    Pentagon();
    Pentagon(const std::vector<Coord> & t);
    Pentagon(const std::initializer_list<Coord> & t);
    Pentagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth);
    Pentagon(const Pentagon<T> & h);
    Pentagon(Pentagon<T>&& h) noexcept;
    ~Pentagon();
    virtual Coord<T> get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Pentagon<T> & rhs) const noexcept;
    bool operator!=(const Pentagon<T> & rhs) const noexcept;
    bool operator>(const Pentagon<T> & rhs) const noexcept;
    bool operator<(const Pentagon<T> & rhs) const noexcept;
    bool operator>=(const Pentagon<T> & rhs) const noexcept;
    bool operator<=(const Pentagon<T> & rhs) const noexcept;
    Pentagon& operator=(const Pentagon<T> & rhs);
    Pentagon& operator=(Pentagon<T>&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 5;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};

static bool is_eq(double x, double y) noexcept {
    return std::fabs(x - y) < EPS;
}


double s_Geron(Coord x1, Coord x2, Coord x3){
    return 0.5 * (x1.first * (x2.second - x3.second) + x2.first * (x3.second - x1.second) + x3.first * (x1.second - x2.second));
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T> & h) {
    for (Coord elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Pentagon<T> & h) {
    std::vector<Coord> v(h._num_of_vertices);
    for (Coord & elem : v) {
        is >> elem;
    }
    return is;
}

template <class T>
Pentagon<T>::Pentagon() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Pentagon<T>::Pentagon(const std::vector<Coord> & t) : _vertices(t) {}

template <class T>
Pentagon<T>::Pentagon(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Pentagon<T>::Pentagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
}

template <class T>
Pentagon<T>::Pentagon(const Pentagon<T> & h) {
    _vertices = h._vertices;
}

template <class T>
Pentagon<T>::Pentagon(Pentagon<T>&& h) noexcept {
    _vertices = std::move(h._vertices);
}

template <class T>
Pentagon<T>::~Pentagon() {}

template <class T>
Coord<T> Pentagon<T>::get_center() const noexcept {
    double a = sqrt((_vertices[0].first - _vertices[3].first) * (_vertices[0].first - _vertices[3].first) + (_vertices[0].second - _vertices[3].second) *  (_vertices[0].second - _vertices[3].second));
    double R = a / (2 * sin(M_PI / 5));
    return Coord{_vertices[0].first, (_vertices[0].second - R)};
}

template <class T>
Pentagon<T>::operator double() const noexcept {
    return 5 * s_Geron(_vertices[1], _vertices[0], _vertices[2]);
}

template <class T>
bool Pentagon<T>::operator==(const Pentagon<T> & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

template <class T>
bool Pentagon<T>::operator!=(const Pentagon<T> & rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Pentagon<T>::operator>(const Pentagon<T> & rhs) const noexcept {
    return (double) *this > (double) rhs;
}

template <class T>
bool Pentagon<T>::operator>=(const Pentagon<T> & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Pentagon<T>::operator<=(const Pentagon<T> & rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
bool Pentagon<T>::operator<(const Pentagon<T> & rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T> & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}