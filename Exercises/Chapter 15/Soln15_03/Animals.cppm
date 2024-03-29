// Animal classes
export module animals;

import std;

export class Animal
{
public:
  Animal(std::string_view name, unsigned weight);  // Constructor
  virtual ~Animal() = default;                     // Very important: a virtual destructor!
  
  virtual std::string who() const;                 // Return string containing name and weight
  virtual std::string_view sound() const = 0;      // Return the sound of an animal

protected:              // Protected getters for use in derived classes
  virtual std::string getName() const { return m_name; }
  virtual unsigned getWeight() const { return m_weight; }

private:
  std::string m_name;   // Name of the animal
  unsigned m_weight;    // Weight of the animal
};

export class Sheep : public Animal
{
public:
  Sheep(std::string_view name, unsigned weight);
  Sheep(std::string_view name, unsigned weight, unsigned wool);
  
  std::string_view sound() const override;  // Return the sound of a sheep

protected:
  std::string getName() const override;
  unsigned getWeight() const override;

private:
  unsigned m_wool_weight;
};

export class Dog : public Animal
{
public:
  using Animal::Animal;                     // Inherit constructor
  
  std::string_view sound() const override;  // Return the sound of a dog
};

export class Cow : public Animal
{
public:
  using Animal::Animal;                     // Inherit constructor
  
  std::string who() const override;         // Override the behaviour of who() for Cows
  std::string_view sound() const override;  // Return the sound of a cow
};

