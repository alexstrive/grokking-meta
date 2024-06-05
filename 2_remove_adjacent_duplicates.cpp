#include <gtest/gtest.h>

using namespace std;

string remove_adjacent_duplicates(string str) {
    // Initialize an empty stack.
    string stack;

    // Loop through the characters in the given string s.
    for (char chr: str) {
        // For each character:
        // If the stack is not empty and the current character is the same as the top character on the stack, pop the character from the stack.
        if (!stack.empty() && chr == stack.back()) {
            stack.pop_back();
        } else {  // Otherwise, push the current character onto the stack.
            stack.push_back(chr);
        }
    }

    return stack;
}

TEST(Example, Case1) {
    auto s = "abccba";
    EXPECT_EQ(remove_adjacent_duplicates(s), "");
}

TEST(Example, Case2) {
    auto s = "foobar";
    EXPECT_EQ(remove_adjacent_duplicates(s), "fbar");
}

TEST(Example, Case3) {
    auto s = "abcd";
    EXPECT_EQ(remove_adjacent_duplicates(s), "abcd");
}