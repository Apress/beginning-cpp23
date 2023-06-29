// Exercise 8-1 Reading  and validating a date of birth. 
// As always, there are many ways of doing this!
import std;

int validate_input(int lower, int upper, const std::string& description);
int year();
int month();
int day(int month_value, int year_value);
std::string ending(int date_day);

int main()
{
  std::println("Enter your date of birth.");
  int date_year {year()};
  int date_month {month()};
  int date_day {day(date_month, date_year)};

  std::string months[]  {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"  };

  std::println("\nYou were born on the {} of {}, {}.", 
    std::to_string(date_day) + ending(date_day), 
    months[date_month - 1], 
    date_year
  );
}

// Reads an integer that is between lower and upper inclusive
int validate_input(int lower, int upper, const std::string& description)
{
  int data {};
  std::print("Please enter {} from {} to {}: ", description, lower, upper);
  std::cin >> data;
  while (data < lower || data > upper)
  {
    std::print("Invalid entry; please re-enter {}: ", description);
    std::cin >> data;
  }
  return data;
}

// Reads the year
int year()
{
  const int low_year {1900};         // Most people aren't older than 120 years...
  const int high_year {2023};        // Most are born already as well...
  return validate_input(low_year, high_year, "a year");
}

// Reads the month
int month()
{
  const int low_month {1};
  const int high_month {12};
  return validate_input(low_month, high_month, "a month number");
}

// Reads in the date in the given month and year
int day(int month_number, int year)
{
  const int date_min {1};
  const int feb {2};

  // Days in month:     Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
  const int date_max[]  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Feb has 29 days in a leap year. A leap year is a year that is divisible by 4
  // except years that are divisible by 100 but not divisible by 400
  if (month_number == feb && year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
    return validate_input(date_min, 29, "a day of the month");
  else
    return validate_input(date_min, date_max[month_number - 1], "a day of the month");
}

// Select the ending of the ordinal day number
std::string ending(int date_day)
{
  switch (date_day)
  {
  case 1: case 21: case 31:
      return "st";
  case 2: case 22:
      return "nd";
  case 3: case 23:
      return "rd";
  default:
      return "th";
  }
}