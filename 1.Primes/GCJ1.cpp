#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

map<char,int> memo;  // map used to store character with their values

int main() {
   int nT; cin >> nT;
   string str;
   int k = 1;
   while (nT-- && cin >> str) {
      memo.clear();
      int next = 0;
      memo[str[0]] = 1;
      for (int i = 1; i < str.size(); i++) {   // we want next to be 0,2,3... therefore we skip 1
         if (memo.count(str[i]) == 0) {             //checks if that particular key is present, if not present
            memo[str[i]] = next;                    //then the value is set to next, if it is already present then no value is set
            next++;
            if (next == 1) next++;                  //we cannot assign the value 1 in the base system.
         }
      }
      long long val = 0;
      int base = next == 0 ? 2 : next;
      for (int i = 0; i < str.size(); i++) {
         val = val * base + memo[str[i]];
      }
      cout << "Case #" << k << ": " << val << "\n";
      k++;
   }
   return 0;
}

/*
CODE EXPLAINED
The problem asks us to determine the minimum possible number we can derive 
from an unknown number representation system. To do this we must assign 
values to each of the characters present in the symbols. For example let's 
say we are given "cats" as an input we need to determine what the 'c' means 
numerically, what the 'a' means numerically etc. Since we want the smallest possible 
number, it suggests a greedy strategy of assigning what each letter means. 
In our case, we first see 'c' and therefore wish for this to be as small as possible.
 However, there is an additional constraint that no number starts with a 0 and 
 since 'c' is the first symbol it cannot be 0. Therefore, the next obvious choice 
 is to give it a value of 1. Next, we process 'a' and assign it a value of 0 since 
 it hasn't been used yet and it's not the first symbol. Following this, 't' gets 
 assigned 2 and 's' gets assigned 3. 

Now the next task is to determine the base system the aliens work on, it can be 
easily shown we want the base as small as possible - yet large enough to allow 
us to use all the symbols (every base system has to assign values to different symbols). 
Therefore, the base system is simply the number of 
unique characters/letters in the alien number. We are then tasked with converting 
this to "human" form (i.e. decimal representation) which can be done iteratively 
like any base conversion algorithm. Implementation wise, we can keep track of our 
character assignments in a map data structure. When we encounter a letter, we 
first check whether or not we have seen the letter - if we haven't then we greedily 
assign it the next available (and smallest) number. If we have, then we simply skip 
over the character.
*/