def plusMinus(arr):
    p, n, z, x = 0, 0, 0, len(arr);
    for i in arr:
        if i > 0: p += 1
        elif i < 0: n += 1
        else: z += 1
    print("{0:.6f}\n{1:.6f}\n{2:.6f}".format(p / x, n / x, z / x))
