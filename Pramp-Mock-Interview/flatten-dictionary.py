# Given a dictionary "dict", write a function "flattenDictionary" that returns a flattened version of it

# Analysis:
# A recursion is a natural choice for this kind of problem. We iterate over the keys in "dict" and distinguish between 2 cases:
# If the value mapped to a key is a primitive, we take that key and simply concatenate it to the flattened key we created up to
# this point. We then map the resultant key to the value in the output dictionary.
# If the value is a dictionary, we do the same concatenation, but instead of mapping the result to the value in the output dictionary,
# we recurse on the value with the newly formed key. */

# Python Solution
function flattenDictionary(dict):
  flatDictionary = {}
  flattenDictionaryHelper("", dict, flatDictionary)

  return flatDictionary

function flattenDictionaryHelper(initialKey, dict, flatDictionary):
  for(key : dict.keyset()):
    value = dict.get(key)

    if(!isDictionary(value)) : // the value is of a primitive type
      if(initialKey == null || initialKey == ""):
        flatDictionary.put(key, value)
      else:
        flatDictionary.put(initialKey + "." + key, value)
    else:
      if(initialKey == null || initialKey == ""):
        flattenDictionaryHelper(key, value, flatDictionary)
      else:
        flattenDictionaryHelper(initialKey + "." + key, value, flatDictionary)

# Complexity:
# Time Complexity: O(n), where n is the number of keys in the input dictionary. We visit every key in dictionary only once, hence
# the linear time complexity.
# Space Complexity: O(n) since the output dictionary is asymptotically as big as the input dictionary. We also store recursive calls
# in the execution stack which in the worst case scenario could be O(n), as well. The total is still O(n).
