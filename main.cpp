#include <iostream>
#include <set>

class PhoneDirectory {
  public:
    PhoneDirectory(int maxnum) {
        while (maxnum > 0)
            availNums.insert(--maxnum);
    }

    int get() {
        if (!availNums.empty()) {
            int result = *(availNums.begin());
            availNums.erase(availNums.begin());
            return result;
        }
    }

    bool check(int num) {
        return availNums.find(num) != availNums.end();
    }

    void release(int num) {
        availNums.insert(num);
    }

  private:
    std::set<int> availNums;
};


int main() {
    PhoneDirectory phoneDir(3);
    std::cout << std::boolalpha;
    std::cout << phoneDir.get() << std::endl;
    std::cout << phoneDir.get() << std::endl;
    std::cout << phoneDir.check(2) << std::endl;
    std::cout << phoneDir.get() << std::endl;
    std::cout << phoneDir.check(2) << std::endl;
    phoneDir.release(2);
    std::cout << phoneDir.check(2) << std::endl;
    std::cout << phoneDir.get() << std::endl;
}
