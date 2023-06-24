// Working with stacks and queues
import std;

int main()
{
  std::stack<int> stack;
  for (int i {}; i < 10; ++i)
    stack.push(i);

  std::print("The elements coming off the top of the stack:    ");
  while (!stack.empty())
  {
    std::print("{} ", stack.top());
    stack.pop();    // pop() is a void function!
  }
  std::println("");

  std::queue<int> queue;
  for (int i {}; i < 10; ++i)
    queue.push(i);

  std::print("The elements coming from the front of the queue: ");
  while (!queue.empty())
  {
    std::print("{} ", queue.front());
    queue.pop();    // pop() is a void function!
  }
  std::println("");
}
