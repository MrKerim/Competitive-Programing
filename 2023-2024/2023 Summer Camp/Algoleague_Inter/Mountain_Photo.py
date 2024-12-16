def sum_of_all_subarrays(arr):
    n = len(arr)
    total_sum = 0

    for i in range(n):
        total_sum += arr[i] * (i + 1) * (n - i)

    return total_sum

# Example usage:
input_array = [1, 2, 1]
result = sum_of_all_subarrays(input_array)
print(result)