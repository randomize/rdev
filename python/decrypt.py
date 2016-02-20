import hashlib, Crypto.Cipher

key = hashlib.sha256(my_password).digest()

with open("my_journal.txt") as f:
    cipher = f.read()
    crypto = AES.new(key, AES.MODE_CBC, iv = cipher[:16])
    plain = crypto.decrypt(cipher[16:])
    plain = plain.strip(plain[-1])
    plain = plain.decode("utf-8")

