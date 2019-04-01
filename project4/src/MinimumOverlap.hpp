#ifndef MinimumOverlap_HPP
#define MinimumOverlap_HPP

#include <string>
#include <vector>

class MinimumOverlap {
    public:

        // Passes in a string pointing to the set/group file.
        // Make sure you store all the sets/groups!
        MinimumOverlap(const std::string &setFile);

        // Returns the minimum number of overlaps possible given a cover.
        // If print is true, it prints the set(s).
        unsigned int findMinimumOverlap(const std::vector<int> &cover, const bool &print) const;
};

#endif
