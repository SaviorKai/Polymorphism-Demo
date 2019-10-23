// PolymorphismDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

///IVAN NOTES:
//1. Ad-hoc polymorphism (AKA ???), has the language feature is Overloading
//2.1 Subtype polymorphism (AKA 'Polymorphism' or Runtime polymorphism), has the language features of Sub-Classes and Virtual functions (override).
//2.2 Pointers are used for subclasses, because when called, we want to point to the subclass of animal, instead of expecting 'Animal' only.
//2.3 Virtual Overrides take place withing CHILDREN of a class (or SubClasses). Virtual Overrides should be established within the declaration of a child class.

///===== IMPORTANT NOTE ABOUT POINTERS / REFERENCES ===== //
//NOTE: (Animal lalalal) = create instance. Thus, function(Animal lalalal){return;} = create temp instance and return.
//NOTE: (Animal* lalalal) = create pointer. Thus, function(Animal* lalalal){return;} = create temp pointer and return.
//NOTE: (Animal& lalalal) = create reference. Thus, function(Animal& lalalal){return;} = create temp reference and return.


/*
Recipe to Override a Virtual Method:
1. Find the signature in the API reference. (Look up the chain of inherited items, and find the original "BeginPlay()" for example. Make sure it's preffixed with virtual).
2. Copy and use the same signature, and add override; to the end.
3. Define it in the .cpp without Virtual or Override
4. Usually call "Super::<funcname> in the first line of code. Example: "Super::BeginPlay();"
*/

#include <iostream>

/// ============ Ad-Hoc Polymorphism ========================
int GetSize(int x)
{
	return x;
}
int GetSize(std::string x)    //Overloading this function with another definition, is Ad-hoc polymorphism
{
	return x.length();
}
//========================================================================


/// ============ Subtype Polymorphism ========================
class Animal
{
public:
	virtual void MakeNoise()
	{
		std::cout << "Animal Noise." << std::endl;
	}
};

class Dog : public Animal					//IVAN NOTE: ': public Animal' makes them child classes of animal.
{
public:
	void MakeNoise() override		//Override a virtual method
	{
		std::cout << "Woof." << std::endl;
	} 
};

class Cat : public Animal					//IVAN NOTE: ': public Animal' makes them child classes of animal.
{
public:
	void MakeNoise() override		//Override a virtual method
	{
		std::cout << "Meow." << std::endl;
	}
};

// Function to Stroke a type Animal
 void Stroke(Animal* lalalal)		//IVAN NOTE: This creates a temp pointer only. You can swap this with a '&'(reference) if you want instead.
{									
	 lalalal->MakeNoise();		
}

//========================================================================

int main()
{
	std::cout << "===== Ad-hoc Poly =====" << std::endl;
	std::cout << GetSize(5) << std::endl;
	std::cout << GetSize("Hello World") << std::endl << std::endl;
	std::cout << "===== Subtype Poly =====" << std::endl;
	Dog dog;
	Cat cat;
	Stroke(&dog); 
	Stroke(&cat); 

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
