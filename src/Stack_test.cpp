#include "Stack.h"
#include "ut.hpp"

int main() {
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("Stack") = [] {
    it("has a constructor") = [] { expect(nothrow([]() { Stack<int>(); })); };

    it("can push and pop items") = [] {
      Stack<int> a;
      expect(that % a.size() == 0);
      for (auto i = 0; i < 7; i++) {
        a.push(i);
      }
      expect(that % a.size() == 7);
      a.push(7);
      expect(that % a.size() == 8);
    };

    it("has state") = [] {
      Stack<int> a;
      expect(that % a.empty());
      a.push(0);
      expect(that % not a.empty());
    };
  };

  return 0;
}
