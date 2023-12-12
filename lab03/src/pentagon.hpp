#pragma once
#include "figure.hpp"
#include <vector>

class Pentagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Pentagon & h);
    friend std::istream& operator>>(std::istream& is, Pentagon & h);
public:
    Pentagon();
    Pentagon(const std::vector<Coord> & t);
    Pentagon(const std::initializer_list<Coord> & t);
    Pentagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth);
    Pentagon(const Pentagon & h);
    Pentagon(Pentagon&& h) noexcept;
    ~Pentagon();
    virtual Coord get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Pentagon & rhs) const noexcept;
    bool operator!=(const Pentagon & rhs) const noexcept;
    bool operator>(const Pentagon & rhs) const noexcept;
    bool operator<(const Pentagon & rhs) const noexcept;
    bool operator>=(const Pentagon & rhs) const noexcept;
    bool operator<=(const Pentagon & rhs) const noexcept;
    Pentagon& operator=(const Pentagon & rhs);
    Pentagon& operator=(Pentagon&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 5;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};