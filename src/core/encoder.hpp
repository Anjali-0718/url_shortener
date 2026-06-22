#ifndef ENCODER_HPP
#define ENCODER_HPP
#include <string>
#include <string_view>
using namespace std;

class Base62Encoder {
private:
    static constexpr string_view ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    static string encode(long long id);
    static long long decode(string_view short_link);
};
#endif