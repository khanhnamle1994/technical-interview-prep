def can_segment_string(s, dict):
    for i in range (1, len(s) + 1):
        first = s[0:i]
        if first in dict:
            second = s[i:]
            if not second or second in dict or can_segment_string(second, dict):
                return True
    return False
