
# decode JSON based config of FreeOTP app on Android (tokens.xml)
# its using format like 1,-13,10,-112,123,39 ... 19,42
# and creates base32 string as output
import base64
import binascii


with open("codes.txt", "r") as f:
    for line in f.read().splitlines():

        s = ""

        for l in line.split(","):
            i = (int(l) + 256) % 256
            s += "{:02x}".format(i)

        print(s);
        bins = bytearray.fromhex(s)
        enc = base64.b32encode(bins)
        print(enc.decode())


