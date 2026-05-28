#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

        auto & email() const { return email_; }
};

struct UserHash {
    size_t operator()(const User& u) const {
        return hash<string>()(u.email());
    }
};

struct UserEqual {
    bool operator()(const User& u1, const User& u2) const {
        return u1.email() == u2.email();
    }
};

int main() {
    unordered_map<User, double, UserHash, UserEqual> vals = {
        { {"Naomi Nagata", "naomi@roci.sp"}, 1234234 },
        { {"James Holden", "james@roci.sp" }, 22343},
        { {"Amos Burton", "amos@roci.sp" }, 23452345},
        { {"Alex Kamal", "alex@roci.sp" }, 452345},
    };

    User u{"Naomi Nagata", "naomi@roci.sp"};

    auto result = vals[u];

    cout << result << endl;
}
