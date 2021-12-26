def lonelyinteger(a):
    r = 0
    for i in a:
        r ^= i
    return r
