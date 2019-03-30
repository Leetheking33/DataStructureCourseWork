// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  // Make a heap from the vector.
  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  // Remove the maximum element
  std::pop_heap (v.begin(),v.end()); 
  v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  std::cout << "size() = " << v.size() << "\n";

  // add 99 the maximum element
  v.push_back(99); 
  std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';
  std::cout << "size() = " << v.size() << "\n";

  while (v.size() > 0) {
      std::cout << "max heap after pop : " << v.front() << '\n';
      std::pop_heap (v.begin(),v.end()); 
      v.pop_back();
  }


  return 0;
}
