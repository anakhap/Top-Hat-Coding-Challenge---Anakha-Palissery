// Thanks for your interest in working at Top Hat!
//
// We would like you to tackle our JUMBLED WORD PROBLEM
//
// Given two words, return if they are anagrams of each other.
//
// A pair of anagrams are two words, phrases, or names formed by rearranging the letters of another, such as “cinema”, formed from “iceman”.
//
// Document any assumptions you make about the problem (e.g. “Assuming that all inputs are strings”) in comments in or around your code.
//
// Examples:
// Input: “tommarvoloriddle”, “iamlordvoldemort”
// Output: TRUE
//
// Input: “harrypotter”, “dracomalfoy”
// Output: FALSE
//
// INSTRUCTIONS:
// - Please self monitor your time and submit your results within x minutes
// - To submit, please press "commit & push" in the Version Control tab on the left.
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std; 

class Solution {
public:
  Solution() {}; 

  bool isAnagram(string a, string b) {
    //check if either strings are empty
    if(a.length() == 0 || b.length() == 0) {
      return false;
    } else if(a.length() != b.length()) {
      //if both strings do not have the same length, they are not anagrams
      return false;
    }
    //use an unordered map to keep track of the number of occurences of each character in string a
    unordered_map<char, int>freq; 
    //build the map by iterating through string a - O(n)
    for(int i = 0; i < a.length(); i++) {
      freq[a[i]]++; 
    }
    //iterate through string b and remove count of occurence from the map; if count of a character becomes 0, then remove it from the map - O(n)
    for(int i = 0; i < b.length(); i++) {
      auto it = freq.find(b[i]); 
      if(it == freq.end()) {
        return false;   //letter not found in map
      } else {
        freq[b[i]]--;
        if(freq[b[i]] == 0) {
          freq.erase(b[i]);
        }
      }
    }
    //if the map is not empty that means there are still characters in it, therefore not anagrams, otherwise return true
    if(!freq.empty()) {
      return false;
    } else {
      return true;
    }

  }
};

  int main() {

    /*Assumptions: 
     * all inputs are strings, of alphanumeric chars
     * boundary checks include if not the same length for both strings, either string is empty, 
     * return type is boolean
    */

    Solution *s = new Solution(); 

    string a = "tommarvoloriddle";
    string b = "iamlordvoldemort";
    cout << s->isAnagram(a, b) << endl; 
    a = "harrypotter";
    b = "dracomalfoy";
    cout << s->isAnagram(a, b) << endl; 
    a = "cin2ema";
    b = "icema2n";
    cout << s->isAnagram(a, b) << endl;
    a = ""; 
    b = "test";
    cout << s->isAnagram(a, b) << endl;
    a = "";
    b = "";
    cout << s->isAnagram(a, b) << endl;
    a = "test"; 
    b = "tests"; 
    cout << s->isAnagram(a, b) << endl;
    return 0;
  }




