# Null terminating strings are not used in Python
# For this question, assume you are passed a null terminated string
def remove_white_spaces(s):
    # s is the array of characters with '\0' as last character to indicate the end of string
    if s == None or len(s) == 0 or s[0] == '\0': return

    # We will use read, write pointers here.
    # Write pointer will follow the read pointer and only write characters read that are neither a space nor a tab.
    read_ptr = 0
    write_ptr = 0
    while read_ptr < len(s) and s[read_ptr] != '\0':
        # Assume there are only two white space characters space and tab
        if s[read_ptr] != ' ' and s[read_ptr] != '\t':
            s[write_ptr] = s[read_ptr]
            write_ptr += 1
        read_ptr += 1

    # Let's mark the end of string
    s[write_ptr] = '\0'

    return s

# Driver Code
s = 'All greek to   me'
print(remove_white_spaces(s))
