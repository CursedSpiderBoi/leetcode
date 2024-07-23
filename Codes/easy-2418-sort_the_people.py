# you are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

# For each index i, names[i] and heights[i] denote the name and height of the ith person.

# Return names sorted in descending order by the people's heights.

 

# Example 1:

# Input: names = ["Mary","John","Emma"], heights = [180,165,170]
# Output: ["Mary","Emma","John"]
# Explanation: Mary is the tallest, followed by Emma and John.

# Example 2:

# Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
# Output: ["Bob","Alice","Bob"]
# Explanation: The first Bob is the tallest, followed by Alice and the second Bob.


class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        returnVar = []
        indexes = []
        for i in range(len(heights)):
            if not returnVar:
                returnVar.append(names[i])
                indexes.append(i)
            else:
                added = False
                for j in range(len(returnVar)):
                    if heights[i] > heights[indexes[j]]:
                        returnVar.insert(j, names[i])
                        indexes.insert(j, i)
                        added = True
                        break
                if not added:
                    returnVar.append(names[i])
                    indexes.append(i)
        return returnVar
