#include <iostream>

class Animal
{
public:
    // Virtual function enables runtime polymorphism
    virtual void makeSound()
    {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal
{
public:
    // Overriding the base class version of makeSound()
    void makeSound() override
    {
        std::cout << "The dog barks." << std::endl;
    }

    // Function specific to Dog only
    void dog_specific()
    {
        std::cout << "Dog specific function." << std::endl;
    }
};

// Function that receives a pointer to base class
void fun(Animal *animal)
{
    // Calls the correct version depending on actual object (polymorphism)
    animal->makeSound();

    // animal->dog_specific();  // ERROR: base class does not have this function

    // dynamic_cast safely checks if 'animal' actually points to a Dog object
    Dog *dog = dynamic_cast<Dog *>(animal);

    // If the cast succeeds, dog is not null
    if (dog != nullptr)
    {
        dog->dog_specific();
    }
}

int main()
{
    // Creating a Dog object but storing it in an Animal pointer (polymorphism)
    Animal *animal1 = new Dog();

    // Passing to function that uses dynamic_cast
    fun(animal1);

    delete animal1; // Free allocated memory
    return 0;
}

// The dog barks.
// Dog specific function.