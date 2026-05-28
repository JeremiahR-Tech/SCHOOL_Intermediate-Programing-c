#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class User {
    string name_;
    string email_;

    public:
        User(string name, string email) : name_{name}, email_{email} {}

        friend ostream& operator<<(ostream& os, const User& u) {
            return os << u.name_ << ", " << u.email_;
        }

        bool operator<(const User& u1) {
            return ((name_.size() + email_.size()) < (u1.name_.size() + u1.email_.size()));
        }
};

int main() {
    vector<User> vals {
        { "Naomi Nagata", "naomi@roci.sp" },
        { "James Holden", "james@roci.sp" },
        { "Amos Burton", "amos@roci.sp" },
        { "Alex Kamal", "alex@roci.sp" },
    };

    for (auto v : vals) {
        cout << v << endl;
    }

    cout << "Sorting...\n" << endl;

    // Sort them
    sort(vals.begin(), vals.end());

    for (auto v : vals) {
        cout << v << endl;
    }
}
