#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Follower (Observer)
class Follower {
public:
    virtual ~Follower() = default;  // Virtual destructor
    virtual void update(const std::string& publisherName, const std::string& content) = 0;
};
// Publisher (Subject)
class Publisher {
public:
    Publisher(const std::string& name) : name(name) {}

    void addFollower(Follower* follower) {
        followers.push_back(follower);
    }

    void removeFollower(Follower* follower) {
        auto it = std::find(followers.begin(), followers.end(), follower);
        if (it != followers.end()) {
            followers.erase(it);
        }
    }

    void notifyFollowers() {
        for (Follower* follower : followers) {
            follower->update(name, latestContent);
        }
    }

    void postContent(const std::string& content) {
        latestContent = content;
        notifyFollowers();
    }

private:
    std::string name;
    std::string latestContent;
    std::vector<Follower*> followers;
};


// Concrete Follower: User
class User : public Follower {
public:
    User(const std::string& username) : username(username) {}

    void update(const std::string& publisherName, const std::string& content) override {
        std::cout << "User " << username << " received an update from " << publisherName << ": " << content << std::endl;
    }

private:
    std::string username;
};

// Client code
int main() {
    Publisher techPublisher("TechChannel");
    User user1("Alice");
    User user2("Bob");

    techPublisher.addFollower(&user1);
    techPublisher.addFollower(&user2);

    techPublisher.postContent("New video on design patterns!");

    techPublisher.removeFollower(&user2);
    techPublisher.postContent("Live stream announcement!");

    return 0;
}
