#pragma once

#include <string>
#include <iostream>

class Three {
public:
    Three();
    Three(const std::initializer_list<unsigned char> & t);
    Three(const std::string & t);
    Three(const Three & other);
    Three(Three&& other) noexcept;
    bool operator==(const Three & t) const;
    bool operator!=(const Three & t) const;
    bool operator!=(const std::string & t) const;
    bool operator>(const Three & t) const;
    bool operator>=(const Three & t) const;
    bool operator<(const Three & t) const;
    bool operator<=(const Three & t) const;
    Three operator+(const Three & t) const;
    Three& operator+=(const Three & t);
    Three operator-(const Three & t) const;
    Three& operator-=(const Three & t);
    Three& operator=(const Three & t);
    size_t size() const noexcept;
    unsigned char* array() const noexcept;
    virtual ~Three() noexcept;
private:
    size_t _size;
    unsigned char* _array; // in reversed order
    static const int _base = 3;
};

std::ostream& operator<<(std::ostream & os, const Three & t);