# Null terminating strings are not used in Python
# For this question, assume you are passed a null terminated string
def str_rev(str, start, end):
    if str == None or len(str) < 2: return

    while (start < end):
        temp = str[start]
        str[start] = str[end]
        str[end] = temp

        start += 1
        end -= 1

def reverse_words(sentence):

    # Sentence is a null-terminated string ending with char '\0'
    if sentence == None or len(sentence) == 0 or sentence[0] == '\0':
        return

    str_len = len(sentence)
    str_rev(sentence, 0, str_len - 2)

    start = 0
    end = 0

    while True:
        while (sentence[start] == ' '):
            start += 1

        if sentence[start] == '\0':
            break

        end = start + 1
        while sentence[end] != '\0' and sentence[end] != ' ':
            end += 1

        str_rev(sentence, start, end - 1)
        start = end

# Driver Code
sentence = "Hello World"
reverse_words(sentence)
print(sentence)
