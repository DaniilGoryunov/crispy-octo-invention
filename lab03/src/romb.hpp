#pragma once
#include "figure.hpp"
#include <vector>

class Romb : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Romb & t);
    friend std::istream& operator>>(std::istream& is, Romb & t);
public:
    Romb();
    Romb(const Romb & t);
    Romb(Romb&& t) noexcept;
    Romb(const std::initializer_list<Coord> & t);
    Romb(Coord first, Coord second, Coord third, Coord fourth);
    Romb(const std::vector<Coord> & t);
    ~Romb();
    virtual Coord get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Romb & rhs) const noexcept;
    bool operator!=(const Romb & rhs) const noexcept;
    bool operator>(const Romb & rhs) const noexcept;
    bool operator<(const Romb & rhs) const noexcept;
    bool operator>=(const Romb & rhs) const noexcept;
    bool operator<=(const Romb & rhs) const noexcept;
    Romb& operator=(const Romb & rhs);
    Romb& operator=(Romb&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 4;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};
