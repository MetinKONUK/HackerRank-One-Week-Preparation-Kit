def superDigit(n, k):
    sum_ = sum(map(int, n)) * k
    return sum_ if sum_ < 10 else superDigit(str(sum_), 1)
