// Exercise 8_6 Computing grade statistics
/*
  This is a bigger exercise, and thus many variations will be valid and correct.
  The focus here isn't on performance, it's on writing and calling functions.
  Main thing is that you:
    (1) got the parameter types right---mostly pass-by-reference-to-const 
        for the input parameters, except for sort() which modifies its argument.
    (2) made sure that the program does something correctly for empty grade lists,
        small grade lists (< 5 values), and for grade lists of both odd and even size.
  
  Some things worth noticing in our solution:
    - we overloaded the recursive sort() function by adding a helper function 
      that users can call without having to know what the second and third parameters are,
      and without having to think about the empty input case. 
      This is common with recursive algorithms: the interface that users use 
      will often not contain the actual recursive function.
    - we defined NOT_AVAILABLE equal to std::numeric_limits<unsigned>::max() 
      (equivalent to static_cast<unsigned>(-1))
      to encode missing values in case there are less than 5 inputs,
      and used NaN values elsewhere in case the user enters no value at all.
      Other solutions for the former could've been signed values,
      or in fact any number larger than 100.
      In Chapter 9 you will learn about std::optional<>
      which allows you to handle such "not available" or "undefined" cases more elegantly, though.
*/
import std;

void sort(std::vector<unsigned>& numbers);

void getHighest(const std::vector<unsigned>& sortedNumbers, unsigned(&highest)[5]);
void getLowest(const std::vector<unsigned>& sortedNumbers, unsigned(&lowest)[5]);

double computeAverage(const std::vector<unsigned>& numbers);
double computeMedian(const std::vector<unsigned>& numbers);
double computeStandardDeviation(const std::vector<unsigned>& numbers);
double computeVariance(const std::vector<unsigned>& numbers);

void printNumber(const std::string& label, double number);
void printNumbers(const std::string& label, const unsigned(&numbers)[5]);

const unsigned NOT_AVAILABLE{ std::numeric_limits<unsigned>::max() };

int main()
{
  std::vector<unsigned> grades;

  std::println("Please enter a number of grades (0-100), terminated by a negative one:");
  while (true)
  {
    int number{};
    std::cin >> number;
    if (number < 0)
      break;
    else if (number > 100)
      std::println("Only numbers <= 100, please...");
    else
      grades.push_back(number);
  }

  sort(grades);

  // It would be better and/or easier 
  //    a) to use std::array<> instead of C-style arrays; and
  //    b) to return the values requested rather than using output parameters
  unsigned highest[5]{};
  unsigned lowest[5]{};

  getHighest(grades, highest);
  getLowest(grades, lowest);

  printNumbers("Five highest grades", highest);
  printNumbers("Five lowest grades", lowest);
  printNumber("The grade average", computeAverage(grades));
  printNumber("The median grade", computeMedian(grades));
  printNumber("The standard deviation of the grades", computeStandardDeviation(grades));
  printNumber("The variance of the grades", computeVariance(grades));
}

// Swap numbers at position first with address at position second
void swap(std::vector<unsigned>& numbers, std::size_t first, std::size_t second)
{
  auto temp{ numbers[first] };
  numbers[first] = numbers[second];
  numbers[second] = temp;
}

// Recursive helper function to sort numbers in ascending sequence
// Numbers to be sorted are from numbers[start] to numbers[end]
void sort(std::vector<unsigned>& numbers, std::size_t start, std::size_t end)
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle of the [start, end] range to partition
  swap(numbers, start, (start + end) / 2); // Swap middle number with start

  // Check values against chosen number
  std::size_t current{ start };
  for (std::size_t i{ start + 1 }; i <= end; i++)
  {
    if (numbers[i] < numbers[start])   // Is number less than chosen value?
      swap(numbers, ++current, i);     // Yes, so swap to the left
  }

  swap(numbers, start, current);       // Swap the chosen value with the last swapped number

  if (current > start) sort(numbers, start, current - 1);  // Sort left subset if exists
  if (end > current + 1) sort(numbers, current + 1, end);  // Sort right subset if exists
}

// Sort numbers in ascending sequence
void sort(std::vector<unsigned>& numbers)
{
  if (!numbers.empty())
    sort(numbers, 0, numbers.size() - 1);
}

void getHighest(const std::vector<unsigned>& sortedNumbers, unsigned(&highest)[5])
{
  const auto numHighest{ static_cast<int>(std::size(highest)) };

  for (int i{}; i < numHighest; ++i)
  {
    const int numberIndex{ static_cast<int>(sortedNumbers.size()) - numHighest + i };
    if (numberIndex >= 0)
      highest[i] = sortedNumbers[numberIndex];
    else
      highest[i] = NOT_AVAILABLE;
  }
}

void getLowest(const std::vector<unsigned>& sortedNumbers, unsigned(&lowest)[5])
{
  for (std::size_t i{}; i < std::size(lowest); ++i)
  {
    if (i < sortedNumbers.size())
      lowest[i] = sortedNumbers[i];
    else
      lowest[i] = NOT_AVAILABLE;
  }
}

double computeAverage(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::numeric_limits<double>::quiet_NaN();

  double average{};
  for (auto& number : numbers)
    average += number;
  return average / numbers.size();
}

double computeMedian(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::numeric_limits<double>::quiet_NaN();

  const auto numNumbers{ numbers.size() };
  const auto middleIndex{ numNumbers / 2 };
  if (numNumbers % 2)
  {
    return numbers[middleIndex];
  }
  else
  {
    return (numbers[middleIndex] + numbers[middleIndex - 1]) / 2.0;
  }
}

double computeStandardDeviation(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::numeric_limits<double>::quiet_NaN();

  const double average{ computeAverage(numbers) };
  double sum{};
  for (auto& number : numbers)
    sum += (number - average) * (number - average);
  return std::sqrt(sum / numbers.size());
}

double computeVariance(const std::vector<unsigned>& numbers)
{
  if (numbers.empty())
    return std::numeric_limits<double>::quiet_NaN();

  const double standardDeviation{ computeStandardDeviation(numbers) };
  return standardDeviation * standardDeviation;
}

void printNumber(const std::string& label, double number)
{
  std::print("{}: ", label);

  if (std::isnan(number))
    std::print("n/a");
  else
    std::print("{:.4}", number);

  std::println("");
}

void printNumbers(const std::string& label, const unsigned(&numbers)[5])
{
  std::print("{}: ", label);

  for (const auto number : numbers)
  {
    if (number != NOT_AVAILABLE)
      std::print("{} ", number);
  }

  std::println("");
}