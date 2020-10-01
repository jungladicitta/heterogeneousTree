#pragma once

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Serialize(T, std::ostream&);

void Serialize(const std::string&, std::ostream&);

template <typename T>
void Deserialize(std::istream&, T&);

void Deserialize(std::istream&, std::string&);



template <typename T>
void Serialize(T data, std::ostream& out) {
	out.write(
		reinterpret_cast<const char*>(&data),
		sizeof(data)
	);
}

template <typename T>
void Deserialize(std::istream& in, T& data) {
	in.read(
		reinterpret_cast<char*>(&data),
		sizeof(data)
	);
}

inline void Serialize(const std::string& s, std::ostream& out) {
    size_t size_ = s.size();
    out.write(
            reinterpret_cast<const char*>(&size_),
            sizeof(size_)
    );
    for (const auto& c : s) {
        Serialize(c, out);
    }
}

inline void Deserialize(std::istream& in, std::string& s) {
    size_t size_;
    in.read(
            reinterpret_cast<char*>(&size_),
            sizeof(size_)
            );
    s = std::string(size_, ' ');
    for (auto& c : s) {
        Deserialize(in, c);
    }
}
