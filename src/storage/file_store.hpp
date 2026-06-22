#ifndef FILE_STORE_HPP
#define FILE_STORE_HPP

#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class FileStore {
private:
    string filepath;
    unordered_map<long long, string> id_to_url;
    unordered_map<string, long long> url_to_id;
    long long next_id;
    ofstream append_stream;

    void load_database();

public:
    FileStore(const string& db_path);
    ~FileStore();
    long long save_url(const string& original_url);
    string get_url(long long id);
};

#endif