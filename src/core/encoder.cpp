#include "encoder.hpp"
#include <algorithm>
#include <stdexcept>
using namespace std;

string Base62Encoder::encode(long long id) {
    if (id == 0) return "0";
    string result;
    result.reserve(7);
    while (id > 0) {
        result+=ALPHABET[id%62];
        id/=62;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long Base62Encoder::decode(string_view short_link) {
    long long id=0;
    
    for (char c:short_link) {
        size_t pos=ALPHABET.find(c);
        if (pos==string_view::npos) {
            throw invalid_argument("Invalid");
        }
        id=id*62+pos;
    }
    return id;
}
