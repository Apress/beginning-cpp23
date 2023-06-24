// Using std::source_location, C++'s answer to __LINE__ and __FILE__
import std;

void logError(std::string_view errorMessage,
       std::source_location location = std::source_location::current())
{
  std::println("{}:{}:{} - An unexpected error occurred in {}: {}",
               location.file_name(), location.line(), location.column(),
               location.function_name(), errorMessage);
}

int main() 
{ 
  logError("OOPS!");  // The line number in the log message will refer to 
                      // this line in main(), not to the where logError() is defined.
}