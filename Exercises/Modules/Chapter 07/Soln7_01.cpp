// Exercise 7-1 Storing student names and grades. 
// This uses a vector of string objects to store the names.
import std;

int main()
{
  std::vector<std::string> names;
  std::vector<double> grades;
  
  std::size_t max_length {};   // Longest name length
  double average_grade {};     // First accumulates the sum of the grades, 
                               // to be divided by the number of grades later
  // Data entry loop. 
  // This loop reads the name and grade for each student.
  while (true)
  {
    std::print("Enter a student's name: ");
    std::string name;                       // Stores a student name
    std::getline(std::cin, name);

    names.push_back(name);
    
    if (max_length < name.length()) 
        max_length = name.length();

    std::print("Enter {}\'s grade: ", name);
    double grade {};                        // Stores a student grade
    std::cin >> grade;
    grades.push_back(grade);

    average_grade += grade;

    std::print("Do you wish to enter another student's details (y/n): ");
    char answer {};
    std::cin >> answer;
    
    // Ignore the line break that is still on the input stream after reading the y/n character
    // Otherwise the next std::getline() always returns an empty line...
    // (Note: we'll try to remember to add this annoyance as a hint in the next edition...)
    std::cin.ignore();
    
    if (std::toupper(answer) == 'N') break;
  } 

  // Calculating the class average.
  average_grade /= grades.size();

  // Displaying the class average.
  std::println("\nThe class average for {} students is {:.2f}", names.size(), average_grade);

  // Displaying the students' names and grades.
  const std::size_t perline {3};
  for (std::size_t i {}; i < names.size(); ++i)
  {
    std::print("{:<{}} {:>4}\t", names[i], max_length, grades[i]);
    if ((i + 1) % perline) continue;
    std::println("");
  }
  std::println("");
}