#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Βασική κλάση Creature
class Creature {
protected:
    std::string name;
    int lifeExpectancy;
    Creature* position; // Δείκτης στη θέση του πλάσματος στην κοινότητα
public:
    Creature(std::string name, int life) : name(name), lifeExpectancy(life), position(nullptr) {
        std::cout << "Creature " << name << " born with life expectancy " << life << std::endl;
    }
    virtual ~Creature() {
        std::cout << "Creature " << name << " dies." << std::endl;
    }
    virtual bool isGood() const = 0; // Πρέπει να υλοποιηθεί από τις παράγωγες κλάσεις
    bool isZombie() const {
        return lifeExpectancy <= 0;
    }
    virtual void clone(Creature* other) = 0; // Κλωνοποίηση
    void beat() {
        if (!isZombie()) {
            --lifeExpectancy;
            std::cout << name << " is beaten. Life expectancy now " << lifeExpectancy << std::endl;
        }
    }
    void bless() {
        if (!isZombie()) {
            ++lifeExpectancy;
            std::cout << name << " is blessed. Life expectancy now " << lifeExpectancy << std::endl;
        }
    }
};

// Κλάση GoodCreature
class GoodCreature : public Creature {
public:
    GoodCreature(std::string name, int life) : Creature(name, life) {}
    virtual bool isGood() const override {
        return true;
    }
    virtual void clone(Creature* other) override {
        // Υλοποίηση κλωνοποίησης για GoodCreature
    }
};

// Κλάση BadCreature
class BadCreature : public Creature {
public:
    BadCreature(std::string name, int life) : Creature(name, life) {}
    virtual bool isGood() const override {
        return false;
    }
    virtual void clone(Creature* other) override {
        // Υλοποίηση κλωνοποίησης για BadCreature
    }
};

// Κλάση CreatureSociety
class CreatureSociety {
private:
    std::vector<Creature*> creatures; // Δείκτες στα πλάσματα
public:
    // Δημιουργία, διαγραφή και λειτουργίες της κοινότητας
};

int main(int argc, char* argv[]) {
    // Επεξεργασία ορισμάτων και δημιουργία κοινότητας
    return 0;
}
