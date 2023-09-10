// Exercise 4-7 Outputting the binary code for a letter.
/*
 * Most of the program is fairly simple. 
 * The cctype functions make determining upper or lower case easy. 
 * Finding out if it's a vowel is also easy with a switch.
 * Only getting the binary code needs a little thought, though. 
 * Each of the masks selects a different bit of the ch variable.
 * If the bit is '1', the expression will be non-zero, which is converted to Boolean true.
 * If it's '0', the whole expression will be zero, or Boolean false.
 * Ones and zeros are therefore output as appropriate.
 */
import std;

int main()
{
  char entered_letter {};
  std::print("Enter a letter: ");
  std::cin >> entered_letter;

  if (!std::isalpha(entered_letter)) 
  {
    std::println("That's not a letter!");
    return 1;
  }

  // We'll need the lower case letter...
  const auto lower_case_letter{ static_cast<char>(std::tolower(entered_letter)) };

  // Determine upper or lower case.
  std::println("'{}' is {}.", entered_letter, std::islower(entered_letter) ? "lowercase" : "uppercase");

  // Determine whether it is a vowel or a consonant.
  std::print("'{}' is a ", entered_letter);

  switch (lower_case_letter)
  {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      std::print("vowel");
      break;
    default:
      std::print("consonant");
      break;
  }
  std::println(".");

  // Output the character code as binary (with println())
  // - 0 is an argument index to repeat lower_case_letter twice;
  // - 08 sets the output field width to 8, adding leading zeroes if needed 
  //   (this to make the output equivalent to that with std::cout below, which also adds leading zeroes);
  // - b triggers binary formatting
  std::println("The binary code for '{0}' is {0:08b} (std::println() version).", lower_case_letter);

  // Output the character code as binary (without println())
  std::cout << "The binary code for '" << lower_case_letter << "' is "
     << ((lower_case_letter & 0b10000000u)? 1 : 0) 
     << ((lower_case_letter & 0b01000000u)? 1 : 0)
     << ((lower_case_letter & 0b00100000u)? 1 : 0) 
     << ((lower_case_letter & 0b00010000u)? 1 : 0)
     << ((lower_case_letter & 0b00001000u)? 1 : 0) 
     << ((lower_case_letter & 0b00000100u)? 1 : 0)
     << ((lower_case_letter & 0b00000010u)? 1 : 0) 
     << ((lower_case_letter & 0b00000001u)? 1 : 0)
     << " (std::cout version)."
     << std::endl;

  return 0;
}