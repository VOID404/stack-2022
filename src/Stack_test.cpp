#include "Stack.h"
#include "ut.hpp"
#include <sstream>

using std::ostringstream;
using std::string;

int main() {
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("Stack") = [] {
    it("has a constructor") = [] { expect(nothrow([]() { Stack<int>(); })); };
    it("can be copied") = [] {
      Stack<int> s1(10, 7);
      Stack<int> s2 = s1;
      expect(that % s1.size() == s2.size());
      expect(that % s2.pop() == 7);
      expect(that % s1.size() == s2.size() + 1);
    };

    it("can push and pop items") = [] {
      Stack<int> a;
      expect(that % a.size() == 0);
      for (auto i = 0; i < 7; i++) {
        a.push(i);
      }
      expect(that % a.size() == 7);
      a.push(7);
      expect(that % a.size() == 8);

      expect(that % a.pop() == 7);
      expect(that % a.pop() == 6);
      expect(that % a.size() == 6);
    };

    it("has state") = [] {
      Stack<int> a;
      expect(that % a.empty());
      a.push(0);
      expect(that % not a.empty());
    };

    it("can be printed") = [] {
      Stack<unsigned int> s;

      for (auto i = 0; i < 5; i++) {
        s.push(i);
      }

      ostringstream stream;
      stream << s;

      string actual = stream.str();
      string expected = "[4 3 2 1 0]";

      expect(that % actual == expected);
    };

    it("can be iterated over") = [] {
      Stack<int> s;

      for (auto i = 0; i < 32; i++) {
        s.push(i);
      }

      auto i = 32;
      for (auto e : s) {
        expect(that % e == --i);
      }
    };
  };

  return 0;
}
