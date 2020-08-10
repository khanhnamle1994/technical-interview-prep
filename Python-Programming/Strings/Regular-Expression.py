def regx_match_rec(text, pattern, i, j):
    if len(text) == i and len(pattern) == j:
        return True

    if j < len(pattern) - 1 and pattern[j + 1] == '*':
        for k in range(i, len(text) + 1):
            if regx_match_rec(text, pattern, k, j + 2):
                return True

            if k >= len(text):
                return False

            if pattern[j] != '.' and text[k] != pattern[j]:
                return False

    elif (i < len(text) and j < len(pattern) and (pattern[j] == '.' or pattern[j] == text[i])):
        return regx_match_rec(text, pattern, i + 1, j + 1)

    return False
