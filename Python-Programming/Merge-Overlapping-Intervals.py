def merge(intervals):
    intervals.sort(key = lambda x:x[0])
    ans = []

    for x, y in intervals:
        if ans and x <= ans[-1][1]:
            if y > ans[-1][1]:
                ans[-1][1] = y
        else:
            ans.append([x, y])

    return ans

# Driver Code
intervals = [[1, 5], [3, 7], [4, 6], [6, 8]]
print(merge(intervals))
