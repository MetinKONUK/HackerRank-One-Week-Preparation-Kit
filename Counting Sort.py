def countingSort(arr):
    # Write your code here
    result = [0] * 100
    for i in set(arr):
        result [i] = arr.count(i)
    return result
