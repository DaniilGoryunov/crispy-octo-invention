#include "three.hpp"
#include <algorithm>

#define unc unsigned char

// Check char for three-base number system
bool isThree(char s) {
    return (0 <= s - '0') && (s - '0' < 3);
}

Three::Three() : _size{0}, _array{nullptr} {}

Three::Three(const std::initializer_list<unc> & t) {
    std::initializer_list<unc>::iterator it = t.begin();
    while (*it == '0') {
        ++it;
    }
    if (it == t.end()) {
        --it;
    }
    _array = new unc[t.end() - it];
    _size = t.end() - it;
    for (size_t i = 0; i < _size; ++i) {
        size_t j = t.size() - (i + 1);
        if (!isThree(*(t.begin() + j))) throw std::logic_error("Number must be in three-base system");
        _array[i] = *(t.begin() + j);
    }
}

Three::Three(const std::string & t) {
    size_t start_idx = 0;
    while (t[start_idx] == '0') {
        ++start_idx;
    }
    if (start_idx == t.size()) {
        --start_idx;
    }
    _array = new unc[t.size() - start_idx];
    _size = t.size() - start_idx;
    for (size_t i = 0; i < _size; ++i) {
        size_t j = t.size() - 1 - i;
        if (!isThree(t[j])) throw std::logic_error("Number must be in three-base system");
        _array[i] = t[j];
    }
}

Three::Three(const Three & other) {
    _array = new unc[other._size];
    _size = other._size;

    for (size_t i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

Three::Three(Three&& other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Three::~Three() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

size_t Three::size() const noexcept {
    return _size;
}

unc* Three::array() const noexcept {
    return _array;
}

std::ostream& operator<<(std::ostream & os, const Three & t) {
    size_t i = t.size();
    while(i--) {
        os << t.array()[i];
    }
    return os;
}

bool Three::operator==(const Three & t) const {
    if (_size != t._size) {
        return false;
    }
    for (size_t i = 0; i < _size; i++) {
        if (_array[i] != t._array[i]) {
            return false;
        }
    }
    return true;
}

bool Three::operator!=(const Three & t) const {
    return !(*this == t);
}

bool Three::operator>(const Three & t) const {
    if (_size != t._size) {
        return _size > t._size;
    }
    size_t i = _size;
    while(i--) {
        if (_array[i] != t._array[i]) {
            return _array[i] > t._array[i];
        }
    }
    return false;
}

bool Three::operator>=(const Three & t) const {
    return (*this > t) || (*this == t);
}

bool Three::operator<(const Three & t) const {
    return !(*this >= t);
}

bool Three::operator<=(const Three & t) const {
    return !(*this > t);
}

Three Three::operator+(const Three & t) const {
    size_t length = std::max(_size, t._size) + 1;
    std::string res(length, '0');

    for (size_t i = 0; i < length - 1; i++) {
        int sum = ((i < _size) ? _array[i] - '0' : 0) + ((i < t._size) ? t._array[i] - '0' : 0);
        res[i + 1] += (res[i] - '0' + sum) / _base;
        res[i] = (res[i] - '0' + sum) % _base + '0';
    }

    std::reverse(res.begin(), res.end());

    return Three(res);
}

Three& Three::operator+=(const Three & t) {
    *this = *this + t;
    return *this;
}

Three Three::operator-(const Three & t) const {
    if (*this < t) {
        throw std::logic_error("Result can't be negative!");
    }

    if (*this == t) {
        return Three("0");
    }

    size_t length = std::max(_size, t._size);
    std::string res(length, '0');

    for (size_t i = 0; i < length - 1; i++) {
        res[i] += _array[i] - '0' - ((i < t._size) ? t._array[i] - '0' : 0);
        if (res[i] - '0' < 0) {
            res[i] += _base;
            res[i + 1] -= 1;
        }
    }
    res[length - 1] += _array[length - 1] - '0' - ((length == t._size) ? t._array[length - 1] - '0' : 0);

    std::reverse(res.begin(), res.end());

    return Three(res);
}

Three& Three::operator-=(const Three & t) {
    *this = *this - t;
    return *this;
}

Three& Three::operator=(const Three & t) {
    if (_size > 0) {
        delete[] _array;
    }
    _size = t._size;
    _array = new unc[_size];

    for (size_t i = 0; i < _size; ++i) {
        _array[i] = t._array[i];
    }

    return *this;
}