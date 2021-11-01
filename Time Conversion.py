def timeConversion(s):
    t = s[-2]
    s = s[:-2]
    n = s.split(":")
    if t == "P":
        if n[0] == "12":
            return ":".join(n)
        n[0] = str(int(n[0]) + 12)
        return ":".join(n)
    else:
        if n[0] == "12":
            n[0] = "00"
            return ":".join(n)
        return ":".join(n)
