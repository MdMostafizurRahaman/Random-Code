#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// Class representing a context-free grammar
class Grammar {
private:
    char start_symbol_;                   // Start symbol
    unordered_set<char> nonterminals_;    // Nonterminal symbols
    unordered_set<char> terminals_;       // Terminal symbols
    set<pair<char, string>> productions_;// Productions

public:
    Grammar(char start_symbol) : start_symbol_(start_symbol) {}

    // Add a production to the grammar
    void add_production(char lhs, string rhs) {
        productions_.insert(make_pair(lhs, rhs));
        nonterminals_.insert(lhs);
        for (char c : rhs) {
            if (!isupper(c)) {
                terminals_.insert(c);
            }
        }
    }

    // Find all the symbols that can be reached from the start symbol
    void find_reachable_symbols(unordered_set<char>& reachable) {
        reachable.insert(start_symbol_);
        bool added;
        do {
            added = false;
            for (auto prod : productions_) {
                if (reachable.count(prod.first)) {
                    for (char c : prod.second) {
                        if (nonterminals_.count(c) && !reachable.count(c)) {
                            reachable.insert(c);
                            added = true;
                        }
                    }
                }
            }
        } while (added);
    }

    // Find all the symbols that generate some string of the language
    void find_generating_symbols(unordered_set<char>& generating) {
        bool added;
        do {
            added = false;
            for (auto prod : productions_) {
                if (!generating.count(prod.first)) {
                    bool can_generate = true;
                    for (char c : prod.second) {
                        if (nonterminals_.count(c) && !generating.count(c)) {
                            can_generate = false;
                            break;
                        }
                    }
                    if (can_generate) {
                        generating.insert(prod.first);
                        added = true;
                    }
                }
            }
        } while (added);
    }

    // Eliminate the symbols that cannot be reached from the start symbol
    void eliminate_unreachable_symbols() {
        unordered_set<char> reachable;
        find_reachable_symbols(reachable);
        vector<pair<char, string>> new_productions;
        for (auto prod : productions_) {
            if (reachable.count(prod.first)) {
                new_productions.push_back(prod);
            }
        }
        productions_ = set<pair<char, string>>(new_productions.begin(), new_productions.end());
        nonterminals_.clear();
        terminals_.clear();
        for (auto prod : productions_) {
            nonterminals_.insert(prod.first);
            for (char c : prod.second) {
                if (!isupper(c)) {
                    terminals_.insert(c);
                }
            }
        }
    }

    // Eliminate the symbols that do not generate any string of the language
    void eliminate_non_generating_symbols() {
        unordered_set<char> generating;
        generating.insert('#');
        find_generating_symbols(generating);
        vector<pair<char, string>> new_productions;
        for (auto prod : productions_) {
            bool can_generate = true;
            for (char c : prod.second) {
                if (nonterminals_.count(c) && !generating.count(c)) {
                    can_generate = false;
                    break;
                }
            }
            if (can_generate && generating.count(prod.first)) {
                new_productions.push_back(prod);
            }
        }
        productions_ = set<pair<char, string>>(new_productions.begin(), new_productions.end());
        nonterminals_.clear();
        terminals_.clear();
        for (auto prod : productions_) {
        nonterminals_.insert(prod.first);
        for (char c : prod.second) {
        if (!isupper(c)) {
        terminals_.insert(c);
       }
     }
    }
   }
// Print the grammar
void print() {
    cout << "Start symbol: " << start_symbol_ << endl;
    cout << "Nonterminals: ";
    for (char c : nonterminals_) {
        cout << c << " ";
    }
    cout << endl;
    cout << "Terminals: ";
    for (char c : terminals_) {
        cout << c << " ";
    }
    cout << endl;
    cout << "Productions:" << endl;
    for (auto prod : productions_) {
        cout << prod.first << " -> " << prod.second << endl;
    }
}
};

int main() {
// Create a sample grammar
Grammar g('S');
g.add_production('S', "AB");
g.add_production('D', "B");
g.add_production('S', "E");
g.add_production('S', "AB");
g.add_production('A', "aA");
g.add_production('A', "a");
g.add_production('B', "bB");
g.add_production('B', "b");
g.add_production('C', "c");
cout << "Original grammar:" << endl;
g.print();

// Eliminate non-generating symbols
g.eliminate_non_generating_symbols();
cout << endl << "Grammar after eliminating non-generating symbols:" << endl;
g.print();

// Eliminate unreachable symbols
g.eliminate_unreachable_symbols();
cout << endl << "Grammar after eliminating unreachable symbols:" << endl;
g.print();

return 0;
}

