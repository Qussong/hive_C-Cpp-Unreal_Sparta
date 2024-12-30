
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

enum EAnimal
{
    ECat = 1,
    EDog = 2,
    EPig = 3
};

class Animal
{
public:
    virtual void makeSound() = 0;

    virtual ~Animal() { std::cout << "Delete Animal Class\n"; }
};

class Cat : public Animal
{
public:
    virtual void makeSound() override
    {
        std::cout << "¾Ö¿Ë~_Cat" << std::endl;
    }

    ~Cat() { std::cout << "Delete Cat Class\n"; }
};

class Dog : public Animal
{
public:
    virtual void makeSound() override
    {
        std::cout << "¿Ð¿Ð~_Dog" << std::endl;
    }

    ~Dog() { std::cout << "Delete Dog Class\n"; }
};

class Pig : public Animal
{
public:
    virtual void makeSound() override
    {
        std::cout << "²Ü²Ü~_Pig" << std::endl;
    }

    ~Pig() { std::cout << "Delete Pig Class\n"; }
};

class Zoo {
private:
    Animal* animals[10]; // µ¿¹° °´Ã¼¸¦ ÀúÀåÇÏ´Â Æ÷ÀÎÅÍ ¹è¿­
    int Cnt = 0;
public:
    void addAnimal(Animal* animal)
    {
        if (Cnt < 10)
        {
            animals[Cnt] = animal;
            ++Cnt;
        }
    }

    void performActions()
    {
        for (int i = 0; i < Cnt; i++)
        {
            animals[i]->makeSound();
        }
    }

    Animal* createRandomAnimal()
    {
        Animal* NewAnimal = nullptr;

        srand(time(NULL));
        int RandomAnimalNum = std::rand() % 3 + 1;

        switch (RandomAnimalNum)
        {
        case EAnimal::ECat:
            NewAnimal = new Cat();
            break;
        case EAnimal::EDog:
            NewAnimal = new Dog();
            break;
        case EAnimal::EPig:
            NewAnimal = new Pig();
            break;
        default:
            break;
        }

        return NewAnimal;
    }

    ~Zoo()
    {
        for (int i = 0; i < Cnt; i++)
        {
            delete animals[i];
        }
    }
};

int main()
{
    Zoo zoo;
    zoo.addAnimal(new Cat);
    zoo.addAnimal(new Dog);
    zoo.addAnimal(new Pig);
    zoo.performActions();

    Animal* newAnimal = zoo.createRandomAnimal();
    newAnimal->makeSound();
    delete newAnimal;

	return 0;
}