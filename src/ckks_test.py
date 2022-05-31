import CKKS as ckks
import numpy as np

def print_example_banner(title: str):
    """Helper function: Prints the name of the example in a fancy banner."""
    if title.strip():
        title_length = len(title)
        banner_length = title_length + 2 * 10
        banner_top = "+" + "-" * (banner_length - 2) + "+"
        banner_middle = "|" + ' ' * 9 + title + ' ' * 9 + "|"
        print("\n" + banner_top + "\n" + banner_middle + "\n" + banner_top + "\n")

print_example_banner("zx test CKKS.py")

M = 8
scale = 64

encoder = ckks.CKKSEncoder(M, scale)

z = np.array([3 + 4j, 2 - 1j])
print("明文向量：", z)

plaintext_polynomial = encoder.encode(z)
print("明文多项式：", plaintext_polynomial)

plain_text = encoder.decode(plaintext_polynomial)
print("解码后的明文向量：：", np.around(plain_text))