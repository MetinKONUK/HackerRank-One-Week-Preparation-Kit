def caesarCipher(s, k):
    result = ""
    for i in s:
        if not i.isalpha():
            result += (i)
            continue
        isC = i.upper() == i
        i = i.lower()
        k = k % 26
        newCode = ord(i)+k
        if newCode > 122:
            newCode = 96 + k - (122 - ord(i))
        if isC:
            result += chr(newCode).upper()
        else:
            result += chr(newCode)
    return result
