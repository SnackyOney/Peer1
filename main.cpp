#include <algorithm>
#include <iostream>
#include <chrono>
#include <string>
#include <stdio.h>
#include <map>
#include <iomanip>
#include <vector>
class People {
  public:
  void Read(int32_t id, int32_t pages) {
    for(int i = id_to_pages_[id] + 1; i <= pages; ++i) {
      ++pages_to_people_[i];
    }
    id_to_pages_[id] = pages;
  }
  void Cheer(int32_t id) {
    if (id_to_pages_[id] == 0) {
      std::cout << 0 << '\n';
      return;
    }
    if (pages_to_people_[1] == 1) {
      std::cout << 1 << '\n';
      return;
    }
    std::cout << (pages_to_people_[1] - pages_to_people_[id_to_pages_[id]]) * 1.0 / (pages_to_people_[1] - 1) << '\n';
  }
  private:
  std::vector<int32_t> id_to_pages_ = std::vector(100001, 0);
  std::vector<int32_t> pages_to_people_ = std::vector(1001, 0);
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  People people;
  std::string str;
  int32_t inp_1 = 0; 
  int32_t inp_2 = 0;
  int32_t number = 0;
  std::cin >> number;
  for(int32_t i = 0; i < number; ++i) {
    std::cin >> str >> inp_1;
    if (str == "CHEER") {
      people.Cheer(inp_1);
    }
    if (str == "READ") {
      std::cin >> inp_2;
      people.Read(inp_1, inp_2);
    }
  }
}
