class Solution:
    def reverse(self, x: int) -> int:
        reversed_num = 0

        while x != 0:
            digit = x % 10
            if reversed_num > (2**31 - 1) // 10 or (reversed_num == (2**31 - 1) // 10 and digit > 7):
                return 0
            if reversed_num < -(2**31) // 10 or (reversed_num == -(2**31) // 10 and digit < -8):
                return 0

            reversed_num = reversed_num * 10 + digit
            x //= 10

        return reversed_num