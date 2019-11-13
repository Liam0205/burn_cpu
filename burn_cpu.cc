#include <iostream>
#include <thread>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    const int num_thread = std::stoi(argv[1]);
    std::vector<std::thread> v;
    v.reserve(num_thread);
    std::cout << "I'm gonna burn your CPU with " << num_thread << " threads!" << std::endl;
    for (int i = 0; i != num_thread; ++i) {
      std::cout << "Thread (" << i << ") is spawning...   ";
      v.emplace_back([]() { for(;;); });
      std::cout << "Thread (" << i << ") spawned!" << std::endl;
    }
    std::cout << "Now, check temprature of your CPU!" << std::endl;
    for (auto& t : v) {
      t.join();
    }
  } else {
    std::cout << "Please input an integer as num_thread!" << std::endl;
  }
  return 0;
}
