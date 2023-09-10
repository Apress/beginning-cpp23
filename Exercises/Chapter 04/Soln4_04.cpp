// Exercise 4-4.
// As promised, you're to go look for a person "who is over 21, under 35, female, 
// has a bachelor's or master's degree, is unmarried, and who speaks Hindi or Urdu"

import std;

enum class AcademicDegree
{
  none, associate, bachelor, professional, master, doctor
};

int main()
{
  unsigned int age {};        // Initialized to 0
  char gender {};             // Initialized to '\0' (see Chapter 5)
  AcademicDegree degree {};   // Initialized to AcademicDegree::none
  bool married {};            // Initialized to false
  bool speaksHindi {};
  bool speaksUrdu {};

  std::print("What is your age, if I may ask? ");
  std::cin >> age;
  
  if (age > 120)
  {
    std::println("Sure it is, joker. Sadly, comedians don't qualify...");
    return 1;
  }
  
  std::print("What is your gender ([m]ale, [f]emale, or [o]ther)? ");
  std::cin >> gender;
  
  gender = std::tolower(gender);
  if (gender != 'm' && gender != 'f' && gender != 'o')
  {
    std::println("That was not one of the options... "
                 "The square brackets were not clear, perhaps? We were worried about that...");
    return 1;
  }
  
  std::println("What is your highest academic degree?");
  std::println("Possible values are:");
  std::println("\tn: no academic degree");
  std::println("\ta: associate's degree");
  std::println("\tb: bachelor's dehree");
  std::println("\tp: professional degree");
  std::println("\tm: master's degree");
  std::println("\td: doctorate");;

  char degreeChar {};
  std::cin >> degreeChar;  
  
  switch (std::tolower(degreeChar))
  {
    case 'n': degree = AcademicDegree::none;         break;
    case 'a': degree = AcademicDegree::associate;    break;
    case 'b': degree = AcademicDegree::bachelor;     break;	
    case 'p': degree = AcademicDegree::professional; break;
    case 'm': degree = AcademicDegree::master;       break;
    case 'd': degree = AcademicDegree::doctor;       break;
    default:
      std::println("Given that you cannot correctly enter your degree, shall I just note down 'none'?");
      std::println("On second thought: no, I do not believe you qualify. Goodbye.");
      return 1;
  }
  
  // Now we ask a few yes/no questions, and use some variations on how to decide
  // whether or not the user's input is valid or not. In real code, one should
  // probably be consistent rather than using a different style each time...  
  
  char yes_no {};
  std::print("Are you married (y or n)? ");
  std::cin >> yes_no;
  
  if (yes_no == 'y' || yes_no == 'Y')
    married = true;
  else if (yes_no == 'n' || yes_no == 'N')
    married = false;
  else
  {
    std::println("Incapable of entering your marital status. Surely still single then...?");
    return 1;
  }
  
  std::print("Do you speak Hindi (y or n)? ");
  std::cin >> yes_no;
  
  yes_no = std::toupper(yes_no);
  if (yes_no == 'Y')
    speaksHindi = true;
  else if (yes_no == 'N')
    speaksHindi = false;
  else
  {
    std::println("I'm sorry? I didn't catch that. Please answer in English next time...");
    return 1;
  }
  
  std::print("Do you speak Urdu (y or n)? ");
  std::cin >> yes_no;
  
  switch (std::tolower(yes_no))
  {
    case 'y': speaksUrdu = true;  break;
    case 'n': speaksUrdu = false; break;
    default:
      std::println("I'm sorry? I didn't catch that. Please answer in English next time...");
      return 1;
  }
  
  // Determine whether the user is someone 
  // "who is over 21, under 35, female, has a bachelor's or master's degree,
  //  is unmarried, and who speaks Hindi or Urdu"
  if ((age > 21 && age < 35) 
        && gender == 'f' 
        && (degree == AcademicDegree::bachelor || degree == AcademicDegree::master)
        && !married
        && (speaksHindi || speaksUrdu))
  {
    std::println("Congratulations: you are precisely the person we were looking for! Are you willing to work for minimum wage?");
  }
  else
  {
    std::println("Sorry. You don't seem to meet our requirements to the letter. Don't call us, we'll call you...?");
  }
}