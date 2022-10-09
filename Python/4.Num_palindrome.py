
def isPalindrome(x):
        x = str(x)
        if len(x) <= 1:
            return True
        else:
            return x[0] == x[-1] and isPalindrome(x[1:-1])

x = int(input("Enter any integer: "))
print(isPalindrome(x))            



        
