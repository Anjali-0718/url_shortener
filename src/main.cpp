#include "core/encoder.hpp"
#include "storage/file_store.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    FileStore store("urls.db");
    unordered_map<string, string> cache;

    string websites[] = {
        "https://www.google.com",
        "https://www.github.com",
        "https://www.wikipedia.org"
    };

    for (const auto& site : websites) {
        long long assigned_id = store.save_url(site);
        string short_code = Base62Encoder::encode(assigned_id);
        cout << "Shortened: " << site << " -> http://short.est/" << short_code << "\n";
    }

    string test_codes[] = {"q0U", "q0V", "q0W", "xyz"};
    for (const auto& code : test_codes) {
        if (cache.find(code) != cache.end()) {
            cout << "Cache Hit: " << cache[code] << "\n";
            continue;
        }

        try {
            long long decoded_id = Base62Encoder::decode(code);
            string original_site = store.get_url(decoded_id);
            
            if (!original_site.empty()) {
                cache[code] = original_site;
                cout << "Database Hit: " << original_site << "\n";
            } else {
                cout << "Not Found: " << code << "\n";
            }
        } catch (const exception& e) {
            cout << "Invalid Code: " << code << "\n";
        }
    }

    return 0;
}