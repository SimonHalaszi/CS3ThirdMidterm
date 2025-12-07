#pragma once

/*

PATTERNS
- registry: canonical vs. non-canonical pattern, 
  use, implementation

*/

#include <string>
#include <iostream>
#include <map>

// Basic entry class nothing crazy
class IntEntry {
    public:
        IntEntry(std::string name = "null", int i = 0)
        : name_(name), i_(i) {}

        std::string getName() const { return name_; }
        int getInt() const { return i_; }

    private:
        std::string name_;
        int i_;
};

// Registry
class IntRegistry {
    public:
        // Add an entry by passing in a pointer to it
        static void addEntry(IntEntry* entry) {
            if(registry.find(entry->getName()) == registry.end()) {
                registry.insert({entry->getName(), entry});
            }
        }

        // Access the entry by entering its key
        static IntEntry* accessEntry(std::string entryKey) {
            auto it = registry.find(entryKey);
            if(it != registry.end()) {
                return it->second;
            }
            return nullptr;
        }

        // Remove an entry by entering its key
        static void removeEntry(std::string entryKey) {
            auto it = registry.find(entryKey);
            if(it != registry.end()) {
                registry.erase(entryKey);
            }           
        }

    private:
        static std::map<std::string, IntEntry*> registry;
};

std::map<std::string, IntEntry*> IntRegistry::registry;