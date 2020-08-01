import sys

def find_buy_sell_stock_prices(array):
    if array == None or len(array) < 2:
        return None

    current_buy = array[0]
    global_sell = array[1]
    global_profit = global_sell - current_buy

    current_profit = -sys.maxsize - 1

    for i in range(1, len(array)):
        current_profit = array[i] - current_buy

        if current_profit > global_profit:
            global_profit = current_profit
            global_sell = array[i]

        if current_buy > array[i]:
            current_buy = array[i]

    result = global_sell - global_profit, global_sell

    return result

# Driver Code
A = [8, 5, 12, 9, 19, 1]
B = [21, 12, 11, 9, 6, 3]

print(find_buy_sell_stock_prices(A))
print(find_buy_sell_stock_prices(B))
