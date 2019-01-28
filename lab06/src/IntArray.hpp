#ifndef INTARRAY_HPP
#define INTARRAY_HPP

class IntArray {
    private:
        /* You fill out the private contents. */

    public:
        /* Copy array’s contents to an internal array, (length = size). */
        IntArray(int *array, int size);

        /* Return the current length of the array */
        int getLength();

        /* Returns the index in the array where value is found.
         * Return -1 if value is not present in the array.
         */
        int indexOf(int value);

        /* Removes an item at position index by shifting later elements left.
         * Returns true iff 0 <= index < size.
         */
        bool remove(int index);

        /* Returns an Array of all integers that are in common with self and ary.
         * Return an empty Array if there are no intersections.
         */
        IntArray* findIntersections(IntArray &ary);

        /* Return true if the array ary is contained sequentually in self. */
        bool isSubsequence(IntArray &ary);

        /* Delete any used memory when this variable goes out of scope. */
        ~IntArray();
};

#endif
