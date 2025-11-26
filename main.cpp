#include <iostream>

// ==================== Base Class ====================
class Base
{
public:
    int pub = 1; // Public member
protected:
    int prot = 2; // Protected member
private:
    int priv = 3; // Private member

public:
    Base() { std::cout << "Base Constructor\n"; }
    ~Base() { std::cout << "Base Destructor\n"; }
};

// ==================== Public Inheritance ====================
class DerivedPublic : public Base
{
public:
    DerivedPublic()
    {
        std::cout << "DerivedPublic Constructor\n";

        // Accessible inside the class
        std::cout << "Public: " << pub << "\n";
        std::cout << "Protected: " << prot << "\n";
        // priv -> NOT accessible
    }

    ~DerivedPublic()
    {
        std::cout << "DerivedPublic Destructor\n";
    }
};

// ==================== Protected Inheritance ====================
class DerivedProtected : protected Base
{
public:
    DerivedProtected()
    {
        std::cout << "DerivedProtected Constructor\n";

        // Base public becomes PROTECTED in this class
        std::cout << "Public becomes Protected: " << pub << "\n";
        std::cout << "Protected: " << prot << "\n";
        // priv -> NOT accessible
    }

    ~DerivedProtected()
    {
        std::cout << "DerivedProtected Destructor\n";
    }
};

// ==================== Private Inheritance ====================
class DerivedPrivate : private Base
{
public:
    DerivedPrivate()
    {
        std::cout << "DerivedPrivate Constructor\n";

        // Base public becomes PRIVATE in this class
        std::cout << "Public becomes Private: " << pub << "\n";
        // Base protected becomes PRIVATE in this class
        std::cout << "Protected becomes Private: " << prot << "\n";
        // priv -> NOT accessible
    }

    ~DerivedPrivate()
    {
        std::cout << "DerivedPrivate Destructor\n";
    }
};

// ==================================================================
// ======================= FRIEND EXAMPLE ============================
// ==================================================================

// ------------ Version WITH friend ------------
class FriendE;

class SecretBox
{
private:
    int secretValue = 999; // Private member

public:
    // Declare FriendE as a friend
    friend class FriendE;
};

class FriendE
{
public:
    void ShowSecret(SecretBox &box)
    {
        // Can access private because it is a friend
        std::cout << "Friend can access private: " << box.secretValue << "\n";
    }
};

// ------------ Version WITHOUT friend ------------
class SecretBox_NoFriend
{
private:
    int secretValue = 999; // Private member

public:
    // No friend declared here
};

class NoFriendE
{
public:
    void TryAccess(SecretBox_NoFriend &box)
    {
        // ERROR if uncommented: cannot access private
        // std::cout << box.secretValue;

        std::cout << "NoFriend cannot access private members.\n";
    }
};

// ==================== Main ====================
int main()
{
    std::cout << "=== Public Inheritance ===\n";
    DerivedPublic dp;

    // Public inheritance -> Base public stays public
    std::cout << "Main access to dp.pub = " << dp.pub << "\n"; // OK

    // std::cout << dp.prot;   // ERROR: protected
    // std::cout << dp.priv;   // ERROR: private

    std::cout << "\n=== Protected Inheritance ===\n";
    DerivedProtected dprot;

    // Public from Base becomes protected -> NOT accessible here
    // std::cout << dprot.pub;   // ERROR
    std::cout << "Main cannot access dprot.pub (protected).\n";

    std::cout << "\n=== Private Inheritance ===\n";
    DerivedPrivate dpriv;

    // Public from Base becomes private -> NOT accessible here
    // std::cout << dpriv.pub;    // ERROR
    std::cout << "Main cannot access dpriv.pub (private).\n";

    std::cout << "\n=== Friend  ===\n";
    SecretBox box;
    FriendE fe;
    fe.ShowSecret(box); // Can access private

    std::cout << "\n=== No-Friend  ===\n";
    SecretBox_NoFriend box2;
    NoFriendE nfe;
    nfe.TryAccess(box2); // Cannot access private

    return 0;
}

// === Public Inheritance ===
// Base Constructor
// DerivedPublic Constructor
// Public: 1
// Protected: 2
// Main access to dp.pub = 1

// === Protected Inheritance ===
// Base Constructor
// DerivedProtected Constructor
// Public becomes Protected: 1
// Protected: 2
// Main cannot access dprot.pub (protected).

// === Private Inheritance ===
// Base Constructor
// DerivedPrivate Constructor
// Public becomes Private: 1
// Protected becomes Private: 2
// Main cannot access dpriv.pub (private).

// === Friend  ===
// Friend can access private: 999

// === No-Friend  ===
// NoFriend cannot access private members.
// DerivedPrivate Destructor
// Base Destructor
// DerivedProtected Destructor
// Base Destructor
// DerivedPublic Destructor
// Base Destructor