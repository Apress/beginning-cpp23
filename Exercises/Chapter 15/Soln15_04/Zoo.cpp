// Implementations of the Zoo class that stores pointers to Animals
module zoo;
import animals;
import std;

// Constructor from a vector of animals
Zoo::Zoo(const std::vector<AnimalPtr>& animals) 
  : m_animals{ animals } 
{}

// Add an animal to the zoo
void Zoo::addAnimal(AnimalPtr animal)
{
  m_animals.push_back(animal);
}

// Output the animals and the sound they make
void Zoo::showAnimals() const
{
  for (const auto& animal : m_animals)
  {
    std::println("{} {}", animal->who(), animal->sound());
  }
}

// Collect all Sheep in the Zoo using dynamic cast (the recommended way)
std::vector<Sheep*> Zoo::herd() const
{
  std::vector<Sheep*> sheep;
  for (auto animal : m_animals)
  {
    auto* casted{ dynamic_cast<Sheep*>(animal.get()) };
    if (casted)
    {
      sheep.push_back(casted);
    }
  }
  return sheep;
}

/*
// Collect all Sheep in the Zoo using the typeid() operator and a static cast
// (for the sake of the exercise only)

std::vector<Sheep*> Zoo::herd() const
{
  std::vector<Sheep*> sheep;
  for (auto animal : m_animals)
  {
    if (typeid(*animal) == typeid(Sheep))
    {
      sheep.push_back(static_cast<Sheep*>(animal.get()));
    }
  }
  return sheep;
}
*/