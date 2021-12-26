def diagonalDifference(arr):
    left_diagonal = 0
    right_diagonal = 0
    n = len(arr)
    for i in range(n):
        left_diagonal += arr[i][i]
    for i,j in zip(range(n-1,-1, -1), range(0, n)):
        right_diagonal += arr[i][j]
    return abs(right_diagonal-left_diagonal)
