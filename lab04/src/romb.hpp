#pragma once

#include "figure.hpp"
#include <vector>

template <class T>
class Romb;

template <class T>
std::ostream& operator<<(std::ostream& os, const Romb<T> & h);

template <class T>
std::istream& operator>>(std::istream& is, Romb<T> & h);

template <class T>
class Romb : public Figure<T> {
    friend std::ostream& operator<<(std::ostream& os, const Romb & t);
    friend std::istream& operator>>(std::istream& is, Romb & t);
public:
    Romb();
    Romb(const Romb & t);
    Romb(Romb&& t) noexcept;
    Romb(const std::initializer_list<Coord<T>> & t);
    Romb(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth);
    Romb(const std::vector<Coord<T>> & t);
    ~Romb();
    virtual Coord<T> get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Romb<T> & rhs) const noexcept;
    bool operator!=(const Romb<T> & rhs) const noexcept;
    bool operator>(const Romb<T> & rhs) const noexcept;
    bool operator<(const Romb<T> & rhs) const noexcept;
    bool operator>=(const Romb<T> & rhs) const noexcept;
    bool operator<=(const Romb<T> & rhs) const noexcept;
    Romb& operator=(const Romb<T> & rhs);
    Romb& operator=(Romb<T>&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 4;
    std::vector<Coord<T>> _vertices = std::vector<Coord<T>>(_num_of_vertices);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Romb<T> & h) {
    for (Coord elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Romb<T> & h) {
    std::vector<Coord<T>> v(h._num_of_vertices);
    for (Coord<T> & elem : v) {
        is >> elem;
    }
    return is;
}

template <class T>
Romb<T>::Romb() {
    for (Coord<T> & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Romb<T>::Romb(const std::vector<Coord<T>> & t) : _vertices(t) {}

template <class T>
Romb<T>::Romb(const std::initializer_list<Coord<T>> & t) {
    size_t i = 0;
    for (Coord<T> elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Romb<T>::Romb(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
}

template <class T>
Romb<T>::Romb(const Romb<T> & h) {
    _vertices = h._vertices;
}

template <class T>
Romb<T>::Romb(Romb<T>&& h) noexcept {
    _vertices = std::move(h._vertices);
}

template <class T>
Romb<T>::~Romb() {}

template <class T>
Coord<T> Romb<T>::get_center() const noexcept {
    Coord<T> c;
    c.first = (_vertices[0].first + _vertices[3].first + _vertices[2].first + _vertices[1].first) / 4;
    c.second = (_vertices[0].second + _vertices[3].second + _vertices[2].second + _vertices[1].second) / 4;
    return c;
}

template <class T>
Romb<T>::operator double() const noexcept {
    double d1 = _vertices[0].second - _vertices[2].second;
    double d2 = _vertices[1].first - _vertices[3].first;
    return 0.5 * d1 * d2;
}

template <class T>
bool Romb<T>::operator==(const Romb<T> & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

template <class T>
bool Romb<T>::operator!=(const Romb<T> & rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Romb<T>::operator>(const Romb<T> & rhs) const noexcept {
    return (double) *this > (double) rhs; 
}

template <class T>
bool Romb<T>::operator>=(const Romb<T> & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Romb<T>::operator<=(const Romb<T> & rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
bool Romb<T>::operator<(const Romb<T> & rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
Romb<T>& Romb<T>::operator=(const Romb<T> & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

template <class T>
Romb<T>& Romb<T>::operator=(Romb<T>&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}

