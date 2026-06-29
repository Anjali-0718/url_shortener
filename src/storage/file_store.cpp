#include "file_store.hpp"
#include <sstream>
using namespace std;

FileStore::FileStore(const string& db_path):filepath(db_path),next_id(100000){
    load_database();
    append_stream.open(filepath, ios::app);
}
FileStore::~FileStore() {
    if (append_stream.is_open()) append_stream.close();
}
void FileStore::load_database() {
    ifstream read_stream(filepath);
    if (!read_stream.is_open()) return;
    string line;
    while (getline(read_stream, line)) {
        stringstream ss(line);
        long long id;
        string url;
        if (ss>>id>>url) {
            id_to_url[id]=url;
            url_to_id[url]=id;
            if (id>=next_id)
                next_id=id+1;
    }
    }
}
long long FileStore::save_url(const string& original_url){
    auto it = url_to_id.find(original_url);
    if (it != url_to_id.end())
        return it->second;
        
    long long new_id=next_id++;
    id_to_url[new_id]=original_url;
    url_to_id[original_url]=new_id;

    if (append_stream.is_open()) {
        append_stream << new_id << " " << original_url << "\n";
        append_stream.flush();
    }
    return new_id;
}
string FileStore::get_url(long long id) {
    auto it = id_to_url.find(id);
    if (it != id_to_url.end()) {
        return it->second;
    }
    return "";
}
