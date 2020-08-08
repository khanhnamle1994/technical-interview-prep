# Null terminating strings are not used in Python
# For this question, assume you are passed a null terminated string
def remove_duplicates(s):

    hash_set = set([])
    write_index = 0
    read_index = 0

    while s[read_index] != '\0':
        if s[read_index] not in hash_set:
            hash_set.add(s[read_index])
            s[write_index] = s[read_index]
            write_index += 1

        read_index += 1

    s[write_index] = '\0'
    return s

# Driver code
string = 'abbabcddbabcdeedebc'
print(remove_duplicates(string))
